/**
\file        Display_Clicked_Obj.h
\author      Minseok Sung
\brief
This file is the header file Display_Clicked_Obj.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/

#pragma once
#include "Component.h"
#include "Tower.h"
#include "Information_Board.h"

class DISPLAY_CLICKED_OBJ : public Component
{
public:
    DISPLAY_CLICKED_OBJ();
    ~DISPLAY_CLICKED_OBJ();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Display_Information();
    void Set_Information();
    void Update_Information_Board();
    void Set_Board_Visible_Invisible(Tower* tower, bool toggle);
private:
    bool is_initialied = false;
    Infroamtion_Board* information;
    Tower* prev_clicked_tower;
    bool done = false;
};