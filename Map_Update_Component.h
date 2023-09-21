/**
\file        Map_Update_Component.h
\author      Jeesoo Kim
\brief
This file is the header file of the Map_Update_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include <engine/Object.h>
#include "Tower.h"
#include "Map.h"
class MAP_UPDATE_COMPONENT : public Component
{
public:
    MAP_UPDATE_COMPONENT();
    ~MAP_UPDATE_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Check_Mouse_Pos();
    void Helper_Convert_Mouse_Pos();
    void Helper_Get_Grid_Vec();
    void Delete_Map_Buttons();
private:
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    std::vector<Tower*> tower_vec;
    b2Vec2 mouse_pos;
    b2Vec3 grid_pos;
    Map* my_map;
    bool once = false;
    
};