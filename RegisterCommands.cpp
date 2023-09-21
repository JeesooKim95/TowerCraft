#include "RegisterCommands.h"
#include "engine/State.h"
#include "engine/CommandBuilder.h"
#include "QuitCommand.h"
#include "Level1Command.h"
#include "CreditCommand.h"

void RegisterCommands()
{
    State::AddCommandBuilder(eCommandTypes::QuitCommand,
        new CommandTBuilder<QuitCommand>);
    State::AddCommandBuilder(eCommandTypes::Level1Command,
        new CommandTBuilder<Level1Command>); 
	State::AddCommandBuilder(eCommandTypes::CreditCommand,
			new CommandTBuilder<CreditCommand>);
}

void UnregisterCommands()
{
    State::RemoveCommandBuilder(eCommandTypes::QuitCommand);
}
