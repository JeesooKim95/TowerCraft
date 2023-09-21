/**
\file        Tower_Attack_Component.h
\author      Sangmin Kim
\brief
This file is header file of the Tower_Attack_Component.cpp

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "Component.h"
#include <engine/State.h>
#include <engine/Object.h>
#include "Map.h"
#include "Lightning.h"
#include "Income.h"


class TOWER_ATTACK_COMPONENT : public Component
{
public:
    TOWER_ATTACK_COMPONENT();
    ~TOWER_ATTACK_COMPONENT();
    virtual void Initialize()       override;
    virtual void Update(float dt)   override;
    void Helper_Get();
    void Helper_Set();
    void Attack(Enemy* this_enemy, int damage, int erase_where, float dt, Tower &tower, Object* grid_pos);
    void Check_Fire();
    void Check_Is_Enemy_In(float dt);
    void Init_Bullet(Tower &tower);
    void Move_Bullet(float dt);
    void Decrease_Energy(Enemy* get_enemy, Tower* tower, int damage_ = 0);
    void Generate_Arrow(Tower* this_tower, Enemy* this_enemy, float size_x = 50.f, float size_y = 50.f, bool go_end = false, bool is_ice = false, bool is_skill = false);
    void Generate_Lightning(Enemy* this_enemy, int erase_where);
    void Generate_Lightning2(Enemy* this_enemy, int erase_where);
	void Income_setting(Enemy* this_enemy);
	void Income_Fading(float dt);
    void Fade_Lightning(float dt);
    void Color_Fading_Effect(SDL_Color& color);
    bool Target_Is_In_Range(Enemy* this_enemy, Tower* this_tower);
	Enemy* Find_Nearest_Enemy(Enemy* this_enemy, int *erase_where_second);
	Enemy* Make_Lightning(Enemy* this_enemy, int *erase_where_second);
private:
    Income* income;
    std::vector<Income*> income_vector;
    std::vector<Object*> grid_vector;
    std::vector<Map::GRID_KIND> grid_state;
    std::vector<Enemy*> enemy_vec;
    std::vector<b2Vec2> enemy_path;
    std::vector<Tower*> tower_vec;
    std::vector<Object*> tower_grid_temp_save;
    std::vector<Bullet*> bullet_vec;
    std::vector<Lightning*> lightning_vec;
    std::vector<Object*> energy_vec;
    Object* effect;
    std::vector<int> temp_save_fire;
    std::vector<float> temp_save_fire_timer;
    float fire_timer = 3.0f;
    Bullet* bullet;
    Tower* temp_tower;
    Map* my_map;
    float temp_attack_speed;
    SDL_Color fade_color = { 0,0,0,1 };
    SoundEffect sound1;
    SoundEffect sound2;
    SoundEffect sound3;
    SoundEffect sound4;
    SoundEffect sound5;
    SoundEffect sound6;
    SoundEffect sound7;
    SoundEffect sound8;
    SoundEffect sound9;
    SoundEffect sound10;
    SoundEffect sound11;
};