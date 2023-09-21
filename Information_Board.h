/**
\file        Information_Board.h
\author      Jeesoo Kim
\brief
This file is the header file Information_Board object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <engine/Object.h>

class Infroamtion_Board : public Object
{
public:
    Infroamtion_Board() = default;
    ~Infroamtion_Board()
    {

    }
    int tower_attack_damage;
    Tower::Skill_Kind skill_kind;
    Tower::Skill_Kind_Level2 skill_kind_2;
    Tower::Skill_Kind_Level3 skill_kind_3;
    Object* tower_sprite;
};
