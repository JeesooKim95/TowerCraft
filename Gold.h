/**
\file        Gold.h
\author      Minseok Sung
\brief
This file is the header file Gold object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <vector>
#include <engine/Object.h>

class Gold : public Object
{
public:
    enum Coin_State
    {
        GOLD = 30000,
        SILVER = 30001,
        BRONZE = 30002,
        NONE = 30003

    };

    Gold() = default;
    ~Gold()
    {

    }
    Coin_State curr_coin_state = NONE;
    CustomSprite* zero_sprite;
    std::string zero_sprite_path;

    CustomSprite* one_sprite;
    std::string one_sprite_path;

    CustomSprite* two_sprite;
    std::string two_sprite_path;

    CustomSprite* three_sprite;
    std::string three_sprite_path;

    CustomSprite* four_sprite;
    std::string four_sprite_path;

    CustomSprite* five_sprite;
    std::string five_sprite_path;

    CustomSprite* six_sprite;
    std::string six_sprite_path;

    CustomSprite* seven_sprite;
    std::string seven_sprite_path;

    CustomSprite* eight_sprite;
    std::string eight_sprite_path;

    CustomSprite* nine_sprite;
    std::string nine_sprite_path;
    std::vector<CustomSprite*> gold_sprite_vec;
private:
};