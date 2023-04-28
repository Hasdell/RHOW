#include "PathFindingAI.h"
#include "ConsoleProgram_ScreenManager.h"
#include "MazeProgramDefineHeader.h"

PathFindingAI& PathFindingAI::GetInstance()
{
	static PathFindingAI instance;

	return instance;
}
PathFindingAI::PathFindingAI() : mCurrentPosition(Maze_Size - 2, 1)
{
	lstrcpy(mDrawText, TEXT("¡Ü"));
}
PathFindingAI::~PathFindingAI()
{

}
void PathFindingAI::Draw()
{
	ConsoleProgramScreenManager& screen = ConsoleProgramScreenManager::GetInstance();

	screen.ScreenPrinting(mCurrentPosition.mX * 2, mCurrentPosition.mY, mDrawText, 15);
	screen.ScreenFlipping();
	screen.ScreenPrinting(mCurrentPosition.mX * 2, mCurrentPosition.mY, mDrawText, 15);
}
void PathFindingAI::Update()
{
	mPathFindingAlgorithm->PathFinding(mCurrentPosition);
	mCurrentPosition = mPathFindingAlgorithm->GetNextPath();

	Draw();
}