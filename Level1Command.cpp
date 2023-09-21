#include "Level1Command.h"
#include "engine/State.h"
#include "CommonLevel.h"

Level1Command::Level1Command() : Command(eCommandTypes::Level1Command)
{
}

Level1Command::~Level1Command()
{
}

void Level1Command::Execute()
{
    State::sCurrentState->m_game->Change(LV_Level1);
}