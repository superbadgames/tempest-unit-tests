#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/Level.h>
#include <Boxes/DataBases.h>

namespace TE = Tempest;

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

	};//end Class
	typedef shared_ptr<TiledTest> p_TiledTest;
}
