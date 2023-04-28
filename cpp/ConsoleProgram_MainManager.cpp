#include "ConsoleProgram_MainManager.h"
#include "ConsoleProgram_TimerManager.h"
#include "ConsoleProgram_ScreenManager.h"
#include <iostream>
#include "IConsoleProgramBase.h"


ConsoleProgramMainManager::ConsoleProgramMainManager(IConsoleProgramBase& consoleProgram, bool bprogramRuntimeCheck, int fps)
{
	ConsoleProgramTimerManager& Timer = ConsoleProgramTimerManager::GetInstance();
	ConsoleProgramScreenManager& Screen = ConsoleProgramScreenManager::GetInstance();

	if (bprogramRuntimeCheck)
		Timer.StartRunTimeCheck();

	Screen.SetFramePerSecond(fps);

	consoleProgram.ProgramStart();

	if (bprogramRuntimeCheck)
	{
		Timer.FinishRunTimeCheck();
		std::cout << Timer.GetRunTime();
	}
}
ConsoleProgramMainManager::~ConsoleProgramMainManager()
{

}