#pragma once
#include "Command.h"

class Level1Command : public Command
{
public:
    Level1Command();
    ~Level1Command();
    virtual void Execute() override;
public:
};