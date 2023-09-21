/**
\file        Credit.h
\author      Jeesoo Kim

\brief
This file is the header file credit object.

copyright   All content 2019 DigiPen (USA) Corporation, all rights reserved.

*/
#pragma once
#include "engine\State.h"
#include "engine\Object.h"

class Credit : public State
{
	friend class Game;
protected:

	Credit() : State() {};
	~Credit() override {};

	void Initialize() override;
	void Update(float dt) override;
	void Close() override;
private:
	Object creditSprite;
	void CreateCredit();
};