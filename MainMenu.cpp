#include "CommonLevel.h"
#include "DemoUIButton.h"
#include "Color.h"
#include "MainMenu.h"
#include "Mouse_Control_Component.h"

float time = 8.0;
bool playSound1 = false;
bool playSound2 = false;
bool playSound3 = false;
bool playSound4 = false;

bool collidingStartButton1 = false;
bool collidingStartButton2 = false;
bool collidingStartButton3 = false;
bool collidingStartButton4 = false;

void MainMenu::Initialize()
{
    State::sCurrentState = this;
    m_backgroundColor = Color::WHITE;
    camera.position.Set(0, 0, 0);
    clickSound.sound.LoadSound("sound/MainMenuButtonClicked.mp3");

    CreateDigipenLogo();
    CreateTeamLogo();
    CreateBackground();
    CreateStartButton();
    CreateCreditButton();
    CreateExitButton();
    CreateTitle();
    InitializeObjects();
}

void MainMenu::Update(float dt)
{
    DemoUIButton collidingCheck;
    MOUSE_CONTROL_COMPONENT mouse;
    mouse.Helper_Convert_Mouse_Pos();
    mouse_position = mouse.Get_Mouse_Pos();

    UpdateObjects(dt);

    time -= dt;

    if (time > 5)
    {
        background.sprite.isVisible = false;
        teamLogo.sprite.isVisible = false;
        startButton.sprite.isVisible = false;
        creditButton.sprite.isVisible = false;
        exitButton.sprite.isVisible = false;
        title.sprite.isVisible = false;
    }
    else if (time < 3.8 && time > 3.79)
    {
        teamLogo.sound.Play();
    }
    else if (time > 1)
    {
        digipenLogo.sprite.Free();
        teamLogo.sprite.isVisible = true;
    }
    else
    {
        teamLogo.sprite.Free();
        background.sprite.isVisible = true;
        startButton.sprite.isVisible = true;
        creditButton.sprite.isVisible = true;
        exitButton.sprite.isVisible = true;
        title.sprite.isVisible = true;
        background.sound.SetVolume(40);
    }

    if (teamLogo.sprite.GetCurrentFrame() == 7)
    {
        teamLogo.sprite.stopAnimation = true;
    }

    if (m_input->IsTriggered(SDL_SCANCODE_P))
        m_game->Pause();

    collidingStartButton1 = collidingCheck.PointToBox(mouse_position, { 500, -150 }, { 150, 50 });
    collidingStartButton2 = collidingCheck.PointToBox(mouse_position, { 500, -210 }, { 150, 50 });    collidingStartButton3 = collidingCheck.PointToBox(mouse_position, { 500, -270 }, { 150, 50 });    collidingStartButton4 = collidingCheck.PointToBox(mouse_position, { 500, -330 }, { 150, 50 });

    if (collidingStartButton1)
    {
        if (m_input->IsTriggered(SDL_BUTTON_LEFT) && playSound1)
        {
            clickSound.sound.Play();
        }
        if (!playSound1)
        {
            startButton.sound.Play();
            playSound1 = true;
        }
    }
    else if(!collidingStartButton1 && playSound1)
    {
        playSound1 = false;
    }

    if (collidingStartButton2)
    {
        if (!playSound2)
        {
            startButton.sound.Play();
            playSound2 = true;
        }
        if(m_input->IsTriggered(SDL_BUTTON_LEFT) && playSound2)
        {
            clickSound.sound.Play();
        }
    }
    else if(!collidingStartButton2 && playSound2)
    {
        playSound2 = false;
    }
    
    if (collidingStartButton3 && !playSound3)
    {
        if (!playSound3)
        {
            startButton.sound.Play();
            playSound3 = true;
        }
        if (m_input->IsTriggered(SDL_BUTTON_LEFT) && playSound3)
        {
            clickSound.sound.Play();
        }
    }
    else if (!collidingStartButton3 && playSound3)
    {
        playSound3 = false;
    }

    if (collidingStartButton4 && !playSound4)
    {
        if (!playSound4)
        {
            startButton.sound.Play();
            playSound4 = true;
        }
        if (m_input->IsTriggered(SDL_BUTTON_LEFT) && playSound4)
        {
            clickSound.sound.Play();
        }
    }
    else if (!collidingStartButton4 && playSound4)
    {
        playSound4 = false;
    }

    UpdatePhysics(dt);
    Render(dt);
}

void MainMenu::Close()
{
    background.sprite.Free();
    startButton.sprite.Free();
    creditButton.sprite.Free();
    exitButton.sprite.Free();
    title.sprite.Free();
    clickSound.sprite.Free();
    startButton.sound.Free();

    ClearBaseState();
}
void MainMenu::CreateTeamLogo()
{
    teamLogo.SetName("teamLogo");
    teamLogo.transform.position.Set(0, 0, 2);
    teamLogo.transform.SetScale(m_width, m_height);
    teamLogo.sprite.LoadImage("texture/Others/teamLogo.png", m_renderer);
    teamLogo.sprite.activeAnimation = true;

    teamLogo.sprite.SetFrame(8);
    teamLogo.sprite.SetSpeed(14.f);
    teamLogo.sound.LoadSound("sound/TeamDoubleCheck.mp3");

    AddObject(&teamLogo);
}

void MainMenu::CreateDigipenLogo()
{
    digipenLogo.SetName("DigipenLogo");
    digipenLogo.transform.position.Set(0, 0, 2);
    digipenLogo.transform.SetScale(1024, 247);
    digipenLogo.sprite.LoadImage("texture/Others/DigipenLogo.png", m_renderer);

    AddObject(&digipenLogo);
}

void MainMenu::CreateBackground()
{
    background.SetName("background");
    background.transform.position.Set(0, 0, 1);
    background.transform.SetScale(m_width, m_height);
    background.sprite.LoadImage("texture/MainMenu/MainMenuBackground.png", State::m_renderer);
    background.sound.LoadSound("sound/BackgroundMusic.mp3");
    background.sound.Play(100);
    background.sound.SetVolume(0);
    AddObject(&background);
}

void MainMenu::CreateStartButton()
{
    startButton.SetName("StartButton");
    startButton.transform.position.Set(500, -170, 0.f);
    startButton.transform.SetScale(150.f, 50.f);
    startButton.sprite.LoadImage("texture/MainMenu/PlayButton.png", State::m_renderer);
    startButton.sound.LoadSound("sound/MenuButtonHover.mp3");

    DemoUIButton* button = dynamic_cast<DemoUIButton*>(AddComponentToObject(&startButton, eComponentTypes::DemoUIButton));
    button->mDefaultSpriteFile = "texture/MainMenu/PlayButton.png";
    button->mHoveredSpriteFile = "texture/MainMenu/PlayButtonHover.png";
    button->mButtonEvent = CreateCommand(eCommandTypes::Level1Command);

    AddObject(&startButton);
}

void MainMenu::CreateCreditButton()
{
    creditButton.SetName("creditButton");
    creditButton.transform.position.Set(500, -240, 0.f);
    creditButton.transform.SetScale(150.f, 50.f);
    creditButton.sprite.LoadImage("texture/MainMenu/creditButton.png", State::m_renderer);

    DemoUIButton* button = dynamic_cast<DemoUIButton*>(AddComponentToObject(&creditButton, eComponentTypes::DemoUIButton));
    button->mDefaultSpriteFile = "texture/MainMenu/CreditButton.png";
    button->mHoveredSpriteFile = "texture/MainMenu/CreditButtonHover.png";
    button->mButtonEvent = CreateCommand(eCommandTypes::CreditCommand);

    AddObject(&creditButton);
}

void MainMenu::CreateExitButton()
{
    exitButton.SetName("ExitButton");
    exitButton.transform.position.Set(500, -310, 0.f);
    exitButton.transform.SetScale(150.f, 50.f);
    exitButton.sprite.LoadImage("texture/MainMenu/ExitButton.png", State::m_renderer);

    DemoUIButton* button = dynamic_cast<DemoUIButton*>(AddComponentToObject(&exitButton, eComponentTypes::DemoUIButton));
    button->mDefaultSpriteFile = "texture/MainMenu/ExitButton.png";
    button->mHoveredSpriteFile = "texture/MainMenu/ExitButtonHover.png";
    button->mButtonEvent = CreateCommand(eCommandTypes::QuitCommand);

    AddObject(&exitButton);
}

void MainMenu::CreateTitle()
{
    title.SetName("Title");
    title.transform.position.Set(30, 300, 0.f);
    title.transform.SetScale(1000.f, 200.f);
    title.sprite.LoadImage("texture/MainMenu/Title.png", State::m_renderer);

    AddObject(&title);
}