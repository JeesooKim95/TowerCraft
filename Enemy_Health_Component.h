/**
\file        Enemy_Health_Component.h
\author      Jeesoo Kim
\brief
This is file is the header file of the Enemy_Health_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/Object.h>
#include "Map.h"
#include "Enemy_Generator.h"

class ENEMY_HEALTH_COMPONENT : public Component, public Object
{
public:
    ENEMY_HEALTH_COMPONENT();
    ~ENEMY_HEALTH_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Decrease_HPBar();
    void Enemy_Energy_Set();
    void Helper_Get();
    void Following_Enemy_Hp_Bar();
    void SetPositionDecrease(float decrease);
    float GetPositionDecrease();
private:
    Object *energy;
    std::vector<Object*> energy_vec;
    std::vector<Enemy*> enemy_vec;
    int enemy_vec_size_prev = 0;
    int temp_size = 0;
    int incre = 0;
    Map *map;
    float positionDecrease;
};