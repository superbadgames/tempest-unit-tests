#include <Boxes/Cannon.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
Cannon::Cannon(void) 
: 
_movementSpeed(1.0f),
_bottomBoundary(0.0f),
_topBoundary(700.0f),
_upDirection(0.0f, 1.0f),
_downDirection(0.0f, -1.0f),
_projectilePool()
{
	// TODO:: After Tempest issue #60, refactor
	//GameObject::MakeSprite();
}

Cannon::~Cannon(void)
{
	_projectilePool.clear();
}
//==========================================================================================================================
//
//Update
//
//==========================================================================================================================
void Cannon::v_Update(void)
{
	//_forceRegistry.UpdateForces();

	//std::cout << ""

	F32 yPos = TE::GameObject::GetPosition()[1];

	if(yPos > _bottomBoundary && yPos < _topBoundary)
	{
		if(TE::Controller::Instance()->GetKeyHeld(TE::W))
		{
			TE::GameObject::AddScaledPosition(_upDirection, _movementSpeed * TM::Timer::Instance()->DeltaTime());
		}
		else if(TE::Controller::Instance()->GetKeyHeld(TE::S))
		{
			TE::GameObject::AddScaledPosition(_downDirection, _movementSpeed * TM::Timer::Instance()->DeltaTime());
		}
	}
	else
	{
		if(yPos <= _bottomBoundary)
		{
			TE::GameObject::AddScaledPosition(_upDirection, _movementSpeed);
		}
		else if(yPos >= _topBoundary)
		{
			TE::GameObject::AddScaledPosition(_downDirection, _movementSpeed);
		}
	}	
}

void Cannon::Fire(const TM::Vector4& heading, ProjectileType type)
{
	for(auto projectile : _projectilePool)
	{
		if(!projectile->GetActive())
		{
			projectile->SetPosition(GameObject::GetPosition());
			projectile->SetType(type);
			projectile->AddScaledVelocity(heading, projectile->GetSpeedScale());
			projectile->SetActive(true);
			return;
		}
	}
}