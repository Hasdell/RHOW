#include <iostream>
#include <thread>
#include "MazePathFindingProgram.h"

#include "MazeMap.h"
#include "PathFindingAI.h"

#include "RightHandOnWall.h"

#include "ConsoleProgram_ScreenManager.h"
#include "ConsoleProgram_TimerManager.h"

MazePathFindingProgram& MazePathFindingProgram::GetInstance()
{
	static MazePathFindingProgram instance;

	return instance;
}

void MazePathFindingProgram::ProgramStart()
{
	MazeMap& Maze = MazeMap::GetInstance();
	PathFindingAI& AI = PathFindingAI::GetInstance();

	AI.SetPathFindingAlgorithm(RightHandOnWall::GetInstance()); // PathFidingAlgorithm Setting

	Maze.Draw();
	AI.Draw();

	std::thread AIUpdateThread = std::thread(&MazePathFindingProgram::AIUpdate, this);

	AIUpdateThread.join();
}

void MazePathFindingProgram::AIUpdate()
{
	PathFindingAI& AI = PathFindingAI::GetInstance();
	MazeMap& Maze = MazeMap::GetInstance();

	while (true)
	{
		AI.Update();

		if (Maze.GetExitPoint() == AI.GetPosition())
			break;

		Sleep(AI_Update_Cycle);
	}

	ProgramExit();
}
void MazePathFindingProgram::ProgramExit()
{
	ConsoleProgramScreenManager& Screen = ConsoleProgramScreenManager::GetInstance();

	TCHAR programEndText[45];
	lstrcpy(programEndText, TEXT("ProgramEnd! 5초후 프로그램이 종료됩니다."));

	Screen.ScreenPrinting(Maze_Size_X / 2, Maze_Size_Y + 3, programEndText, 15);

	if (mbProgramRuntimeCheck)
	{
		ConsoleProgramTimerManager& Timer = ConsoleProgramTimerManager::GetInstance();
		Timer.FinishRunTimeCheck();

		Screen.ScreenPrinting(Maze_Size_X / 2, Maze_Size_Y + 4, Timer.GetRunTime_Text_Sec(), 15);
	}

	Screen.ScreenFlipping();

	Sleep(5000);
}

void MazePathFindingProgram::SetRuntimeCheck(bool bruntimeCheck)
{
	mbProgramRuntimeCheck = bruntimeCheck;
}