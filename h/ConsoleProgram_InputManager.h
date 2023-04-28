#pragma once
#include <Windows.h>

enum class EArrowKey : UINT8
{
	NONE, UP, DOWN, LEFT, RIGHT
};
class ConsoleProgramInputManager
{
public:
	ConsoleProgramInputManager();
	static ConsoleProgramInputManager& GetInstance();
public:
	void PickKeyboardInput();
public:
	inline UINT8 GetInputKeyCode() const { return mInputKeycode; }
	inline EArrowKey GetInputArrow() const { return mInputArrow; }
private:
	UINT8 mInputKeycode;
	EArrowKey mInputArrow;
};

