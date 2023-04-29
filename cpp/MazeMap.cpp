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
	ConsoleProgramScreenManager& Screen = ConsoleProgramScreenManager::GetInstance();

	for (int y = 0; y < Maze_Size_Y; y++)
	{
		for (int x = 0; x < Maze_Size_X; x++)
		{
			if (mMap[y][x])
			{
				lstrcpy(mDrawText, TEXT("бс"));
			}
			else
			{
				lstrcpy(mDrawText, TEXT(" "));
			}
			Screen.ScreenPrinting(x * 2, y, mDrawText, 15);
			Screen.ScreenFlipping();
			Screen.ScreenPrinting(x * 2, y, mDrawText, 15);
		}
	}
}