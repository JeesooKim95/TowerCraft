/**
\file        Map.h
\author      Jeesoo Kim
\brief
This file is the header file Map object.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once

#include <Box2D/Common/b2Math.h>
#include <vector>
#include <engine/Object.h>
#include "Enemy.h"
#include "Tower.h"
#include "Bullet.h"

class Map : public Object
{
public:
    enum GRID_KIND
    {
        NOTHING,
        FIRING,
        UNSELECTED,
        SELECTED,
        ENEMY_PATH,
        CHUL_TOWER_BUTTON,
        CHUL_TOWER_SETTED,
        START_BUTTON,
        START_BUTTON_SETTED,
        END_BUTTON,
        END_BUTTON_SETTED,
        WAY_BUTTON,
        WAY_BUTTON_SETTED,
        TOWER_POSITION_BUTTON,
        TOWER_POSITION_BUTTON_SETTED,
        ATTACK_RANGE,
        START,
        TWICE_SPEED,
        INCOME_INCREMENT,
		EDGE,
		POND1,
		POND2,
		POND3,
		POND4,
		POND5,
		POND6,
		POND7,
		POND8,
		POND9,
		POND10,
		POND11,
        TOWER_UPGRADE_SWORD,
        TOWER_UPGRADE_BOW,
        TOWER_UPGRADE_STICK,
        TOWER_UPGRADE_DOUBLE_SWORD,
        TOWER_UPGRADE_BIG_SWODR,
        TOWER_UPGRADE_UNNAMED_SWORD,
        TOWER_UPGRADE_BIGGER_BOW,
        TOWER_UPGRADE_CROSSBOW,
        TOWER_UPGRADE_UNNAMED_BOW,
        TOWER_UPGRADE_ICE_STICK,
        TOWER_UPGRADE_FIRE_STICK,
        TOWER_UPGRADE_UNNAMED_STICK,
        SWORD_TOWER_SETTED,
        BOW_TOWER_SETTED,
        STICK_TOWER_SETTED,
        DOUBLE_SWORD_TOWER_SETTED,
        BIG_SWORD_TOWER_SETTED,
        UNNAMED_SWORD_TOWER_SETTED,
        BIGGER_BOW_TOWER_SETTED,
        CROSSBOW_TOWER_SETTED,
        UNNAMED_BOW_TOWER_SETTED,
        ICE_STICK_TOWER_SETTED,
        FIRE_STICK_TOWER_SETTED,
        UNNAMED_STICK_TOWER_SETTED,
        INCOME_INCREASE_BUTTON_SETTED,
        TOWER_INITED
    };
    Map() = default;
    ~Map()
    {
        
    }
    void Init_Map();
    void Set_Grid_Vector(std::vector<Object*> grid)
    {
        this->grid_vector = grid;
    }
    void Set_Grid_State_Vector(std::vector<GRID_KIND> grid_state_vec)
    {
        this->grid_state = grid_state_vec;
    }
    std::vector<Object*>& Get_Grid_Vector()
    {
        return grid_vector;
    }
    std::vector<GRID_KIND>& Get_Grid_Kind_Vector()
    {
        return grid_state;
    }
    std::vector<b2Vec2>& Get_Enemy_Path()
    {
        return enemy_path;
    }
    void Set_Enemy_Path(std::vector<b2Vec2> enemy_path_vec)
    {
        enemy_path = enemy_path_vec;
    }
    void Set_enemy_start_pos(b2Vec2 start_pos)
    {
        enemy_start_pos = start_pos;
    }
    void Set_enemy_end_pos(b2Vec2 end_pos)
    {
        enemy_end_pos = end_pos;
    }
    std::vector<b2Vec2>& Get_enemy_path()
    {
        return enemy_path;
    }
    b2Vec2& Get_enemy_start_pos()
    {
        return enemy_start_pos;
    }
    b2Vec2& Get_enemy_end_pos()
    {
        return enemy_end_pos;
    }
    std::vector<Enemy*>& Get_enemy_vec()
    {
        return enemy_vec;
    }
    void set_enemy_vec(std::vector<Enemy*>& enemy_vec_)
    {
        enemy_vec = enemy_vec_;
    }
    float Get_enemy_respawn_timer()
    {
        return enemy_respawn_timer;
    }
    float Get_enemy_move_timer()
    {
        return enemy_move_timer;
    }
    void Set_tower_vec(std::vector<Tower*> tower_vec_)
    {
        tower_vec = tower_vec_;
    }
    std::vector<Tower*>& Get_tower_vec()
    {
        return tower_vec;
    }
    void enemy_limit_increment()
    {
        enemy_limit++;
    }
    int get_enemy_limit()
    {
        return enemy_limit;
    }
    void set_energy_vec(std::vector<Object*> energy_vec_)
    {
        energy_vec = energy_vec_;
    }
    std::vector<Object*>& get_energy_vec()
    {
        return energy_vec;
    }
    void set_bullet_vec(std::vector<Bullet*> bullet_vec_)
    {
        bullet_vec = bullet_vec_;
    }
    int get_tower_damage(Tower* tower)
    {
        return tower->get_attack_damage();
    }
    int get_enemy_hp(Enemy* enemy)
    {
        return enemy->get_initial_hp();
    }
    void set_enemy_path_in_obj(std::vector<Object*> enemy_path_)
    {
        enemy_path_in_obj = enemy_path_;
    }
    std::vector<Object*>& get_enemy_path_in_obj()
    {
        return enemy_path_in_obj;
    }
    b2Vec2 get_mouse_pos()
    {
        return mouse_pos;
    }
    void set_mouse_pos(float mouse_pos_x, float mouse_pos_y)
    {
        mouse_pos.x = mouse_pos_x;
        mouse_pos.y = mouse_pos_y;
    }
    int income = 3;
private:
    int asdf = 10;
    std::vector<Object*> grid_vector;
    std::vector<GRID_KIND> grid_state;
    std::vector<Enemy*> enemy_vec;
    std::vector<b2Vec2> enemy_path;
    std::vector<Object*> enemy_path_in_obj;
    std::vector<Tower*> tower_vec;
    std::vector<Object*> energy_vec;
    std::vector<Bullet*> bullet_vec;
    
    b2Vec2 enemy_start_pos;
    b2Vec2 enemy_end_pos;
    b2Vec2 mouse_pos;

    float enemy_respawn_timer = 1.5f;
    float enemy_move_timer = 2.0f;
    int enemy_limit = 7;
};
