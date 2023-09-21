/**
\file        Wave_Component.cpp
\author      Minseok Sung
\brief
This will treating current wave number.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Wave_Component.h"
#include "Mouse_Control_Component.h"
#include "CustomSprite.h"

WAVE_COMPONENT::WAVE_COMPONENT() : Component(eComponentTypes::WAVE_COMPONENT)
{

}
WAVE_COMPONENT::~WAVE_COMPONENT()
{

}
void WAVE_COMPONENT::Helper_Set_Wave_Sprite(Gold& this_wave)
{
	this_wave.zero_sprite_path = "texture/Others/wavenumber/0.png";
	this_wave.one_sprite_path = "texture/Others/wavenumber/1.png";
	this_wave.two_sprite_path = "texture/Others/wavenumber/2.png";
	this_wave.three_sprite_path = "texture/Others/wavenumber/3.png";
	this_wave.four_sprite_path = "texture/Others/wavenumber/4.png";
	this_wave.five_sprite_path = "texture/Others/wavenumber/5.png";
	this_wave.six_sprite_path = "texture/Others/wavenumber/6.png";
	this_wave.seven_sprite_path = "texture/Others/wavenumber/7.png";
	this_wave.eight_sprite_path = "texture/Others/wavenumber/8.png";
	this_wave.nine_sprite_path = "texture/Others/wavenumber/9.png";

	this_wave.zero_sprite = new CustomSprite;
	this_wave.zero_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.zero_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.zero_sprite);

	this_wave.one_sprite = new CustomSprite;
	this_wave.one_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.one_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.one_sprite);

	this_wave.two_sprite = new CustomSprite;
	this_wave.two_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.two_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.two_sprite);

	this_wave.three_sprite = new CustomSprite;
	this_wave.three_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.three_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.three_sprite);

	this_wave.four_sprite = new CustomSprite;
	this_wave.four_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.four_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.four_sprite);

	this_wave.five_sprite = new CustomSprite;
	this_wave.five_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.five_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.five_sprite);

	this_wave.six_sprite = new CustomSprite;
	this_wave.six_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.six_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.six_sprite);

	this_wave.seven_sprite = new CustomSprite;
	this_wave.seven_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.seven_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.seven_sprite);

	this_wave.eight_sprite = new CustomSprite;
	this_wave.eight_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.eight_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.eight_sprite);

	this_wave.nine_sprite = new CustomSprite;
	this_wave.nine_sprite->Initialize(State::sCurrentState->m_renderer, this_wave.nine_sprite_path);
	this_wave.gold_sprite_vec.push_back(this_wave.nine_sprite);
}

void WAVE_COMPONENT::Initialize()
{
	wave_vec.clear();

	wave_display = new Object;
	wave_display->transform.position.Set(360, -300,0);
	wave_display->transform.rotation = 0;
	wave_display->transform.SetScale(150, 100);
	wave_display->sprite.LoadImage("texture/Others/wave.png", State::m_renderer);
	wave_vec.push_back(wave_display);

	wave_first = new Gold;
	wave_first->transform.position.Set(480, -300, 0);
	wave_first->SetName("wave_first");
	wave_first->transform.rotation = 0;
	wave_first->transform.SetScale(100, 100);
	wave_first->sprite.LoadImage("texture/Others/wavenumber/0.png", State::m_renderer);
	wave_first->curr_coin_state = Gold::NONE;
	Helper_Set_Wave_Sprite(*wave_first);
	wave_vec.push_back(wave_first);

	wave_second = new Gold;
	wave_second->transform.position.Set(600, -300, 0);
	wave_second->SetName("wave_second");
	wave_second->transform.rotation = 0;
	wave_second->transform.SetScale(100, 100);
	wave_second->sprite.LoadImage("texture/Others/wavenumber/0.png", State::m_renderer);
	wave_second->curr_coin_state = Gold::NONE;
	Helper_Set_Wave_Sprite(*wave_second);
	wave_vec.push_back(wave_second);

	please_add_this_wave_vec = true;
	
}
bool WAVE_COMPONENT::Helper_Check_Color_Equal(SDL_Color this_color, SDL_Color compare_color)
{
	if (this_color.r != compare_color.r)
	{
		return false;
	}
	if (this_color.g != compare_color.g)
	{
		return false;
	}
	if (this_color.b != compare_color.b)
	{
		return false;
	}
	if (this_color.a != compare_color.a)
	{
		return false;
	}

	return true;
}
void WAVE_COMPONENT::Check_Curr_Wave_State()
{
	if (wave >= 0 && wave <= 9)
	{
		wave_first->sprite = std::move(*wave_first->gold_sprite_vec[0]);
		wave_second->sprite = std::move(*wave_second->gold_sprite_vec[wave]);
	}
	else if (wave >= 10 && wave <= 99)
	{
		int temp_wave_ten = wave;
		int temp_wave_one = wave;
		temp_wave_ten /= 10;
		temp_wave_one %= 10;
		wave_first->sprite = std::move(*wave_first->gold_sprite_vec[temp_wave_ten]);
		wave_second->sprite = std::move(*wave_second->gold_sprite_vec[temp_wave_one]);
	}
}
void WAVE_COMPONENT::Update(float dt)
{
	(dt);
	Check_Curr_Wave_State();
}