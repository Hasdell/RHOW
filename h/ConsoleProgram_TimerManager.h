#pragma once
#include <time.h>
#include <Windows.h>
#include <tchar.h>

class ConsoleProgramTimerManager
{
public:
	static ConsoleProgramTimerManager& GetInstance();
public:
	inline void StartRunTimeCheck() { mStart = clock(); }
	inline void FinishRunTimeCheck() { mFinish = clock(); }

	inline double GetRunTime_Double() { return (double)mFinish - mStart / CLOCKS_PER_SEC; }
	TCHAR* GetRunTime_Text_Ms();
	TCHAR* GetRunTime_Text_Sec();
private:
	clock_t mStart;
	clock_t mFinish;

	TCHAR mRuntimeText[30];
};

