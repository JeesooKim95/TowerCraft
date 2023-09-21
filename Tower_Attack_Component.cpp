/**
\file        Tower_Attack_Component.cpp
\author      Sangmin Kim
\brief
This file will treating all of the tower attack component - skill, attack motion...

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Tower_Attack_Component.h"
#include "Mouse_Control_Component.h"
#include <iostream>
#include "CustomSprite.h"


TOWER_ATTACK_COMPONENT::TOWER_ATTACK_COMPONENT() : Component(eComponentTypes::TOWER_ATTACK_COMPONENT)
{
}
TOWER_ATTACK_COMPONENT::~TOWER_ATTACK_COMPONENT()
{

}
void TOWER_ATTACK_COMPONENT::Income_setting(Enemy* this_enemy)
{
	(this_enemy);
	
    income = new Income;
    income->income_sprite = new CustomSprite;
    switch(real_increment)
    {
    case 1:
        income->income_string = "texture/Others/income/income_one.png";
        break;

    case 2:
        income->income_string = "texture/Others/income/income_two.png";
        break;

    case 3:
        income->income_string = "texture/Others/income/income_three.png";
        break;

    case 4:
        income->income_string = "texture/Others/income/income_four.png";
        break;

    case 5:
        income->income_string = "texture/Others/income/income_five.png";
        break;

    case 6:
        income->income_string = "texture/Others/income/income_six.png";
        break;

    case 7:
        income->income_string = "texture/Others/income/income_seven.png";
        break;

    case 8:
        income->income_string = "texture/Others/income/income_eight.png";
        break;

    case 9:
        income->income_string = "texture/Others/income/income_nine.png";
        break;

    case 10:
        income->income_string = "texture/Others/income/income_ten.png";
        break;

    }
    income->income_sprite->Initialize(State::m_renderer, income->income_string);
    income->transform.position.Set(this_enemy->transform.position.x - 20, this_enemy->transform.position.y - 20, 0);
    income->transform.SetScale(200, 200);
    income->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
    income->sprite = std::move(*income->income_sprite);
    income_vector.push_back(income);
    State::sCurrentState->AddDynamicObject(income);
}
void TOWER_ATTACK_COMPONENT::Helper_Get()
{
    grid_state = my_map->Get_Grid_Kind_Vector();
    grid_vector = my_map->Get_Grid_Vector();
    tower_vec = my_map->Get_tower_vec();
    enemy_vec = my_map->Get_enemy_vec();
    energy_vec = my_map->get_energy_vec();
}
void TOWER_ATTACK_COMPONENT::Helper_Set()
{
    my_map->Set_Grid_State_Vector(grid_state);
    my_map->set_enemy_vec(enemy_vec);
    my_map->set_energy_vec(energy_vec);
}

void Effect_Helper(Enemy* this_enemy)
{
    int enemyCurrentFrame = 0;

    enemyCurrentFrame = this_enemy->sprite.GetCurrentFrame();
    this_enemy->sprite.Free();
    this_enemy->sprite.LoadImage("texture/Enemy/EnemyMushroomHitted.png", State::m_renderer);
    this_enemy->sprite.SetFrame(12);
    this_enemy->sprite.SetSpeed(14.1f);
    this_enemy->sprite.SetCurrentFrame(false, enemyCurrentFrame);

}
void TOWER_ATTACK_COMPONENT::Attack(Enemy* this_enemy, int damage, int erase_where, float dt, Tower &tower, Object* grid_pos)
{
    (dt);

    Helper_Get();



    if (tower.get_current_mana() > tower.get_skill_mana())
    {
        if (tower.get_tower_skill() == Tower::SWORD_DOUBLE_ATTACK1)
        {
            Decrease_Energy(this_enemy, &tower);
            this_enemy->hitted(tower.get_attack_damage());
            Decrease_Energy(this_enemy, &tower);
            this_enemy->hitted(tower.get_attack_damage());
            tower.set_current_mana(0);
        }
        else if (tower.get_tower_skill() == Tower::SWORD_DOUBLE_ATTACK2)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                this_enemy->set_debuf_timer(1.5f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                this_enemy->set_enemy_recover_timer(1.5f);
                this_enemy->sprite = std::move(*this_enemy->hitted_sprite_enemy);
                this_enemy->sprite.SetFrame(12);
                this_enemy->sprite.SetSpeed(12.f);
                this_enemy->sprite.activeAnimation = true;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.5f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(5);
                tower.sprite.SetSpeed(30.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(150, 150);
                sound3.SetVolume(128);
                sound3.Play();
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                this_enemy->hitted(200);
                Decrease_Energy(this_enemy, nullptr, 200);
                this_enemy->hitted(tower.get_attack_damage());
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::SWORD_FEVER_TIME)
        {
            tower.set_tower_statement(Tower::ATTACK_SPEED_BUFF);
            tower.set_buff_timer(3.0f);
            tower.set_temp_attack_timer(tower.get_prev_attack_timer());
            tower.set_prev_attack_timer(0.05f);
            tower.set_current_mana(0);
            tower.transform.SetScale(200, 200);
            tower.sprite = std::move(*tower.skill_using_sprite);
            tower.default_frame = 4;
            tower.default_sprite_speed = 80.f;
            tower.sprite.activeAnimation = true;
        }
        else if (tower.get_tower_skill() == Tower::SWORD_POWER_SLASH1)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.6f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(7);
                tower.sprite.SetSpeed(14.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(200, 200);

                this_enemy->set_debuf_timer(0.3f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                this_enemy->set_enemy_recover_timer(1.3f);
                this_enemy->sprite = std::move(*this_enemy->hitted_sprite_enemy);
                this_enemy->sprite.SetFrame(12);
                this_enemy->sprite.SetSpeed(12.f);
                this_enemy->sprite.activeAnimation = true;
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                Decrease_Energy(this_enemy, &tower);
                this_enemy->hitted(tower.get_attack_damage());
                this_enemy->set_debuf_timer(1.f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::SWORD_POWER_SLASH2)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.0f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(6);
                tower.sprite.SetSpeed(8.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(400, 400);
                sound1.SetVolume(128);
                sound1.Play();
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                float normalize_left;
                float normalize_right;
                float normalize_up;
                float normalize_down;
                int pos;
                pos = grid_pos->GetId() - grid_vector[0]->GetId();
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        for (auto& z : enemy_vec)
                        {
                            if (z != nullptr)
                            {
                                normalize_left = grid_vector[(i * width) + j + pos]->transform.position.x - (grid_vector[(i * width) + j + pos]->transform.GetScale().x / 2);
                                normalize_right = grid_vector[(i * width) + j + pos]->transform.position.x + (grid_vector[(i * width) + j + pos]->transform.GetScale().x / 2);
                                normalize_up = grid_vector[(i * width) + j + pos]->transform.position.y + (grid_vector[(i * width) + j + pos]->transform.GetScale().y / 2);
                                normalize_down = grid_vector[(i * width) + j + pos]->transform.position.y - (grid_vector[(i * width) + j + pos]->transform.GetScale().y / 2);

                                if (z->transform.position.x > normalize_left && z->transform.position.x < normalize_right &&
                                    z->transform.position.y > normalize_down && z->transform.position.y < normalize_up)
                                {
                                    Decrease_Energy(z, &tower);
                                    z->hitted(tower.get_attack_damage());
                                    z->set_debuf_timer(1.f);
                                    z->set_enemy_current_state(Enemy::STUN);
                                }
                            }
                        }
                    }
                }
                tower.set_tower_statement(Tower::NONONO);
                tower.set_current_mana(0);
            }
        }
        else if (tower.get_tower_skill() == Tower::SWORD_POWER_SLASH3)
        {
            float normalize_left;
            float normalize_right;
            float normalize_up;
            float normalize_down;
            if (!tower.is_using_skill)
            {
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.set_buff_timer(3.f);
                tower.sprite.SetFrame(8);
                tower.sprite.SetSpeed(20.f);
                tower.transform.SetScale(200, 200);
                tower.sprite.activeAnimation = true;
                tower.set_tower_statement(Tower::WHEEL_WIND);
                tower.is_using_skill = true;
                sound2.SetVolume(128);
                sound2.Play();
            }
            if (tower.get_tower_statement() == Tower::WHEEL_WIND)
            {
                for (auto& i : tower.get_attack_range())
                {
                    normalize_left = i->transform.position.x - (i->transform.GetScale().x / 2);
                    normalize_right = i->transform.position.x + (i->transform.GetScale().x / 2);
                    normalize_up = i->transform.position.y + (i->transform.GetScale().y / 2);
                    normalize_down = i->transform.position.y - (i->transform.GetScale().y / 2);
                    for (auto& j : enemy_vec)
                    {
                        if (j != nullptr)
                        {
                            if (j->transform.position.x > normalize_left && j->transform.position.x < normalize_right &&
                                j->transform.position.y > normalize_down &&j->transform.position.y < normalize_up)
                            {
                                j->hitted(50);
                                Decrease_Energy(j, &tower, 50);
                            }
                        }
                    }
                }
            }
        }
        else if (tower.get_tower_skill() == Tower::BOW_BIG_ARROW)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.target = this_enemy;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.3f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(7);
                tower.sprite.SetSpeed(7.3f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(200, 200);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                Generate_Arrow(&tower, this_enemy, 100, 100, true, false, true);
                this_enemy->hitted(tower.get_attack_damage());
                Decrease_Energy(this_enemy, &tower);
                this_enemy->hitted(tower.get_attack_damage());
                Decrease_Energy(this_enemy, &tower);
                tower.set_tower_statement(Tower::NONONO);
                tower.set_current_mana(0);
            }
        }
        else if (tower.get_tower_skill() == Tower::BOW_BIG_ARROW_MULTI)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.target = this_enemy;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.3f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(7);
                tower.sprite.SetSpeed(7.3f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(150, 150);
                sound4.Play();
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                float normalize_left;
                float normalize_right;
                float normalize_up;
                float normalize_down;
                for (auto &i : tower.get_attack_range())
                {
                    normalize_left = i->transform.position.x - (i->transform.GetScale().x / 2);
                    normalize_right = i->transform.position.x + (i->transform.GetScale().x / 2);
                    normalize_up = i->transform.position.y + (i->transform.GetScale().y / 2);
                    normalize_down = i->transform.position.y - (i->transform.GetScale().y / 2);
                    for (auto& j : enemy_vec)
                    {
                        if (j != nullptr)
                        {
                            if (j->transform.position.x > normalize_left && j->transform.position.x < normalize_right &&
                                j->transform.position.y > normalize_down &&j->transform.position.y < normalize_up)
                            {
                                Decrease_Energy(j, &tower);
                                Generate_Arrow(&tower, j, 100, 100, true, false, true);
                                j->hitted(damage);
                            }
                        }
                    }
                }
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::BOW_VERY_BIG_ARROW_MULTI)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.target = this_enemy;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.3f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(3);
                tower.sprite.SetSpeed(9.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(200, 200);
                sound5.Play();
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                float normalize_left;
                float normalize_right;
                float normalize_up;
                float normalize_down;
                for (auto& i : tower.get_attack_range())
                {
                    normalize_left = i->transform.position.x - (i->transform.GetScale().x / 2);
                    normalize_right = i->transform.position.x + (i->transform.GetScale().x / 2);
                    normalize_up = i->transform.position.y + (i->transform.GetScale().y / 2);
                    normalize_down = i->transform.position.y - (i->transform.GetScale().y / 2);
                    for (auto& j : enemy_vec)
                    {
                        if (j != nullptr)
                        {
                            if (j->transform.position.x > normalize_left && j->transform.position.x < normalize_right &&
                                j->transform.position.y > normalize_down &&j->transform.position.y < normalize_up)
                            {
                                Generate_Arrow(&tower, j, 100, 100, true, false, true);
                                j->hitted(damage);
                            }
                        }
                    }
                }
                tower.set_tower_statement(Tower::NONONO);
                tower.set_current_mana(0);
            }
        }
        else if (tower.get_tower_skill() == Tower::CROSS_BOW_CRITICAL)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.target = this_enemy;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(7);
                tower.sprite.SetSpeed(7.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(200, 200);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                this_enemy->hitted(tower.get_attack_damage());
                Decrease_Energy(this_enemy, &tower, tower.get_attack_damage());
                Generate_Arrow(&tower, this_enemy, 100, 100, true, false, true);
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::CROSS_BOW_CRITICAL_WITH_STUN)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                sound6.Play();
                tower.target = this_enemy;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(7);
                tower.sprite.SetSpeed(7.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(200, 200);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                this_enemy->set_debuf_timer(3.0f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                this_enemy->hitted(tower.get_attack_damage());
                Decrease_Energy(this_enemy, &tower, tower.get_attack_damage());
                Generate_Arrow(&tower, this_enemy, 100, 100, true, false, true);
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::CROSS_BOW_DEATH)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                sound7.Play();
                tower.target = this_enemy;
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(1.f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(7);
                tower.sprite.SetSpeed(7.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(200, 200);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                this_enemy->set_hp(-1);
                Generate_Arrow(&tower, this_enemy, 100, 100, true, false, true);
                this_enemy->hitted(tower.get_attack_damage() * 5);
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::ICE_BOLT)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.7f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(4);
                tower.sprite.SetSpeed(6.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(250, 250);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                Generate_Arrow(&tower, this_enemy);
                this_enemy->set_debuf_timer(2.0f);
                this_enemy->set_enemy_current_state(Enemy::SLOW);
                this_enemy->hitted(tower.get_attack_damage());
                Decrease_Energy(this_enemy, &tower);
                this_enemy->sprite.color = { 0,0,255,255 };
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::ICE_BOLT2)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                sound10.SetVolume(128);
                sound10.Play();
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.7f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(4);
                tower.sprite.SetSpeed(6.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(250, 250);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                float normalize_left;
                float normalize_right;
                float normalize_up;
                float normalize_down;
                int pos;
                pos = grid_pos->GetId() - grid_vector[0]->GetId();
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        for (auto &z : enemy_vec)
                        {
                            if (z != nullptr)
                            {
                                normalize_left = grid_vector[(i * width) + j + pos]->transform.position.x - (grid_vector[(i * width) + j + pos]->transform.GetScale().x / 2);
                                normalize_right = grid_vector[(i * width) + j + pos]->transform.position.x + (grid_vector[(i * width) + j + pos]->transform.GetScale().x / 2);
                                normalize_up = grid_vector[(i * width) + j + pos]->transform.position.y + (grid_vector[(i * width) + j + pos]->transform.GetScale().y / 2);
                                normalize_down = grid_vector[(i * width) + j + pos]->transform.position.y - (grid_vector[(i * width) + j + pos]->transform.GetScale().y / 2);

                                if (z->transform.position.x > normalize_left && z->transform.position.x < normalize_right &&
                                    z->transform.position.y > normalize_down && z->transform.position.y < normalize_up)
                                {
                                    z->hitted(tower.get_attack_damage());
                                    Decrease_Energy(z, &tower);
                                    z->set_debuf_timer(1.f);
                                    z->set_enemy_current_state(Enemy::SLOW);
                                    z->sprite.color = { 0,0,255,255 };
                                }
                            }
                        }
                    }
                }
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::ICE_BOLT3)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                sound11.SetVolume(128);
                sound11.Play();
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.7f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(4);
                tower.sprite.SetSpeed(6.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(250, 250);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                Generate_Arrow(&tower, this_enemy, 100, 100, true, true);
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }

        }
        else if (tower.get_tower_skill() == Tower::FIRE_BOLT)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.7f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(4);
                tower.sprite.SetSpeed(6.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(250, 250);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                this_enemy->sprite = std::move(*this_enemy->hitted_sprite_enemy);
                this_enemy->sprite.SetFrame(12);
                this_enemy->sprite.SetSpeed(12.f);
                this_enemy->sprite.activeAnimation = true;
                this_enemy->set_debuf_timer(1.f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                this_enemy->hitted(100);
                this_enemy->set_enemy_recover_timer(1.f);
                Decrease_Energy(this_enemy, nullptr, 60);
                int erase_where_second;
                Enemy* to_this_enemy = Make_Lightning(this_enemy, &erase_where_second);
                if (to_this_enemy != nullptr)
                {
                    to_this_enemy->sprite = std::move(*to_this_enemy->hitted_sprite_enemy);
                    to_this_enemy->sprite.SetFrame(12);
                    to_this_enemy->sprite.SetSpeed(12.f);
                    to_this_enemy->sprite.activeAnimation = true;
                    to_this_enemy->set_debuf_timer(1.f);
                    to_this_enemy->set_enemy_current_state(Enemy::STUN);
                    to_this_enemy->hitted(50);
                    to_this_enemy->set_enemy_recover_timer(1.f);
                    Decrease_Energy(to_this_enemy, nullptr, 50);
                    if (to_this_enemy->get_hp() <= 0)
                    {
                        Income_setting(to_this_enemy);
                        gold += real_increment;
                        enemy_vec[erase_where_second]->isDead = true;
                        energy_vec[erase_where_second]->isDead = true;
                        delete enemy_vec[erase_where_second]->default_sprite_enemy;
                        delete enemy_vec[erase_where_second]->hitted_sprite_enemy;
                        enemy_vec[erase_where_second] = nullptr;
                        energy_vec[erase_where_second] = nullptr;
                        enemy_count++;
                        my_map->set_enemy_vec(enemy_vec);
                        my_map->set_energy_vec(energy_vec);
                    }
                }
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::FIRE_BOLT2)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                sound8.SetVolume(128);
                sound8.Play();
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.7f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(4);
                tower.sprite.SetSpeed(6.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(250, 250);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                this_enemy->sprite = std::move(*this_enemy->hitted_sprite_enemy);
                this_enemy->sprite.SetFrame(12);
                this_enemy->sprite.SetSpeed(12.f);
                this_enemy->sprite.activeAnimation = true;
                this_enemy->set_debuf_timer(1.f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                this_enemy->hitted(70);
                this_enemy->set_enemy_recover_timer(1.f);
                Decrease_Energy(this_enemy, nullptr, 70);
                int erase_where_second;
                int erase_where_third;
                Enemy* to_this_enemy = Make_Lightning(this_enemy, &erase_where_second);
                if (to_this_enemy != nullptr)
                {
                    to_this_enemy->sprite = std::move(*to_this_enemy->hitted_sprite_enemy);
                    to_this_enemy->sprite.SetFrame(12);
                    to_this_enemy->sprite.SetSpeed(12.f);
                    to_this_enemy->set_debuf_timer(1.f);
                    to_this_enemy->set_enemy_current_state(Enemy::STUN);
                    to_this_enemy->hitted(70);
                    to_this_enemy->set_enemy_recover_timer(1.f);
                    to_this_enemy->sprite.activeAnimation = true;
                    Decrease_Energy(to_this_enemy, nullptr, 70);
                    if (to_this_enemy->get_hp() <= 0)
                    {
                        

                        Income_setting(to_this_enemy);

                        gold += real_increment;
                        enemy_vec[erase_where_second]->isDead = true;
                        energy_vec[erase_where_second]->isDead = true;
                        delete enemy_vec[erase_where_second]->default_sprite_enemy;
                        delete enemy_vec[erase_where_second]->hitted_sprite_enemy;
                        enemy_vec[erase_where_second] = nullptr;
                        energy_vec[erase_where_second] = nullptr;
                        enemy_count++;
                        my_map->set_enemy_vec(enemy_vec);
                        my_map->set_energy_vec(energy_vec);
                    }
                    Enemy* to_this_enemy2 = Make_Lightning(to_this_enemy, &erase_where_third);
                    if (to_this_enemy2 != nullptr)
                    {
                        to_this_enemy2->sprite = std::move(*to_this_enemy2->hitted_sprite_enemy);
                        to_this_enemy2->sprite.SetFrame(12);
                        to_this_enemy2->sprite.SetSpeed(12.f);
                        to_this_enemy2->set_debuf_timer(1.f);
                        to_this_enemy2->set_enemy_current_state(Enemy::STUN);
                        to_this_enemy2->hitted(70);
                        to_this_enemy2->set_enemy_recover_timer(1.f);
                        to_this_enemy2->sprite.activeAnimation = true;
                        Decrease_Energy(to_this_enemy2, nullptr, 70);
                        if (to_this_enemy2->get_hp() <= 0)
                        {
                            

                            Income_setting(to_this_enemy2);
                            gold += real_increment;
                            enemy_vec[erase_where_third]->isDead = true;
                            energy_vec[erase_where_third]->isDead = true;
                            delete enemy_vec[erase_where_third]->default_sprite_enemy;
                            delete enemy_vec[erase_where_third]->hitted_sprite_enemy;
                            enemy_vec[erase_where_third] = nullptr;
                            energy_vec[erase_where_third] = nullptr;
                            enemy_count++;
                            my_map->set_enemy_vec(enemy_vec);
                            my_map->set_energy_vec(energy_vec);
                        }
                    }
                }
                tower.set_current_mana(0);
                tower.set_tower_statement(Tower::NONONO);
            }
        }
        else if (tower.get_tower_skill() == Tower::FIRE_BOLT3)
        {
            if (tower.get_tower_statement() == Tower::NONONO)
            {
                sound9.SetVolume(128);
                sound9.Play();
                tower.set_tower_statement(Tower::BOW_BIG_PREPARING);
                tower.set_buff_timer(0.7f);
                tower.sprite = std::move(*tower.skill_using_sprite);
                tower.sprite.SetFrame(4);
                tower.sprite.SetSpeed(6.f);
                tower.sprite.activeAnimation = true;
                tower.transform.SetScale(250, 250);
            }
            if (tower.get_tower_statement() == Tower::BOW_BIG_PREPARED)
            {
                tower.set_prev_attack_timer(0.5f);
                tower.default_frame = 3;
                tower.default_sprite_speed = 15.f;
                int erase_where_second;
                int erase_where_third;
                int erase_where_fourth;
                this_enemy->sprite = std::move(*this_enemy->hitted_sprite_enemy);
                this_enemy->sprite.SetFrame(12);
                this_enemy->sprite.SetSpeed(12.f);
                this_enemy->sprite.activeAnimation = true;
                this_enemy->set_debuf_timer(1.f);
                this_enemy->set_enemy_current_state(Enemy::STUN);
                this_enemy->hitted(70);
                this_enemy->set_enemy_recover_timer(1.f);
                Decrease_Energy(this_enemy, nullptr, 70);
                Enemy* to_this_enemy = Make_Lightning(this_enemy, &erase_where_second);
                if (to_this_enemy != nullptr)
                {
                    to_this_enemy->sprite = std::move(*to_this_enemy->hitted_sprite_enemy);
                    to_this_enemy->sprite.SetFrame(12);
                    to_this_enemy->sprite.SetSpeed(12.f);
                    to_this_enemy->set_debuf_timer(1.f);
                    to_this_enemy->set_enemy_current_state(Enemy::STUN);
                    to_this_enemy->hitted(70);
                    Decrease_Energy(to_this_enemy, nullptr, 70);
                    to_this_enemy->sprite.activeAnimation = true;
                    to_this_enemy->set_enemy_recover_timer(1.f);
                    if (to_this_enemy->get_hp() <= 0)
                    {

                        Income_setting(to_this_enemy);
                        gold += real_increment;
                        enemy_vec[erase_where_second]->isDead = true;
                        energy_vec[erase_where_second]->isDead = true;
                        delete enemy_vec[erase_where_second]->default_sprite_enemy;
                        delete enemy_vec[erase_where_second]->hitted_sprite_enemy;
                        enemy_vec[erase_where_second] = nullptr;
                        energy_vec[erase_where_second] = nullptr;
                        enemy_count++;
                        my_map->set_enemy_vec(enemy_vec);
                        my_map->set_energy_vec(energy_vec);
                    }
                    Enemy* to_this_enemy2 = Make_Lightning(to_this_enemy, &erase_where_third);
                    if (to_this_enemy2 != nullptr)
                    {
                        to_this_enemy2->sprite = std::move(*to_this_enemy2->hitted_sprite_enemy);
                        to_this_enemy2->sprite.SetFrame(12);
                        to_this_enemy2->sprite.SetSpeed(12.f);
                        to_this_enemy2->set_enemy_recover_timer(1.f);
                        to_this_enemy2->set_debuf_timer(1.f);
                        to_this_enemy2->set_enemy_current_state(Enemy::STUN);
                        to_this_enemy2->hitted(70);
                        to_this_enemy2->sprite.activeAnimation = true;
                        Decrease_Energy(to_this_enemy2, nullptr, 70);
                        if (to_this_enemy2->get_hp() <= 0)
                        {
                            
                            Income_setting(to_this_enemy2);
                            gold += real_increment;
                            enemy_vec[erase_where_third]->isDead = true;
                            energy_vec[erase_where_third]->isDead = true;
                            delete enemy_vec[erase_where_third]->default_sprite_enemy;
                            delete enemy_vec[erase_where_third]->hitted_sprite_enemy;
                            enemy_vec[erase_where_third] = nullptr;
                            energy_vec[erase_where_third] = nullptr;
                            enemy_count++;
                            my_map->set_enemy_vec(enemy_vec);
                            my_map->set_energy_vec(energy_vec);
                        }

                        Enemy* to_this_enemy3 = Make_Lightning(to_this_enemy2, &erase_where_fourth);
                        if (to_this_enemy3 != nullptr)
                        {
                            to_this_enemy3->sprite = std::move(*to_this_enemy3->hitted_sprite_enemy);
                            to_this_enemy3->sprite.SetFrame(12);
                            to_this_enemy3->sprite.SetSpeed(12.f);
                            to_this_enemy3->set_debuf_timer(1.f);
                            to_this_enemy3->set_enemy_current_state(Enemy::STUN);
                            to_this_enemy3->hitted(70);
                            to_this_enemy3->set_enemy_recover_timer(1.f);
                            to_this_enemy3->sprite.activeAnimation = true;
                            Decrease_Energy(to_this_enemy3, nullptr, 70);
                            if (to_this_enemy3->get_hp() <= 0)
                            {
                                Income_setting(to_this_enemy3);

                                gold += real_increment;
                                enemy_vec[erase_where_fourth]->isDead = true;
                                energy_vec[erase_where_fourth]->isDead = true;
                                delete enemy_vec[erase_where_fourth]->default_sprite_enemy;
                                delete enemy_vec[erase_where_fourth]->hitted_sprite_enemy;
                                enemy_vec[erase_where_fourth] = nullptr;
                                energy_vec[erase_where_fourth] = nullptr;
                                enemy_count++;
                                my_map->set_enemy_vec(enemy_vec);
                                my_map->set_energy_vec(energy_vec);
                            }
                        }
                    }
                }
                this_enemy->hitted(70);
                Decrease_Energy(this_enemy, nullptr, 70);
                tower.attack_stack_increment();

                if (tower.get_attack_stack() >= 10)
                {
                    tower.default_frame = 3;
                    tower.default_sprite_speed = 6.f;
                    tower.set_prev_attack_timer(1.0f);
                    tower.set_current_mana(0);
                    tower.set_attack_zero();
                    tower.set_tower_statement(Tower::NONONO);
                }
            }
        }
    }
    else
    {
        tower.sprite = std::move(*tower.default_sprite);
        int tower_frame = tower.default_frame;
        float tower_frame_speed = tower.default_sprite_speed;
        tower.sprite.SetFrame(tower_frame);
        tower.sprite.SetSpeed(tower_frame_speed);
        tower.sprite.activeAnimation = true;
        if (tower.get_tower_statement() != Tower::ATTACK_SPEED_BUFF)
        {
            tower.current_mana_incre();
        }
        if (tower.Get_Attack_Type() == Tower::BOW_ATTACK || tower.Get_Attack_Type() == Tower::BOW_BIGGER_ATTACK ||
            tower.Get_Attack_Type() == Tower::BOW_CROSSBOW_ATTACK || tower.Get_Attack_Type() == Tower::BOW_BIG2 ||
            tower.Get_Attack_Type() == Tower::BOW_BIG3 || tower.Get_Attack_Type() == Tower::BOW_CROSSBOW_ATTACK ||
            tower.Get_Attack_Type() == Tower::CROSS_BOW2)
        {
            Generate_Arrow(&tower, this_enemy);
        }
        else if (tower.Get_Attack_Type() == Tower::CROSS_BOW3)
        {
            this_enemy->set_debuf_timer(0.3f);
            this_enemy->set_enemy_current_state(Enemy::STUN);
            Generate_Arrow(&tower, this_enemy);

        }

        float angle = atan2(this_enemy->transform.position.y - tower.transform.position.y, this_enemy->transform.position.x - tower.transform.position.x);
        angle *= 180.f;
        angle /= 3.141592f;
        tower.transform.rotation = angle + 90.f;
        tower.set_current_rotation(tower.transform.rotation);
        tower.sprite.stopAnimation = false;
        this_enemy->hitted(damage);

        int enemyCurrentFrame = 0;
        enemyCurrentFrame = this_enemy->sprite.GetCurrentFrame();
        this_enemy->sprite = std::move(*this_enemy->hitted_sprite_enemy);
        this_enemy->sprite.activeAnimation = true;
        this_enemy->sprite.SetFrame(12);
        this_enemy->sprite.SetSpeed(24.f);
        this_enemy->set_enemy_recover_timer(0.7f);
        Decrease_Energy(this_enemy, &tower);
    }
    if (this_enemy->get_hp() <= 0)
    {

        Income_setting(this_enemy);
        gold += real_increment;
        if (enemy_vec[erase_where] != nullptr && energy_vec[erase_where] != nullptr)
        {
            enemy_vec[erase_where]->isDead = true;
            energy_vec[erase_where]->isDead = true;

            delete enemy_vec[erase_where]->default_sprite_enemy;
            delete enemy_vec[erase_where]->hitted_sprite_enemy;
            enemy_vec[erase_where] = nullptr;
            energy_vec[erase_where] = nullptr;
            enemy_count++;
        }

        my_map->set_enemy_vec(enemy_vec);
        my_map->set_energy_vec(energy_vec);

        please_remove_this_bullet = false;
    }
    Helper_Set();
}

Enemy* TOWER_ATTACK_COMPONENT::Find_Nearest_Enemy(Enemy* this_enemy, int *erase_where_second)
{
    (this_enemy);
    enemy_vec = my_map->Get_enemy_vec();
    int a = 0;
    if (!enemy_vec.empty())
    {
        for (auto& i : enemy_vec)
        {
            if (i == nullptr)
            {
                a++;
                continue;
            }
            if (i != this_enemy && i != nullptr)
            {
                *erase_where_second = a;
                return i;
            }
            a++;
        }
    }
    return nullptr;
}
Enemy* TOWER_ATTACK_COMPONENT::Make_Lightning(Enemy* this_enemy, int *erase_where_second)
{
    Enemy* to_this_enemy = Find_Nearest_Enemy(this_enemy, erase_where_second);
    if (to_this_enemy != nullptr)
    {
        Lightning* new_lightning = new Lightning;
        b2Vec2 mid_pos;
        b2Vec2 scale;

        mid_pos.x = (this_enemy->transform.position.x + to_this_enemy->transform.position.x) / 2;
        mid_pos.y = (this_enemy->transform.position.y + to_this_enemy->transform.position.y) / 2;
        scale.x = (this_enemy->transform.position.x - to_this_enemy->transform.position.x);
        scale.x *= scale.x;
        scale.y = (this_enemy->transform.position.y - to_this_enemy->transform.position.y);
        scale.y *= scale.y;
        scale.x = sqrt(scale.x);
        scale.y = sqrt(scale.y);

        float angle;
        angle = atan2(this_enemy->transform.position.y - to_this_enemy->transform.position.y, this_enemy->transform.position.x - to_this_enemy->transform.position.x) * 180.f / 3.141592f;
        new_lightning->transform.position.Set(mid_pos.x, mid_pos.y, 0);
        new_lightning->transform.rotation = angle + 90.f;
        new_lightning->transform.SetScale(scale.x + 100, scale.y + 100);
        new_lightning->sprite.LoadImage("texture/Effects/HitEffectLightning2.png", State::m_renderer);
        new_lightning->sprite.activeAnimation = true;
        new_lightning->sprite.SetFrame(4);
        new_lightning->sprite.SetSpeed(36.f);
        State::sCurrentState->AddDynamicObject(new_lightning);
        lightning_vec.push_back(new_lightning);
        return to_this_enemy;
    }
    return nullptr;
}
void TOWER_ATTACK_COMPONENT::Generate_Lightning2(Enemy* this_enemy, int erase_where)
{
    (erase_where);
    (this_enemy);
    Helper_Get();
    Helper_Set();
}
void TOWER_ATTACK_COMPONENT::Generate_Lightning(Enemy* this_enemy, int erase_where)
{
    (this_enemy);
    (erase_where);
    Enemy* to_this_enemy = nullptr;

    if (to_this_enemy != nullptr)
    {
        Lightning* new_lightning = new Lightning;
        b2Vec2 mid_pos;
        b2Vec2 scale;

        mid_pos.x = (this_enemy->transform.position.x + to_this_enemy->transform.position.x) / 2;
        mid_pos.y = (this_enemy->transform.position.y + to_this_enemy->transform.position.y) / 2;
        scale.x = (this_enemy->transform.position.x - to_this_enemy->transform.position.x);
        scale.x *= scale.x;
        scale.y = (this_enemy->transform.position.y - to_this_enemy->transform.position.y);
        scale.y *= scale.y;
        scale.x = sqrt(scale.x);
        scale.y = sqrt(scale.y);

        float angle;
        angle = atan2(this_enemy->transform.position.y - to_this_enemy->transform.position.y, this_enemy->transform.position.x - to_this_enemy->transform.position.x);
        angle *= 180.f;
        angle /= 3.141592f;
        new_lightning->transform.position.Set(mid_pos.x, mid_pos.y, 0);
        new_lightning->transform.rotation = angle + 90.f;
        new_lightning->transform.SetScale(scale.x, 50);
        new_lightning->transform.rotation = angle;
        new_lightning->sprite.LoadImage("texture/Effects/HitEffectLightning.png", State::m_renderer);
        new_lightning->sprite.isVisible = true;
        new_lightning->isDead = false;
        State::sCurrentState->AddDynamicObject(new_lightning);
        to_this_enemy->hitted(10);
        Decrease_Energy(to_this_enemy, tower_clicked, 10);
        lightning_vec.push_back(new_lightning);
    }
}
void TOWER_ATTACK_COMPONENT::Color_Fading_Effect(SDL_Color& color)
{
    color.a -= 2;
}

void TOWER_ATTACK_COMPONENT::Fade_Lightning(float dt)
{
    (dt);
    if (!lightning_vec.empty())
    {
        for (auto& i : lightning_vec)
        {
            if (i != nullptr)
            {
                i->lightning_timer -= dt;
                Color_Fading_Effect(i->sprite.color);
                if (i->lightning_timer < 0)
                {
                    i->isDead = true;
                    i = nullptr;
                }
            }
        }
    }
}
void TOWER_ATTACK_COMPONENT::Initialize()
{
    my_map = (Map*)GetOwner();
    sound1.LoadSound("sound/BigSwordLevel2Skill.mp3");
    sound2.LoadSound("sound/BigSwordLevel3Skill.mp3");
    sound3.LoadSound("sound/DoubleSwordLevel2Skill.mp3");
    sound4.LoadSound("sound/BowLevel2Skill.mp3");
    sound5.LoadSound("sound/BowLevel3Skill.mp3");
    sound6.LoadSound("sound/CrossBowLevel2Skill.mp3");
    sound7.LoadSound("sound/CrossBowLevel3Skill.mp3");
    sound8.LoadSound("sound/StaffLevel2Skill.mp3");
    sound9.LoadSound("sound/StaffLevel3Skill.mp3");
    sound10.LoadSound("sound/WandLevel2Skill.mp3");
    sound11.LoadSound("sound/WandLevel3Skill.mp3");
}
void TOWER_ATTACK_COMPONENT::Init_Bullet(Tower & tower)
{
    bullet = new Bullet;
    bullet->SetName("bullet");
    bullet->transform.position.Set(tower.transform.position.x, tower.transform.position.y, 0.0f);
    bullet->transform.SetScale(120, 120);
    bullet->sprite.Free();
    bullet->sprite.LoadImage("texture/Bullets/Bullet.png", State::m_renderer);
    bullet->sprite.isHud = true;
    please_add_this_bullet = bullet;
    please_add_this_bullet_once = true;
    bullet_vec.push_back(bullet);
}
void TOWER_ATTACK_COMPONENT::Move_Bullet(float dt)
{
    Helper_Get();
    const float pixels_per_second = 4.5f;
    float newDt = dt * pixels_per_second;

    float normalize_val_left;
    float normalize_val_right;
    float normalize_val_up;
    float normalize_val_down;

    float normalize_val_left_enemy;
    float normalize_val_right_enemy;
    float normalize_val_up_enemy;
    float normalize_val_down_enemy;

    int a = 0;
    int b = 0;
    int c = 0;

    if (!bullet_vec.empty())
    {
        for (auto& i : bullet_vec)
        {
            if (i != nullptr)
            {
                i->transform.position.x += (newDt * i->direction_vector.x);
                i->transform.position.y += (newDt * i->direction_vector.y);

                if (i->target != nullptr)
                {
                    normalize_val_left = i->target->transform.position.x - (i->target->transform.GetScale().x / 2);
                    normalize_val_right = i->target->transform.position.x + (i->target->transform.GetScale().x / 2);
                    normalize_val_down = i->target->transform.position.y - (i->target->transform.GetScale().y / 2);
                    normalize_val_up = i->target->transform.position.y + (i->target->transform.GetScale().y / 2);
                    if (i->go_end && !i->is_ice)
                    {
                        b = 0;
                        for (auto& j : enemy_vec)
                        {
                            if (j == nullptr)
                            {
                                b++;
                                continue;
                            }
                            if (j != nullptr)
                            {
                                normalize_val_left_enemy = j->transform.position.x - (j->transform.GetScale().x / 2);
                                normalize_val_right_enemy = j->transform.position.x + (j->transform.GetScale().x / 2);
                                normalize_val_up_enemy = j->transform.position.y + (j->transform.GetScale().y / 2);
                                normalize_val_down_enemy = j->transform.position.y - (j->transform.GetScale().y / 2);;

                                if (i->transform.position.x > normalize_val_left_enemy && i->transform.position.x < normalize_val_right_enemy &&
                                    i->transform.position.y > normalize_val_down_enemy && i->transform.position.y < normalize_val_up_enemy)
                                {
                                    j->hitted(5);
                                    Decrease_Energy(j, tower_clicked, 5);

                                    if (j->get_hp() < 0)
                                    {
                                        enemy_count++;
                                        energy_vec[b]->isDead = true;
                                        energy_vec[b] = nullptr;
                                        enemy_vec[b]->isDead = true;
                                        enemy_vec[b] = nullptr;
                                    }
                                }
                            }
                            b++;
                        }

                    }
                    else if (i->go_end && i->is_ice)
                    {
                        c = 0;
                        for (auto& j : enemy_vec)
                        {
                            if (j == nullptr)
                            {
                                c++;
                                continue;
                            }
                            if (j != nullptr)
                            {
                                normalize_val_left_enemy = j->transform.position.x - (j->transform.GetScale().x / 2);
                                normalize_val_right_enemy = j->transform.position.x + (j->transform.GetScale().x / 2);
                                normalize_val_up_enemy = j->transform.position.y + (j->transform.GetScale().y / 2);
                                normalize_val_down_enemy = j->transform.position.y - (j->transform.GetScale().y / 2);;

                                if (i->transform.position.x > normalize_val_left_enemy && i->transform.position.x < normalize_val_right_enemy &&
                                    i->transform.position.y > normalize_val_down_enemy && i->transform.position.y < normalize_val_up_enemy)
                                {
                                    j->hitted(5);
                                    Decrease_Energy(j, tower_clicked, 5);
                                    j->set_debuf_timer(3.0f);
                                    j->set_enemy_current_state(Enemy::SLOW);
                                    j->sprite.color = { 0,0,255,255 };
                                    if (j->get_hp() < 0)
                                    {
                                        enemy_count++;
                                        energy_vec[c]->isDead = true;
                                        energy_vec[c] = nullptr;
                                        enemy_vec[c]->isDead = true;
                                        enemy_vec[c] = nullptr;
                                    }
                                }
                            }
                            c++;
                        }

                    }

                    if (i->transform.position.x > normalize_val_left && i->transform.position.x < normalize_val_right &&
                        i->transform.position.y > normalize_val_down && i->transform.position.y < normalize_val_up && !i->go_end)
                    {
                        bullet_vec[a]->isDead = true;
                        bullet_vec[a] = nullptr;
                        bullet_vec.erase(bullet_vec.begin() + a);
                        a--;
                    }
                    else if ((i->transform.position.x < -State::m_width / 2 || i->transform.position.x > State::m_width / 2 ||
                        i->transform.position.y > State::m_height / 2 || i->transform.position.y < -State::m_height / 2) && i->go_end)
                    {
                        bullet_vec[a]->isDead = true;
                        bullet_vec[a] = nullptr;
                        bullet_vec.erase(bullet_vec.begin() + a);
                        a--;
                    }
                }
                a++;


            }
        }
    }
    my_map->set_enemy_vec(enemy_vec);
    my_map->set_energy_vec(energy_vec);

}
void TOWER_ATTACK_COMPONENT::Generate_Arrow(Tower* this_tower, Enemy* this_enemy, float size_x, float size_y, bool go_end, bool is_ice, bool is_skill)
{
    float angle;
    angle = atan2(this_tower->transform.position.y - this_enemy->transform.position.y, this_tower->transform.position.x - this_enemy->transform.position.x);
    angle *= 180.f;
    angle /= 3.141592f;
    angle += 90.f;
    Bullet* new_bullet;
    new_bullet = new Bullet;
    new_bullet->SetName("bullet");
    new_bullet->transform.position.x = this_tower->transform.position.x;
    new_bullet->transform.position.y = this_tower->transform.position.y;
    new_bullet->transform.rotation = angle;
    new_bullet->transform.SetScale(size_x, size_y);
    new_bullet->sprite.Free();
    if (is_ice)
    {
        new_bullet->transform.SetScale(200, 200);

        new_bullet->sprite.LoadImage("texture/Effects/iceskilleffect.png", State::m_renderer);
        new_bullet->sprite.SetFrame(3);
        new_bullet->sprite.SetSpeed(3.f);
        new_bullet->sprite.activeAnimation = true;
    }
    else if (this_tower->Get_Attack_Type() == Tower::BOW_ATTACK)
    {
        new_bullet->transform.SetScale(200, 200);

        new_bullet->sprite.LoadImage("texture/Bullets/Bullet.png", State::m_renderer);
    }
    else if (this_tower->Get_Attack_Type() == Tower::BOW_BIGGER_ATTACK && !is_skill)
    {
        new_bullet->transform.SetScale(200, 200);

        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/BowLevel1Arrow.png", State::m_renderer);
    }
	else if (this_tower->Get_Attack_Type() == Tower::BOW_BIGGER_ATTACK && is_skill)
	{
		new_bullet->transform.SetScale(200, 200);
		angle += 180;
		new_bullet->transform.rotation = angle;
		new_bullet->sprite.LoadImage("texture/Bullets/level1bowskill.png", State::m_renderer);
		new_bullet->sprite.SetFrame(3);
		new_bullet->sprite.SetSpeed(12.f);
		new_bullet->sprite.activeAnimation = true;
	}
    else if (this_tower->Get_Attack_Type() == Tower::BOW_BIG2 && !is_skill)
    {
        new_bullet->transform.SetScale(200, 200);
        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/BowLevel2Arrow.png", State::m_renderer);
    }
	else if (this_tower->Get_Attack_Type() == Tower::BOW_BIG2 && is_skill)
	{
		new_bullet->transform.SetScale(200, 200);
		angle += 180;
		new_bullet->transform.rotation = angle;
		new_bullet->sprite.LoadImage("texture/Bullets/level2bowskill.png", State::m_renderer);
		new_bullet->sprite.SetFrame(3);
		new_bullet->sprite.SetSpeed(12.f);
		new_bullet->sprite.activeAnimation = true;
	}
    else if (this_tower->Get_Attack_Type() == Tower::BOW_BIG3 && !is_skill)
    {
        new_bullet->transform.SetScale(200, 200);
        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/BowLefel3Arrow.png", State::m_renderer);
    }
    else if (this_tower->Get_Attack_Type() == Tower::BOW_BIG3 && is_skill)
    {
        new_bullet->transform.SetScale(200, 200);
        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/level3bowskillarrow.png", State::m_renderer);
        new_bullet->sprite.SetFrame(3);
        new_bullet->sprite.SetSpeed(12.f);
        new_bullet->sprite.activeAnimation = true;
    }
    else if (this_tower->Get_Attack_Type() == Tower::BOW_CROSSBOW_ATTACK&& !is_skill)
    {
        new_bullet->transform.SetScale(200, 200);
        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/CrossBowLevel1.png", State::m_renderer);
    }
	else if (this_tower->Get_Attack_Type() == Tower::BOW_CROSSBOW_ATTACK && is_skill)
	{
		new_bullet->transform.SetScale(200, 200);
		angle += 180;
		new_bullet->transform.rotation = angle;
		new_bullet->sprite.LoadImage("texture/Bullets/level1crossbowskillarrow.png", State::m_renderer);
		new_bullet->sprite.SetFrame(3);
		new_bullet->sprite.SetSpeed(12.f);
		new_bullet->sprite.activeAnimation = true;
	}
    else if (this_tower->Get_Attack_Type() == Tower::CROSS_BOW2 && !is_skill)
    {
        new_bullet->transform.SetScale(200, 200);
        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/CrossBowLevel2.png", State::m_renderer);
    }
	else if (this_tower->Get_Attack_Type() == Tower::CROSS_BOW2 && is_skill)
	{
		new_bullet->transform.SetScale(200, 200);
		angle += 180;
		new_bullet->transform.rotation = angle;
		new_bullet->sprite.LoadImage("texture/Bullets/level2crossbowskill.png", State::m_renderer);
		new_bullet->sprite.SetFrame(1);
	}
    else if (this_tower->Get_Attack_Type() == Tower::CROSS_BOW3 && !is_skill)
    {
        new_bullet->transform.SetScale(200, 200);
        angle += 180;
        new_bullet->transform.rotation = angle;
        new_bullet->sprite.LoadImage("texture/Bullets/CrossBowLevel3Arrow.png", State::m_renderer);
    }
	else if (this_tower->Get_Attack_Type() == Tower::CROSS_BOW3 && is_skill)
	{
		new_bullet->transform.SetScale(200, 200);
		angle += 180;
		new_bullet->transform.rotation = angle;
		new_bullet->sprite.LoadImage("texture/Bullets/level3crossbowskill.png", State::m_renderer);
		new_bullet->sprite.SetFrame(3);
		new_bullet->sprite.SetSpeed(12.f);
		new_bullet->sprite.activeAnimation = true;
	}

    new_bullet->target_position.x = this_enemy->transform.position.x;
    new_bullet->target_position.y = this_enemy->transform.position.y;
    new_bullet->direction_vector.x = this_enemy->transform.position.x - this_tower->transform.position.x;
    new_bullet->direction_vector.y = this_enemy->transform.position.y - this_tower->transform.position.y;
    new_bullet->target = this_enemy;
    new_bullet->go_end = go_end;
    new_bullet->is_ice = is_ice;
    bullet_vec.push_back(new_bullet);
    if (is_ice)
    {

        Bullet* new_bullet2;
        new_bullet2 = new Bullet;
        new_bullet2->SetName("bullet");
        new_bullet2->transform.position.x = this_tower->transform.position.x;
        new_bullet2->transform.position.y = this_tower->transform.position.y;
        new_bullet2->transform.rotation = angle;
        new_bullet2->transform.SetScale(200, 200);
        new_bullet2->sprite.Free();

        new_bullet2->sprite.LoadImage("texture/Effects/iceskilleffect.png", State::m_renderer);
        new_bullet2->sprite.SetFrame(3);
        new_bullet2->sprite.SetSpeed(3.f);
        new_bullet2->sprite.activeAnimation = true;

        new_bullet2->target_position.x = this_enemy->transform.position.x;
        new_bullet2->target_position.y = this_enemy->transform.position.y;
        new_bullet2->direction_vector.x = this_enemy->transform.position.x - this_tower->transform.position.x - 20;
        new_bullet2->direction_vector.y = this_enemy->transform.position.y - this_tower->transform.position.y - 20;
        new_bullet2->target = this_enemy;
        new_bullet2->go_end = go_end;
        new_bullet2->is_ice = is_ice;
        bullet_vec.push_back(new_bullet2);
        Bullet* new_bullet3;
        new_bullet3 = new Bullet;
        new_bullet3->SetName("bullet");
        new_bullet3->transform.position.x = this_tower->transform.position.x;
        new_bullet3->transform.position.y = this_tower->transform.position.y;
        new_bullet3->transform.rotation = angle;
        new_bullet3->transform.SetScale(200, 200);
        new_bullet3->sprite.Free();

        new_bullet3->sprite.LoadImage("texture/Effects/iceskilleffect.png", State::m_renderer);
        new_bullet3->sprite.SetFrame(3);
        new_bullet3->sprite.SetSpeed(3.f);
        new_bullet3->sprite.activeAnimation = true;

        new_bullet3->target_position.x = this_enemy->transform.position.x;
        new_bullet3->target_position.y = this_enemy->transform.position.y;
        new_bullet3->direction_vector.x = this_enemy->transform.position.x - this_tower->transform.position.x + 20;
        new_bullet3->direction_vector.y = this_enemy->transform.position.y - this_tower->transform.position.y + 20;
        new_bullet3->target = this_enemy;
        new_bullet3->go_end = go_end;
        new_bullet3->is_ice = is_ice;
        bullet_vec.push_back(new_bullet3);
        State::sCurrentState->AddDynamicObject(new_bullet2);
        State::sCurrentState->AddDynamicObject(new_bullet3);
    }
    State::sCurrentState->AddDynamicObject(new_bullet);

}
void TOWER_ATTACK_COMPONENT::Decrease_Energy(Enemy* get_enemy, Tower* tower, int damage_)
{
    if (get_enemy->get_energy_bar() != nullptr)
    {
        if (damage_ == 0)
        {

            float result_hp_scale_decrement = 120.f / get_enemy->hp_saving;
            result_hp_scale_decrement *= tower->get_attack_damage();
            const float result_hp_scale = get_enemy->saving_hp_bar_scale - result_hp_scale_decrement;
            get_enemy->saving_hp_bar_scale = result_hp_scale;
            const float prev_hp_x = get_enemy->get_energy_bar()->transform.position.x;
            const float prev_hp_y = get_enemy->get_energy_bar()->transform.position.y;
            get_enemy->get_energy_bar()->transform.SetScale(result_hp_scale, 80.f);
            get_enemy->get_energy_bar()->transform.position.Set(prev_hp_x - result_hp_scale_decrement, prev_hp_y, 0.f);
        }
        else
        {
            float result_hp_scale_decrement = 120.f / get_enemy->hp_saving;
            result_hp_scale_decrement *= damage_;
            const float result_hp_scale = get_enemy->saving_hp_bar_scale - result_hp_scale_decrement;
            get_enemy->saving_hp_bar_scale = result_hp_scale;
            const float prev_hp_x = get_enemy->get_energy_bar()->transform.position.x;
            const float prev_hp_y = get_enemy->get_energy_bar()->transform.position.y;
            get_enemy->get_energy_bar()->transform.SetScale(result_hp_scale, 80.f);
            get_enemy->get_energy_bar()->transform.position.Set(prev_hp_x - result_hp_scale_decrement, prev_hp_y, 0.f);

        }
    }
}
bool TOWER_ATTACK_COMPONENT::Target_Is_In_Range(Enemy* this_enemy, Tower* this_tower)
{
    if (this_tower != nullptr && this_enemy != nullptr)
    {
        const float enemy_pos_normalize_left = this_enemy->transform.position.x - (this_enemy->transform.GetScale().x / 6);
        const float enemy_pos_normalize_right = this_enemy->transform.position.x + (this_enemy->transform.GetScale().x / 6);
        const float enemy_pos_normalize_up = this_enemy->transform.position.y + (this_enemy->transform.GetScale().y / 6);
        const float enemy_pos_normalize_down = this_enemy->transform.position.y - (this_enemy->transform.GetScale().y / 6);

        for (auto &i : this_tower->get_attack_range())
        {
            const float tower_attack_pos_normalize_down = i->transform.position.y - (i->transform.GetScale().y / 2);
            const float tower_attack_pos_normalize_up = i->transform.position.y + (i->transform.GetScale().y / 2);
            const float tower_attack_pos_normalize_right = i->transform.position.x + (i->transform.GetScale().x / 2);
            const float tower_attack_pos_normalize_left = i->transform.position.x - (i->transform.GetScale().x / 2);
            if (this_enemy->transform.position.y > tower_attack_pos_normalize_down &&
                this_enemy->transform.position.y < tower_attack_pos_normalize_up)
            {
                if (enemy_pos_normalize_right > tower_attack_pos_normalize_left &&
                    enemy_pos_normalize_right < tower_attack_pos_normalize_right)
                {
                    return true;
                }
                else if (enemy_pos_normalize_left > tower_attack_pos_normalize_left &&
                    enemy_pos_normalize_left < tower_attack_pos_normalize_right)
                {
                    return true;
                }
            }
            else if (this_enemy->transform.position.x < tower_attack_pos_normalize_right &&
                this_enemy->transform.position.x > tower_attack_pos_normalize_left)
            {
                if (enemy_pos_normalize_up > tower_attack_pos_normalize_down &&
                    enemy_pos_normalize_up < tower_attack_pos_normalize_up)
                {
                    return true;
                }
                else if (enemy_pos_normalize_down > tower_attack_pos_normalize_down &&
                    enemy_pos_normalize_down < tower_attack_pos_normalize_up)
                {
                    return true;
                }
            }

        }

    }
    return false;
}
void TOWER_ATTACK_COMPONENT::Check_Is_Enemy_In(float dt)
{
    Helper_Get();
    int a = 0;
    int enemyCurrentFrame = 0;

    for (auto& i : tower_vec)
    {
        if (i != nullptr)
        {
            if (i->get_tower_statement() == Tower::ATTACK_SPEED_BUFF)
            {
                if (i->get_buff_timer() < 0)
                {
                    i->set_tower_statement(Tower::NONONO);
                    i->set_prev_attack_timer(i->get_temp_attack_timer());
                    i->sprite = std::move(*i->default_sprite);
                    i->sprite.SetFrame(4);
                    i->sprite.SetSpeed(8.f);
                    i->default_sprite_speed = 8.f;
                    i->default_frame = 4;
                    i->sprite.activeAnimation = true;
                    i->transform.SetScale(100, 100);
                }
                else
                {
                    i->get_buff_timer() -= dt;
                }
            }
            if (i->get_tower_statement() == Tower::WHEEL_WIND)
            {
                if (i->get_buff_timer() < 0)
                {
                    i->set_tower_statement(Tower::NONONO);
                    i->is_using_skill = false;
                    i->set_current_mana(0);
                    i->sprite = std::move(*i->default_sprite);
                    i->sprite.SetFrame(4);
                    i->sprite.SetSpeed(8.f);
                    i->sprite.activeAnimation = true;
                    i->transform.SetScale(200, 200);
                }
                else
                {
                    i->get_buff_timer() -= dt;
                }
            }
            if (i->get_tower_statement() == Tower::BOW_BIG_PREPARING)
            {
                if (i->get_buff_timer() < 0)
                {
                    i->set_tower_statement(Tower::BOW_BIG_PREPARED);
                    i->sprite = std::move(*i->default_sprite);
                    int default_sprite_frame = i->default_frame;
                    i->sprite.SetFrame(default_sprite_frame);
                    float default_sprite_speed = i->default_sprite_speed;
                    i->sprite.SetSpeed(default_sprite_speed);
                    i->sprite.activeAnimation = true;
                    i->transform.SetScale(100, 100);
                }
                else
                {
                    if (i->target != nullptr)
                    {
                        float angle = atan2(i->target->transform.position.y - i->transform.position.y, i->target->transform.position.x - i->transform.position.x) * 180.f / 3.141592f;
                        angle += 90.f;
                        i->transform.rotation = angle;
                    }
                    i->get_buff_timer() -= dt;
                }
            }
            if (i->target != nullptr)
            {
                if (Target_Is_In_Range(i->target, i))
                {
                    float angle = atan2(i->target->transform.position.y - i->transform.position.y, i->target->transform.position.x - i->transform.position.x) * 180.f / 3.141592f;
                    angle += 90.f;
                    i->transform.rotation = angle;
                }
            }
            i->get_attack_timer() -= dt;
            std::vector<Object*> temp_attack_range = i->get_attack_range();
        if (i->get_tower_statement() == Tower::ATTACK_SPEED_BUFF)
        {
            if (i->get_buff_timer() < 0)
            {
                i->set_tower_statement(Tower::NONONO);
                i->set_prev_attack_timer(i->get_temp_attack_timer());
                i->sprite = std::move(*i->default_sprite);
                i->sprite.SetFrame(4);
                i->sprite.SetSpeed(8.f);
                i->default_sprite_speed = 8.f;
                i->default_frame = 4;
                i->sprite.activeAnimation = true;
                i->transform.SetScale(100, 100);
            }
            else
            {
                i->get_buff_timer() -= dt;
            }
        }
        if (i->get_tower_statement() == Tower::WHEEL_WIND)
        {
            if (i->get_buff_timer() < 0)
            {
                i->set_tower_statement(Tower::NONONO);
                i->is_using_skill = false;
                i->set_current_mana(0);
                i->sprite = std::move(*i->default_sprite);
                i->sprite.SetFrame(4);
                i->sprite.SetSpeed(8.f);
                i->sprite.activeAnimation = true;
                i->transform.SetScale(200, 200);
            }
            else
            {
                i->get_buff_timer() -= dt;
            }
        }
        if (i->get_tower_statement() == Tower::BOW_BIG_PREPARING)
        {
            if (i->get_buff_timer() < 0)
            {
                i->set_tower_statement(Tower::BOW_BIG_PREPARED);
                i->sprite = std::move(*i->default_sprite);
                int default_sprite_frame = i->default_frame;
                i->sprite.SetFrame(default_sprite_frame);
                float default_sprite_speed = i->default_sprite_speed;
                i->sprite.SetSpeed(default_sprite_speed);
                i->sprite.activeAnimation = true;
                i->transform.SetScale(100, 100);
            }
            else
            {
                if (i->target != nullptr)
                {
                    float angle = atan2(i->target->transform.position.y - i->transform.position.y, i->target->transform.position.x - i->transform.position.x) * 180.f / 3.141592f;
                    angle += 90.f;
                    i->transform.rotation = angle;
                }
                i->get_buff_timer() -= dt;
            }
        }
        if (i->target != nullptr)
        {
            if (Target_Is_In_Range(i->target, i))
            {
                float angle = atan2(i->target->transform.position.y - i->transform.position.y, i->target->transform.position.x - i->transform.position.x) * 180.f / 3.141592f;
                angle += 90.f;
                i->transform.rotation = angle;
            }
        }
		if (i != nullptr)
		{
			if (i->get_tower_statement() == Tower::ATTACK_SPEED_BUFF)
			{
				if (i->get_buff_timer() < 0)
				{
					i->set_tower_statement(Tower::NONONO);
					i->set_prev_attack_timer(i->get_temp_attack_timer());
					i->sprite = std::move(*i->default_sprite);
					i->sprite.SetFrame(4);
					i->sprite.SetSpeed(8.f);
					i->default_sprite_speed = 8.f;
					i->default_frame = 4;
					i->sprite.activeAnimation = true;
					i->transform.SetScale(100, 100);
				}
				else
				{
					i->get_buff_timer() -= dt;
				}
			}
			if (i->get_tower_statement() == Tower::WHEEL_WIND)
			{
				if (i->get_buff_timer() < 0)
				{
					i->set_tower_statement(Tower::NONONO);
					i->is_using_skill = false;
					i->set_current_mana(0);
					i->sprite = std::move(*i->default_sprite);
					i->sprite.SetFrame(4);
					i->sprite.SetSpeed(8.f);
					i->sprite.activeAnimation = true;
					i->transform.SetScale(200, 200);
				}
				else
				{
					i->get_buff_timer() -= dt;
				}
			}
			if (i->get_tower_statement() == Tower::BOW_BIG_PREPARING)
			{
				if (i->get_buff_timer() < 0)
				{
					i->set_tower_statement(Tower::BOW_BIG_PREPARED);
					i->sprite = std::move(*i->default_sprite);
					int default_sprite_frame = i->default_frame;
					i->sprite.SetFrame(default_sprite_frame);
					float default_sprite_speed = i->default_sprite_speed;
					i->sprite.SetSpeed(default_sprite_speed);
					i->sprite.activeAnimation = true;
					i->transform.SetScale(100, 100);
				}
				else
				{
					if (i->target != nullptr)
					{
						float angle = atan2(i->target->transform.position.y - i->transform.position.y, i->target->transform.position.x - i->transform.position.x) * 180.f / 3.141592f;
						angle += 90.f;
						i->transform.rotation = angle;
					}
					i->get_buff_timer() -= dt;
				}
			}
        if (i->target != nullptr)
        {
            if (Target_Is_In_Range(i->target, i))
            {
                float angle = atan2(i->target->transform.position.y - i->transform.position.y, i->target->transform.position.x - i->transform.position.x) * 180.f / 3.141592f;
                angle += 90.f;
                i->transform.rotation = angle;
            }
        }
		}

            a = 0;
            for (auto& j : enemy_vec)
            {
                if (j == nullptr)
                {
                    a++;
                    continue;
                }
                const float enemy_pos_normalize_left = j->transform.position.x - (j->transform.GetScale().x / 6);
                const float enemy_pos_normalize_right = j->transform.position.x + (j->transform.GetScale().x / 6);
                const float enemy_pos_normalize_up = j->transform.position.y + (j->transform.GetScale().y / 6);
                const float enemy_pos_normalize_down = j->transform.position.y - (j->transform.GetScale().y / 6);
                for (auto& k : temp_attack_range)
                {
                    const float tower_attack_pos_normalize_down = k->transform.position.y - (k->transform.GetScale().y / 2);
                    const float tower_attack_pos_normalize_up = k->transform.position.y + (k->transform.GetScale().y / 2);
                    const float tower_attack_pos_normalize_right = k->transform.position.x + (k->transform.GetScale().x / 2);
                    const float tower_attack_pos_normalize_left = k->transform.position.x - (k->transform.GetScale().x / 2);
                    if (j != nullptr)
                    {
                        if (j->transform.position.y > tower_attack_pos_normalize_down &&
                            j->transform.position.y < tower_attack_pos_normalize_up)
                        {
                            if (enemy_pos_normalize_right > tower_attack_pos_normalize_left &&
                                enemy_pos_normalize_right < tower_attack_pos_normalize_right)
                            {
                                if (i->get_attack_timer() < 0)
                                {
                                    i->target = j;
                                    Attack(j, i->get_attack_damage(), a, dt, *i, k);
                                    i->sound.Play(0);
                                    i->set_attack_timer(i->get_prev_attack_timer());
                                }
                            }
                            else if (enemy_pos_normalize_left > tower_attack_pos_normalize_left &&
                                enemy_pos_normalize_left < tower_attack_pos_normalize_right)
                            {
                                if (i->get_attack_timer() < 0)
                                {
                                    i->target = j;
                                    Attack(j, i->get_attack_damage(), a, dt, *i, k);
                                    i->sound.Play(0);
                                    i->set_attack_timer(i->get_prev_attack_timer());
                                }
                            }
                        }
                        else if (j->transform.position.x < tower_attack_pos_normalize_right &&
                            j->transform.position.x > tower_attack_pos_normalize_left)
                        {
                            if (enemy_pos_normalize_up > tower_attack_pos_normalize_down &&
                                enemy_pos_normalize_up < tower_attack_pos_normalize_up)
                            {
                                if (i->get_attack_timer() < 0)
                                {
                                    i->target = j;
                                    Attack(j, i->get_attack_damage(), a, dt, *i, k);
                                    i->sound.Play(0);
                                    i->set_attack_timer(i->get_prev_attack_timer());
                                }
                            }
                            else if (enemy_pos_normalize_down > tower_attack_pos_normalize_down &&
                                enemy_pos_normalize_down < tower_attack_pos_normalize_up)
                            {
                                if (i->get_attack_timer() < 0)
                                {
                                    i->target = j;
                                    Attack(j, i->get_attack_damage(), a, dt, *i, k);
                                    i->sound.Play(0);
                                    i->set_attack_timer(i->get_prev_attack_timer());
                                }
                            }
                        }
                    }
                }
                if (j != nullptr)
                {
                    j->get_enemy_recover_timer() -= dt;

                    if (j->get_enemy_recover_timer() < 0)
                    {
                        enemyCurrentFrame = j->sprite.GetCurrentFrame();
                        j->sprite = std::move(*j->default_sprite_enemy);
                        j->sprite.activeAnimation = true;
                        j->sprite.SetFrame(12);
                        j->sprite.SetSpeed(14.f);
                        j->sprite.SetCurrentFrame(false, enemyCurrentFrame);
                        j->set_enemy_recover_timer(3000.0f);
                    }
                }
                a++;
            }
            const float currRotation = i->get_current_rotation();
            if (currRotation == i->transform.rotation && i->get_attack_timer() < 0)
            {
                i->sprite.stopAnimation = true;
                i->sprite.SetCurrentFrame(false, 0);

            }
        }
    }
}
void TOWER_ATTACK_COMPONENT::Income_Fading(float dt)
{
    for(auto &i : income_vector)
    {
        if (i != nullptr)
        {
            i->timer -= dt;
            if (i->timer < 0.f)
            {
                i->isDead = true;
                i = nullptr;
            }
        }
    }
}

void TOWER_ATTACK_COMPONENT::Update(float dt)
{
    (dt);
    Helper_Get();
    Income_Fading(dt);
    if (game_start)
    {
        for (auto& i : my_map->Get_enemy_vec())
        {
            if (i != nullptr)
            {
                if (i->get_hp() <= 0)
                {

                    i->isDead = true;
                    i->get_energy_bar()->isDead = true;
                    i->get_energy_bar() = nullptr;
                    i = nullptr;
                    enemy_count++;
                }
            }
        }
        Move_Bullet(dt);
        Check_Is_Enemy_In(dt);

        Fade_Lightning(dt);
    }
    else if (!game_start)
    {
        if (!my_map->Get_tower_vec().empty())
        {
            for (auto &i : my_map->Get_tower_vec())
            {
                if (i != nullptr)
                {
                    i->sprite = std::move(*i->default_sprite_idle);
                }
            }
        }
        if (!temp_save_fire_timer.empty())
        {
            temp_save_fire_timer.clear();
        }
        if (!temp_save_fire.empty())
        {
            temp_save_fire.clear();
        }
        if (!my_map->Get_enemy_vec().empty())
        {
            for (auto &i : my_map->Get_enemy_vec())
            {
                if (i != nullptr)
                {
                    i->isDead = true;
                    i = nullptr;
                }
            }
            my_map->Get_enemy_vec().clear();
        }
        if (!bullet_vec.empty())
        {
            for (auto& i : bullet_vec)
            {
                if (i != nullptr)
                {
                    i->isDead = true;
                    i = nullptr;
                }
            }
            bullet_vec.clear();
        }
        if (!my_map->get_energy_vec().empty())
        {
            for (auto &i : my_map->get_energy_vec())
            {
                if (i != nullptr)
                {
                    i->isDead = true;
                    i = nullptr;
                }
            }
        }
        if (!lightning_vec.empty())
        {
            for (auto& i : lightning_vec)
            {
                if (i != nullptr)
                {
                    i->isDead = true;
                    i = nullptr;
                }
            }
            lightning_vec.clear();
        }
        if (!income_vector.empty())
        {
            for (auto& i : income_vector)
            {
                if (i != nullptr)
                {
                    i->isDead = true;
                    i = nullptr;
                }
            }
            income_vector.clear();
        }
    }
    Helper_Set();
}