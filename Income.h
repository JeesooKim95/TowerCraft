/**
\file        Income.h
\author      Sangmin Kim
\brief
This file is the header file Income object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <engine/Object.h>
#include "Component.h"

class Income : public Object
{
public:
    Income() = default;
    ~Income()
    {

    }
    std::string income_string;
    CustomSprite* income_sprite;
    Object* income;
    float timer = 1.f;
private:

};