/*==========================================================================================================================
Main Menu used to select different modes that the game can use, as well as an exit. This can be reached at any time by 
pressing the ESC key in this project.

This is not free to use, and cannot be used without the express permission
of KillerWave.

Written by Maxwell Miller
==========================================================================================================================*/
#ifndef MAIN_MAIN_H
#define MAIN_MAIN_H

//=====Engine includes=====
#include <Engine/Atom.h>
#include <Engine/LevelManager.h>
#include <Engine/GameWindow.h>
#include <Engine/Level.h>
#include <Engine/Controller.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Text.h>
#include <Engine/Engine.h>
#include <Engine/Point.h>
#include <Engine/Color.h>
#include <Engine/Menu.h>
#include <Engine/AudioManager.h>

namespace TE = Tempest;
namespace TM = TempestMath;

//=====Box includes=====
#include <Boxes/Box.h>
#include <Boxes/DataBases.h>
#include <Boxes/MovingBoxes.h>
#include <Boxes/Ballistics.h>
#include <Boxes/Demo3D.h>
#include <Boxes/ProjectFactory.h>

namespace Boxes
{
	class MainMenu : public TE::Level
	{
	public:
//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================		
		MainMenu(void);

		~MainMenu(void);

//==========================================================================================================================
//
//Virtual Functions 
//
//==========================================================================================================================		
		void v_Init(void) final;

		void v_Update(void) final;

	private:
//==========================================================================================================================
//
//Members
//
//==========================================================================================================================		
//==========================================================================================================================
//Menu Members. For now the menu is going to be hard coded into this level. There is a project added to make this an enigine
//feature, so when that is completed this will be replaced. 
//==========================================================================================================================				
		p_Box 	    _selector;
		TE::Menu 	_menu;
		TE::Font    _menuItemFont;
		TE::Text    _mainTitle;
	};//End MainMenu

//==========================================================================================================================
//
//Menu Functions
//
//==========================================================================================================================
	static void MenuItem_Level1Action(void)
	{
		TE::Engine::Instance()->SetActiveLevel(make_shared<MovingBoxes>());
	}

	static void MenuItem_BallisticsAction(void)
	{
		TE::Engine::Instance()->SetActiveLevel(make_shared<Ballistics>());
	}

	static void MenuItem_OpenglAction(void)
	{
		TE::Engine::Instance()->SetActiveLevel(make_shared<Demo3D>());
	}
}

#endif