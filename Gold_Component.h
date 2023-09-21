/**
\file        Gold_Component.h
\author      Jeesoo Kim
\brief
This is the header file of the Gold_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include "Gold.h"

class GOLD_COMPONENT : public Component
{
public:

    GOLD_COMPONENT();
    ~GOLD_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Check_Curr_Coin_State();
    bool Helper_Check_Color_Equal(SDL_Color this_color, SDL_Color compare_color);
    void Helper_Set_Coin_Sprite(Gold& this_gold);
private:
    Gold* gold_first;
    Gold* gold_second;
    Gold* gold_third;
	Object* gold_display;
};