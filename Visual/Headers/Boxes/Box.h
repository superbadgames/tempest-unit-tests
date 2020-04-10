/*=========================================================================
The player controled object in the basic game of boxes. It will inher-
it from the GameObject class, and will define its own update and render.
It will have a controller in time that will allow a player to control 
where the box goes.

This is not free to use, and cannot be used without the express permission
of KillerWave.

Written by Maxwell Miller
=========================================================================*/
#pragma once;

//Killer1 Includes
#include <Engine/Atom.h>
#include <Engine/GameObject2D.h>
#include <Engine/Controller.h>
#include <Engine/Timer.h>
#include <Engine/Vector2.h>
#include <Engine/Point2.h>
#include <Engine/Color.h>
#include <Engine/AABB.h>

namespace TE = Tempest;
namespace TM = TempestMath;
namespace TC = TempestCollisions;

namespace Boxes
{
	class Box;
	typedef shared_ptr<Box> p_Box;

	class Box : public TE::GameObject2D
	{
	public:
//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================		

		Box(void);

		Box(const TM::Point2& pos, F32 width, F32 height);
		
		Box(const TM::Point2& pos, F32 width, F32 height, const TE::Color& col);

		Box(const TM::Point2& pos, F32 width, F32 height, const TE::Color& col, TE::p_Texture texture);

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================		
		void v_Update(void);

		inline bool OverlapCheck(const shared_ptr<Box> other)
		{
			return _boundingBox.TestCollision(other->GetBounding());
		}

		void OnCollide(void);

//==========================================================================================================================
//
//Accessors
//
//==========================================================================================================================
		inline void SetSpeed(F32 s) 
		{ 
			_speed = s; 
		}

		inline F32 GetSpeed(void) const
		{
			return _speed;
		}

		inline void SetDirection(const TM::Vector2& dir)
		{
			_direction = dir;
		}

		inline void SetDirection(F32 x, F32 y)
		{
			_direction.x = x;
			_direction.y = y;
		}

		inline const TM::Vector2& GetDirection(void) const
		{
			return _direction;
		}

	private:
//==========================================================================================================================
//
//Data
//
//==========================================================================================================================		
		F32  	  				_speed;
		TM::Vector2 			_direction;
	};

}//End namespace
