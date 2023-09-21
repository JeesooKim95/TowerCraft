/**
\file        Enemy_Generator.h
\author      Minseok Sung
\brief
This file is the header file Enemy_Generator.h

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"
#include "Enemy.h"

class ENEMY_GENERATOR : public Component
{
public:
    ENEMY_GENERATOR();
    ~ENEMY_GENERATOR();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Spawn_Enemy();
    void Helper_Enemy_Pos_Init();
    void Helper_Enemy_Vector_Set();
private:
    Map* my_map;
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    std::vector<Enemy*> enemy_vec;
    std::vector<b2Vec2> enemy_path;
    b2Vec2 enemy_start_pos;
    b2Vec2 enemy_end_pos;
    float enemy_spawn_timer = 0.2f;
    Enemy* temp_enemy;
    int enemy_proiorty = 0;
    int enemy_limit = 0;
};