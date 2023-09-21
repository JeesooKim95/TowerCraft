/**
\file        Display_Clicked_Obj.cpp
\author      Minseok Sung
\brief
This file will make the information board of the clicked tower

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/

#include "Display_Clicked_Obj.h"
#include "Mouse_Control_Component.h"

DISPLAY_CLICKED_OBJ::DISPLAY_CLICKED_OBJ() : Component(eComponentTypes::DISPLAY_CLICKED_OBJ)
{
}
DISPLAY_CLICKED_OBJ::~DISPLAY_CLICKED_OBJ()
{
}
void DISPLAY_CLICKED_OBJ::Initialize()
{
}
void DISPLAY_CLICKED_OBJ::Display_Information()
{
}
void DISPLAY_CLICKED_OBJ::Set_Information()
{
    information = new Infroamtion_Board;
    information->sprite.color = { 255,255,255,255 };
    information->transform.position.Set(450, 0, 0);
    information->transform.SetScale(300, 700);
    information->transform.rotation = 0;
    information->sprite.Free();
    information->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);

    information->tower_sprite = new Object;
    information->tower_sprite->transform.position.Set(450, 230, 0);
    information->tower_sprite->sprite.Free();
    information->tower_sprite->sprite.LoadImage(tower_clicked->get_tower_sprite_path().c_str(), State::m_renderer);
    information->tower_sprite->transform.SetScale(100, 100);

    for(auto& i : tower_clicked->get_tower_upgrade_info())
    {
        i->sprite.isVisible = true;
    }
    please_add_this_tower_sprite = information->tower_sprite;
    please_add_this_tower_sprite_once = true;
    please_add_this_tower_information = information;
    please_add_this_tower_information_once = true;
    tower_clicked->set_informaiton_board(information);
}

void DISPLAY_CLICKED_OBJ::Update_Information_Board()
{
    tower_clicked->get_information_board()->sprite.Free();
    tower_clicked->get_information_board()->tower_sprite->sprite.LoadImage(tower_clicked->get_tower_sprite_path().c_str(), State::m_renderer);
    tower_clicked->get_information_board()->sprite.isVisible = true;
    tower_clicked->get_information_board()->tower_sprite->sprite.isVisible = true;
    for(auto& i : tower_clicked->get_tower_upgrade_info())
    {
        i->sprite.isVisible = true;
    }
}
void DISPLAY_CLICKED_OBJ::Set_Board_Visible_Invisible(Tower* tower, bool toggle)
{
    if (toggle == false)
    {
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        for(auto& i : tower->get_tower_upgrade_info())
        {
            i->sprite.isVisible = toggle;
        }
    }
    else
    {
        tower->get_information_board()->sprite.isVisible = true;
        tower->get_information_board()->tower_sprite->sprite.isVisible = true;
        for (auto& i : tower->get_tower_upgrade_info())
        {
            i->sprite.isVisible = toggle;
        }
    }
}

void DISPLAY_CLICKED_OBJ::Update(float dt)
{
    
    if(tower_clicked != nullptr && prev_clicked_tower == nullptr)
    {
        prev_clicked_tower = tower_clicked;
    }
    if(State::m_input->IsTriggered(SDL_BUTTON_LEFT))
    {
        if(tower_clicked != nullptr && tower_clicked == prev_clicked_tower)
        {
            Set_Board_Visible_Invisible(tower_clicked, true);
            prev_clicked_tower = tower_clicked;
        }
        else if(tower_clicked == nullptr && prev_clicked_tower != nullptr)
        {
            Set_Board_Visible_Invisible(prev_clicked_tower, false);
            prev_clicked_tower = tower_clicked;
        }
        else if(tower_clicked != nullptr && tower_clicked != prev_clicked_tower)
        {
            Set_Board_Visible_Invisible(prev_clicked_tower, false);
            Set_Board_Visible_Invisible(tower_clicked, true);
            prev_clicked_tower = tower_clicked;
        }


    }
    (dt);
}
