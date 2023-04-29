#include "ConsoleProgram_MainManager.h"
#include "ConsoleProgram_TimerManager.h"
#include "ConsoleProgram_ScreenManager.h"
#include <iostream>
#include "IConsoleProgramBase.h"


ConsoleProgramMainManager::ConsoleProgramMainManager(IConsoleProgramBase& consoleProgram, const bool bprogramRuntimeCheck, const int fps)
{
	ConsoleProgramTimerManager& Timer = ConsoleProgramTimerManager::GetInstance();
	ConsoleProgramScreenManager& Screen = ConsoleProgramScreenManager::GetInstance();

	if (bprogramRuntimeCheck)
	{
		Timer.StartRunTimeCheck();
	}

	Screen.SetFramePerSecond(fps);

	consoleProgram.SetRuntimeCheck(bprogramRuntimeCheck);
	consoleProgram.ProgramStart();
}
ConsoleProgramMainManager::~ConsoleProgramMainManager()
{

}

/*
void ConsoleProgramMainManager::ProgramUpdate_Fps(IConsoleProgramBase& consoleProgram)
{
	ConsoleProgramScreenManager& screen = ConsoleProgramScreenManager::GetInstance();

	clock_t currentTime = 0;
	clock_t oldTime = clock();

	currentTime = clock();

	int fps = screen.GetFramePerSecond();

	while (!mbProgramEnd)
	{
		if (currentTime >= oldTime + 1000.f / fps)
		{
			consoleProgram.Update();
			oldTime = currentTime;
		}
	}
}
*/