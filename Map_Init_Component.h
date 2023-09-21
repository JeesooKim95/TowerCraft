/**
\file        Map_Init_Component.h
\author      Minseok Sung
\brief
This file is the header file of the Map_Init_Component.cpp.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <SDL2/SDL_hints.h>
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"

class MAP_INIT_COMPONENT : public Component
{
public:

    MAP_INIT_COMPONENT();
    ~MAP_INIT_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Set_Grid();
    int get_width()
    {
        return cut_twenty;
    }
    int get_height()
    {
        return cut_eleven;
    }
private:
    const int cut_twenty = 20;
    const int cut_eleven = 11;
    Object* grid;
    Map* my_map;
    std::vector<b2Vec2> enemy_path;
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    b2Vec2 mouse_pos;
    b2Vec3 grid_pos;
};