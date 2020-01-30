#include <Boxes/TiledTest.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
TiledTest::TiledTest(void)
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

	ImportTMXMapData("tiled_tests.tmx");
}

void TiledTest::v_Update(void)
{

}