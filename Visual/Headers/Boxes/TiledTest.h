#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/Level.h>
#include <Engine/Texture.h>
#include <Engine/GameWindow.h>
#include <Engine/Controller.h>
#include <Engine/Engine.h>
#include <Engine/Timer.h>
#include <Boxes/DataBases.h>
#include <Boxes/Box.h>

namespace TE = Tempest;
namespace TM = TempestMath;

namespace Boxes
{
	class TiledTest : public TE::Level
	{
	public:
		//==========================================================================================================================
		//
		//Constructors	 	
		//
		//==========================================================================================================================
		TiledTest(void);

		~TiledTest(void);

		//==========================================================================================================================
		//
		//Functions
		//
		//==========================================================================================================================
		void v_Init(void)final;
		
		void v_Update(void) final;

	private:
		TE::p_Camera _camera;

	};//end Class
	typedef shared_ptr<TiledTest> p_TiledTest;
}
