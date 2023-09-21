#pragma once
#include "Component.h"
#include <SDL2/SDL_hints.h>
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"
#include "Enemy.h"


class INFORMATION_BOARD_CONTROL : public Component
{
public:
    enum Mouse_Interaction_Board
    {
        Click_Attack_Object = 200,
        Click_Attack_Speed_Object = 201

    };

    INFORMATION_BOARD_CONTROL();
    ~INFORMATION_BOARD_CONTROL();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Helper_Convert_Mouse_Pos();
    void Check_Mouse_Interaction_Board();
    void Check_Mouse_Pos();
    Map* my_map{};
private:
    b2Vec2 mouse_pos;
    Mouse_Interaction_Board current_clicked;
};