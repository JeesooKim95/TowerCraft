#pragma once
#include <Box2D/Common/b2Math.h>
#include <vector>
#include <engine/Object.h>
#include "engine\State.h"
#include "Component.h"
#include <atomic>
#include <string>

class Skill : public Object
{
public:
    enum SWORD_TOWER_SKILL
    {
        DOUBLE_ATTACK = 500,
        CRITICAL_SWORD = 501
    };
    enum BOW_TOWER_SKILL
    {
        MULTI_SHOT = 600,
        COLD_SHOT = 601,
        FIRE_SHOT = 602,
        CRITICAL_BOW = 603
    };

    Skill() = default;
    ~Skill()
    {
    }
private:
};
