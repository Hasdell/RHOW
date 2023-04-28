#pragma once
#include <Windows.h>
class ConsoleProgramScreenManager
{
public:
	ConsoleProgramScreenManager();
	~ConsoleProgramScreenManager();
	static ConsoleProgramScreenManager& GetInstance();
public:
	void ScreenClearing();
	void ScreenFlipping();
	void ScreenPrinting(UINT8 x, UINT8 y, TCHAR* print, int color);
public:
	inline void SetFramePerSecond(int fps) { mScreenFramePerSecond = fps; }
	inline int GetFramePerSecond() const { return mScreenFramePerSecond; }
private:
	HANDLE mScreenBuffer[2];
	UINT8 mScreenBufferIndex;

	UINT8 mScreenFramePerSecond;

	UINT8 mWidth;
	UINT8 mHeight;
};

