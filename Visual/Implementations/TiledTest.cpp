#include <Boxes/TiledTest.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
TiledTest::TiledTest(void)
	:
	_camera(make_shared<TE::FPSCamera>())
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

	_camera = make_shared<TE::FPSCamera>();
	_camera->SetOrthographic(TE::GameWindow::Instance()->GetScreenLeft(), TE::GameWindow::Instance()->GetScreenRight(), 
							 TE::GameWindow::Instance()->GetScreenBottom(), TE::GameWindow::Instance()->GetScreenTop(), 
							 -100.0f, 100.0f);
	_camera->SetPosition(0.0f, 0.0f, 0.0f);
	_camera->SetMoveSpeed(100.0f);
	_camera->SetMouseSensitivity(0.0f);
	_camera->SetDeadZone(0.2f);

	TE::GameWindow::Instance()->SetCamera(_camera);

	std::vector<TileData> objects = _ImportTMXMapData("tiled_tests.tmx");

	for(TileData object : objects)
	{
		p_Box obj = make_shared<Box>();
		TE::p_Texture tex = make_shared<TE::Texture>();
		tex->LoadTexture(object.imageFilePath);

		obj->SetPosition(object.pos);
		obj->SetTexture(tex);
		obj->SetScale(static_cast<F32>(object.imageWidth), static_cast<F32>(object.imageHeight));

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
		_camera->v_Move(_camera->GetUpVector()); //up
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::S))
	{
		_camera->v_Move(_camera->GetUpVector() * -1.0f); //up
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::D))
	{
		
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::A))
	{
		
	}
}