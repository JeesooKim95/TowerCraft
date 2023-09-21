#pragma once
#include <string>

enum class eCommandTypes
{
    INVALID = 0,
    Level1Command,
	CreditCommand,
    QuitCommand,

    Count
};


inline eCommandTypes StringToCommand(const std::string& string)
{
    if (string == "QuitCommand")				    return eCommandTypes::QuitCommand;
	if (string == "CreditCommand")					return eCommandTypes::CreditCommand;
    if (string == "Level1Command")                   return eCommandTypes::Level1Command;
    return eCommandTypes::INVALID;
}

inline std::string CommandToString(eCommandTypes type)
{
    if (type == eCommandTypes::QuitCommand)				        return "QuitCommand";
	if (type == eCommandTypes::CreditCommand)					return "CreditCommand";
    if (type == eCommandTypes::Level1Command)                    return "Level1Command";
    return "Invalid";
}