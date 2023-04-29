#include "PathFindingAI.h"
#include "ConsoleProgram_ScreenManager.h"
#include "MazeProgramDefineHeader.h"

PathFindingAI& PathFindingAI::GetInstance()
{
	static PathFindingAI instance;

	return instance;
}
PathFindingAI::PathFindingAI() 
	: mCurrentPosition(Maze_Size_X - 2, Maze_Size_Y - 2),
	  mTextColor(10)
{
	lstrcpy(mDrawText, TEXT("¡Ü"));
}
PathFindingAI::~PathFindingAI()
{
	mPathFindingAlgorithm = nullptr;
}
void PathFindingAI::Draw()
{
	ConsoleProgramScreenManager& Screen = ConsoleProgramScreenManager::GetInstance();

	int nextPathDirection = mPathFindingAlgorithm->GetNextPathDirection();
	
	switch (nextPathDirection)
	{
	case (int)Direction::UP:
		lstrcpy(mDrawText, TEXT("¡è"));
		break;
	case (int)Direction::RIGHT:
		lstrcpy(mDrawText, TEXT("¡æ"));
		break;
	case (int)Direction::DOWN:
		lstrcpy(mDrawText, TEXT("¡é"));
		break;
	case (int)Direction::LEFT:
		lstrcpy(mDrawText, TEXT("¡ç"));
		break;
	}

	Screen.ScreenPrinting(mCurrentPosition.mX * 2, mCurrentPosition.mY, mDrawText, mTextColor);
	Screen.ScreenFlipping();
	Screen.ScreenPrinting(mCurrentPosition.mX * 2, mCurrentPosition.mY, mDrawText, mTextColor);
}
void PathFindingAI::Update()
{
	mPathFindingAlgorithm->PathFinding(mCurrentPosition);
	mCurrentPosition = mPathFindingAlgorithm->GetNextPath();

	Draw();
}