/**
\file        Level1.h
\author      Chulseung Lee
\brief
This file is the header file of the Level.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "engine\State.h"
#include "engine\Object.h"
#include "Map.h"
#include "Information_Board.h"

extern Object* please_add_this;
extern Object* please_add_this_tower;
extern Object* please_add_this_enemy;
extern Object* please_add_this_bullet;
extern Object* please_add_this_enemy_hp;
extern Object* please_remove_this_enemy_hp;
extern Object* please_remove_this_bullet_obj;
extern Object* please_remove_this_enemy_obj;
extern Object* please_add_this_tower_information;
extern Object* tower_grid;
extern Object* please_remove_this_tower_information;
extern Object* please_remove_this_tower_attack;
extern Object* please_add_this_tower_attack;
extern Object* please_add_this_tower_sprite;
extern Object* please_remove_this_tower_sprite;
extern Object* please_add_this_tower_attack_speed;
extern Object* please_remove_this_tower_attack_speed;
extern Object* please_add_this_tower_sprite;
extern Object* gold_sprite;
extern Object* wave_sprite;
extern Object* please_add_this_tower_skill;
extern Object* please_remove_this_player_hp_obj;
extern Object* please_remove_this_tower_skill;
extern std::vector<Object*> please_add_this_player_hp_vec;
extern std::vector<Object*> add_tower_upgrade_vec;
extern std::vector<Object*> remove_tower_upgrade_vec;
extern std::vector<Object*> gold_vec;
extern std::vector<Object*> wave_vec;
extern bool please_add_this_gold_vec;
extern bool please_add_this_wave_vec;
extern bool twice_speed_is_on;
extern bool please_remove_this;
extern bool please_remove_this_enemy;
extern bool game_start;
extern bool please_add_this_enemy_once;
extern bool please_add_this_tower_once;
extern bool please_add_this_bullet_once;
extern bool please_add_this_enemy_hp_once;
extern bool please_add_this_tower_information_once;
extern bool please_remove_this_tower_information_once;
extern bool please_add_this_tower_attack_once;
extern bool please_remove_this_tower_attack_once;
extern bool please_add_this_tower_attack_speed_once;
extern bool please_remove_this_tower_attack_speed_once;
extern bool please_add_this_tower_skill_once;
extern bool please_remove_this_tower_skill_once;
extern bool please_add_this_tower_sprite_once;
extern bool please_remove_this_tower_sprite_once;
extern bool gold_sprite_once;
extern bool game_initial_finish;
extern bool add_this_upgrade_vec_once;
extern bool please_remove_this_bullet;
extern bool please_remove_this_player_hp;
extern bool wave_sprite_once;
extern bool please_add_this_player_hp_once;
extern int real_increment;
extern int enemy_count;
extern int width;
extern int height;
extern int enemy_hp;
extern int Set_Count;
extern int gold;
extern int wave;
extern int player_hp;
extern int towerCheck;
extern _TTF_Font* asd;
extern Tower* tower_clicked;
extern Tower* tower_clicked_to_upgrade;
extern Infroamtion_Board* current_inforamtion_board;
extern Tower::Tower_Kind upgrade_state;

class Level1 : public State
{
    friend class Game;

protected:
    Level1() : State() {};
    ~Level1() override {};

    void Initialize() override;
    void Update(float dt) override;
    void Close() override;
    void Tutorial();
	void GameOver(float dt);

private:
    Map* level1_map = new Map;
    b2Vec2 mouse_position;
    Object level1Map;
    Object tutorial;
    Object tutorialClickSound;
    Object loseLifeSound;
	Object gameOver;
    int isTutorial = 0;
};