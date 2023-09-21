#pragma once

#include "Component.h"
#include <SDL2/SDL_hints.h>
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"
#include "Enemy.h"


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