#include <Boxes/Box.h>

using namespace Boxes;


//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
Box::Box(void) 
: 
_speed(200.0f),
_direction(0.0f),
_boundingBox()
{ 
	_direction.Make2D();
	//TE::p_Mesh mesh = make_shared<TE::Mesh>();
	//SetMesh(mesh);
	MakeSprite();
	SetPosition(0.0f, 0.0f);
	SetScale(1.0f, 1.0f);
}

Box::Box(const TM::Point& pos, F32 width, F32 height)
:
_speed(200.0f),
_direction(0.0f),
_boundingBox(pos, width, height, 0.0f)
{
	_direction.Make2D();
	//TE::p_Mesh mesh = make_shared<TE::Mesh>();
	//SetMesh(mesh);
	MakeSprite();
	SetPosition(pos);
	SetScale(width, height);
}

Box::Box(const TM::Point& pos, F32 width, F32 height, const TE::Color& col)
: 
_speed(200.0f),
_direction(0.0f),
_boundingBox(pos, width, height, 0.0f)
{ 	
	_direction.Make2D();
	//TE::p_Mesh mesh = make_shared<TE::Mesh>();
	//SetMesh(mesh);
	MakeSprite();
	SetPosition(pos);
	SetScale(width, height);
	SetColor(col);
}


Box::Box(const TM::Point& pos, F32 width, F32 height, const TE::Color& col, shared_ptr<TE::Texture> texture)
: 
_speed(200.0f),
_direction(0.0f),
_boundingBox(pos, width, height, 0.0f)
{ 
	_direction.Make2D();
	//TE::p_Mesh mesh = make_shared<TE::Mesh>();
	//SetMesh(mesh);
	MakeSprite();
	SetPosition(pos);
	SetScale(width, height);
	SetColor(col);
	SetTexture(texture);
}

//==========================================================================================================================
//
//Virtual functions
//
//==========================================================================================================================
//==========================================================================================================================
//Update
//==========================================================================================================================
void Box::v_Update(void) 
{
	AddScaledPosition(_direction, TM::Timer::Instance()->DeltaTime() * _speed);
	_boundingBox.SetCenter(GetPosition());
}

void Box::OnCollide(void)
{
	AddScaledPosition(-_direction, TM::Timer::Instance()->DeltaTime() * _speed);
	_boundingBox.SetCenter(GetPosition());

	_direction = 0.0f;
}

void Box::InitBounding(void)
{
	_boundingBox.SetCenter(GetPosition());
	//Set the half dimensions equal to the dimensions... Not sure why this is. It was not intended to be used this way.
	_boundingBox.SetHalfDimensions(GetScale());
}