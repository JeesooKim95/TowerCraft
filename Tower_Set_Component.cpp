/**
\file        Tower_Set_Component.cpp
\author      Minseok Sung
\brief
This file will treating setting of the tower.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Tower_Set_Component.h"
#include "Mouse_Control_Component.h"
#include "CustomSprite.h"

TOWER_SET_COMPONENET::TOWER_SET_COMPONENET() : Component(eComponentTypes::TOWER_SET_COMPONENET)
{
}
TOWER_SET_COMPONENET::~TOWER_SET_COMPONENET()
{

}
void TOWER_SET_COMPONENET::Helper_Get()
{
    grid_state = my_map->Get_Grid_Kind_Vector();
    grid_vector = my_map->Get_Grid_Vector();
}
void TOWER_SET_COMPONENET::Helper_Set()
{
    my_map->Set_Grid_State_Vector(grid_state);
    my_map->Set_tower_vec(tower_vec);
}
void TOWER_SET_COMPONENET::Set_Tower_Attack_Range(int in_tower_vec, Tower::Attack_Type statement, Tower* tower)
{
    switch (statement)
    {
    case Tower::BASIC_ATTACK:
        tower->get_attack_range().push_back(grid_vector[in_tower_vec - 1]);
        tower->get_attack_range().push_back(grid_vector[in_tower_vec + 1]);
        if (in_tower_vec + width < grid_vector.size())
        {
            tower->get_attack_range().push_back(grid_vector[in_tower_vec + width]);
        }
        if (in_tower_vec - width > 0)
        {
            tower->get_attack_range().push_back(grid_vector[in_tower_vec - width]);
        }
        break;
    }
}
void TOWER_SET_COMPONENET::Reset_Tower_Attack_Range(int in_tower_vec)
{
    Helper_Set();
    if (tower_clicked != nullptr)
    {
        switch (tower_clicked->Get_Attack_Type())
        {
        case Tower::SWORD_ATTACK:
            tower_clicked->get_attack_range().clear();
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + width]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - width]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + 1]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - 1]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + (width - 1)]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + (width + 1)]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - (width - 1)]);
            tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - (width + 1)]);
            break;

        case Tower::STICK_ATTACK:
            tower_clicked->get_attack_range().clear();
            if (in_tower_vec + width > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + width]);
            }
            if (in_tower_vec + width + width > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + width + width]);
            }
            if (in_tower_vec - width - width > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - width - width]);
            }
            if (in_tower_vec - width > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - width]);
            }
            if (in_tower_vec + 1 > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + 1]);
            }
            if (in_tower_vec + 2 > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + 2]);
            }
            if (in_tower_vec - 1 > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - 1]);
            }
            if (in_tower_vec - 2 > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - 2]);
            }
            if (in_tower_vec + (width - 1) > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + (width - 1)]);
            }
            if (in_tower_vec + (width + 1) > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + (width + 1)]);
            }
            if (in_tower_vec - (width - 1) > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - (width - 1)]);
            }
            if (in_tower_vec - (width + 1) > 0)
            {
                tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec - (width + 1)]);
            }
            break;

        case Tower::BOW_ATTACK:
            tower_clicked->get_attack_range().clear();
            for (int i = -2; i < 3; i++)
            {
                for (int j = -2; j < 3; j++)
                {
                    if (in_tower_vec + (width * i) + j >= 0)
                    {

                        tower_clicked->get_attack_range().push_back(grid_vector[in_tower_vec + (width * i) + j]);

                    }
                }
            }
            break;
        }

    }
    Helper_Get();
}
void TOWER_SET_COMPONENET::set_upgrade_obj_weapon(Tower* tower)
{
    b2Vec2 tower_information_board_pos = { 0,0 };

    if (tower->get_information_board() != nullptr)
    {
        tower_information_board_pos.x = tower->get_information_board()->transform.position.x;
        tower_information_board_pos.y = tower->get_information_board()->transform.position.y;
    }
    switch (tower->Get_Attack_Type())
    {

    case Tower::BASIC_ATTACK:
        sword_up = new Object;
        bow_up = new Object;
        stick_up = new Object;
        tower->selling_price++;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->skill_preparing_sprite = new CustomSprite;
        tower->skill_using_sprite = new CustomSprite;
        tower->default_sprite = new CustomSprite;
        tower->default_sprite_idle = new CustomSprite;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        sword_up->transform.position.Set(450, 30, 0);
        sword_up->transform.SetScale(100, 100);
        sword_up->sprite.Free();
        sword_up->sprite.LoadImage("texture/Tower/BasicSwordTowerButton.png", State::m_renderer);
        sword_up->sprite.isVisible = false;
        sword_up->SetName("sword_upgrade");
        bow_up->transform.position.Set(450, -100, 0);
        bow_up->transform.SetScale(100, 100);
        bow_up->sprite.Free();
        bow_up->sprite.LoadImage("texture/Tower/BasicBowTowerButton.png", State::m_renderer);
        bow_up->sprite.isVisible = false;
        bow_up->SetName("bow_upgrade");
        stick_up->transform.position.Set(450, -230, 0);
        stick_up->transform.SetScale(100, 100);
        stick_up->sprite.Free();
        stick_up->sprite.LoadImage("texture/Tower/BasicMagicTowerButton.png", State::m_renderer);
        stick_up->sprite.isVisible = false;
        stick_up->SetName("stick_upgrade");
        tower->get_tower_upgrade_info().push_back(sword_up);
        tower->get_tower_upgrade_info().push_back(bow_up);
        tower->get_tower_upgrade_info().push_back(stick_up);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(sword_up);
        State::sCurrentState->AddDynamicObject(bow_up);
        State::sCurrentState->AddDynamicObject(stick_up);
        break;

    case Tower::BOW_ATTACK:
        bow_one = new Object;
        bow_crossbow = new Object;
        bow_unname = new Object;
        tower->selling_price += 3;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        bow_one->transform.position.Set(450, 30, 0);
        bow_one->transform.SetScale(100, 100);
        bow_one->sprite.Free();
        bow_one->sprite.LoadImage("texture/Tower/BowLevel1Button.png", State::m_renderer);
        bow_one->sprite.isVisible = false;
        bow_one->SetName("bow_one_upgrade");
        bow_crossbow->transform.position.Set(450, -100, 0);
        bow_crossbow->transform.SetScale(100, 100);
        bow_crossbow->sprite.Free();
        bow_crossbow->sprite.LoadImage("texture/Tower/CrossBowLevel1Button.png", State::m_renderer);
        bow_crossbow->sprite.isVisible = false;
        bow_crossbow->SetName("bow_crossbow_upgrade");
        tower->get_tower_upgrade_info().push_back(bow_one);
        tower->get_tower_upgrade_info().push_back(bow_crossbow);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(bow_one);
        State::sCurrentState->AddDynamicObject(bow_crossbow);
        break;

    case Tower::SWORD_ATTACK:
        sword_double = new Object;
        sword_big = new Object;
        sword_unnamed = new Object;
        tower->selling_price += 3;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        sword_double->transform.position.Set(450, 30, 0);
        sword_double->transform.SetScale(100, 100);
        sword_double->sprite.Free();
        sword_double->sprite.LoadImage("texture/Tower/DoubleSwordLevel1Button.png", State::m_renderer);
        sword_double->sprite.isVisible = false;
        sword_double->SetName("sword_double_upgrade");
        sword_big->transform.position.Set(450, -100, 0);
        sword_big->transform.SetScale(100, 100);
        sword_big->sprite.Free();
        sword_big->sprite.LoadImage("texture/Tower/BigSwordLevel1Button.png", State::m_renderer);
        sword_big->sprite.isVisible = false;
        sword_big->SetName("sword_big_upgrade");
        tower->get_tower_upgrade_info().push_back(sword_double);
        tower->get_tower_upgrade_info().push_back(sword_big);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(sword_double);
        State::sCurrentState->AddDynamicObject(sword_big);
        break;

    case Tower::STICK_ATTACK:
        stick_fire = new Object;
        stick_ice = new Object;
        stick_unname = new Object;
        tower->selling_price += 3;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        stick_fire->transform.position.Set(450, 30, 0);
        stick_fire->transform.SetScale(100, 100);
        stick_fire->sprite.Free();
        stick_fire->sprite.LoadImage("texture/Tower/StaffLevel1Button.png", State::m_renderer);
        stick_fire->sprite.isVisible = false;
        stick_fire->SetName("stick_fire_upgrade");
        stick_ice->transform.position.Set(450, -100, 0);
        stick_ice->transform.SetScale(100, 100);
        stick_ice->sprite.Free();
        stick_ice->sprite.LoadImage("texture/Tower/WandLevel1Button.png", State::m_renderer);
        stick_ice->sprite.isVisible = false;
        stick_ice->SetName("stick_ice_upgrade");
        tower->get_tower_upgrade_info().push_back(stick_fire);
        tower->get_tower_upgrade_info().push_back(stick_ice);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(stick_fire);
        State::sCurrentState->AddDynamicObject(stick_ice);
        break;

    case Tower::SWORD_BIG_ATTACK:
        tower->selling_price += 5;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        upgrade = new Object;
        upgrade->transform.position.Set(450, 0, 0);
        upgrade->transform.SetScale(100, 100);
        upgrade->transform.rotation = 0;
        upgrade->sprite.Free();
        upgrade->sprite.LoadImage("texture/Tower/BigSwordLevel2Button.png", State::m_renderer);
        upgrade->sprite.isVisible = false;
        upgrade->SetName("upgrade_curr");
        tower->get_tower_upgrade_info().push_back(upgrade);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(upgrade);
        break;

    case Tower::SWORD_DOUBLE_ATTACK:
        tower->selling_price += 5;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        upgrade = new Object;
        upgrade->transform.position.Set(450, 0, 0);
        upgrade->transform.SetScale(100, 100);
        upgrade->transform.rotation = 0;
        upgrade->sprite.Free();
        upgrade->sprite.LoadImage("texture/Tower/DoubleSwordLevel2Button.png", State::m_renderer);
        upgrade->sprite.isVisible = false;
        upgrade->SetName("upgrade_curr");
        tower->get_tower_upgrade_info().push_back(upgrade);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(upgrade);
        break;

    case Tower::BOW_BIGGER_ATTACK:
        tower->selling_price += 5;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        upgrade = new Object;
        upgrade->transform.position.Set(450, 0, 0);
        upgrade->transform.SetScale(100, 100);
        upgrade->transform.rotation = 0;
        upgrade->sprite.Free();
        upgrade->sprite.LoadImage("texture/Tower/BowLevel2Button.png", State::m_renderer);
        upgrade->sprite.isVisible = false;
        upgrade->SetName("upgrade_curr");
        tower->get_tower_upgrade_info().push_back(upgrade);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(upgrade);
        break;

    case Tower::BOW_CROSSBOW_ATTACK:
        tower->selling_price += 5;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        upgrade = new Object;
        upgrade->transform.position.Set(450, 0, 0);
        upgrade->transform.SetScale(100, 100);
        upgrade->transform.rotation = 0;
        upgrade->sprite.Free();
        upgrade->sprite.LoadImage("texture/Tower/CrossBowLevel2Button.png", State::m_renderer);
        upgrade->sprite.isVisible = false;
        upgrade->SetName("upgrade_curr");
        tower->get_tower_upgrade_info().push_back(upgrade);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(upgrade);
        break;

    case Tower::STICK_FIRE_ATTACK:
        tower->selling_price += 5;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        upgrade = new Object;
        upgrade->transform.position.Set(450, 0, 0);
        upgrade->transform.SetScale(100, 100);
        upgrade->transform.rotation = 0;
        upgrade->sprite.Free();
        upgrade->sprite.LoadImage("texture/Tower/StaffLevel1Button.png", State::m_renderer);
        upgrade->sprite.isVisible = false;
        upgrade->SetName("upgrade_curr");
        tower->get_tower_upgrade_info().push_back(upgrade);
        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(upgrade);
        break;

    case Tower::STICK_ICE_ATTACK:
        tower->selling_price += 5;
        tower->get_information_board() = new Infroamtion_Board;
        tower->get_information_board()->tower_sprite = new Object;
        tower->get_information_board()->sprite.color = { 255,255,255,255 };
        tower->get_information_board()->transform.position.Set(450, 0, 0);
        tower->get_information_board()->transform.SetScale(300, 700);
        tower->get_information_board()->transform.rotation = 0;
        tower->get_information_board()->sprite.Free();
        tower->get_information_board()->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
        tower->get_information_board()->sprite.isVisible = false;
        tower->get_information_board()->tower_sprite->transform.position.Set(450, 230, 0);
        tower->get_information_board()->tower_sprite->sprite.Free();
        tower->get_information_board()->tower_sprite->sprite.LoadImage(tower->get_tower_sprite_path().c_str(), State::m_renderer);
        tower->get_information_board()->tower_sprite->transform.SetScale(100, 100);
        tower->get_information_board()->tower_sprite->sprite.isVisible = false;
        upgrade = new Object;
        upgrade->transform.position.Set(450, 0, 0);
        upgrade->transform.SetScale(100, 100);
        upgrade->transform.rotation = 0;
        upgrade->sprite.Free();
        upgrade->sprite.LoadImage("texture/Tower/WandLevel1Button.png", State::m_renderer);
        upgrade->sprite.isVisible = false;
        upgrade->SetName("upgrade_curr");

        tower->get_tower_upgrade_info().push_back(upgrade);

        State::sCurrentState->AddDynamicObject(tower->get_information_board());
        State::sCurrentState->AddDynamicObject(tower->get_information_board()->tower_sprite);
        State::sCurrentState->AddDynamicObject(upgrade);
        break;
    }
}
void TOWER_SET_COMPONENET::Set_Tower_Upgrade_Info(Tower* tower)
{
    switch (tower->Get_Attack_Type())
    {
    case Tower::BASIC_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        add_this_upgrade_vec_once = true;
        break;
    case Tower::SWORD_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        add_this_upgrade_vec_once = true;
        break;
    case Tower::SWORD_DOUBLE_ATTACK:
        set_upgrade_obj_weapon(tower);
        tower->set_skill(Tower::NONE);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        add_this_upgrade_vec_once = true;
        break;
    case Tower::SWORD_BIG_ATTACK:
        set_upgrade_obj_weapon(tower);
        tower->set_skill(Tower::NONE);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        add_this_upgrade_vec_once = true;
        break;
    case Tower::SWORD_UNNAMED_ATTACK:
        set_upgrade_obj_weapon(tower);
        tower->set_skill(Tower::NONE);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        add_this_upgrade_vec_once = true;
        break;
    case Tower::BOW_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::BOW_BIGGER_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::BOW_CROSSBOW_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::BOW_UNNAMED_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::STICK_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::STICK_ICE_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::STICK_FIRE_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    case Tower::STICK_UNNAMED_ATTACK:
        set_upgrade_obj_weapon(tower);
        add_tower_upgrade_vec = tower->get_tower_upgrade_info();
        tower->set_skill(Tower::NONE);
        add_this_upgrade_vec_once = true;
        break;
    }

}
void TOWER_SET_COMPONENET::set_upgrade_obj_current(std::vector<Object*>& upgrade_vec, Tower* tower)
{
    (upgrade_vec);
    (tower);

}
void TOWER_SET_COMPONENET::Set_Tower()
{
    int a = 0;
    Helper_Get();
    for (auto i : grid_vector)
    {
        if (grid_state[a] == Map::GRID_KIND::CHUL_TOWER_SETTED)
        {
            temp_tower = new Tower;
            temp_tower->set_tower_statement(Tower::NONONO);
            temp_tower->sound.LoadSound("sound/Punch.mp3");
            temp_tower->transform.position = i->transform.position;
            temp_tower->transform.SetScale(80, 80);
            temp_tower->set_tower_sprite_path("texture/Tower/BasicTowerButton.png");
            temp_tower->sprite.Free();
            temp_tower->sprite.LoadImage("texture/Tower/basic/BasicTower_idle.png", State::m_renderer);
            temp_tower->Set_Attack_Type(Tower::Attack_Type::BASIC_ATTACK);
            temp_tower->set_upgrade_amount(4);
			temp_tower->set_attack_damage(10);
            temp_tower->set_in_grid_pos(a);
            temp_tower->set_skill_mana(500000);
            tower_vec.push_back(temp_tower);
            Set_Tower_Attack_Range(a, temp_tower->Get_Attack_Type(), temp_tower);
            Set_Tower_Upgrade_Info(temp_tower);
            temp_tower->default_sprite_path = "texture/Tower/basic/BasicTower.png";
            temp_tower->default_sprite->Initialize(State::m_renderer, temp_tower->default_sprite_path);
            temp_tower->default_sprite_idle_path = "texture/Tower/basic/BasicTower_idle.png";
            temp_tower->default_sprite_idle->Initialize(State::m_renderer, temp_tower->default_sprite_idle_path);
            temp_tower->default_frame = 3;
            temp_tower->default_sprite_speed = 3.f;
            State::sCurrentState->AddDynamicObject(temp_tower);
            grid_state[a] = Map::TOWER_INITED;
        }

        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_SWORD)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            tower_clicked->sound.Free();
            tower_clicked->sound.LoadSound("sound/Sword.mp3");
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::SWORD_TOWER_SETTED;
            tower_clicked->set_tower_sprite_path("texture/Tower/BasicSwordTowerButton.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/basic/BasicSwordTower_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            tower_clicked->default_sprite_path = "texture/Tower/basic/BasicSwordTower.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/basic/BasicSwordTower_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_BOW)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::BOW_TOWER_SETTED;
            tower_clicked->sound.Free();
            tower_clicked->sound.LoadSound("sound/Bow.mp3");
            tower_clicked->set_tower_sprite_path("texture/Tower/BasicBowTowerButton.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/basic/BasicBowTower_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked->default_sprite_path = "texture/Tower/basic/BasicBowTower.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/basic/BasicBowTower_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_STICK)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::STICK_TOWER_SETTED;
            temp_tower->sound.Free();
            temp_tower->sound.LoadSound("sound/Magic.mp3");
            tower_clicked->set_tower_sprite_path("texture/Tower/BasicMagicTowerButton.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/basic/BasicMagicTower_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            tower_clicked->default_sprite_path = "texture/Tower/basic/BasicMagicTower.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/basic/BasicMagicTower_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_frame = 5;
            tower_clicked->default_sprite_speed = 5.f;
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_DOUBLE_SWORD)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::DOUBLE_SWORD_TOWER_SETTED;
            tower_clicked->set_tower_sprite_path("texture/Tower/DoubleSwordLevel1Button.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/doublesword/DoubleSwordLevel1_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            tower_clicked->default_sprite_path = "texture/Tower/doublesword/DoubleSwordLevel1.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/doublesword/DoubleSwordLevel1_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_frame = 10;
            tower_clicked->default_sprite_speed = 10.f;
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_BIG_SWODR)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::BIG_SWORD_TOWER_SETTED;
            tower_clicked->set_tower_sprite_path("texture/Tower/BigSwordLevel1Button.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/bigsword/BigSwordLevel1_idle.png", State::m_renderer);
            tower_clicked->sprite.activeAnimation = false;
            tower_clicked->transform.SetScale(100, 100);
            tower_clicked->default_sprite_idle_path = "texture/Tower/bigsword/BigSwordLevel1_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/bigsword/BigSwordLevel1.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/bigsword/skill/BigSwordLevel1Skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_BIGGER_BOW)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::BIGGER_BOW_TOWER_SETTED;
            temp_tower->set_tower_sprite_path("texture/Tower/BowLevel1Button.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/bigbow/bowlevel_1_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            tower_clicked->default_sprite_idle_path = "texture/Tower/bigbow/bowlevel_1_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/bigbow/bowlevel_1.png";
            tower_clicked->default_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/bigbow/skill/bowskill1.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->set_tower_statement(Tower::NONONO);
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_CROSSBOW)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::CROSSBOW_TOWER_SETTED;
            tower_clicked->set_tower_sprite_path("texture/Tower/CrossBowLevel1Button.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/crossbow/level1_crossbow_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked->default_sprite_idle_path = "texture/Tower/crossbow/level1_crossbow_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/crossbow/level1_crossbow.png";
            tower_clicked->default_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/crossbow/skill/level1_crossbow_skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            tower_clicked = nullptr;
        }

        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_ICE_STICK)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::ICE_STICK_TOWER_SETTED;
            tower_clicked->set_tower_sprite_path("texture/Tower/WandLevel1Button.png");
            tower_clicked->sprite.LoadImage("texture/Tower/ice/WandLevel1_idle.png", State::m_renderer);
            tower_clicked->transform.SetScale(100, 100);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 6.f;
            tower_clicked->default_sprite_path = "texture/Tower/ice/WandLevel1.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/ice/WandLevel1_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/ice/skill/level1wandskill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->transform.SetScale(100, 100);
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked = nullptr;
        }
        else if (grid_state[a] == Map::GRID_KIND::TOWER_UPGRADE_FIRE_STICK)
        {
            Reset_Tower_Attack_Range(a);
            tower_clicked->get_information_board()->isDead = true;
            tower_clicked->get_information_board()->tower_sprite->isDead = true;
            for (auto k : tower_clicked->get_tower_upgrade_info())
            {
                k->isDead = true;
            }
            tower_clicked->get_tower_upgrade_info().clear();
            upgrade_state = Tower::Tower_Kind::nothing;
            grid_state[a] = Map::FIRE_STICK_TOWER_SETTED;
            tower_clicked->set_tower_sprite_path("texture/Tower/StaffLevel1Button.png");
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/lightning/StaffLevel1_idle.png", State::m_renderer);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 6.f;
            tower_clicked->transform.SetScale(100, 100);
            Set_Tower_Upgrade_Info(tower_clicked);
            tower_clicked->default_sprite_path = "texture/Tower/lightning/StaffLevel1.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/lightning/StaffLevel1_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/lightning/skill/level1staffskill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked = nullptr;
        }
        a++;
    }
    Helper_Set();
}

void TOWER_SET_COMPONENET::Initialize()
{
    my_map = (Map*)GetOwner();
    grid_state = my_map->Get_Grid_Kind_Vector();
}

void TOWER_SET_COMPONENET::Update(float dt)
{
    (dt);
    Set_Tower();
}