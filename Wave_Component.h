/**
\file        Wave_Component.h
\author      Minseok Sung
\brief
This file is the header file of the Wave_Component.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include <engine/Object.h>
#include "Gold.h"

class WAVE_COMPONENT : public Component
{
public:
	WAVE_COMPONENT();
	~WAVE_COMPONENT();
	virtual void Initialize()       override;
	virtual void Update(float dt)   override;
	void Check_Curr_Wave_State();
	bool Helper_Check_Color_Equal(SDL_Color this_color, SDL_Color compare_color);
	void Helper_Set_Wave_Sprite(Gold& this_wave);
private:
	Gold* wave_first;
	Gold* wave_second;
	Gold* wave_third;
	Object* wave_display;
};