/**
\file        Tower_Upgrade.h
\author      Chulseung Lee
\brief
This file is the header file of the Tower_Upgrade.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <SDL2/SDL_hints.h>
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"
#include "Enemy.h"

class TOWER_UPGRADE : public Component
{
public:
    TOWER_UPGRADE();
    ~TOWER_UPGRADE();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Helper_Get();
    bool check_tower_state();
    void Upgrade_this_tower();
    void Set_Mana_1(Tower* this_tower, Tower::Skill_Kind skill_kind);
    void Set_Mana_2(Tower* this_tower, Tower::Skill_Kind_Level2 skill_kind_2);
    void Set_Mana_3(Tower* this_tower, Tower::Skill_Kind_Level3 skill_kind_3);

    std::vector<Tower::Skill_Kind> skill_sword;
    std::vector<Tower::Skill_Kind> skill_bow;
    std::vector<Tower::Skill_Kind_Level2> skill_sword_2;
    std::vector<Tower::Skill_Kind_Level2> skill_bow_2;
    std::vector<Tower::Skill_Kind_Level3> skill_sword_3;
    std::vector<Tower::Skill_Kind_Level3> skill_bow_3;
private:
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    std::vector<Enemy*> enemy_vec;
    std::vector<b2Vec2> enemy_path;
    std::vector<Tower*> tower_vec;
    std::vector<Object*> tower_grid_temp_save;
    Tower* temp_tower;
    Map* my_map;
    b2Vec2 mouse_pos;
};