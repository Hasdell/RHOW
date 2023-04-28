#include "MazeMap.h"
#include "MazeProgramDefineHeader.h"
#include "ConsoleProgram_ScreenManager.h"

MazeMap& MazeMap::GetInstance()
{
	static MazeMap instance;
	
	return instance;
}

MazeMap::MazeMap() : mExitPoint(0, 1)
{

}

void MazeMap::Draw()
{
	ConsoleProgramScreenManager& screen = ConsoleProgramScreenManager::GetInstance();

	for (int y = 0; y < Maze_Size / 2; y++)
	{
		for (int x = 0; x < Maze_Size; x++)
		{
			if (mMap[y][x])
			{
				lstrcpy(mDrawText, TEXT("бс"));
			}
			else
			{
				lstrcpy(mDrawText, TEXT(" "));
			}
			screen.ScreenPrinting(x * 2, y, mDrawText, 15);
		}
	}
}