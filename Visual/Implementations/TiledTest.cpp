#include <Boxes/TiledTest.h>
#include <iostream>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
TiledTest::TiledTest(void)
	:
	_camera(make_shared<TE::Camera2D>()),
	_camera2(make_shared<TE::FPSCamera>())
{  }

TiledTest::~TiledTest(void)
{  }

void TiledTest::v_Init(void)
{
	Level::SetID(TILED_TEST_ID);
	// TODO: These will be set to the map width and height, when they are gotten from the importer
	//Level::SetWidth(TE::GameWindow::Instance()->GetWidth());
	//Level::SetHeight(TE::GameWindow::Instance()->GetHeight());
	Level::SetBackgroundColor(TE::Color(0.2f, 0.2f, 0.2f));

	_camera->SetOrthographic(TE::GameWindow::Instance()->GetScreenLeft(), TE::GameWindow::Instance()->GetScreenRight(), 
							 TE::GameWindow::Instance()->GetScreenBottom(), TE::GameWindow::Instance()->GetScreenTop(), 
							 -100.0f, 100.0f);
	_camera->SetPosition(0.0f, 0.0f, 0.0f);
	_camera->SetMoveSpeed(500.0f);

	_camera2->SetOrthographic(TE::GameWindow::Instance()->GetScreenLeft(), TE::GameWindow::Instance()->GetScreenRight(),
							 TE::GameWindow::Instance()->GetScreenBottom(), TE::GameWindow::Instance()->GetScreenTop(),
							 -100.0f, 100.0f);
	_camera2->SetPosition(0.0f, 0.0f, 0.0f);
	_camera2->SetMoveSpeed(500.0f);
	_camera2->SetMouseSensitivity(0.0f);

	std::vector<TileData> objects = _ImportTMXMapData("tiled_tests.tmx");

	for(TileData object : objects)
	{
		p_Box obj = make_shared<Box>();
		TE::p_Texture tex = make_shared<TE::Texture>();
		tex->LoadTexture(object.imageFilePath);

		obj->SetPosition(object.pos);
		obj->SetTexture(tex);
		obj->SetScale(static_cast<F32>(object.imageWidth) / 2.0f, static_cast<F32>(object.imageHeight) / 2.0f);

		AddObjectToLevel(obj);
	}
}

void TiledTest::v_Update(void)
{
	if(TE::Controller::Instance()->GetKeyDown(TE::ESCAPE))
	{
		TE::Engine::Instance()->End();
	}
	
	if(TE::Controller::Instance()->GetKeyHeld(TE::W))
	{
		_camera->v_Move(0.0f, 1.0f); //up
		//_camera2->v_Move(0.0f, 1.0f); //up
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::S))
	{
		_camera->v_Move(0.0f, -1.0f); //up
		//_camera2->v_Move(0.0f, -1.0f); //up
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::D))
	{
		_camera->v_Move(1.0f, 0.0f);
		//_camera2->v_Move(1.0f, 0.0f);
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::A))
	{
		_camera->v_Move(-1.0f, 0.0f);
		//_camera2->v_Move(-1.0f, 0.0f);
	}
}