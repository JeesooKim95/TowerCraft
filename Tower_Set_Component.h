/**
\file        Tower_Set_Component.h
\author      Minseok Sung
\brief
This file is the header file of the Tower_Set_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"

class TOWER_SET_COMPONENET : public Component
{
public:

    TOWER_SET_COMPONENET();
    ~TOWER_SET_COMPONENET();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Set_Grid();
    void Helper_Get();
    void Set_Tower();
    void Helper_Set();
    void Set_Tower_Attack_Range(int in_tower_vec, Tower::Attack_Type statement, Tower* tower);
    void Reset_Tower_Attack_Range(int in_tower_vec);
    void Set_Tower_Upgrade_Info(Tower* tower);
    void set_upgrade_obj_weapon(Tower* tower);
    void set_upgrade_obj_current(std::vector<Object*>& upgrade_vec, Tower* tower);
private:
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    std::vector<Enemy*> enemy_vec;
    std::vector<b2Vec2> enemy_path;
    std::vector<Tower*> tower_vec;
    Object* sword_up;
    Object* bow_up;
    Object* stick_up;
    Object* sword_double;
    Object* sword_big;
    Object* sword_unnamed;
    Object* bow_one;
    Object* bow_crossbow;
    Object* bow_unname;
    Object* stick_ice;
    Object* stick_fire;
    Object* stick_unname;
    Object* upgrade;
    Object* sell;
    Tower* temp_tower;
    Map* my_map;
};