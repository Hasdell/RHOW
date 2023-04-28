#pragma once
#include "MazeProgramDefineHeader.h"

interface IConsoleProgramBase
{
public:
	virtual void ProgramStart() = 0;
	virtual void ProgramExit() = 0;
};

