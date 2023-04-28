#include <iostream>
#include <thread>
#include "MazePathFindingProgram.h"

#include "MazeMap.h"
#include "PathFindingAI.h"

#include "RightHandOnWall.h"

#include "ConsoleProgram_ScreenManager.h"

MazePathFindingProgram& MazePathFindingProgram::GetInstance()
{
	static MazePathFindingProgram instance;

	return instance;
}

void MazePathFindingProgram::ProgramStart()
{
	bprogramEnd = false;

	MazeMap& Maze = MazeMap::GetInstance();
	PathFindingAI& AI = PathFindingAI::GetInstance();

	ConsoleProgramScreenManager& screen = ConsoleProgramScreenManager::GetInstance();

	Maze.Draw();
	screen.ScreenFlipping();
	Maze.Draw();
	AI.Draw();
	screen.ScreenFlipping();


	AI.SetPathFindingAlgorithm(RightHandOnWall::GetInstance()); // PathFidingAlgorithm Setting

	std::thread AIUpdateThread = std::thread(&MazePathFindingProgram::AIUpdate, this);
	// std::thread screenThread = std::thread(&MazePathFindingProgram::ScreenUpdate, this);

	AIUpdateThread.join();

	// screenThread.join();
}

void MazePathFindingProgram::AIUpdate()
{
	PathFindingAI& AI = PathFindingAI::GetInstance();
	MazeMap& Maze = MazeMap::GetInstance();

	while (true)
	{
		AI.Update();

		if (Maze.GetExitPoint().mX == AI.GetPosition().mX && Maze.GetExitPoint().mY == AI.GetPosition().mY)
			break;

		Sleep(AI_Update_Cycle);
	}

	ProgramExit();
}
/*
void MazePathFindingProgram::ScreenUpdate()
{
	ConsoleProgramScreenManager& screen = ConsoleProgramScreenManager::GetInstance();

	clock_t currentTime = 0;
	clock_t oldTime = clock();

	UINT8 fps = screen.GetFramePerSecond();

	while (!bprogramEnd)
	{
		currentTime = clock();

		if (currentTime >= oldTime + 6000 / fps)
		{
			screen.ScreenFlipping();
			oldTime = currentTime;
		}
	}
}
*/
void MazePathFindingProgram::ProgramExit()
{
	bprogramEnd = true;

	ConsoleProgramScreenManager& screen = ConsoleProgramScreenManager::GetInstance();

	TCHAR GameEndText[30];
	lstrcpy(GameEndText, TEXT("GameEnd! 5초후 게임이 종료됩니다."));

	screen.ScreenPrinting(Maze_Size, Maze_Size, GameEndText, 15);
	screen.ScreenFlipping();

	Sleep(5000);
}

MazePathFindingProgram::~MazePathFindingProgram()
{
	
}