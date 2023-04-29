#include "ConsoleProgram_TimerManager.h"

ConsoleProgramTimerManager& ConsoleProgramTimerManager::GetInstance()
{
	static ConsoleProgramTimerManager instance;

	return instance;
}

TCHAR* ConsoleProgramTimerManager::GetRunTime_Text_Ms()
{
	double ms = GetRunTime_Double();

	_stprintf_s(mRuntimeText, L"�ҿ�� �ð� : %.lfms", ms);

	return mRuntimeText;
}
TCHAR* ConsoleProgramTimerManager::GetRunTime_Text_Sec()
{
	double sec = GetRunTime_Double() / 1000.f;

	_stprintf_s(mRuntimeText, L"�ҿ�� �ð� : %.2lf��", sec);

	return mRuntimeText;
}