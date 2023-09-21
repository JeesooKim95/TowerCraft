/**
\file        Map_Init_Component.cpp
\author      Minseok Sung
\brief
This file will initialize the map.

copyright   All content © 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#include "Map_Init_Component.h"

MAP_INIT_COMPONENT::MAP_INIT_COMPONENT() : Component(eComponentTypes::MAP_INIT_COMPONENT)
{

}
MAP_INIT_COMPONENT::~MAP_INIT_COMPONENT()
{

}
void MAP_INIT_COMPONENT::Initialize()
{
    my_map = (Map*)GetOwner();
    b2Vec2 path;
    Uint8 color_g = 100;
    Uint8 color_r = 100;
    float init_map_x = -State::m_width / 2.0f;
    float init_map_y = State::m_height / 2.0f;
    const float map_cut_20_x = (State::m_width / 20.f);
    const float map_cut_11_y = (State::m_height / 11.f);

    for (int i = 0; i < cut_eleven; i++)
    {
        for (int j = 0; j < cut_twenty; j++)
        {
            if (i == 4)
            {
                color_g = 0;
                color_r = 100;
            }
            else
            {
                color_g = 100;
                color_r = 0;

            }
            grid = new Object;
            grid->transform.SetScale(map_cut_20_x, map_cut_11_y);
            grid->SetName("grid");
            grid->transform.position.Set(init_map_x + (map_cut_20_x / 2.f), init_map_y - (map_cut_11_y / 2.f), 1);
            grid->transform.rotation = 0;
            grid->sprite.Free();
            grid->sprite.LoadImage("texture/Others/rect.png", State::m_renderer);
            grid->sprite.color = { 0,0,0,255 };
            grid_vector.push_back(grid);
            grid_state.push_back(Map::NOTHING);
            init_map_x += map_cut_20_x;
        }
        init_map_x = -State::m_width / 2.0f;
        init_map_y -= map_cut_11_y;
    }
	grid_state[1] = Map::START_BUTTON_SETTED;
	path.x = grid_vector[1]->transform.position.x;
	path.y = grid_vector[1]->transform.position.y;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[1]);
	my_map->Set_enemy_start_pos(path);
	enemy_path.push_back(path);
	grid_state[19] = Map::CHUL_TOWER_BUTTON;
	grid_state[39] = Map::START;
    grid_state[59] = Map::TWICE_SPEED;
	grid_state[52] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[28] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[62] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[50] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[56] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[66] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[95] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[103] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[110] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[113] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[135] = Map::TOWER_POSITION_BUTTON_SETTED;
	grid_state[126] = Map::TOWER_POSITION_BUTTON_SETTED;
	for (int i = 0; i < 180; i += 40)
	{
		grid_state[i] = Map::EDGE;
	}
	grid_state[59] = Map::EDGE;
    grid_state[59] = Map::TWICE_SPEED;
	grid_state[99] = Map::EDGE;
	grid_state[179] = Map::EDGE;
	for (int i = 2; i < 19; i+=2)
	{
		grid_state[i] = Map::EDGE;
	}
	grid_state[128] = Map::POND1;
	grid_state[129] = Map::POND2;
	grid_state[148] = Map::POND3;
	grid_state[149] = Map::POND4;
	grid_state[150] = Map::POND5;
	grid_state[143] = Map::POND6;
	grid_state[144] = Map::POND7;
	grid_state[145] = Map::POND8;
	grid_state[57] = Map::POND9;
	grid_state[77] = Map::POND10;
	grid_state[97] = Map::POND11;
	grid_state[21] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[21]);
	path.x = grid_vector[21]->transform.position.x;
	path.y = grid_vector[21]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[41] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[41]);
	path.x = grid_vector[41]->transform.position.x;
	path.y = grid_vector[41]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[61] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[61]);
	path.x = grid_vector[61]->transform.position.x;
	path.y = grid_vector[61]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[81] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[81]);
	path.x = grid_vector[81]->transform.position.x;
	path.y = grid_vector[81]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[101] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[101]);
	path.x = grid_vector[101]->transform.position.x;
	path.y = grid_vector[101]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[121] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[121]);
	path.x = grid_vector[121]->transform.position.x;
	path.y = grid_vector[121]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[122] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[122]);
	path.x = grid_vector[122]->transform.position.x;
	path.y = grid_vector[122]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[123] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[123]);
	path.x = grid_vector[123]->transform.position.x;
	path.y = grid_vector[123]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[124] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[124]);
	path.x = grid_vector[124]->transform.position.x;
	path.y = grid_vector[124]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[104] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[104]);
	path.x = grid_vector[104]->transform.position.x;
	path.y = grid_vector[104]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[84] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[84]);
	path.x = grid_vector[84]->transform.position.x;
	path.y = grid_vector[84]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[64] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[64]);
	path.x = grid_vector[64]->transform.position.x;
	path.y = grid_vector[64]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[44] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[44]);
	path.x = grid_vector[44]->transform.position.x;
	path.y = grid_vector[44]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[45] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[45]);
	path.x = grid_vector[45]->transform.position.x;
	path.y = grid_vector[45]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[46] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[46]);
	path.x = grid_vector[46]->transform.position.x;
	path.y = grid_vector[46]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[47] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[47]);
	path.x = grid_vector[47]->transform.position.x;
	path.y = grid_vector[47]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[48] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[48]);
	path.x = grid_vector[48]->transform.position.x;
	path.y = grid_vector[48]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[49] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[49]);
	path.x = grid_vector[49]->transform.position.x;
	path.y = grid_vector[49]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[69] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[69]);
	path.x = grid_vector[69]->transform.position.x;
	path.y = grid_vector[69]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[89] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[89]);
	path.x = grid_vector[89]->transform.position.x;
	path.y = grid_vector[89]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[90] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[90]);
	path.x = grid_vector[90]->transform.position.x;
	path.y = grid_vector[90]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[91] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[91]);
	path.x = grid_vector[91]->transform.position.x;
	path.y = grid_vector[91]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[92] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[92]);
	path.x = grid_vector[92]->transform.position.x;
	path.y = grid_vector[92]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[93] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[93]);
	path.x = grid_vector[93]->transform.position.x;
	path.y = grid_vector[93]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[94] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[94]);
	path.x = grid_vector[94]->transform.position.x;
	path.y = grid_vector[94]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[74] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[74]);
	path.x = grid_vector[74]->transform.position.x;
	path.y = grid_vector[74]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[75] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[75]);
	path.x = grid_vector[75]->transform.position.x;
	path.y = grid_vector[75]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[76] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[76]);
	path.x = grid_vector[76]->transform.position.x;
	path.y = grid_vector[76]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[96] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[96]);
	path.x = grid_vector[96]->transform.position.x;
	path.y = grid_vector[96]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[116] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[116]);
	path.x = grid_vector[116]->transform.position.x;
	path.y = grid_vector[116]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[136] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[136]);
	path.x = grid_vector[136]->transform.position.x;
	path.y = grid_vector[136]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[137] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[137]);
	path.x = grid_vector[137]->transform.position.x;
	path.y = grid_vector[137]->transform.position.y;
	enemy_path.push_back(path);
	grid_state[138] = Map::WAY_BUTTON_SETTED;
	my_map->get_enemy_path_in_obj().push_back(grid_vector[138]);
	path.x = grid_vector[138]->transform.position.x;
	path.y = grid_vector[138]->transform.position.y;
	enemy_path.push_back(path);

	grid_state[139] = Map::END_BUTTON_SETTED;
    grid_state[79] = Map::INCOME_INCREMENT;
    Set_Grid();
    my_map->Get_Grid_Vector() = grid_vector;
    my_map->Set_Grid_State_Vector(grid_state);
    my_map->Set_Enemy_Path(enemy_path);
}
void MAP_INIT_COMPONENT::Set_Grid()
{
    int a = 0;
    for (auto& i : grid_vector)
    {
        if (grid_state[a] == Map::CHUL_TOWER_BUTTON)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/Tower/BasicTowerButton.png", State::m_renderer);
        }
        else if (grid_state[a] == Map::CHUL_TOWER_SETTED)
        {
            i->sprite.color = { 100,100,0,100 };
        }        
		else if (grid_state[a] == Map::INCOME_INCREMENT)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/IncomeUpgrade.png", State::m_renderer);
			i->transform.SetScale(67, 67);
			i->sprite.color = { 255, 255, 255, 255 };
		}
        else if (grid_state[a] == Map::TWICE_SPEED)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/twice.png", State::m_renderer);
            i->sprite.color = { 255, 255, 255, 255 };
        }
        else if(grid_state[a] == Map::INCOME_INCREMENT)
        {
            i->sprite.Free();
            i->sprite.color = { 255,0,0,255 };
        }
		else if (grid_state[a] == Map::START_BUTTON_SETTED)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/EnemyStart.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
		}
        else if (grid_state[a] == Map::START_BUTTON)
        {
            i->sprite.color = { 0,0,100,100 };
        }
        else if (grid_state[a] == Map::END_BUTTON)
        {
            i->sprite.color = { 100,0,0,100 };
        }
		else if (grid_state[a] == Map::END_BUTTON_SETTED)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/Castle.png", State::m_renderer);
			i->transform.SetScale(150, 100);
			i->sprite.color = { 255, 255, 255, 255 };
		}
        else if (grid_state[a] == Map::WAY_BUTTON)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/Others/Path.png", State::m_renderer);
            i->sprite.color = { 255, 255, 255, 255 };
        }
        else if (grid_state[a] == Map::WAY_BUTTON_SETTED)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/Others/Path.png", State::m_renderer);
            i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
        }

		else if (grid_state[a] == Map::EDGE)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/Tree.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
		}
		else if (grid_state[a] == Map::POND1)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond128_1.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND2)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond129_2.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND3)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond148_3.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND4)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond149_4.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND5)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond150_5.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND6)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond143_6.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND7)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond144_7.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND8)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond145_8.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND9)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond57_9.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND10)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond77_10.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
		else if (grid_state[a] == Map::POND11)
		{
			i->sprite.Free();
			i->sprite.LoadImage("texture/Others/pond97_11.png", State::m_renderer);
			i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
		}
        else if (grid_state[a] == Map::START)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/Others/StartButton.png", State::m_renderer);
            i->sprite.color = { 255, 255, 255, 255 };
        }
        else if (grid_state[a] == Map::TOWER_POSITION_BUTTON)
        {
            i->sprite.color = { 50,20,30,200 };
        }
        else if (grid_state[a] == Map::TOWER_POSITION_BUTTON_SETTED)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/Others/TowerSet.png", State::m_renderer);
            i->sprite.color = { 255, 255, 255, 255 };
        }
        else if (grid_state[a] == Map::NOTHING)
        {
            i->sprite.Free();
            i->sprite.LoadImage("texture/Others/Grass.png", State::m_renderer);
            i->sprite.color = { 255, 255, 255, 255 };
			i->transform.SetScale({ 69,69 });
        }
        a++;
    }
}

void MAP_INIT_COMPONENT::Update(float dt)
{
    (dt);
}
