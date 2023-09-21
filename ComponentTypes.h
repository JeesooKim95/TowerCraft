/******************************************************************************/
/*!
\file   ComponentTypes.h
\author Hun Yang
\par    email: hun.yang8456@gmail.com
\par    GAM150 demo
\date   2019/04/30


*/
/******************************************************************************/
#pragma once

#include <string>

/**
 * \brief 
 * This is enum class for component types
 */
enum class eComponentTypes
{
    INVALID = 0,
    DemoUIButton,
    MAP_INIT_COMPONENT,
    MAP_UPDATE_COMPONENT,
    MOUSE_CONTROL_COMPONENT,
    ENEMY_GENERATOR,
    ENEMY_MOVE_COMPONENT,
    TOWER_SET_COMPONENET,
    TOWER_ATTACK_COMPONENT,
    ENEMY_HEALTH_COMPONENT,
    DISPLAY_CLICKED_OBJ,
    INFORMATION_BOARD_CONTROL,
    GOLD_COMPONENT,

	WAVE_COMPONENT,

    TOWER_UPGRADE,
    PLAYER_HP_COMPONENT,

	NUM_COMPONENTS
};

/**
 * \brief 
 * Convert string to eComponentTypes's component
 * 
 * \param string
 * String to be  converted for component type
 * 
 * \return 
 * Converted component type
 */
inline eComponentTypes StringToComponent(const std::string& string)
{
    if (string == "DemoUIButton")			        return eComponentTypes::DemoUIButton;
    if (string == "MAP_INIT_COMPONENT")                      return eComponentTypes::MAP_INIT_COMPONENT;
    if (string == "MAP_UPDATE_COMPONENT")                      return eComponentTypes::MAP_UPDATE_COMPONENT;
    if (string == "MOUSE_CONTROL_COMPONENT")                      return eComponentTypes::MOUSE_CONTROL_COMPONENT;
    if (string == "ENEMY_GENERATOR")                      return eComponentTypes::ENEMY_GENERATOR;
    if (string == "ENEMY_MOVE_COMPONENT")                      return eComponentTypes::ENEMY_MOVE_COMPONENT;
    if (string == "TOWER_SET_COMPONENET")                      return eComponentTypes::TOWER_SET_COMPONENET; 
    if (string == "ENEMY_HEALTH_COMPONENT")                      return eComponentTypes::ENEMY_HEALTH_COMPONENT;
    if (string == "TOWER_ATTACK_COMPONENT")                      return eComponentTypes::TOWER_ATTACK_COMPONENT;
    if (string == "DISPLAY_CLICKED_OBJ")                      return eComponentTypes::DISPLAY_CLICKED_OBJ;
    if (string == "INFORMATION_BOARD_CONTROL")                      return eComponentTypes::INFORMATION_BOARD_CONTROL;
    if (string == "GOLD_COMPONENT")                      return eComponentTypes::GOLD_COMPONENT;
    if (string == "TOWER_UPGRADE")                      return eComponentTypes::TOWER_UPGRADE; 
	if (string == "WAVE_COMPONENT")                      return eComponentTypes::WAVE_COMPONENT;
    if (string == "PLAYER_HP_COMPONENT")                      return eComponentTypes::PLAYER_HP_COMPONENT;
	return eComponentTypes::INVALID;
}

/**
 * \brief 
 * Convert eComponentTypes's component to string
 * 
 * \param type 
 * Component type to be converted for string
 * 
 * \return 
 * Converted string
 */
inline std::string ComponentToString(eComponentTypes type)
{
    if (type == eComponentTypes::DemoUIButton)		            return "DemoUIButton";
    if (type == eComponentTypes::MAP_INIT_COMPONENT)                     return "MAP_INIT_COMPONENT";
    if (type == eComponentTypes::MAP_UPDATE_COMPONENT)                     return "MAP_UPDATE_COMPONENT";
    if (type == eComponentTypes::MOUSE_CONTROL_COMPONENT)                     return "MOUSE_CONTROL_COMPONENT";
    if (type == eComponentTypes::ENEMY_GENERATOR)                     return "ENEMY_GENERATOR";
    if (type == eComponentTypes::ENEMY_MOVE_COMPONENT)                     return "ENEMY_MOVE_COMPONENT";
    if (type == eComponentTypes::TOWER_SET_COMPONENET)                     return "TOWER_SET_COMPONENET";
    if (type == eComponentTypes::ENEMY_HEALTH_COMPONENT)                     return "ENEMY_HEALTH_COMPONENT";
    if (type == eComponentTypes::TOWER_ATTACK_COMPONENT)                     return "TOWER_ATTACK_COMPONENT";
    if (type == eComponentTypes::DISPLAY_CLICKED_OBJ)                     return "DISPLAY_CLICKED_OBJ";
    if (type == eComponentTypes::INFORMATION_BOARD_CONTROL)                     return "INFORMATION_BOARD_CONTROL";
    if (type == eComponentTypes::GOLD_COMPONENT)                     return "GOLD_COMPONENT";
    if (type == eComponentTypes::TOWER_UPGRADE)                     return "TOWER_UPGRADE"; 
	if (type == eComponentTypes::WAVE_COMPONENT)                     return "WAVE_COMPONENT";
    if (type == eComponentTypes::PLAYER_HP_COMPONENT)                     return "PLAYER_HP_COMPONENT";
	return "Invalid";
}