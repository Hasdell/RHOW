#include <iostream>
#include <tchar.h>
#include "ConsoleProgram_ScreenManager.h"

ConsoleProgramScreenManager& ConsoleProgramScreenManager::GetInstance()
{
	static ConsoleProgramScreenManager instance;

	return instance;
}

ConsoleProgramScreenManager::ConsoleProgramScreenManager()
:   mScreenBufferIndex(0),
	mWidth(80),
	mHeight(25),
	mScreenFramePerSecond(60)
{
	mScreenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	mScreenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

	CONSOLE_CURSOR_INFO cursor;

	cursor.bVisible = false;
	cursor.dwSize = 1;

	SetConsoleCursorInfo(mScreenBuffer[0], &cursor);
	SetConsoleCursorInfo(mScreenBuffer[1], &cursor);
}

ConsoleProgramScreenManager::~ConsoleProgramScreenManager()
{
	CloseHandle(mScreenBuffer[0]);
	CloseHandle(mScreenBuffer[1]);
}

void ConsoleProgramScreenManager::ScreenClearing()
{
	DWORD dw;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	FillConsoleOutputCharacter(mScreenBuffer[mScreenBufferIndex], ' ', columns * rows, { 0, 0 }, &dw);
}

void ConsoleProgramScreenManager::ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(mScreenBuffer[mScreenBufferIndex]);
	mScreenBufferIndex = !mScreenBufferIndex;
}

void ConsoleProgramScreenManager::ScreenPrinting(UINT8 x, UINT8 y, TCHAR* print, int color)
{
	DWORD dw;
	COORD cursorPosition = { x, y };

	SetConsoleCursorPosition(mScreenBuffer[mScreenBufferIndex], cursorPosition);
	SetConsoleTextAttribute(mScreenBuffer[mScreenBufferIndex], color);

#ifdef _UNICODE
	WriteConsole(mScreenBuffer[mScreenBufferIndex], print, _tcslen(print), &dw, NULL);
#else
	WriteConsole(mScreenBuffer[mScreenBufferIndex], print, _tcslen(print), &dw, NULL);
#endif

	SetConsoleTextAttribute(mScreenBuffer[mScreenBufferIndex], 15);
}