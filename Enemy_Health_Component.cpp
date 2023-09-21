/**
\file        Enemy_Health_Component.cpp
\author      Jeesoo Kim
\brief
This is file will generate enemy's health bar.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Enemy_Health_Component.h"
#include "Level1.h"

ENEMY_HEALTH_COMPONENT::ENEMY_HEALTH_COMPONENT() :Component(eComponentTypes::ENEMY_HEALTH_COMPONENT)
{

}
ENEMY_HEALTH_COMPONENT::~ENEMY_HEALTH_COMPONENT()
{

}
void ENEMY_HEALTH_COMPONENT::Helper_Get()
{
    enemy_vec = map->Get_enemy_vec();
    energy_vec = map->get_energy_vec();
}
void ENEMY_HEALTH_COMPONENT::Initialize()
{
    map = (Map*)GetOwner();
    Helper_Get();
}
void ENEMY_HEALTH_COMPONENT::Enemy_Energy_Set()
{
    if (!enemy_vec.empty())
    {
        Helper_Get();
        energy = new Object;
        energy->SetName("energy");
        energy->transform.position.x = enemy_vec[incre]->transform.position.x;
        energy->transform.position.y = enemy_vec[incre]->transform.position.y - 40.0f;
        energy->transform.SetScale({ 120, 80 });
        energy->sprite.LoadImage("texture/Others/HPBar.png", State::m_renderer);
        energy->sprite.isHud = true;
        enemy_vec[incre]->set_energy_bar(energy);
        incre++;
        energy_vec.push_back(energy);
        State::sCurrentState->AddDynamicObject(energy);
        map->set_energy_vec(energy_vec);
    }
}
void ENEMY_HEALTH_COMPONENT::Decrease_HPBar()
{

}
void ENEMY_HEALTH_COMPONENT::Following_Enemy_Hp_Bar()
{
    int a = 0;
    if (!energy_vec.empty())
    {
        for (auto i : energy_vec)
        {
            if(i == nullptr)
            {
                a++;
                continue;
            }
            if(enemy_vec[a] == nullptr)
            {
                a++;
                continue;
            }
            i->transform.position.x = enemy_vec[a]->transform.position.x;
            i->transform.position.y = enemy_vec[a]->transform.position.y - 40.0f;
            a++;
        }
    }

}

void ENEMY_HEALTH_COMPONENT::SetPositionDecrease(float decrease)
{
    positionDecrease = decrease;
}

float ENEMY_HEALTH_COMPONENT::GetPositionDecrease()
{
    return positionDecrease;
}

void ENEMY_HEALTH_COMPONENT::Update(float dt)
{
    (dt);
    Helper_Get();
    if (game_start)
    {
        if (enemy_vec_size_prev != enemy_vec.size() &&
            !please_add_this_enemy_hp_once)
        {
            enemy_vec_size_prev = (int)enemy_vec.size();
            Enemy_Energy_Set();
            temp_size = (int)enemy_vec.size();
            Set_Count++;
        }
        Following_Enemy_Hp_Bar();
    }
    else if (!game_start)
    {
        energy_vec.clear();
        incre = 0;
        enemy_vec_size_prev = -1;
        temp_size = 0;
        map->set_energy_vec(energy_vec);
    }
}
