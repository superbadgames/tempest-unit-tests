#include <Boxes/MovingBoxes.h>

using namespace Boxes;

//=============================================================================
//
//Constructor
//
//=============================================================================
MovingBoxes::MovingBoxes(void)
:
_left(0.0f),
_right(0.0f), 
_bottom(0.0f),
_top(0.0f),
_redbox(ProjectFactory::Instance()->MakeBox()),
_bluebox(ProjectFactory::Instance()->MakeBox()),
_greenbox(ProjectFactory::Instance()->MakeBox()),
_levelTitle(),
_updateText(),
_message1("Message 1"),
_message2("Message 2"),
_activeBox(nullptr)
{  }

MovingBoxes::~MovingBoxes(void) 
{
    _activeBox.reset();
    _redbox.reset();
    _bluebox.reset();
    _greenbox.reset();
}

//=============================================================================
//
//InitLevel
//
//=============================================================================
void MovingBoxes::v_Init(void) 
{ 

    Level::SetID(MOVING_BOXES_ID);
    Level::SetWidth(TE::GameWindow::Instance()->GetWidth());
    Level::SetHeight(TE::GameWindow::Instance()->GetHeight());
    Level::SetBackgroundColor(TE::Color(0.2f, 0.2f, 0.2f));

    F32 width = static_cast<F32>(TE::GameWindow::Instance()->GetWidth());
    F32 height = static_cast<F32>(TE::GameWindow::Instance()->GetHeight());

    _left = TE::GameWindow::Instance()->GetScreenLeft();
    _right = TE::GameWindow::Instance()->GetScreenRight();
    _bottom = TE::GameWindow::Instance()->GetScreenBottom();
    _top = TE::GameWindow::Instance()->GetScreenTop();

    _levelTitle.SetFont(TE::FontManager::Instance()->GetFont(100));
    _levelTitle.AddText("Moving Boxes");
    _levelTitle.SetPosition(TM::Point2(-_levelTitle.GetWidth(), _top - (_top * 0.1f)));
    Level::AddTextToLevel(_levelTitle);

    _updateText.SetFont(TE::FontManager::Instance()->GetFont(100));
    _updateText.AddText("Starting Text");
    _updateText.SetPosition(TM::Point2(-_levelTitle.GetWidth(), _top - (_top * 0.25f)));
    Level::AddTextToLevel(_updateText);

    _redbox->SetPosition(0.0f, _top / 3.0f);
    _redbox->SetTexture(TE::TextureManager::Instance()->GetTexture(100));
    _redbox->SetScale(32.0f, 32.0f);
    Level::AddObjectToLevel(_redbox);

    _greenbox->SetPosition(_left / 3.0f, 0.0f);
    _greenbox->SetTexture(TE::TextureManager::Instance()->GetTexture(101));
    _greenbox->SetScale(32.0f, 32.0f);
    Level::AddObjectToLevel(_greenbox);

    _bluebox->SetPosition(_right / 3.0f, 0.0f);
    _bluebox->SetTexture(TE::TextureManager::Instance()->GetTexture(102));
    _bluebox->SetScale(32.0f, 32.0f);
    Level::AddObjectToLevel(_bluebox);

    _activeBox = _redbox;
}

//=============================================================================
//
//Update
//
//=============================================================================
void MovingBoxes::v_Update(void) 
{	
    TE::AudioManager::Instance()->PlaySource(2);
    
    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ESCAPE)) 
    { 
        TE::AudioManager::Instance()->StopSource(2);
        TE::Engine::Instance()->SetActiveLevel(TE::LevelManager::Instance()->GetLevel(MAIN_MENU_ID));
        return;
    }

    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ONE)) 
    { 
        _activeBox = _redbox;
    }
    else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::TWO)) 
    { 
        _activeBox = _greenbox; 
    }
    else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::THREE)) 
    { 
        _activeBox = _bluebox;
    }

    bool up = TE::Controller::Instance()->GetKeyDown(TE::UP_ARROW);
    bool down = TE::Controller::Instance()->GetKeyDown(TE::DOWN_ARROW);
    bool left = TE::Controller::Instance()->GetKeyDown(TE::LEFT_ARROW);
    bool right = TE::Controller::Instance()->GetKeyDown(TE::RIGHT_ARROW);

    if(up)	  
    { 
        _activeBox->SetDirection(0.0f, 1.0f);
    }
    else if(down)  
    { 
        _activeBox->SetDirection(0.0f, -1.0f);
    }
    else if(right) 
    { 
        _activeBox->SetDirection(1.0f, 0.0f);
    }
    else if(left)  
    { 
        _activeBox->SetDirection(-1.0f, 0.0f);
    }
    
    if(up && right)
    { 
        _activeBox->SetDirection(1.0f, 1.0f);	
    }
    else if(up && left)
    {
        _activeBox->SetDirection(-1.0f, 1.0f);
    }
    else if(down && right) 
    { 
        _activeBox->SetDirection(1.0f, -1.0f);
    }
    else if(down && left)  
    { 
        _activeBox->SetDirection(-1.0f, -1.0f);
    }

    if(TE::Controller::Instance()->GetKeyHeld(TE::E))
    {
        _activeBox->AddOrientation(0.0f, 0.0f, 25.0f);
    }
    else if(TE::Controller::Instance()->GetKeyHeld(TE::Q))
    {
        _activeBox->AddOrientation(0.0f, 0.0f, -25.0f);
    }
    
    if(TE::Controller::Instance()->GetKeyDown(TE::SPACE))
    {
        _activeBox->SetDirection(0.0f, 0.0f);
    }

    if(TE::Controller::Instance()->GetKeyDown(TE::U))
    {
        if(_updateText.GetText() == _message1)
        {
            _updateText.AddText(_message2);
        }
        else
        {
            _updateText.AddText(_message1);
        }
    }

    CheckBoxEdge(_redbox);
    CheckBoxEdge(_greenbox);
    CheckBoxEdge(_bluebox);

    CheckCollisions();
}//End update

//==========================================================================================================================
//
//MovingBoxes functions
//
//==========================================================================================================================	
void MovingBoxes::CheckBoxEdge(p_Box b)
{
    TM::Point2 tempPos = b->GetPosition();

    //Righ/Left check
    if(tempPos.x >= _right) 
    {
        tempPos.x = _left;
    }
    else if(tempPos.x <= _left) 
    {
        tempPos.x = _right;
    }
    
    //Top/Bottom check
    if(tempPos.y >= _top) 
    {
        tempPos.y = _bottom;
    }
    else if(tempPos.y <= _bottom) 
    {
        tempPos.y = _top;
    }

    b->SetPosition(tempPos);
}

void MovingBoxes::CheckCollisions(void)
{

    if(_redbox->OverlapCheck(_greenbox) || _redbox->OverlapCheck(_bluebox))
    {
        _redbox->OnCollide();
    }

    if(_greenbox->OverlapCheck(_redbox) || _greenbox->OverlapCheck(_bluebox))
    {
        _greenbox->OnCollide();
    }

    if(_bluebox->OverlapCheck(_redbox) || _bluebox->OverlapCheck(_greenbox))
    {
        _bluebox->OnCollide();
    }

}