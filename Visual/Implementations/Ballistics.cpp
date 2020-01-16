#include <Boxes/Ballistics.h>

using namespace Boxes;

//=============================================================================
//
//Constructor
//
//=============================================================================
Ballistics::Ballistics(void) 
:
_poolSize(10),
_activeProjectileType(ProjectileType::BULLET),
_levelTitle(),
_cannon(nullptr),
p_gravityForce(nullptr)
{
	p_gravityForce = TP::PhysicsFactory::Instance()->MakeGravityForce();
	p_gravityForce->Set(0.0f, -100.0f, 0.0f);
}

Ballistics::~Ballistics(void)
{
	_cannon.reset();
}

//=============================================================================
//
//InitLevel
//
//=============================================================================
void Ballistics::v_Init(void)
{
	Level::SetID(BALLISTICS_ID);
	Level::SetWidth(TE::GameWindow::Instance()->GetWidth());
	Level::SetHeight(TE::GameWindow::Instance()->GetHeight());
	Level::SetBackgroundColor(TE::Color(0.2f, 0.2f, 0.2f));

	F32 width = static_cast<F32>(Level::GetWidth());
	F32 height = static_cast<F32>(Level::GetHeight());

	F32 left = -width / 2.0f;
	F32 right = width / 2.0f;
	F32 bottom = -height / 2.0f;
	F32 top = height / 2.0f;

	_levelTitle.SetFont(TE::FontManager::Instance()->GetFont(100));
	_levelTitle.AddText("BALLISTICS");
	_levelTitle.SetPosition(TM::Point(-_levelTitle.GetWidth(), top - (top * 0.1f)));
	Level::AddTextToLevel(_levelTitle);
	

	//=====Setup GameObjects=====
	_cannon = ProjectFactory::Instance()->MakeCannon();
	//minus because left and bottom are already negative
	_cannon->SetPosition(left - (left / 10.0f), bottom - (bottom / 10.0f));
	_cannon->SetScale(25.0f, 25.0f);
	_cannon->SetMovementSpeed(120.0f);
	_cannon->SetTopBoundary(top);
	_cannon->SetBottomBoundary(bottom);
	// TODO:: After Tempest issue #64, refactor
	//_cannon->SetTexture(TE::TextureManager::Instance()->GetTexture(300));
	Level::AddObjectToLevel(_cannon);

	
	for(U32 i = 0; i < _poolSize; ++i)
	{
		p_Projectile p = ProjectFactory::Instance()->MakeProjectile();
		p->SetScale(10.0f, 10.0f);
		_cannon->AddToPool(p);
		Level::AddObjectToLevel(p);
		Level::RegisterRigidBody2DForce(p->GetRigidBody(), p_gravityForce);
	}

	//TODO:: Once level's call init when they are set to active, this can be removed
	TE::GameWindow::Instance()->EnableMouseCursor();
}	

//=============================================================================
//
//Update
//
//=============================================================================
void Ballistics::v_Update(void)
{
	if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ESCAPE)) 
	{ 
		TE::LevelManager::Instance()->SetActiveLevel(MAIN_MENU_ID);
		return;
	}

	//===== Get User Input =====
	if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ONE))
	{
		_activeProjectileType = BULLET;
	}
	else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::TWO))
	{
		_activeProjectileType = ARTILLERY;
	}
	else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::THREE))
	{
		_activeProjectileType = MISSILE;
	}
	else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::FOUR))
	{
		_activeProjectileType = FIRE_BALL;
	}
	else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::FIVE))
	{
		_activeProjectileType = LAZER;
	}
	else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::SIX))
	{
		_activeProjectileType = GRENADE;
	}

	if(TE::Controller::Instance()->GetKeyDown(TE::Keys::LEFT_MOUSE)) 
	{ 
		TM::Point input = TE::Controller::Instance()->GetMouseCoordInScreen();

		TM::Vector4 heading = TM::Vector4(input - _cannon->GetPosition());

		heading.Normalize();
				
		_cannon->Fire(heading, _activeProjectileType);
	}
}