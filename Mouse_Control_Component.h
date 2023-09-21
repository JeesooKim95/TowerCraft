/**
\file        Mouse_Control_Component.h
\author      Chulseung Lee
\brief
This file is the header file of the Mouse_Control_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/Object.h>
#include "Map.h"
#include "Level1.h"
#include "Tower.h"

class MOUSE_CONTROL_COMPONENT : public Component
{
public:
    enum MOUSE_STATE
    {
        NOTHING,
        START,
        CHUL_TOWER_SETTING,
        START_BUTTON_SETTING,
        END_BUTTON_SETTING,
        WAY_SETTING,
        TOWER_POSITION_SETTING
    };
    MOUSE_CONTROL_COMPONENT();
    ~MOUSE_CONTROL_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Check_Mouse_Click();
    void Mouse_Setting();
    void Helper_Convert_Mouse_Pos();
    void Generate_Following_Thing(Map::GRID_KIND grid_kind_curr);
    void Helper_Set_Grid_Vec();
    void Helper_Get_Grid_Vec();
    void Check_Following_State();
    void Upgrade_Tower_Mouse_Setting();
    b2Vec2 Get_Mouse_Pos();
private:
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    b2Vec2 mouse_pos;
    std::vector<Tower*> tower_vec;
    b2Vec3 grid_pos;
    Object* following;
    MOUSE_STATE current_mouse_state;
    Map* my_map;
    std::vector<b2Vec2> enemy_path;
    int tower_cost = 0;
};