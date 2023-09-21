#pragma once
#include "Command.h"

class CreditCommand : public Command
{
public:
	CreditCommand();
	~CreditCommand();
	virtual void Execute() override;
};