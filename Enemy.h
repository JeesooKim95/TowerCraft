/**
\file        Enemy.h
\author      Minseok Sung
\brief
This file is the header file Enemy object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <Box2D/Common/b2Math.h>
#include <vector>
#include <engine/Object.h>
#include <iostream>

class Enemy : public Object
{
public:
    enum ENEMY_CURRENT_STATE
    {
        NONE = 999,
        SLOW = 1000,
        STUN = 1001
    };
    Enemy() = default;
    ~Enemy()
    {

    }
    int priority;
    int now_in = 0;
    int move_to = 0;
    bool is_reach_end = false;
    bool is_check_end = false;
    int inVectorPosition = 0;
    int hp_saving = 0;
    float saving_hp_bar_scale = 120.f;
    int& get_hp()
    {
        return hp;
    }
    void enemy_hp_increment()
    {
        hp++;
    }
    int get_initial_hp()
    {
        return initial_hp;
    }
    void hitted(int damage)
    {
        hp -= damage;
    }
    void set_hp(int hp_)
    {
        hp = hp_;
    }
    float get_speed()
    {
        return speed_enemy;
    }
    void set_enemy_speed(float speed_)
    {
        speed_enemy = speed_;
    }
    void set_enemy_current_state(ENEMY_CURRENT_STATE state_)
    {
        enemy_current = state_;
    }
    ENEMY_CURRENT_STATE get_enemy_current_state()
    {
        return enemy_current;
    }
    float& get_debuf_timer()
    {
        return debuf_timer;
    }
    void set_debuf_timer(float time_)
    {
        debuf_timer = time_;
    }
    void set_prev_speed(float speed_)
    {
        speed_save = speed_;
    }
    float get_prev_speed()
    {
        return speed_save;
    }
    void set_energy_bar(Object* energy)
    {
        energy_bar = energy;
    }
    Object* &get_energy_bar()
    {
        return energy_bar;
    }
    void set_x_energy_bar_scale(float hit)
    {
        energy_bar_scale -= hit;
    }
    float get_x_energy_bar_scale()
    {
        return energy_bar_scale;
    }
    void set_current_grid(Object* grid__)
    {
        current_grid = grid__;
    }
    Object* get_current_grid()
    {
        return current_grid;
    }
    float& get_enemy_recover_timer()
    {
        return enemy_recover_timer;
    }
    void set_enemy_recover_timer(float timer)
    {
        enemy_recover_timer = timer;
    }
    std::string default_enemy;
    std::string hitted_enemy;
    CustomSprite* default_sprite_enemy;
    CustomSprite* hitted_sprite_enemy;

private:
    std::vector<b2Vec2> enemy_path;
    std::vector<Object*> enemy_path_in_obj;
    Object* current_grid;
    float hitted_timer = 0.0f;
    int speed = 3;
    int hp = 5;
    const int initial_hp = get_hp();
    Object* energy_bar;
    float energy_bar_scale = 120.f;
    float speed_enemy = 64;
    ENEMY_CURRENT_STATE enemy_current = NONE;
    float debuf_timer;
    float speed_save = speed_enemy;
    float enemy_recover_timer = 3.0f;

};
