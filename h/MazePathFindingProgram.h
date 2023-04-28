#pragma once
#include "IConsoleProgramBase.h"

class MazePathFindingProgram : public IConsoleProgramBase
{
public:
	~MazePathFindingProgram();
	static MazePathFindingProgram& GetInstance();
public:
	void ProgramStart();
	void ProgramExit();

	void AIUpdate();
	void ScreenUpdate();
private:
	bool bprogramEnd;
};

