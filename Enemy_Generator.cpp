/**
\file        Enemy_Generator.cpp
\author      Minseok Sung
\brief
This file is the header file Enemy_Generator.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/

#include "Enemy_Generator.h"
#include "CustomSprite.h"
#include "Mouse_Control_Component.h"

ENEMY_GENERATOR::ENEMY_GENERATOR() : Component(eComponentTypes::ENEMY_GENERATOR)
{
}
ENEMY_GENERATOR::~ENEMY_GENERATOR()
{

}
void ENEMY_GENERATOR::Helper_Enemy_Pos_Init()
{
    my_map = (Map*)GetOwner();
    enemy_vec = my_map->Get_enemy_vec();
    enemy_path = my_map->Get_Enemy_Path();
    enemy_start_pos = my_map->Get_enemy_start_pos();
    enemy_end_pos = my_map->Get_enemy_end_pos();
    enemy_spawn_timer = my_map->Get_enemy_respawn_timer();
}
void ENEMY_GENERATOR::Helper_Enemy_Vector_Set()
{
    my_map->set_enemy_vec(enemy_vec);
}
void ENEMY_GENERATOR::Initialize()
{
    Helper_Enemy_Pos_Init();
}
void ENEMY_GENERATOR::Spawn_Enemy()
{
    Helper_Enemy_Pos_Init();
    temp_enemy = new Enemy;
    temp_enemy->SetName("enemy");
    temp_enemy->transform.position.Set(enemy_start_pos.x, enemy_start_pos.y, 0.0f);
    temp_enemy->transform.SetScale(100, 100);
    temp_enemy->sprite.Free();
    temp_enemy->sprite.LoadImage("texture/Enemy/EnemyMushroom.png", State::m_renderer);
    temp_enemy->sprite.activeAnimation = true;
    temp_enemy->sprite.SetFrame(12);
    temp_enemy->sprite.SetSpeed(14.f);
    temp_enemy->set_hp(enemy_hp);
    temp_enemy->hp_saving = enemy_hp;
    temp_enemy->priority = enemy_proiorty;
    enemy_proiorty++;
    temp_enemy->default_enemy = "texture/Enemy/EnemyMushroom.png";
    temp_enemy->hitted_enemy = "texture/Enemy/temp/EnemyMushroomHitted2.png";
    temp_enemy->default_sprite_enemy = new CustomSprite;
    temp_enemy->default_sprite_enemy->Initialize(State::sCurrentState->m_renderer, temp_enemy->default_enemy);
    temp_enemy->hitted_sprite_enemy = new CustomSprite;
    temp_enemy->hitted_sprite_enemy->Initialize(State::sCurrentState->m_renderer, temp_enemy->hitted_enemy);
    State::sCurrentState->AddDynamicObject(temp_enemy);
    enemy_vec.push_back(temp_enemy);
    Helper_Enemy_Vector_Set();
}
void ENEMY_GENERATOR::Update(float dt)
{
    if(my_map->get_enemy_limit() != enemy_limit && game_start)
    {
        enemy_spawn_timer -= dt;

        if (enemy_spawn_timer < 0 && game_start)
        {
            Spawn_Enemy();
            enemy_spawn_timer = my_map->Get_enemy_respawn_timer();
            enemy_limit++;
        }
    }
    else if(!game_start)
    {
        enemy_limit = 0;
    }
}
