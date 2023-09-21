/**
\file        Credit.cpp
\author      Jeesoo Kim
\brief
This will treating current Credit.

copyright   All content 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Credit.h"
#include "Game.h"

float credit_time = 5.0;

void Credit::Initialize()
{
	State::sCurrentState = this;
	camera.position.Set(0, 0, 0);
	CreateCredit();
	InitializeObjects();
}

void Credit::Update(float dt)
{
	UpdateObjects(dt);

	credit_time -= dt;
	if(credit_time <= 0)
	{
		m_game->Change(LV_MainMenu);
		credit_time = 5.0;
	}
	UpdatePhysics(dt);
	Render(dt);
}

void Credit::Close()
{
	ClearBaseState();
}

void Credit::CreateCredit()
{
	creditSprite.SetName("credit");
	creditSprite.transform.position.Set(0, 0, 2);
	creditSprite.transform.SetScale(m_width, m_height);
	creditSprite.sprite.Free();
	creditSprite.sprite.LoadImage("texture/Others/Credit.png", m_renderer);
	creditSprite.sprite.activeAnimation = false;
    creditSprite.sound.LoadSound("sound/DouDouDouDoubleCheck.mp3");
    creditSprite.sound.Play();

	AddObject(&creditSprite);
}