#pragma once
#include <time.h>

class ConsoleProgramTimerManager
{
public:
	static ConsoleProgramTimerManager& GetInstance();
public:
	inline void StartRunTimeCheck() { mStart = clock(); }
	inline void FinishRunTimeCheck() { mFinish = clock(); }

	inline double GetRunTime() { return (double)mFinish - mStart / CLOCKS_PER_SEC; }
private:
	clock_t mStart;
	clock_t mFinish;
};

