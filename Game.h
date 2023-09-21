/******************************************************************************/
/*!
\file   Game.h
\author David Ly and Juyong Jeong
\par    email: dly\@digipen.edu
\par    GAM150 demo
\par	v0
\date   2018/03/11

Game will only handle the changes of the game states (Level switching)
ie. Main Menu, Levels, Pause, etc.
No game play logic should be added here.
*/
/******************************************************************************/

#pragma once
#include "MainMenu.h"
#include "PauseState.h"
#include "Level1.h"
#include "Credit.h"

typedef enum
{
	LV_MainMenu = 0,
	LV_Level1,
	LV_Credit,
	LV_Pause,
	LV_NUM_LEVELS
}Level_ID;

class StateManager;

class Game
{
	friend class Application;
	StateManager *m_stateManager = nullptr;
public:

	Game();
	~Game();

	void	RegisterState(State* state);
	void	SetFirstState(State* state);
	State*	GetCurrentState();

	void	Quit();
	void	Change(unsigned stateId);

	bool	Initialize();
	void	Update(float dt);
	void	Close();

	void	RegisterPauseState(State *state);
	void	Pause();
	void	Resume();
	void	Restart();
	bool	IsQuit();
        
private:
	MainMenu	mainMenu;
	PauseState	pauseLevel;
    Level1      level1;	
	Credit		credit;
public:
	
	static constexpr int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;
	int	m_width = 0, m_height = 0;

	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;

};