/**
\file        Level1.cpp
\author      Chulseung Lee
\brief
This file is treating our level1.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Level1.h"
#include "CommonLevel.h"
#include "Game.h"
#include "Mouse_Control_Component.h"
#include "DemoUIButton.h"

extern Object* please_add_this = nullptr;
extern Object* please_add_this_tower = nullptr;
extern Object* please_add_this_enemy = nullptr;
extern Object* please_add_this_bullet = nullptr;
extern Object* please_add_this_enemy_hp = nullptr;
extern Object* please_remove_this_enemy_hp = nullptr;
extern Object* please_remove_this_bullet_obj = nullptr;
extern Object* please_remove_this_enemy_obj = nullptr;
extern Object* please_add_this_tower_information = nullptr;
extern Object* tower_grid = nullptr;
extern Object* please_remove_this_tower_information = nullptr;
extern Object* please_remove_this_tower_attack = nullptr;
extern Object* please_add_this_tower_attack = nullptr;
extern Object* please_add_this_tower_sprite = nullptr;
extern Object* please_remove_this_tower_sprite = nullptr;
extern Object* please_add_this_tower_attack_speed = nullptr;
extern Object* please_remove_this_tower_attack_speed = nullptr;
extern Object* please_add_this_tower_skill = nullptr;
extern Object* gold_sprite = nullptr;
extern Object* wave_sprite = nullptr;
extern Object* please_remove_this_tower_skill = nullptr;
extern Object* please_remove_this_player_hp_obj = nullptr;
extern std::vector<Object*> gold_vec = { nullptr };
extern std::vector<Object*> wave_vec = { nullptr };
extern std::vector<Object*> please_add_this_player_hp_vec = { nullptr };
extern std::vector<Object*> add_tower_upgrade_vec = { nullptr };
extern std::vector<Object*> remove_tower_upgrade_vec = { nullptr };
extern bool please_add_this_tower_once = false;
extern bool please_add_this_gold_vec = false;
extern bool please_add_this_wave_vec = false;
extern bool please_remove_this = false;
extern bool please_remove_this_enemy = false;
extern bool game_start = false;
extern bool please_add_this_enemy_once = false;
extern bool please_add_this_bullet_once = false;
extern bool please_add_this_enemy_hp_once = false;
extern bool please_add_this_tower_information_once = false;
extern bool please_remove_this_tower_information_once = false;
extern bool please_add_this_tower_attack_once = false;
extern bool please_remove_this_tower_attack_once = false;
extern bool please_add_this_tower_attack_speed_once = false;
extern bool twice_speed_is_on = false;
extern bool please_add_this_tower_skill_once = false;
extern bool please_remove_this_tower_attack_speed_once = false;
extern bool please_add_this_tower_sprite_once = false;
extern bool please_remove_this_tower_sprite_once = false;
extern bool please_remove_this_tower_skill_once = false;
extern bool gold_sprite_once = false;
extern bool game_initial_finish = false;
extern bool add_this_upgrade_vec_once = false;
extern bool please_remove_this_bullet = false;
extern bool please_remove_this_player_hp = false;
extern bool wave_sprite_once = false;
extern bool please_add_this_player_hp_once = false;
extern int towerCheck = 0;
extern int enemy_count = 0;
extern int width = 20;
extern int height = 11;
extern int enemy_hp = 6;
extern int Set_Count = 0;
extern int gold = 10;
extern int wave = 1;
extern int player_hp = 5;
extern int real_increment = 1;
bool tutorial_start = false;
bool tutorial_check = false;
bool tutorial_check2 = false;
bool tutorial_check3 = false;
bool tutorial_check4 = false;
bool tutorial_check5 = false;
bool isColliding1 = false;
bool isColliding2 = false;
int player_prev_hp = 5;
extern Tower* tower_clicked = nullptr;
extern Tower* tower_clicked_to_upgrade = nullptr;
extern _TTF_Font* asd = nullptr;
extern Infroamtion_Board* current_inforamtion_board = nullptr;
extern Tower::Tower_Kind upgrade_state = Tower::nothing;

void Level1::Initialize()
{
    State::sCurrentState = this;

    if (!level1_map->Get_enemy_vec().empty())
    {
        level1_map->Get_enemy_vec().clear();
    }
    if (!level1_map->Get_tower_vec().empty())
    {
        level1_map->Get_tower_vec().clear();
    }
    if (!level1_map->get_energy_vec().empty())
    {
        level1_map->get_energy_vec().clear();
    }
    camera.position.Set(0, 0, 0);
    AddComponentToObject(level1_map, eComponentTypes::MAP_INIT_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::MAP_UPDATE_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::ENEMY_GENERATOR);
    AddComponentToObject(level1_map, eComponentTypes::MOUSE_CONTROL_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::DISPLAY_CLICKED_OBJ);
    AddComponentToObject(level1_map, eComponentTypes::TOWER_SET_COMPONENET);
    AddComponentToObject(level1_map, eComponentTypes::TOWER_ATTACK_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::TOWER_UPGRADE);
    AddComponentToObject(level1_map, eComponentTypes::ENEMY_MOVE_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::ENEMY_HEALTH_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::GOLD_COMPONENT);
	AddComponentToObject(level1_map, eComponentTypes::WAVE_COMPONENT);
    AddComponentToObject(level1_map, eComponentTypes::PLAYER_HP_COMPONENT);

    level1_map->sound.LoadSound("sound/BackgroundMusic.mp3");
    level1_map->sound.Play(100);
    AddObject(level1_map);

    tutorialClickSound.sound.LoadSound("sound/MainMenuButtonClicked.mp3");
    loseLifeSound.sound.LoadSound("sound/LoseLife.mp3");

    InitializeObjects();
    for (auto& i : level1_map->Get_Grid_Vector())
    {
        AddObject(i);
    }
}

void Level1::Update(float dt)
{
    if (twice_speed_is_on)
    {
        dt *= 2;
    }
    if (!gold_vec.empty() && please_add_this_gold_vec)
    {
        for (auto& i : gold_vec)
        {
            if (i != nullptr)
            {
                AddDynamicObject(i);
            }
        }
        please_add_this_gold_vec = false;
    }
	if (!wave_vec.empty() && please_add_this_wave_vec)
	{
		for (auto& i : wave_vec)
		{
			if (i != nullptr)
			{
				AddDynamicObject(i);
			}
		}
		please_add_this_wave_vec = false;
	}
    if (please_add_this != nullptr)
    {
        AddObject(please_add_this);
    }
    if (please_remove_this)
    {
        RemoveObject(please_add_this);
    }
    if (please_add_this_tower != nullptr && please_add_this_tower_once)
    {
        AddObject(please_add_this_tower);
        please_add_this_tower_once = false;
    }
    if (please_add_this_bullet != nullptr && please_add_this_bullet_once)
    {
        AddObject(please_add_this_bullet);
        please_add_this_bullet_once = false;
    }
    if (please_add_this_enemy_hp != nullptr && please_add_this_enemy_hp_once)
    {
        AddObject(please_add_this_enemy_hp);
        please_add_this_enemy_hp_once = false;
    }
    if (please_remove_this_bullet_obj != nullptr && please_remove_this_bullet)
    {
        RemoveObject(please_remove_this_bullet_obj);
        please_remove_this_bullet_obj = nullptr;
        please_remove_this_bullet = false;
    }
    if (please_add_this_tower_information != nullptr && please_add_this_tower_information_once)
    {
        AddObject(please_add_this_tower_information);
        please_add_this_tower_information_once = false;
    }
    if (please_add_this_tower_skill != nullptr && please_add_this_tower_skill_once)
    {
        AddObject(please_add_this_tower_skill);
        please_add_this_tower_skill_once = false;
    }
    if (please_remove_this_tower_skill != nullptr && please_remove_this_tower_skill_once)
    {
        RemoveObject(please_remove_this_tower_skill);
        please_remove_this_tower_skill_once = false;
    }
    if (please_remove_this_tower_information != nullptr && please_remove_this_tower_information_once)
    {
        RemoveObject(please_remove_this_tower_information);
        please_remove_this_tower_information_once = false;
    }
    if (please_add_this_tower_attack != nullptr && please_add_this_tower_attack_once)
    {
        AddObject(please_add_this_tower_attack);
        please_add_this_tower_attack_once = false;
    }
    if (please_remove_this_tower_attack != nullptr && please_remove_this_tower_attack_once)
    {
        RemoveObject(please_remove_this_tower_attack);
        please_remove_this_tower_attack_once = false;
    }
    if (please_add_this_tower_attack_speed != nullptr && please_add_this_tower_attack_speed_once)
    {
        AddObject(please_add_this_tower_attack_speed);
        please_add_this_tower_attack_speed_once = false;
    }
    if (please_remove_this_tower_attack_speed != nullptr && please_remove_this_tower_attack_speed_once)
    {
        RemoveObject(please_remove_this_tower_attack_speed);
        please_remove_this_tower_attack_speed_once = false;
    }
    if (please_add_this_tower_sprite != nullptr && please_add_this_tower_sprite_once)
    {
        AddObject(please_add_this_tower_sprite);
        please_add_this_tower_sprite_once = false;
        if (!add_tower_upgrade_vec.empty() && add_this_upgrade_vec_once)
        {
            for (auto& i : add_tower_upgrade_vec)
            {
                if (i != nullptr)
                {
                    AddObject(i);
                }
            }
            add_this_upgrade_vec_once = false;
        }
    }
    if (!remove_tower_upgrade_vec.empty())
    {
        for (auto& i : remove_tower_upgrade_vec)
        {
            if (i != nullptr)
            {
                RemoveObject(i);
            }
        }
        remove_tower_upgrade_vec.clear();
    }
    if (please_remove_this_tower_sprite != nullptr && please_remove_this_tower_sprite_once)
    {
        RemoveObject(please_remove_this_tower_sprite);
        please_remove_this_tower_sprite_once = false;
    }
    if (gold_sprite != nullptr && gold_sprite_once)
    {
        AddObject(gold_sprite);
        gold_sprite_once = false;
    }
    if (wave_sprite != nullptr && wave_sprite_once)
    {
        AddObject(wave_sprite);
        wave_sprite_once = false;
    }
    if (please_add_this_player_hp_once)
    {
        for (int i = 0; i < please_add_this_player_hp_vec.size(); i++)
        {

            AddObject(please_add_this_player_hp_vec[i]);
        }
        please_add_this_player_hp_once = false;
    }
    if (please_remove_this_player_hp_obj != nullptr && please_remove_this_player_hp)
    {
        RemoveObject(please_remove_this_player_hp_obj);
        please_remove_this_player_hp = false;
    }
    if (game_start)
    {

        if (please_remove_this_enemy_obj != nullptr&& please_remove_this_enemy_hp != nullptr)
        {
            RemoveObject(please_remove_this_enemy_hp);
            RemoveObject(please_remove_this_enemy_obj);
            please_remove_this_enemy_obj = nullptr;
            please_remove_this_enemy_hp = nullptr;
        }
        if (enemy_count == level1_map->get_enemy_limit())
        {
            level1_map->Get_enemy_vec().clear();
            level1_map->enemy_limit_increment();
            game_start = false;
            enemy_count = 0;
            enemy_hp += 6;
            if (wave >= 10)
            {
                enemy_hp += 12;
            }
            else if(wave >= 15)
            {
                enemy_hp += 20;
            }
            else if(wave >= 20)
            {
                enemy_hp += 25;
            }
            else if(wave >= 25)
            {
                enemy_hp += 35;
            }
            else if(wave>= 30)
            {
                enemy_hp += 45;
            }
            else if(wave >= 35)
            {
                enemy_hp += 80;
            }
            wave++;
        }
        if (player_hp <= 0 && !level1_map->Get_enemy_vec().empty())
        {
            GameOver(dt);
            game_start = false;
            m_game->Change(LV_MainMenu);
            player_hp = 5;
            enemy_hp = 6;
            real_increment = 1;
        }
    }
    if (m_input->IsTriggered(SDL_BUTTON_LEFT))
    {
        tutorialClickSound.sound.Play();
    }
    if (player_hp != player_prev_hp)
    {
        loseLifeSound.sound.Play();
        player_prev_hp = player_hp;
    }

    Tutorial();
    UpdateObjects(dt);
    UpdatePhysics(dt);
    Render(dt);
}

void Level1::Tutorial()
{
    if (isTutorial <=11)
    {
        MOUSE_CONTROL_COMPONENT mouse;
		DemoUIButton collidingCheck;

        mouse.Helper_Convert_Mouse_Pos();
        mouse_position = mouse.Get_Mouse_Pos();

        if (!tutorial_start &&  isTutorial == 0)
        {
            tutorial_start = true;
            tutorial.SetName("TowerSet");
            tutorial.transform.position.Set(360, 280, 0);
            tutorial.transform.SetScale(400, 100);
            tutorial.sprite.LoadImage("texture/Tutorial/TowerTutorial.png", m_renderer);
            AddObject(&tutorial);
            isTutorial++;
        }
        else if (mouse_position.x >= 270 && mouse_position.y >= 260)
        {
            if (State::m_input->IsTriggered(SDL_BUTTON_LEFT) && isTutorial == 1)
            {
                tutorial.sprite.Free();
                tutorial_check = true;
                isTutorial++;
            }
        }
        else if (tutorial_check && isTutorial == 2)
        {
            tutorial_check = false;

            tutorial.sprite.Free();

            tutorial.transform.position.Set(-250, 50, 0);
            tutorial.transform.SetScale(400, 200);
            tutorial.sprite.LoadImage("texture/Tutorial/Tutorial2.png", m_renderer);
            isTutorial++;
        }
        else if (isTutorial == 3)
        {
            if (m_input->IsTriggered(SDL_BUTTON_LEFT))
            {
                tutorial.sprite.Free();
                isColliding1 = false;
                tutorial_check2 = true;
                isTutorial++;
            }
        }
        else if (tutorial_check2 && isTutorial == 4)
        {
            tutorial.transform.position.Set(380, 170, 0);
            tutorial.transform.SetScale(400, 200);
            tutorial.sprite.LoadImage("texture/Tutorial/Tutorial3.png", m_renderer);
            tutorial_check2 = false;
            isTutorial++;
        }
        else if (isTutorial == 5)
        {
            if (m_input->IsTriggered(SDL_BUTTON_LEFT))
            {
                tutorial_check3 = true;
                tutorial.sprite.Free();
                isTutorial++;
            }
        }
        else if (tutorial_check3 && isTutorial == 6)
        {
            tutorial.transform.position.Set(-260, 100, 0);
            tutorial.transform.SetScale(400, 150);
            tutorial.sprite.LoadImage("texture/Tutorial/Tutorial4.png", m_renderer);
            tutorial_check3 = false;
            isTutorial++;
        }
        else if (isTutorial == 7)
        {
            if (m_input->IsTriggered(SDL_BUTTON_LEFT))
            {
                tutorial.sprite.Free();
                tutorial.transform.position.Set(0, 200, 0);
                tutorial.transform.SetScale(500, 250);
                tutorial.sprite.LoadImage("texture/Tutorial/Tutorial5.png", m_renderer);
                isTutorial++;
            }
        }
        else if (isTutorial == 8 && m_input->IsTriggered(SDL_BUTTON_LEFT))
        {
            tutorial.sprite.Free();

            tutorial.transform.position.Set(360, 120, 0);
            tutorial.transform.SetScale(400, 200);
            tutorial.sprite.LoadImage("texture/Tutorial/Tutorial7.png", m_renderer);
            isTutorial++;
        }
        else if (isTutorial == 9 && m_input->IsTriggered(SDL_BUTTON_LEFT))
        {
            tutorial.sprite.Free();

            tutorial.transform.position.Set(380, 30, 0);
            tutorial.transform.SetScale(350, 250);
            tutorial.sprite.LoadImage("texture/Tutorial/Tutorial8.png", m_renderer);
            isTutorial++;
        }
        else if (isTutorial == 10 && m_input->IsTriggered(SDL_BUTTON_LEFT))
        {
            tutorial.sprite.Free();

            tutorial.transform.position.Set(0, 200, 0);
            tutorial.transform.SetScale(600, 300);
            tutorial.sprite.LoadImage("texture/Tutorial/Tutorial6.png", m_renderer);
            isTutorial++;
        }
        else if (isTutorial == 11 && m_input->IsTriggered(SDL_BUTTON_LEFT))
        {
            tutorial.sprite.Free();
        }
    }
}

float gameover_timer = 5.0f;

void Level1::GameOver(float dt)
{
    gameOver.transform.position.Set(0, 0, 2);
    gameOver.transform.SetScale(m_width, m_height);
    gameOver.sprite.LoadImage("texture/gameover.png", m_renderer);
    gameOver.sprite.isVisible = true;
    AddObject(&gameOver);
    while (gameover_timer > 0)
    {
        gameover_timer -= dt;
    }
    gameover_timer = 5.0f;
}
void Level1::Close()
{
    ClearBaseState();
    if(!level1_map->Get_Grid_Vector().empty())
    {
        for(auto& i : level1_map->Get_Grid_Vector())
        {
            delete i;
            i = nullptr;
        }
        level1_map->Get_Grid_Vector().clear();
    }

    delete level1_map;
}
