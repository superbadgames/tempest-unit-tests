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
	_camera(nullptr)
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

	_camera = make_shared<TE::Camera>();
	_camera->SetOrthographic(TE::GameWindow::Instance()->GetScreenLeft(), TE::GameWindow::Instance()->GetScreenRight(), 
							 TE::GameWindow::Instance()->GetScreenBottom(), TE::GameWindow::Instance()->GetScreenTop(), 
							 -100.0f, 100.0f);

	TE::GameWindow::Instance()->SetCamera(_camera);

	std::vector<TileData> objects = _ImportTMXMapData("tiled_tests.tmx");

	for(TileData object : objects)
	{
		p_Box obj = make_shared<Box>();
		TE::p_Texture tex = make_shared<TE::Texture>();
		std::cout << "texture path = " << object.imageFilePath << std::endl;
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

	F32 speed = 25.0f;

	//std::cout << "delta * speed: " << speed * TM::Timer::Instance()->DeltaTime() << std::endl;

	TM::Point camPos = TE::GameWindow::Instance()->GetCamera()->GetPosition();
	
	if(TE::Controller::Instance()->GetKeyHeld(TE::W))
	{
		camPos.AddScaledPoint(TM::Point(0.0f, 1.0f), speed * TM::Timer::Instance()->DeltaTime());
		TE::GameWindow::Instance()->GetCamera()->SetPosition(100.0f, 100.0f);
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::S))
	{
		//TE::GameWindow::Instance()->GetCamera()->ScalePosition(0.0f, -1.0f, TM::Timer::Instance()->DeltaTime());
		camPos.AddScaledPoint(TM::Point(0.0f, -1.0f), speed * TM::Timer::Instance()->DeltaTime());
		TE::GameWindow::Instance()->GetCamera()->SetPosition(0.0f, 0.0f);
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::D))
	{
		//TE::GameWindow::Instance()->GetCamera()->ScalePosition(1.0f, 0.0f, TM::Timer::Instance()->DeltaTime());
		camPos.AddScaledPoint(TM::Point(1.0f, 0.0f), speed * TM::Timer::Instance()->DeltaTime());
		TE::GameWindow::Instance()->GetCamera()->SetPosition(100.0f, 0.0f);
	}
	else if(TE::Controller::Instance()->GetKeyHeld(TE::A))
	{
		//TE::GameWindow::Instance()->GetCamera()->ScalePosition(-1.0f, 0.0f, TM::Timer::Instance()->DeltaTime());
		camPos.AddScaledPoint(TM::Point(-1.0f, 0.0f), speed * TM::Timer::Instance()->DeltaTime());
		TE::GameWindow::Instance()->GetCamera()->SetPosition(0.0f, 0.0f);
	}

	Level::SetObjectUniforms("view_position", camPos);

	std::cout << "camera pos = " << TE::GameWindow::Instance()->GetCamera()->GetPosition()[x] << "," << TE::GameWindow::Instance()->GetCamera()->GetPosition()[y] << "," << TE::GameWindow::Instance()->GetCamera()->GetPosition()[z] << std::endl;
}