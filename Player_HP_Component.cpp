/**
\file        Plyaer_HP_Component.cpp
\author      Jeesoo Kim
\brief
This file will treating PLAYER_HP setting.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Player_HP_Component.h"
#include "Game.h"

PLAYER_HP_COMPONENT::PLAYER_HP_COMPONENT() : Component(eComponentTypes::PLAYER_HP_COMPONENT)
{

}
PLAYER_HP_COMPONENT::~PLAYER_HP_COMPONENT()
{

}

void PLAYER_HP_COMPONENT::Initialize()
{
    for (int life_count = 0; life_count < player_hp; life_count++) 
    {
        playerHP = new Object;
        playerHP->SetName("playerHP");
        playerHP->transform.position.Set(-550+ hp_offset, -300, 0);
        playerHP->transform.rotation = 0;
        playerHP->transform.SetScale(80, 80);
        playerHP->sprite.color = { 255,0,0,255 };
        playerHP->sprite.Free();
        playerHP->sprite.LoadImage("texture/Others/life_heart.png", State::m_renderer);
        hp_offset += 80.f;
        playerHP_vec.push_back(playerHP);
    }
    please_add_this_player_hp_vec = playerHP_vec;
    please_add_this_player_hp_once = true;
}
void PLAYER_HP_COMPONENT::Update(float dt)
{
    (dt);
    if(game_start)
    {
        if (current_playerHP != player_hp && !playerHP_vec.empty())
        {
            please_remove_this_player_hp_obj = playerHP_vec.front();
            playerHP_vec.front() = nullptr;
            playerHP_vec.erase(playerHP_vec.begin());
            please_remove_this_player_hp = true;
            current_playerHP = player_hp;
        }
    }
}