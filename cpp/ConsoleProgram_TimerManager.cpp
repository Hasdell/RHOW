#include "ConsoleProgram_TimerManager.h"

ConsoleProgramTimerManager& ConsoleProgramTimerManager::GetInstance()
{
	static ConsoleProgramTimerManager instance;

	return instance;
}