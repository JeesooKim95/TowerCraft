/**
\file        Mouse_Control_Component.cpp
\author      Chulseung Lee
\brief
This file will treating every user's mouse click statement.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Map_Init_Component.h"
#include "Mouse_Control_Component.h"
#include <crtdbg.h>

void MOUSE_CONTROL_COMPONENT::Helper_Get_Grid_Vec()
{
    my_map = (Map*)GetOwner();
    grid_state = my_map->Get_Grid_Kind_Vector();
    grid_vector = my_map->Get_Grid_Vector();
    enemy_path = my_map->Get_Enemy_Path();
    tower_vec = my_map->Get_tower_vec();
}

void MOUSE_CONTROL_COMPONENT::Helper_Convert_Mouse_Pos()
{
    mouse_pos = State::m_input->GetMousePos();
    mouse_pos.x -= State::m_width / 2;
    mouse_pos.y -= State::m_height / 2;
    mouse_pos.y *= -1;
}
void MOUSE_CONTROL_COMPONENT::Helper_Set_Grid_Vec()
{
    my_map->Set_Grid_State_Vector(grid_state);
    my_map->Set_Grid_Vector(grid_vector);
    my_map->Set_Enemy_Path(enemy_path);
    my_map->Set_tower_vec(tower_vec);
}

MOUSE_CONTROL_COMPONENT::MOUSE_CONTROL_COMPONENT() : Component(eComponentTypes::MOUSE_CONTROL_COMPONENT), following(nullptr)
{
}
MOUSE_CONTROL_COMPONENT::~MOUSE_CONTROL_COMPONENT()
{
}
void MOUSE_CONTROL_COMPONENT::Initialize()
{
    my_map = (Map*)GetOwner();
    grid_vector = my_map->Get_Grid_Vector();
    grid_state = my_map->Get_Grid_Kind_Vector();
}
void MOUSE_CONTROL_COMPONENT::Check_Mouse_Click()
{
    int a = 0;
    Helper_Convert_Mouse_Pos();
    Helper_Get_Grid_Vec();
    for (auto& i : grid_vector)
    {
        grid_pos = i->transform.position;
        if (mouse_pos.x > grid_pos.x - i->transform.GetScale().x / 2 &&
            mouse_pos.x < grid_pos.x + i->transform.GetScale().x / 2 &&
            mouse_pos.y > grid_pos.y - i->transform.GetScale().y / 2 &&
            mouse_pos.y < grid_pos.y + i->transform.GetScale().y / 2)
        {
            if (grid_state[a] == Map::CHUL_TOWER_BUTTON)
            {
                if (gold >= 1)
                {
                    tower_cost = 1;
                    gold -= tower_cost;
                    current_mouse_state = CHUL_TOWER_SETTING;
                    Generate_Following_Thing(grid_state[a]);
                }
            }
            else if (grid_state[a] == Map::INCOME_INCREASE_BUTTON_SETTED && gold >= 5)
            {
                my_map->income++;
                gold -= 5;
            }
            else if(grid_state[a] == Map::INCOME_INCREMENT && gold >= 50 && real_increment < 3)
            {
                real_increment++;
                gold -= 50;
            }
            else if (grid_state[a] == Map::TWICE_SPEED)
            {
                if (!twice_speed_is_on)
                {
                    twice_speed_is_on = true;
                }
                else
                {
                    twice_speed_is_on = false;
                }
            }
            else if (grid_state[a] == Map::CHUL_TOWER_SETTED)
            {
                Generate_Following_Thing(grid_state[a]);
            }
            else if (grid_state[a] == Map::START_BUTTON)
            {
                current_mouse_state = START_BUTTON_SETTING;
                Generate_Following_Thing(grid_state[a]);
            }
            else if (grid_state[a] == Map::END_BUTTON)
            {
                current_mouse_state = END_BUTTON_SETTING;
                Generate_Following_Thing(grid_state[a]);
            }
            else if (grid_state[a] == Map::WAY_BUTTON)
            {
                current_mouse_state = WAY_SETTING;
                Generate_Following_Thing(grid_state[a]);
            }
            else if (grid_state[a] == Map::START)
            {
                Generate_Following_Thing(grid_state[a]);

                game_initial_finish = true;
                game_start = true;
            }
            else if (grid_state[a] == Map::TOWER_POSITION_BUTTON)
            {
                current_mouse_state = TOWER_POSITION_SETTING;
                Generate_Following_Thing(grid_state[a]);
            }
            else if (grid_state[a] == Map::TOWER_INITED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::SWORD_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::DOUBLE_SWORD_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::BIG_SWORD_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::UNNAMED_SWORD_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::BOW_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::BIGGER_BOW_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::CROSSBOW_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::UNNAMED_BOW_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::STICK_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::ICE_STICK_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::FIRE_STICK_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::UNNAMED_STICK_TOWER_SETTED)
            {
                for (auto& z : tower_vec)
                {
                    if (z->transform.position.x == grid_vector[a]->transform.position.x &&
                        z->transform.position.y == grid_vector[a]->transform.position.y)
                    {
                        tower_clicked = z;
                        tower_grid = grid_vector[a];
                    }
                }
            }
            else if (grid_state[a] == Map::TOWER_UPGRADE_SWORD && gold > 100)
            {
                upgrade_state = Tower::sword_tower;
                gold -= 100;
            }
            else if (grid_state[a] == Map::TOWER_UPGRADE_BOW && gold > 100)
            {
                upgrade_state = Tower::bow_tower;
                gold -= 100;
            }
            else if (grid_state[a] == Map::TOWER_UPGRADE_STICK && gold > 100)
            {
                upgrade_state = Tower::stick_tower;
                gold -= 100;
            }
            else
            {
                current_mouse_state = NOTHING;

                if (upgrade_state == Tower::nothing)
                {
                    if (tower_clicked != nullptr)
                    {
                        tower_clicked->get_information_board()->sprite.isVisible = false;
                        tower_clicked->get_information_board()->tower_sprite->sprite.isVisible = false;
                        if (!tower_clicked->get_tower_upgrade_info().empty())
                        {
                            for (auto& h : tower_clicked->get_tower_upgrade_info())
                            {
                                h->sprite.isVisible = false;
                            }
                        }
                    }
                    tower_clicked = nullptr;
                }
                else if (upgrade_state != Tower::nothing)
                {
                    if (tower_clicked != nullptr)
                    {
                        for (auto& k : tower_clicked->get_tower_upgrade_info())
                        {
                            k->sprite.isVisible = false;
                        }
                    }
                }
            }
        }
        a++;
    }
    my_map->Set_Grid_State_Vector(grid_state);
}
void MOUSE_CONTROL_COMPONENT::Mouse_Setting()
{
    int a = 0;
    Helper_Get_Grid_Vec();
    b2Vec2 temp_vec;

    for (auto& i : grid_vector)
    {
        grid_pos = i->transform.position;
        if (mouse_pos.x > grid_pos.x - i->transform.GetScale().x / 2 &&
            mouse_pos.x < grid_pos.x + i->transform.GetScale().x / 2 &&
            mouse_pos.y > grid_pos.y - i->transform.GetScale().y / 2 &&
            mouse_pos.y < grid_pos.y + i->transform.GetScale().y / 2)
        {
            if (current_mouse_state == CHUL_TOWER_SETTING)
            {
                if (grid_state[a] == Map::TOWER_POSITION_BUTTON_SETTED)
                {
                    grid_state[a] = Map::CHUL_TOWER_SETTED;
                    following = nullptr;
                    current_mouse_state = NOTHING;
                    tower_cost = 0;
                    please_remove_this = true;
                }
            }
            else
            {
                if (grid_state[a] == NOTHING)
                {
                    switch (current_mouse_state)
                    {

                    case START_BUTTON_SETTING:
                        grid_state[a] = Map::START_BUTTON_SETTED;
                        i->sprite.color = { 200,123,123,200 };
                        following = nullptr;
                        current_mouse_state = NOTHING;
                        please_remove_this = true;
                        temp_vec.x = grid_pos.x;
                        temp_vec.y = grid_pos.y;
                        my_map->Set_enemy_start_pos(temp_vec);
                        enemy_path.push_back(temp_vec);
                        break;

                    case END_BUTTON_SETTING:

                        grid_state[a] = Map::END_BUTTON_SETTED;
                        i->sprite.color = { 255,34,23,200 };
                        following = nullptr;
                        current_mouse_state = NOTHING;
                        please_remove_this = true;
                        temp_vec.x = grid_pos.x;
                        temp_vec.y = grid_pos.y;
                        my_map->Set_enemy_end_pos(temp_vec);
                        enemy_path.push_back(temp_vec);
                        break;

                    case WAY_SETTING:

                        grid_state[a] = Map::WAY_BUTTON_SETTED;
                        i->sprite.color = { 12,200,12,200 };
                        temp_vec.x = grid_pos.x;
                        temp_vec.y = grid_pos.y;
                        enemy_path.push_back(temp_vec);
                        break;

                    case TOWER_POSITION_SETTING:

                        grid_state[a] = Map::TOWER_POSITION_BUTTON_SETTED;
                        i->sprite.color = { 1,23,233,200 };
                        following = nullptr;
                        current_mouse_state = NOTHING;
                        please_remove_this = true;
                        break;
                    }
                }
            }
        }
        a++;
    }

    Helper_Set_Grid_Vec();
}

void MOUSE_CONTROL_COMPONENT::Generate_Following_Thing(Map::GRID_KIND grid_kind_curr)
{
    switch (grid_kind_curr)
    {
    case Map::GRID_KIND::CHUL_TOWER_BUTTON:
        following = new Object;
        following->sprite.Free();
        following->sprite.LoadImage("texture/Tower/BasicTowerButton.png", State::m_renderer);
        following->sprite.color = { 50,50,100,100 };
        following->transform.SetScale(100, 100);
        following->transform.rotation = 0;
        please_add_this = following;
        break;

    case Map::GRID_KIND::START_BUTTON:
        following = new Object;
        following->sprite.Free();
        following->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        following->sprite.color = { 50,50,100,100 };
        following->transform.SetScale(100, 100);
        following->transform.rotation = 0;
        please_add_this = following;
        break;

    case Map::GRID_KIND::END_BUTTON:
        following = new Object;
        following->sprite.Free();
        following->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        following->sprite.color = { 50,50,100,100 };
        following->transform.SetScale(100, 100);
        following->transform.rotation = 0;
        please_add_this = following;
        break;

    case Map::GRID_KIND::WAY_BUTTON:
        following = new Object;
        following->sprite.Free();
        following->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        following->sprite.color = { 50,50,100,100 };
        following->transform.SetScale(100, 100);
        following->transform.rotation = 0;
        please_add_this = following;
        break;

    case Map::GRID_KIND::TOWER_POSITION_BUTTON:
        following = new Object;
        following->sprite.Free();
        following->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        following->sprite.color = { 50,50,100,100 };
        following->transform.SetScale(100, 100);
        following->transform.rotation = 0;
        please_add_this = following;

        break;
    }

}
void MOUSE_CONTROL_COMPONENT::Check_Following_State()
{
    int a = 0;
    Helper_Convert_Mouse_Pos();
    for (auto& i : grid_vector)
    {
        grid_pos = i->transform.position;
        if (mouse_pos.x > grid_pos.x - i->transform.GetScale().x / 2 &&
            mouse_pos.x < grid_pos.x + i->transform.GetScale().x / 2 &&
            mouse_pos.y > grid_pos.y - i->transform.GetScale().y / 2 &&
            mouse_pos.y < grid_pos.y + i->transform.GetScale().y / 2)
        {
            switch (current_mouse_state)
            {
            case CHUL_TOWER_SETTING:
                following->sprite.color = { 200,0,0,100 };
                if (grid_state[a] == Map::GRID_KIND::TOWER_POSITION_BUTTON_SETTED)
                {
                    following->sprite.color = { 0,200,0,100 };
                }
                break;

            case START_BUTTON_SETTING:
                if (grid_state[a] == Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 0,200,0,100 };
                }
                else if (grid_state[a] != Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 200,0,0,100 };
                }
            case END_BUTTON_SETTING:
                if (grid_state[a] == Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 0,200,0,100 };
                }
                else if (grid_state[a] != Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 200,0,0,100 };
                }
            case WAY_SETTING:
                if (grid_state[a] == Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 0,200,0,100 };
                }
                else if (grid_state[a] != Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 200,0,0,100 };
                }
            case TOWER_POSITION_SETTING:
                if (grid_state[a] == Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 0,200,0,100 };
                }
                else if (grid_state[a] != Map::GRID_KIND::NOTHING)
                {
                    following->sprite.color = { 200,0,0,100 };
                }
            }
        }
        a++;
    }
}
void MOUSE_CONTROL_COMPONENT::Upgrade_Tower_Mouse_Setting()
{
    Helper_Convert_Mouse_Pos();
    float normalize_left;
    float normalize_right;
    float normalize_up;
    float normalize_down;

    for (auto& i : tower_clicked->get_tower_upgrade_info())
    {
        normalize_left = i->transform.position.x - (i->transform.GetScale().x / 2);
        normalize_right = i->transform.position.x + (i->transform.GetScale().x / 2);
        normalize_up = i->transform.position.y + (i->transform.GetScale().y / 2);
        normalize_down = i->transform.position.y - (i->transform.GetScale().y / 2);

        if (i->sprite.isVisible)
        {
            if (mouse_pos.x > normalize_left && mouse_pos.x < normalize_right &&
                mouse_pos.y > normalize_down && mouse_pos.y < normalize_up)
            {
                if (i->GetName() == "sword_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::sword_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "sword_double_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::sword_double_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "sword_big_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::sword_big_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "bow_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::bow_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "bow_one_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::bow_big_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "bow_crossbow_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::bow_crossbow_tower;
                    gold -= 25;
                }
                else if (i->GetName() == "upgrade_curr" && gold >= 40 && !tower_clicked->is_last)
                {
                    upgrade_state = Tower::upgrade_this;
                    gold -= 40;
                }

                else if (i->GetName() == "stick_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::stick_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "stick_fire_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::stick_fire_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "stick_ice_upgrade" && gold >= 15)
                {
                    upgrade_state = Tower::stick_ice_tower;
                    gold -= 15;
                }
                else if (i->GetName() == "sword_steel_upgrade")
                {
                    upgrade_state = Tower::steel_sword_tower;
                }
                else if (i->GetName() == "bow_steel_upgrade")
                {
                    upgrade_state = Tower::steel_bow_tower;
                }
                else if (i->GetName() == "sword_emerald_upgrade")
                {
                    upgrade_state = Tower::emerald_sword_tower;
                }
                else if (i->GetName() == "bow_emerald_upgrade")
                {
                    upgrade_state = Tower::emerald_bow_tower;
                }
                else if (i->GetName() == "sell")
                {
                    upgrade_state = Tower::sell;
                }
            }
        }
    }
}

b2Vec2 MOUSE_CONTROL_COMPONENT::Get_Mouse_Pos()
{
    return mouse_pos;
}

void MOUSE_CONTROL_COMPONENT::Update(float dt)
{
    (dt);
    if (State::m_input->IsTriggered(SDL_BUTTON_LEFT))
    {
        if (tower_clicked != nullptr)
        {
            Upgrade_Tower_Mouse_Setting();
        }
        if (current_mouse_state == NOTHING)
        {
            please_remove_this = false;
            Check_Mouse_Click();
        }
        else if (current_mouse_state != NOTHING)
        {
            Mouse_Setting();
        }
    }

    else if (State::m_input->IsTriggered(SDL_BUTTON_RIGHT))
    {
        gold += 10;
        if (following != nullptr)
        {
            State::sCurrentState->RemoveObject(following);
            current_mouse_state = NOTHING;
            gold += tower_cost;
            tower_cost = 0;
        }
		gold += 10;
        if (tower_cost != 0)
        {
            gold += tower_cost;
        }
    }
    if (following != nullptr)
    {
        Helper_Convert_Mouse_Pos();
        Check_Following_State();
        following->transform.position.Set(mouse_pos.x, mouse_pos.y, 0.f);
    }
}
