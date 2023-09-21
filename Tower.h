/**
\file        Tower.h
\author      Sangmin Kim
\brief
This file is the header file Tower object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include <vector>
#include <engine/Object.h>
#include <string>
#include "Enemy.h"
class Infroamtion_Board;

class Tower : public Object
{
public:
    enum Skill_Kind
    {
        NONE = 900,
        DOUBLE_ATTACK_SWORD = 500,
        CRITICAL_SWORD_SWORD = 501,
        TIMBERSAW = 502,
        MULTI_SHOT_BOW = 600,
        COLD_SHOT_BOW = 601,
        FIRE_SHOT_BOW = 602,
        CRITICAL_BOW = 603
    };
    enum Skill_Kind_Level2
    {
        NONE_2 = 1000,
        CRITICAL_SWORD_2 = 1002,
        TIMERSAW_2 = 1003,
        DOUBLE_MULTI_SHOT = 1004,
        COLD_SHOT_BOW_2 = 1005,
        CRITICAL_BOW_2 = 1006
    };
    enum Skill_Kind_Level3
    {
        NONE_3 = 1100,
        CRITICAL_3 = 1101,
        TIMBERSAW_3 = 1102,
        TRIPLE_MULTI_SHOT = 1103,
        COLD_MULTI_SHOT = 1104
    };
    enum STATEMENT
    {
        NONONO = 1999,
        ATTACK_SPEED_BUFF = 2000,
        WHEEL_WIND = 2001,
        BOW_BIG_PREPARING = 2002,
        BOW_BIG_PREPARED = 2003,
    };
    enum Skills
    {
        NONO = 999,
        SWORD_DOUBLE_ATTACK1 = 1000,
        SWORD_POWER_SLASH1 = 1001,
        SWORD_DOUBLE_ATTACK2 = 1002,
        SWORD_POWER_SLASH2 = 1003,
        SWORD_FEVER_TIME = 1004,
        SWORD_POWER_SLASH3 = 1005,
        BOW_BIG_ARROW = 1006,
        BOW_BIG_ARROW_MULTI = 1007,
        BOW_VERY_BIG_ARROW_MULTI = 1008,
        CROSS_BOW_CRITICAL = 1009,
        CROSS_BOW_CRITICAL_WITH_STUN = 1010,
        CROSS_BOW_DEATH = 1011,
        ICE_BOLT = 1012,
        ICE_BOLT2 = 1013,
        ICE_BOLT3 = 1014,
        FIRE_BOLT = 1015,
        FIRE_BOLT2 = 1016,
        FIRE_BOLT3 = 1017,
        LIGHTNING_BOLT = 1018,
        LIGHTNING_BOLT2 = 1019,
        LIGHTNING_BOLT3 = 1020
    };
    enum Tower_Kind
    {
        nothing = 99,
        basic_tower = 100,
        sword_tower = 101,
        bow_tower = 102,
        stick_tower = 103,
        steel_sword_tower = 104,
        steel_bow_tower = 105,
        emerald_sword_tower = 106,
        emerald_bow_tower = 107,
        upgrade_this = 130,
        sword_double_tower = 141,
        sword_big_tower = 142,
        sword_unnamed_tower = 143,
        bow_big_tower = 144,
        bow_crossbow_tower = 145,
        bow_unnamed_tower = 146,
        stick_ice_tower = 147,
        stick_fire_tower = 148,
        stick_unnamed_tower = 149,
        sell = 150
    };
    enum Attack_Type
    {
        BASIC_ATTACK = 300,
        SWORD_ATTACK = 301,
        BOW_ATTACK = 302,
        STICK_ATTACK = 303,
        SWORD_DOUBLE_ATTACK = 304,
        SWORD_BIG_ATTACK = 305,
        SWORD_UNNAMED_ATTACK = 306,
        BOW_BIGGER_ATTACK = 307,
        BOW_CROSSBOW_ATTACK = 308,
        BOW_UNNAMED_ATTACK = 309,
        STICK_ICE_ATTACK = 310,
        STICK_FIRE_ATTACK = 311,
        STICK_UNNAMED_ATTACK = 312,
        SWORD_DOUBLE2 = 313,
        SWORD_DOUBLE3 = 314,
        SWORD_BIG2 = 315,
        SWORD_BIG3 = 316,
        BOW_BIG2 = 317,
        BOW_BIG3 = 318,
        CROSS_BOW2 = 319,
        CROSS_BOW3 = 320,
        ICE_STICK2 = 321,
        ICE_STICK3 = 322,
        FIRE_STICK2 = 323,
        FIRE_STICK3 = 324,
        LIGHTNING_STICK2 = 325,
        LIGHTNING_STICK3 = 326
    };

    Tower() = default;
    ~Tower()
    {

    }
    void Set_Attack_Type(Attack_Type attacking)
    {
        attack_type = attacking;
    }
    float& get_attack_timer()
    {
        return attack_timer;
    }
    void set_attack_timer(float timer)
    {
        attack_timer = timer;
    }
    Attack_Type Get_Attack_Type()
    {
        return attack_type;
    }
    std::vector<Object*>& get_attack_range()
    {
        return attack_range;
    }
    std::vector<Object*>& get_tower_upgrade_info()
    {
        return upgrade_info;
    }
    int get_attack_damage()
    {
        return attack_damage;
    }
    void  set_attack_damage(int damage_)
    {
        attack_damage = damage_;
    }
    std::string get_tower_sprite_path()
    {
        return tower_sprite_path;
    }
    void set_tower_sprite_path(std::string file_path)
    {
        tower_sprite_path = file_path;
    }
    void set_prev_attack_timer(float attack_timer_)
    {
        prev_attack_timer = attack_timer_;
    }
    float get_prev_attack_timer()
    {
        return prev_attack_timer;
    }
    void set_upgrade_amount(int amount)
    {
        upgrade_amount = amount;
    }
    void set_tower_upgrade_state(std::vector<Object*> upgrade_vec)
    {
        upgrade_info = upgrade_vec;
    }
    void level_increment()
    {
        level++;
    }
    int get_level()
    {
        return level;
    }
    bool get_attack_timer_incre_once()
    {
        return attack_timer_incre_once;
    }
    void set_attack_timer_incre_once(bool toggle)
    {
        attack_timer_incre_once = toggle;
    }
    void set_skill(Skill_Kind skill_)
    {
        skill = skill_;
    }
    Skill_Kind get_skill()
    {
        return skill;
    }
    void set_skill_2(Skill_Kind_Level2 _skill_2)
    {
        skill_2 = _skill_2;
    }
    Skill_Kind_Level2 get_skill_2()
    {
        return skill_2;
    }
    void set_skill_3(Skill_Kind_Level3 _skill_3)
    {
        skill_3 = _skill_3;
    }
    Skill_Kind_Level3 get_skill_3()
    {
        return skill_3;
    }
    void set_tower_skill(Skills add_this_skill)
    {
        tower_skill = add_this_skill;
    }
    Skills get_tower_skill()
    {
        return tower_skill;
    }
    void set_skill_mana(int mana_)
    {
        skill_mana = mana_;
    }
    int get_skill_mana()
    {
        return skill_mana;
    }
    void set_current_mana(int mana)
    {
        current_mana = mana;
    }
    int get_current_mana()
    {
        return current_mana;
    }
    void current_mana_incre()
    {
        current_mana++;
    }
    void tower_level_plus()
    {
        level_of_tower++;
    }
    int get_tower_level_()
    {
        return level_of_tower;
    }
    void set_informaiton_board(Infroamtion_Board* infor)
    {
        information_board = infor;
    }
    Infroamtion_Board* &get_information_board()
    {
        return information_board;
    }
    void set_buff_timer(float buf_timer)
    {
        buff_timer = buf_timer;
    }
    float& get_buff_timer()
    {
        return buff_timer;
    }
    STATEMENT get_tower_statement()
    {
        return tower_curr_statement;
    }
    void set_tower_statement(STATEMENT setting_statement)
    {
        tower_curr_statement = setting_statement;
    }
    void set_temp_attack_timer(float timer__)
    {
        temp_attack_timer = timer__;
    }
    float get_temp_attack_timer()
    {
        return temp_attack_timer;
    }
    int get_in_grid_pos()
    {
        return which_grid;
    }
    void set_in_grid_pos(int which__)
    {
        which_grid = which__;
    }
    void attack_stack_increment()
    {
        attack_stack++;
    }
    int get_attack_stack()
    {
        return attack_stack;
    }
    void set_attack_zero()
    {
        attack_stack = 0;
    }
    void set_current_rotation(float currRotation)
    {
        curr_rotation = currRotation;
    }
    float get_current_rotation()
    {
        return curr_rotation;
    }
    CustomSprite* skill_preparing_sprite;
    std::string skill_preparing_sprite_path;
    CustomSprite* skill_using_sprite;
    std::string skill_using_sprite_path;
    CustomSprite* default_sprite;
    std::string default_sprite_path;
    int selling_price = 0;
    CustomSprite* default_sprite_idle;
    std::string default_sprite_idle_path;
    int default_frame;
    float default_sprite_speed;
    int default_skill_frame;
    float default_skill_sprite_speed;
    bool is_using_skill = false;
    Enemy* target;
    bool is_last;

private:

    std::vector<Object*> attack_range;
    float attack_timer = 1.0f;
    int level = 1;
    float prev_attack_timer = attack_timer;
    float temp_attack_timer;
    float buff_timer;
    Attack_Type attack_type;
    int attack_damage = 2;
    std::string tower_sprite_path;
    std::vector<Object*> upgrade_info;
    int upgrade_amount;
    bool attack_timer_incre_once = true;
    Skill_Kind skill = NONE;
    Skill_Kind_Level2 skill_2 = NONE_2;
    Skill_Kind_Level3 skill_3 = NONE_3;
    Skills tower_skill = NONO;
    Infroamtion_Board* information_board;
    int skill_mana = 5;
    int current_mana = 0;
    int level_of_tower = 1;
    STATEMENT tower_curr_statement;
    int which_grid;
    int attack_stack = 0;
    float curr_rotation;
};
