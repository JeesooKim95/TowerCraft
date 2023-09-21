/**
\file        Enemy_Move_Component.cpp
\author      Minseok Sung
\brief
This file contain the enemy movement equation.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/

#include "Enemy_Move_Component.h"
#include "Mouse_Control_Component.h"

ENEMY_MOVE_COMPONENT::ENEMY_MOVE_COMPONENT() : Component(eComponentTypes::ENEMY_MOVE_COMPONENT)
{
}
ENEMY_MOVE_COMPONENT::~ENEMY_MOVE_COMPONENT()
{
}
void ENEMY_MOVE_COMPONENT::Helper_Enemy_Pos_Init()
{
    my_map = (Map*)GetOwner();
    enemy_vec = my_map->Get_enemy_vec();
    enemy_path = my_map->Get_Enemy_Path();
    enemy_start_pos = my_map->Get_enemy_start_pos();
    enemy_end_pos = my_map->Get_enemy_end_pos();
    enemy_spawn_timer = my_map->Get_enemy_respawn_timer();
    enemy_move_timer = my_map->Get_enemy_move_timer();
    energy_vec = my_map->get_energy_vec();
}

void ENEMY_MOVE_COMPONENT::Initialize()
{
    Helper_Enemy_Pos_Init();
}
void ENEMY_MOVE_COMPONENT::Enemy_Move_Forward(float dt)
{
    Helper_Enemy_Pos_Init();
    b2Vec2 enemy_curr_position = enemy_start_pos;
    b2Vec2 enemy_move_position;

    int a = 0;
    float newDt;
    
    for (auto& enemy : enemy_vec)
    {
        if (enemy == nullptr)
        {
            a++;
            continue;
        }

        if (enemy->get_enemy_current_state() == Enemy::SLOW)
        {
            if (enemy->get_debuf_timer() < 0)
            {
                enemy->set_enemy_current_state(Enemy::NONE);
                enemy->set_enemy_speed(enemy->get_prev_speed());
            }
            else
            {
                enemy->set_enemy_speed(10.f);
                enemy->get_debuf_timer() -= dt;
            }
        }
        else if (enemy->get_enemy_current_state() == Enemy::STUN)
        {
            if (enemy->get_debuf_timer() < 0)
            {
                enemy->set_enemy_current_state(Enemy::NONE);
                enemy->set_enemy_speed(enemy->get_prev_speed());
            }
            else
            {
                enemy->set_enemy_speed(0.f);
                enemy->get_debuf_timer() -= dt;
            }
        }
        newDt = dt * enemy->get_speed();
        int inVectorPosition = enemy->inVectorPosition;
        b2Vec3 enemyPos = enemy->transform.position;
        if (enemy->is_reach_end && !enemy->is_check_end)
        {
            enemy->is_check_end = true;
            enemy_count++;

            player_hp--;
        }

        if (inVectorPosition >= enemy_path.size() - 1)
        {
            if (enemy != nullptr)
            {
                enemy->get_energy_bar()->isDead = true;
                enemy->isDead = true;
                enemy->is_reach_end = true;
                energy_vec[a] = nullptr;
                enemy_vec[a] = nullptr;
                my_map->set_enemy_vec(enemy_vec);
                my_map->set_energy_vec(energy_vec);
                enemy_count++;
                player_hp--;
            }
            my_map->set_enemy_vec(enemy_vec);
        }
        else if (enemy_path[inVectorPosition].x < enemy_path[inVectorPosition + 1].x)
        {
            enemyPos.x += newDt;
            
            if (enemyPos.x > enemy_path[inVectorPosition + 1].x)
            {
                enemy->inVectorPosition++;
            }
            enemy->set_current_grid(my_map->get_enemy_path_in_obj()[inVectorPosition]);
        }
        else if (enemy_path[inVectorPosition].x > enemy_path[inVectorPosition + 1].x)
        {
            enemyPos.x -= newDt;
            
            if (enemyPos.x < enemy_path[inVectorPosition + 1].x)
            {
                enemy->inVectorPosition++;
            }
            enemy->set_current_grid(my_map->get_enemy_path_in_obj()[inVectorPosition]);
        }
        else if (enemy_path[inVectorPosition].y < enemy_path[inVectorPosition + 1].y)
        {
            enemyPos.y += newDt;
            
            if (enemyPos.y > enemy_path[inVectorPosition + 1].y)
            {
                enemy->inVectorPosition++;
            }
            enemy->set_current_grid(my_map->get_enemy_path_in_obj()[inVectorPosition]);
        }
        else if (enemy_path[inVectorPosition].y > enemy_path[inVectorPosition + 1].y)
        {
            enemyPos.y -= newDt;
            
            if (enemyPos.y < enemy_path[inVectorPosition + 1].y)
            {
                enemy->inVectorPosition++;
            }
            enemy->set_current_grid(my_map->get_enemy_path_in_obj()[inVectorPosition]);
        }
		if(enemy!=nullptr)
		{
			enemy->transform.position.Set(enemyPos.x, enemyPos.y, 0.0f);			
		}
        a++;
    }
}

void ENEMY_MOVE_COMPONENT::Update(float dt)
{
    if (game_start)
    {
        enemy_vec = my_map->Get_enemy_vec();
        Enemy_Move_Forward(dt);
        my_map->set_enemy_vec(enemy_vec);
    }
    else if (!game_start)
    {
        if (!enemy_vec.empty())
        {
            int a = 0;
            for (auto& i : enemy_vec)
            {
                if (enemy_vec[a] != nullptr)
                {
                    enemy_vec[a]->isDead = true;
                    enemy_vec[a] = nullptr;
                }
                (i);
                a++;
            }
            enemy_vec.clear();
        }
    }
}

