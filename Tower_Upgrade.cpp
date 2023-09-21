/**
\file        Tower_Upgrade.cpp
\author      Chulseung Lee
\brief
This file will treating the Tower Upgrade

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Tower_Upgrade.h"
#include "Mouse_Control_Component.h"
#include <iostream>
#include <ctime>
#include "CustomSprite.h"

TOWER_UPGRADE::TOWER_UPGRADE() : Component(eComponentTypes::TOWER_UPGRADE)
{
}
TOWER_UPGRADE::~TOWER_UPGRADE()
{

}
void TOWER_UPGRADE::Initialize()
{
    my_map = (Map*)GetOwner();
    skill_sword.push_back(Tower::DOUBLE_ATTACK_SWORD);
    skill_sword.push_back(Tower::CRITICAL_SWORD_SWORD);
    skill_sword.push_back(Tower::TIMBERSAW);

    skill_bow.push_back(Tower::MULTI_SHOT_BOW);
    skill_bow.push_back(Tower::COLD_SHOT_BOW);
    skill_bow.push_back(Tower::FIRE_SHOT_BOW);
    skill_bow.push_back(Tower::CRITICAL_BOW);

    skill_sword_2.push_back(Tower::CRITICAL_SWORD_2);
    skill_sword_2.push_back(Tower::TIMERSAW_2);

    skill_bow_2.push_back(Tower::DOUBLE_MULTI_SHOT);
    skill_bow_2.push_back(Tower::COLD_SHOT_BOW_2);
    skill_bow_2.push_back(Tower::CRITICAL_BOW_2);

    skill_sword_3.push_back(Tower::CRITICAL_3);
    skill_sword_3.push_back(Tower::TIMBERSAW_3);
    skill_bow_3.push_back(Tower::TRIPLE_MULTI_SHOT);
    skill_bow_3.push_back(Tower::COLD_MULTI_SHOT);
}
void TOWER_UPGRADE::Helper_Get()
{
    tower_vec = my_map->Get_tower_vec();
    grid_vector = my_map->Get_Grid_Vector();
    grid_state = my_map->Get_Grid_Kind_Vector();
}
bool TOWER_UPGRADE::check_tower_state()
{
    if (tower_clicked->Get_Attack_Type() != Tower::nothing)
    {
        return true;
    }
    return false;
}

void TOWER_UPGRADE::Set_Mana_1(Tower* this_tower, Tower::Skill_Kind skill_kind)
{
    switch (skill_kind)
    {
    case Tower::DOUBLE_ATTACK_SWORD:
        this_tower->set_skill_mana(5);
        break;

    case Tower::CRITICAL_SWORD_SWORD:
        this_tower->set_skill_mana(5);
        break;

    case Tower::TIMBERSAW:
        this_tower->set_skill_mana(8);
        break;

    case Tower::MULTI_SHOT_BOW:
        this_tower->set_skill_mana(8);
        break;

    case Tower::COLD_SHOT_BOW:
        this_tower->set_skill_mana(3);
        break;

    case Tower::FIRE_SHOT_BOW:
        this_tower->set_skill_mana(2);
        break;

    case Tower::CRITICAL_BOW:
        this_tower->set_skill_mana(3);
        break;
    }
}
void TOWER_UPGRADE::Set_Mana_2(Tower* this_tower, Tower::Skill_Kind_Level2 skill_kind_2)
{
    switch (skill_kind_2)
    {
    case Tower::CRITICAL_SWORD_2:
        this_tower->set_skill_mana(5);
        break;

    case Tower::TIMERSAW_2:
        this_tower->set_skill_mana(7);
        break;

    case Tower::DOUBLE_MULTI_SHOT:
        this_tower->set_skill_mana(8);
        break;

    case Tower::COLD_SHOT_BOW_2:
        this_tower->set_skill_mana(4);
        break;

    case Tower::CRITICAL_BOW_2:
        this_tower->set_skill_mana(3);
        break;
    }
}
void TOWER_UPGRADE::Set_Mana_3(Tower* this_tower, Tower::Skill_Kind_Level3 skill_kind_3)
{
    switch (skill_kind_3)
    {
    case Tower::CRITICAL_3:
        this_tower->set_skill_mana(3);
        break;

    case Tower::TIMBERSAW_3:
        this_tower->set_skill_mana(7);
        break;

    case Tower::TRIPLE_MULTI_SHOT:
        this_tower->set_skill_mana(8);
        break;

    case Tower::COLD_MULTI_SHOT:
        this_tower->set_skill_mana(2);
        break;
    }
}

void TOWER_UPGRADE::Upgrade_this_tower()
{
    srand((unsigned int)time(NULL));
    SDL_Color darker = { 1,1,1,0 };
    switch (upgrade_state)
    {
    case Tower::sword_tower:
        tower_clicked->set_prev_attack_timer(1.0f);
        tower_clicked->set_attack_damage(13);
        tower_clicked->set_skill_mana(500000);
        tower_clicked->Set_Attack_Type(Tower::SWORD_ATTACK);
        tower_clicked->set_tower_skill(Tower::NONO);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_SWORD;
        towerCheck++;
        break;

    case Tower::sword_double_tower:
        tower_clicked->sound.Free();
        tower_clicked->sound.LoadSound("sound/DoubleSword.mp3");
        tower_clicked->set_prev_attack_timer(0.9f);
        tower_clicked->set_attack_damage(14);
        tower_clicked->set_skill_mana(7);
        tower_clicked->Set_Attack_Type(Tower::SWORD_DOUBLE_ATTACK);
        tower_clicked->set_tower_skill(Tower::SWORD_DOUBLE_ATTACK1);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_DOUBLE_SWORD;
        break;

    case Tower::sword_big_tower:
        tower_clicked->set_attack_damage(17);
        tower_clicked->set_prev_attack_timer(1.3f);
        tower_clicked->set_skill_mana(3);
        tower_clicked->set_tower_skill(Tower::SWORD_POWER_SLASH1);
        tower_clicked->Set_Attack_Type(Tower::SWORD_BIG_ATTACK);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_BIG_SWODR;
        break;

    case Tower::bow_tower:
        tower_clicked->set_prev_attack_timer(0.9f);
        tower_clicked->set_skill_mana(500000);
        tower_clicked->Set_Attack_Type(Tower::BOW_ATTACK);
        tower_clicked->set_attack_damage(7);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_BOW;
        towerCheck++;
        break;

    case Tower::bow_big_tower:
        tower_clicked->set_prev_attack_timer(0.8f);
        tower_clicked->set_attack_damage(11);
        tower_clicked->Set_Attack_Type(Tower::BOW_BIGGER_ATTACK);
        tower_clicked->set_skill_mana(3);
        tower_clicked->set_tower_skill(Tower::BOW_BIG_ARROW);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_BIGGER_BOW;
        break;

    case Tower::bow_crossbow_tower:
        tower_clicked->set_prev_attack_timer(0.9f);
        tower_clicked->set_skill_mana(3);
        tower_clicked->set_attack_damage(13);
        tower_clicked->Set_Attack_Type(Tower::BOW_CROSSBOW_ATTACK);
        tower_clicked->set_tower_skill(Tower::CROSS_BOW_CRITICAL);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_CROSSBOW;
        tower_clicked->sound.Free();
        tower_clicked->sound.LoadSound("sound/CrossBow.mp3");
        break;

    case Tower::stick_tower:
        tower_clicked->set_prev_attack_timer(0.9f);
        tower_clicked->set_attack_damage(7);
        tower_clicked->set_skill_mana(500000);
        tower_clicked->Set_Attack_Type(Tower::STICK_ATTACK);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_STICK;
        towerCheck++;
        break;

    case Tower::stick_ice_tower:
        tower_clicked->set_prev_attack_timer(0.9f);
        tower_clicked->set_attack_damage(10);
        tower_clicked->set_skill_mana(6);
        tower_clicked->Set_Attack_Type(Tower::STICK_ICE_ATTACK);
        tower_clicked->set_tower_skill(Tower::ICE_BOLT);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_ICE_STICK;
        break;

    case Tower::stick_fire_tower:
        tower_clicked->set_prev_attack_timer(0.9f);
        tower_clicked->set_skill_mana(6);
        tower_clicked->set_attack_damage(10);
        tower_clicked->Set_Attack_Type(Tower::STICK_FIRE_ATTACK);
        tower_clicked->set_tower_skill(Tower::FIRE_BOLT);
        grid_state[tower_grid->GetId() - grid_vector[0]->GetId()] = Map::TOWER_UPGRADE_FIRE_STICK;
        break;

    case Tower::upgrade_this:
        upgrade_state = Tower::nothing;
        
         if (tower_clicked->Get_Attack_Type() == Tower::SWORD_DOUBLE_ATTACK)
        {
            tower_clicked->selling_price += 7;
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/doublesword/DoubleSwordLevel2_idle.png", State::m_renderer);
            tower_clicked->Set_Attack_Type(Tower::SWORD_DOUBLE2);
            tower_clicked->set_attack_damage(17);
            tower_clicked->set_prev_attack_timer(0.8f);
            tower_clicked->set_skill_mana(3);
            tower_clicked->set_tower_skill(Tower::SWORD_DOUBLE_ATTACK2);
            tower_clicked->get_tower_upgrade_info()[0]->sprite.LoadImage("texture/Tower/DoubleSwordLevel3Button.png", State::m_renderer);
            tower_clicked->default_sprite_path = "texture/Tower/doublesword/DoubleSwordLevel2.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/doublesword/DoubleSwordLevel2_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->skill_using_sprite_path = "texture/SkillEffetcs/doublesword/DoubleSwordLevel2Skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_frame = 7;
            tower_clicked->default_sprite_speed = 7.f;

        }
        else if (tower_clicked->Get_Attack_Type() == Tower::SWORD_DOUBLE2)
        {
            tower_clicked->selling_price += 10;
            tower_clicked->sound.Free();
            tower_clicked->sound.LoadSound("sound/DoubleSwordLevel3.mp3");
            tower_clicked->sprite.Free();
            tower_clicked->sound.Free();
            tower_clicked->sound.LoadSound("sound/DoubleSwordLevel3Skill.mp3");
            tower_clicked->sprite.LoadImage("texture/Tower/doublesword/DoubleSwordLevel3_idle.png", State::m_renderer);
            tower_clicked->Set_Attack_Type(Tower::SWORD_DOUBLE3);
            tower_clicked->set_attack_damage(40);
            tower_clicked->set_skill_mana(4);
            tower_clicked->set_tower_skill(Tower::SWORD_FEVER_TIME);
            tower_clicked->default_sprite_idle_path = "texture/Tower/doublesword/DoubleSwordLevel3_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 8.f;
            tower_clicked->skill_using_sprite_path = "texture/SkillEffetcs/doublesword/DoubleSwordLevel3Skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_sprite_path = "texture/Tower/doublesword/DoubleSwordLevel3.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->is_last = true;
        }

        else if (tower_clicked->Get_Attack_Type() == Tower::SWORD_BIG_ATTACK)
        {
            tower_clicked->selling_price += 7;
            tower_clicked->sprite.Free();
            tower_clicked->transform.SetScale(200, 200);
            tower_clicked->sprite.LoadImage("texture/Tower/bigsword/BigSwordLevel2_idle.png", State::m_renderer);
            tower_clicked->sprite.SetFrame(0);
            tower_clicked->sprite.SetSpeed(0.f);
            tower_clicked->sprite.activeAnimation = false;
            tower_clicked->Set_Attack_Type(Tower::SWORD_BIG2);
            tower_clicked->set_prev_attack_timer(1.0f);
            tower_clicked->set_attack_damage(30);
            tower_clicked->set_skill_mana(3);
            tower_clicked->set_tower_skill(Tower::SWORD_POWER_SLASH2);
            tower_clicked->skill_using_sprite_path = "texture/Tower/bigsword/skill/BigSwordLevel2Skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_sprite_path = "texture/Tower/bigsword/BigSwordLevel2.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/bigsword/BigSwordLevel2_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->get_tower_upgrade_info()[0]->sprite.LoadImage("texture/Tower/BigSwordLevel3Button.png", State::m_renderer);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::SWORD_BIG2)
        {
            tower_clicked->selling_price += 10;
            tower_clicked->sprite.Free();
            tower_clicked->transform.SetScale(200, 200);
            tower_clicked->sprite.LoadImage("texture/Tower/bigsword/BigSwordLevel3_idle.png", State::m_renderer);
            tower_clicked->sprite.SetFrame(0);
            tower_clicked->sprite.SetSpeed(0.f);
            tower_clicked->sprite.activeAnimation = false;
            tower_clicked->skill_using_sprite_path = "texture/SkillEffetcs/BigSwordLevel3Skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_sprite_path = "texture/Tower/bigsword/BigSwordLevel3.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->is_last = true;
            tower_clicked->default_sprite_idle_path = "texture/Tower/bigsword/BigSwordLevel3_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->set_prev_attack_timer(0.9f);
            tower_clicked->set_attack_damage(60);
            tower_clicked->set_skill_mana(3);
            tower_clicked->set_tower_skill(Tower::SWORD_POWER_SLASH3);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::BOW_BIGGER_ATTACK)
        {
            tower_clicked->selling_price += 7;
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/bigbow/bowlevel_2_idle.png", State::m_renderer);
            tower_clicked->set_prev_attack_timer(0.7f);
            tower_clicked->set_attack_damage(20);
            tower_clicked->set_skill_mana(3);
            tower_clicked->Set_Attack_Type(Tower::BOW_BIG2);
            tower_clicked->set_tower_skill(Tower::BOW_BIG_ARROW_MULTI);
            tower_clicked->default_sprite_idle_path = "texture/Tower/bigbow/bowlevel_2_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/bigbow/bowlevel_2.png";
            tower_clicked->default_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/bigbow/skill/bowskill2.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->set_tower_statement(Tower::NONONO);
            tower_clicked->get_tower_upgrade_info()[0]->sprite.LoadImage("texture/Tower/BowLevel3Button.png", State::m_renderer);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::BOW_BIG2)
        {
            tower_clicked->selling_price += 10;
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/bigbow/bowlevel_3_idle.png", State::m_renderer);
            tower_clicked->set_prev_attack_timer(0.5f);
            tower_clicked->set_skill_mana(3);
            tower_clicked->set_attack_damage(50);
            tower_clicked->Set_Attack_Type(Tower::BOW_BIG3);
            tower_clicked->set_tower_skill(Tower::BOW_VERY_BIG_ARROW_MULTI);
            tower_clicked->is_last = true;
            tower_clicked->default_sprite_idle_path = "texture/Tower/bigbow/bowlevel_3_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/bigbow/bowlevel_3.png";
            tower_clicked->default_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/bigbow/skill/BowBigSkill.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->set_tower_statement(Tower::NONONO);
        }

        else if (tower_clicked->Get_Attack_Type() == Tower::BOW_CROSSBOW_ATTACK)
        {
            tower_clicked->selling_price += 7;
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/crossbow/level2_crossbow_idle.png", State::m_renderer);
            tower_clicked->set_prev_attack_timer(0.8f);
            tower_clicked->set_attack_damage(25);
            tower_clicked->set_skill_mana(3);
            tower_clicked->Set_Attack_Type(Tower::CROSS_BOW2);
            tower_clicked->set_tower_skill(Tower::CROSS_BOW_CRITICAL_WITH_STUN);
            tower_clicked->default_sprite_idle_path = "texture/Tower/crossbow/level2_crossbow_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/crossbow/level2_crossbow.png";
            tower_clicked->default_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/crossbow/skill/level2_crossbow_skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            tower_clicked->get_tower_upgrade_info()[0]->sprite.LoadImage("texture/Tower/CrossBowLevel3Button.png", State::m_renderer);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::CROSS_BOW2)
        {
            tower_clicked->selling_price += 10;
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/crossbow/level3_crossbow_idle.png", State::m_renderer);
            tower_clicked->sprite.SetFrame(7);
            tower_clicked->sprite.SetSpeed(14.f);
            tower_clicked->set_prev_attack_timer(0.7f);
            tower_clicked->set_attack_damage(55);
            tower_clicked->set_skill_mana(10);
            tower_clicked->Set_Attack_Type(Tower::CROSS_BOW3);
            tower_clicked->set_tower_skill(Tower::CROSS_BOW_DEATH);
            tower_clicked->default_sprite_idle_path = "texture/Tower/crossbow/level3_crossbow_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/crossbow/level3_crossbow.png";
            tower_clicked->default_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/crossbow/skill/level3_crossbow_skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::sCurrentState->m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            tower_clicked->is_last = true;
        }
        
        else if (tower_clicked->Get_Attack_Type() == Tower::STICK_ICE_ATTACK)
        {
            tower_clicked->selling_price += 7;
            tower_clicked->sprite.LoadImage("texture/Tower/ice/WandLevel2_idle.png", State::m_renderer);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            tower_clicked->set_prev_attack_timer(0.9f);
            tower_clicked->set_attack_damage(20);
            tower_clicked->set_skill_mana(8);
            tower_clicked->Set_Attack_Type(Tower::ICE_STICK2);
            tower_clicked->default_sprite_idle_path = "texture/Tower/ice/WandLevel2_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/ice/WandLevel2.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/ice/skill/level2wandskill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->set_tower_skill(Tower::ICE_BOLT2);
            tower_clicked->get_tower_upgrade_info()[0]->sprite.LoadImage("texture/Tower/StaffLevel3Button.png", State::m_renderer);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::ICE_STICK2)
        {
            tower_clicked->selling_price += 10;
            tower_clicked->sprite.LoadImage("texture/Tower/ice/WandLevel3_idle.png", State::m_renderer);
            tower_clicked->default_frame = 2;
            tower_clicked->default_sprite_speed = 2.f;
            tower_clicked->set_prev_attack_timer(0.9f);
            tower_clicked->set_attack_damage(30);
            tower_clicked->set_skill_mana(3);
            tower_clicked->Set_Attack_Type(Tower::ICE_STICK3);
            tower_clicked->is_last = true;
            tower_clicked->default_sprite_idle_path = "texture/Tower/ice/WandLevel3_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->default_sprite_path = "texture/Tower/ice/WandLevel3.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/ice/skill/WandLevel3SKill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->set_tower_skill(Tower::ICE_BOLT3);
        }
       
        else if (tower_clicked->Get_Attack_Type() == Tower::STICK_FIRE_ATTACK)
        {
            tower_clicked->selling_price += 7;
            tower_clicked->sprite.Free();
            tower_clicked->sprite.LoadImage("texture/Tower/lightning/StaffLevel2_idle.png", State::m_renderer);
            tower_clicked->default_frame = 4;
            tower_clicked->default_sprite_speed = 4.f;
            tower_clicked->set_prev_attack_timer(0.9f);
            tower_clicked->set_skill_mana(3);
            tower_clicked->set_attack_damage(20);
            tower_clicked->Set_Attack_Type(Tower::FIRE_STICK2);
            tower_clicked->set_tower_skill(Tower::FIRE_BOLT2);
            tower_clicked->default_sprite_path = "texture/Tower/lightning/StaffLevel2.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/lightning/StaffLevel2_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/lightning/skill/level2staffskill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
            tower_clicked->get_tower_upgrade_info()[0]->sprite.LoadImage("texture/Tower/WandLevel3Button.png", State::m_renderer);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::FIRE_STICK2)
        {
            tower_clicked->selling_price += 10;
            tower_clicked->sprite.LoadImage("texture/Tower/lightning/StaffLevel3_idle.png", State::m_renderer);
            tower_clicked->default_frame = 3;
            tower_clicked->default_sprite_speed = 6.f;
            tower_clicked->set_prev_attack_timer(0.9f);
            tower_clicked->set_attack_damage(30);
            tower_clicked->set_skill_mana(8);
            tower_clicked->Set_Attack_Type(Tower::FIRE_STICK3);
            tower_clicked->set_tower_skill(Tower::FIRE_BOLT3);
            tower_clicked->is_last = true;
            tower_clicked->default_sprite_path = "texture/Tower/lightning/StaffLevel3.png";
            tower_clicked->default_sprite->Initialize(State::m_renderer, tower_clicked->default_sprite_path);
            tower_clicked->default_sprite_idle_path = "texture/Tower/lightning/StaffLevel3_idle.png";
            tower_clicked->default_sprite_idle->Initialize(State::m_renderer, tower_clicked->default_sprite_idle_path);
            tower_clicked->skill_using_sprite_path = "texture/Tower/lightning/skill/StaffLevel3Skill.png";
            tower_clicked->skill_using_sprite->Initialize(State::m_renderer, tower_clicked->skill_using_sprite_path);
        }
        else if (tower_clicked->Get_Attack_Type() == Tower::FIRE_STICK3)
        {
            tower_clicked->set_prev_attack_timer(0.6f);
            tower_clicked->set_attack_damage(20);
            tower_clicked->set_tower_skill(Tower::FIRE_BOLT3);
        }
    }

    my_map->Set_Grid_State_Vector(grid_state);
}

void TOWER_UPGRADE::Update(float dt)
{
    (dt);
    Helper_Get();
    if (tower_clicked != nullptr)
    {
        if (check_tower_state())
        {
            Upgrade_this_tower();
        }

    }
}