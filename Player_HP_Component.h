/**
\file        Plyaer_HP_Component.h
\author      Jeesoo Kim
\brief
This file is the header file of the Player_HP_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/Object.h>
#include "Map.h"

class PLAYER_HP_COMPONENT : public Component
{
public:

    PLAYER_HP_COMPONENT();
    ~PLAYER_HP_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Life_Decrease();
private:
    std::vector<Object*> playerHP_vec;
    Object* playerHP;
    float hp_offset = 0;
    int current_playerHP = 5;
};
