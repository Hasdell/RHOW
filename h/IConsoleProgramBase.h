#pragma once
#include "MazeProgramDefineHeader.h"

class IConsoleProgramBase
{
public:
	virtual void ProgramStart() = 0;
	virtual void ProgramExit() = 0;
	virtual void SetRuntimeCheck(bool bruntimeCheck) = 0;
};

