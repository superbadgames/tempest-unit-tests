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
_direction(0.0f)
{ 
    Init();
    SetPosition(0.0f, 0.0f);
    SetScale(1.0f, 1.0f);
}

Box::Box(const TM::Point2& pos, F32 width, F32 height)
:
_speed(200.0f),
_direction(0.0f)
{
    Init();
    SetPosition(pos);
    SetScale(width, height);
}

Box::Box(const TM::Point2& pos, F32 width, F32 height, const TE::Color& col)
: 
_speed(200.0f),
_direction(0.0f)
{ 	
    Init();
    SetPosition(pos);
    SetScale(width, height);
    SetColor(col);
}


Box::Box(const TM::Point2& pos, F32 width, F32 height, const TE::Color& col, TE::p_Texture texture)
: 
_speed(200.0f),
_direction(0.0f)
{ 
    Init();
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
    AddPosition(_direction * TM::Timer::Instance()->DeltaTime() * _speed);
    DefaultUpdate();
}

void Box::OnCollide(void)
{
    AddPosition(-_direction * TM::Timer::Instance()->DeltaTime() * _speed);
    _direction = 0.0f;
}