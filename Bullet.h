/**
\file        Bullet.h
\author      Minseok Sung
\brief
This file is the header file Bullet object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <Box2D/Common/b2Math.h>
#include <engine/Object.h>

class Bullet : public Object
{
public:
    Bullet() = default;
    ~Bullet()
    {

    }

    b2Vec3 direction_vector;
    b2Vec2 target_position;
    Object* target;
    float bullet_timer = 0.05f;
    bool go_end;
    bool is_ice;
    float speed = 5.0f;
private:
};
