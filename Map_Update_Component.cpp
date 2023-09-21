/**
\file        Map_Update_Component.cpp
\author      Jeesoo Kim
\brief
This file will uploading the current map's statement.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Map_Update_Component.h"
#include "Game.h"
#define _CRT_SECURE_NO_WARNINGS

MAP_UPDATE_COMPONENT::MAP_UPDATE_COMPONENT() : Component(eComponentTypes::MAP_UPDATE_COMPONENT) { }
MAP_UPDATE_COMPONENT::~MAP_UPDATE_COMPONENT()   {   }

void MAP_UPDATE_COMPONENT::Helper_Get_Grid_Vec()
{
    my_map = (Map*)GetOwner();
    grid_state = my_map->Get_Grid_Kind_Vector();
    grid_vector = my_map->Get_Grid_Vector();
    tower_vec = my_map->Get_tower_vec();
}

void MAP_UPDATE_COMPONENT::Initialize()
{
    Helper_Get_Grid_Vec();
}

void MAP_UPDATE_COMPONENT::Helper_Convert_Mouse_Pos()
{
    mouse_pos = State::m_input->GetMousePos();
    mouse_pos.x -= State::m_width / 2;
    mouse_pos.y -= State::m_height / 2;
    mouse_pos.y *= -1;
}

void MAP_UPDATE_COMPONENT::Check_Mouse_Pos()
{
    Helper_Convert_Mouse_Pos();
    Helper_Get_Grid_Vec();

    int a = 0;
    int id_save;

    for (auto& i : grid_vector)
    {

        grid_pos = i->transform.position;
        if (mouse_pos.x > grid_pos.x - i->transform.GetScale().x / 2 &&
            mouse_pos.x < grid_pos.x + i->transform.GetScale().x / 2 &&
            mouse_pos.y > grid_pos.y - i->transform.GetScale().y / 2 &&
            mouse_pos.y < grid_pos.y + i->transform.GetScale().y / 2)
        {
            i->SetName("asd");

            if (grid_state[a] == Map::TOWER_INITED || grid_state[a] == Map::SWORD_TOWER_SETTED 
                || grid_state[a] == Map::STICK_TOWER_SETTED || grid_state[a] == Map::BOW_TOWER_SETTED
                || grid_state[a] == Map::CROSSBOW_TOWER_SETTED || grid_state[a] == Map::DOUBLE_SWORD_TOWER_SETTED ||
                grid_state[a] == Map::BIG_SWORD_TOWER_SETTED || grid_state[a] == Map::BIGGER_BOW_TOWER_SETTED ||
                grid_state[a] == Map::CROSSBOW_TOWER_SETTED || grid_state[a] == Map::ICE_STICK_TOWER_SETTED ||
                grid_state[a] == Map::FIRE_STICK_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        for (auto& j : z->get_attack_range())
                        {
                            id_save = j->GetId() - grid_vector[0]->GetId();
                            if (grid_state[id_save] != Map::START &&
                                grid_state[id_save] != Map::CHUL_TOWER_BUTTON)
                            {
                                grid_state[id_save] = Map::ATTACK_RANGE;
                            }
                        }
                    }
                }
            }
        }
        else if(grid_state[a] == Map::INCOME_INCREASE_BUTTON_SETTED)
        {
            i->sprite.color = { 255, 215, 0, 255 };
        }
        else if (grid_state[a] == Map::CHUL_TOWER_BUTTON)
        {
            i->sprite.color = { 255,255,255,255 };
        }
        else if (grid_state[a] == Map::CHUL_TOWER_SETTED)
        {
            i->sprite.color = { 100,100,0,100 };
        }
        else if (grid_state[a] == Map::START_BUTTON)
        {
            i->sprite.color = { 255,255,255,255 };
        }
        else if (grid_state[a] == Map::START_BUTTON_SETTED)
        {
			i->sprite.isVisible = true;
        }
        else if (grid_state[a] == Map::END_BUTTON)
        {
            i->sprite.color = { 100,0,0,100 };
        }
        else if (grid_state[a] == Map::END_BUTTON_SETTED)
        {
			i->sprite.isVisible = true;
        }
        else if (grid_state[a] == Map::WAY_BUTTON)
        {
            i->sprite.color = { 0,100,100,100 };
        }
        else if (grid_state[a] == Map::WAY_BUTTON_SETTED)
        {
                i->sprite.isVisible = true;
        }
        else if (grid_state[a] == Map::START)
        {
        }
        else if(grid_state[a] == Map::TWICE_SPEED)
        {
            i->sprite.isVisible = true;
        }
        else if(grid_state[a] == Map::INCOME_INCREMENT)
        {
            i->sprite.isVisible = true;
        }
        else if (grid_state[a] == Map::TOWER_POSITION_BUTTON)
        {
            i->sprite.color = { 50,20,30,200 };
        }
        else if (grid_state[a] == Map::TOWER_POSITION_BUTTON_SETTED)
        {
            if (i->sprite.isVisible == false)
            {
                i->sprite.isVisible = true;
            }
        }
        else if (grid_state[a] == Map::TOWER_UPGRADE_BOW)
        {
            i->sprite.color = { 50,120,30,200 };
        }
        else if (grid_state[a] == Map::TOWER_UPGRADE_STICK)
        {
            i->sprite.color = { 50,20,130,200 };
        }
        else
        {
            if (i->sprite.isVisible == false)
            {
                i->sprite.isVisible = true;
            }
        }
        a++;
    }
    a = 0;
    for(auto& i : grid_vector)
    {
        if(grid_state[a] == Map::ATTACK_RANGE)
        {
            i->sprite.isVisible = false;
        }
        a++;
    }
}
void MAP_UPDATE_COMPONENT::Delete_Map_Buttons()
{
    int a = 0;
    for (auto& i : grid_state)
    {
        if (i == Map::START_BUTTON)
        {
            grid_state[a] = Map::NOTHING;
        }
        else if (i == Map::END_BUTTON)
        {
            grid_state[a] = Map::NOTHING;
        }
        else if (i == Map::WAY_BUTTON)
        {
            grid_state[a] = Map::NOTHING;
        }
        a++;
    }

    my_map->Set_Grid_State_Vector(grid_state);
    once = true;
}


void MAP_UPDATE_COMPONENT::Update(float dt)
{
    (dt);
    Check_Mouse_Pos();
    
    if(game_initial_finish && !once)
    {
        Delete_Map_Buttons();
    }
}
