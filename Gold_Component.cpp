/**
\file        Gold_Component.cpp
\author      Jeesoo Kim
\brief
This file will treat every gold system.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Gold_Component.h"
#include "Mouse_Control_Component.h"
#include "CustomSprite.h"


GOLD_COMPONENT::GOLD_COMPONENT() : Component(eComponentTypes::GOLD_COMPONENT)
{
}
GOLD_COMPONENT::~GOLD_COMPONENT()
{

}
void GOLD_COMPONENT::Helper_Set_Coin_Sprite(Gold& this_gold)
{
    this_gold.zero_sprite_path = "texture/Gold/0.png";
    this_gold.one_sprite_path = "texture/Gold/1.png";
    this_gold.two_sprite_path = "texture/Gold/2.png";
    this_gold.three_sprite_path = "texture/Gold/3.png";
    this_gold.four_sprite_path = "texture/Gold/4.png";
    this_gold.five_sprite_path = "texture/Gold/5.png";
    this_gold.six_sprite_path = "texture/Gold/6.png";
    this_gold.seven_sprite_path = "texture/Gold/7.png";
    this_gold.eight_sprite_path = "texture/Gold/8.png";
    this_gold.nine_sprite_path = "texture/Gold/9.png";

    this_gold.zero_sprite = new CustomSprite;
    this_gold.zero_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.zero_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.zero_sprite);

    this_gold.one_sprite = new CustomSprite;
    this_gold.one_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.one_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.one_sprite);

    this_gold.two_sprite = new CustomSprite;
    this_gold.two_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.two_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.two_sprite);

    this_gold.three_sprite = new CustomSprite;
    this_gold.three_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.three_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.three_sprite);

    this_gold.four_sprite = new CustomSprite;
    this_gold.four_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.four_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.four_sprite);

    this_gold.five_sprite = new CustomSprite;
    this_gold.five_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.five_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.five_sprite);

    this_gold.six_sprite = new CustomSprite;
    this_gold.six_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.six_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.six_sprite);

    this_gold.seven_sprite = new CustomSprite;
    this_gold.seven_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.seven_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.seven_sprite);

    this_gold.eight_sprite = new CustomSprite;
    this_gold.eight_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.eight_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.eight_sprite);

    this_gold.nine_sprite= new CustomSprite;
    this_gold.nine_sprite->Initialize(State::sCurrentState->m_renderer, this_gold.nine_sprite_path);
    this_gold.gold_sprite_vec.push_back(this_gold.nine_sprite);

}
void GOLD_COMPONENT::Initialize()
{
	gold_vec.clear();

	gold_display = new Object;
	gold_display->transform.position.Set(-120, -300, 0);
	gold_display->transform.rotation = 0;
	gold_display->transform.SetScale(150, 100);
	gold_display->sprite.LoadImage("texture/Others/gold.png", State::m_renderer);
	gold_vec.push_back(gold_display);

    gold = 16;
    gold_first = new Gold;
    gold_first->transform.position.Set(0, -300, 0);
    gold_first->SetName("gold_first");
    gold_first->transform.rotation = 0;
    gold_first->transform.SetScale(100, 100);
    gold_first->sprite.LoadImage("texture/Gold/0.png", State::m_renderer);
    gold_first->curr_coin_state = Gold::NONE;
    Helper_Set_Coin_Sprite(*gold_first);
    gold_vec.push_back(gold_first);

    gold_second = new Gold;
    gold_second->transform.position.Set(120, -300, 0);
    gold_second->SetName("gold_second");
    gold_second->transform.rotation = 0;
    gold_second->transform.SetScale(100, 100);
    gold_second->sprite.LoadImage("texture/Gold/0.png", State::m_renderer);
    gold_second->curr_coin_state = Gold::NONE;
    Helper_Set_Coin_Sprite(*gold_second);
    gold_vec.push_back(gold_second);

    gold_third = new Gold;
    gold_third->transform.position.Set(240, -300, 0);
    gold_third->SetName("gold_third");
    gold_third->transform.rotation = 0;
    gold_third->transform.SetScale(100, 100);
    gold_third->sprite.LoadImage("texture/Gold/0.png", State::m_renderer);
    gold_third->curr_coin_state = Gold::NONE;
    Helper_Set_Coin_Sprite(*gold_third);
    gold_vec.push_back(gold_third);
    please_add_this_gold_vec = true;

}
bool GOLD_COMPONENT::Helper_Check_Color_Equal(SDL_Color this_color, SDL_Color compare_color)
{
    if(this_color.r != compare_color.r)
    {
        return false;
    }
    if(this_color.g != compare_color.g)
    {
        return false;
    }
    if(this_color.b != compare_color.b)
    {
        return false;
    }
    if(this_color.a != compare_color.a)
    {
        return false;
    }

    return true;
}
void GOLD_COMPONENT::Check_Curr_Coin_State()
{
    if(gold >= 0 && gold <= 9)
    {
        gold_first->sprite = std::move(*gold_first->gold_sprite_vec[0]);
        gold_second->sprite = std::move(*gold_second->gold_sprite_vec[0]);
        gold_third->sprite = std::move(*gold_third->gold_sprite_vec[gold]);
    }
    else if(gold >= 10 && gold <= 99)
    {
        int temp_gold_ten = gold;
        int temp_gold_one = gold;
        temp_gold_ten /= 10;
        temp_gold_one %= 10;
        gold_first->sprite = std::move(*gold_first->gold_sprite_vec[0]);
        gold_second->sprite = std::move(*gold_second->gold_sprite_vec[temp_gold_ten]);
        gold_third->sprite = std::move(*gold_third->gold_sprite_vec[temp_gold_one]);
    }
    else if(gold >= 100 && gold <= 999)
    {
        int temp_gold_hundred = gold;
        int temp_gold_ten = gold;
        int temp_gold_one = gold;
        temp_gold_hundred /= 100;
        temp_gold_ten /= 10;
        temp_gold_ten %= 10;
        temp_gold_one %= 10;
        gold_first->sprite = std::move(*gold_first->gold_sprite_vec[temp_gold_hundred]);
        gold_second->sprite = std::move(*gold_second->gold_sprite_vec[temp_gold_ten]);
        gold_third->sprite = std::move(*gold_third->gold_sprite_vec[temp_gold_one]);
    }
}

void GOLD_COMPONENT::Update(float dt)
{
    (dt);
    Check_Curr_Coin_State();
}
