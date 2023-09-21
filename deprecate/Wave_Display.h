/**
\file        Wave_Display.h
\author      Minseok Sung
\brief
This file is the header file of the Wave_Display.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once

#include "Component.h"
#include <engine/Object.h>

class WAVE_DISPLAY_COMPONENT : public Component
{
public:

    WAVE_DISPLAY_COMPONENT();
    ~WAVE_DISPLAY_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
private:
    Object* wave_status;
};