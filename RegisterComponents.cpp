
#include "engine\State.h"
#include "RegisterComponents.h"
#include "engine/ComponentBuilder.h"
#include "DemoUIButton.h"
#include "Map.h"
#include "Map_Init_Component.h"
#include "Map_Update_Component.h"
#include "Mouse_Control_Component.h"
#include "Enemy_Generator.h"
#include  "Enemy_Move_Component.h"
#include "Tower_Set_Component.h"
#include "Tower_Attack_Component.h"
#include "Enemy_Health_Component.h"
#include "Display_Clicked_Obj.h"
#include "Gold_Component.h"
#include "Tower_Upgrade.h"
#include "Player_HP_Component.h"
#include "Wave_Component.h"
/**
 * \brief 
 * Register each component builder
 */
void RegisterComponents()
{
    State::AddComponentBuilder(eComponentTypes::DemoUIButton,
        new ComponentTBuilder<DemoUIButton>());
    State::AddComponentBuilder(eComponentTypes::MAP_INIT_COMPONENT,
        new ComponentTBuilder<MAP_INIT_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::MAP_UPDATE_COMPONENT,
        new ComponentTBuilder<MAP_UPDATE_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::MOUSE_CONTROL_COMPONENT,
        new ComponentTBuilder<MOUSE_CONTROL_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::ENEMY_GENERATOR,
        new ComponentTBuilder<ENEMY_GENERATOR>());
    State::AddComponentBuilder(eComponentTypes::ENEMY_MOVE_COMPONENT,
        new ComponentTBuilder<ENEMY_MOVE_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::TOWER_SET_COMPONENET,
        new ComponentTBuilder<TOWER_SET_COMPONENET>());
    State::AddComponentBuilder(eComponentTypes::TOWER_ATTACK_COMPONENT,
        new ComponentTBuilder<TOWER_ATTACK_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::ENEMY_HEALTH_COMPONENT,
        new ComponentTBuilder<ENEMY_HEALTH_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::DISPLAY_CLICKED_OBJ,
        new ComponentTBuilder<DISPLAY_CLICKED_OBJ>());
    State::AddComponentBuilder(eComponentTypes::GOLD_COMPONENT,
        new ComponentTBuilder<GOLD_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::TOWER_UPGRADE,
        new ComponentTBuilder<TOWER_UPGRADE>());
	State::AddComponentBuilder(eComponentTypes::WAVE_COMPONENT,
		new ComponentTBuilder<WAVE_COMPONENT>());
    State::AddComponentBuilder(eComponentTypes::PLAYER_HP_COMPONENT,
            new ComponentTBuilder<PLAYER_HP_COMPONENT>());
}
void UnregisterComponents()
{
    State::RemoveComponentBuilder(eComponentTypes::DemoUIButton);
}
