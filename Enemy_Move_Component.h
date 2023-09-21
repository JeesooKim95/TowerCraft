/**
\file        Enemy_Move_Component.h
\author      Minseok Sung
\brief
This file is the header file of the Enemy_Move_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"
#include "Enemy.h"

class ENEMY_MOVE_COMPONENT : public Component
{
public:
    ENEMY_MOVE_COMPONENT();
    ~ENEMY_MOVE_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Helper_Enemy_Pos_Init();
    void Enemy_Move_Forward(float dt);

private:
    Map* my_map;
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    std::vector<Enemy*> enemy_vec;
    std::vector<Object*> energy_vec;
    std::vector<b2Vec2> enemy_path;
    b2Vec2 enemy_start_pos;
    b2Vec2 enemy_end_pos;
    float enemy_spawn_timer;
    Enemy* temp_enemy;
    int enemy_proiorty = 0;
    float enemy_move_timer;
    Object* temp_save_enemy_obj;
};