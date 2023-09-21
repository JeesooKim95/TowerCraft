/**
\file        Lightning.h
\author      Minseok Sung
\brief
This file is the header file Lightning object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <engine/Object.h>

class Lightning : public Object
{
public:
    Lightning() = default;
    ~Lightning()
    {

    }
    
    float lightning_timer = 0.3f;
    
private:
};
