#pragma once
#include "IConsoleProgramBase.h"

class MazePathFindingProgram : public IConsoleProgramBase
{
public:
	static MazePathFindingProgram& GetInstance();
public:
	void SetRuntimeCheck(bool bruntimeCheck);
public:
	void ProgramStart();
	void ProgramExit();

	void AIUpdate();
private:
	bool mbProgramRuntimeCheck;
};

