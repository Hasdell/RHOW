#include "ConsoleProgram_MainManager.h"
#include "MazePathFindingProgram.h"

int main()
{
	ConsoleProgramMainManager CM(MazePathFindingProgram::GetInstance(), false, 144);
}