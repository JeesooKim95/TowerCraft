#include "CreditCommand.h"
#include "engine/State.h"
#include "CommonLevel.h"

CreditCommand::CreditCommand() :
	Command(eCommandTypes::CreditCommand)
{
}

CreditCommand::~CreditCommand()
{
}

void CreditCommand::Execute()
{
	State::sCurrentState->m_game->Change(LV_Credit);
}