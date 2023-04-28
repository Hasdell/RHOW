#include "ConsoleProgram_InputManager.h"
#include <conio.h>

ConsoleProgramInputManager& ConsoleProgramInputManager::GetInstance()
{
	static ConsoleProgramInputManager instance;

	return instance;
}

ConsoleProgramInputManager::ConsoleProgramInputManager()
	: mInputKeycode(0),
	  mInputArrow(EArrowKey::NONE)
{

}

void ConsoleProgramInputManager::PickKeyboardInput()
{
	mInputKeycode = 0;
	mInputArrow = EArrowKey::NONE;

	if (_kbhit())
	{
		mInputKeycode = _getch();
	}

	if (mInputKeycode == 224)
	{
		mInputKeycode = _getch();

		switch (mInputKeycode)
		{
		case 72:
			mInputArrow = EArrowKey::UP;
			mInputKeycode = 0;
			break;
		case 80:
			mInputArrow = EArrowKey::DOWN;
			mInputKeycode = 0;
			break;
		case 75:
			mInputArrow = EArrowKey::LEFT;
			mInputKeycode = 0;
			break;
		case 77:
			mInputArrow = EArrowKey::RIGHT;
			mInputKeycode = 0;
			break;
		default:
			mInputArrow = EArrowKey::NONE;
			mInputKeycode = 0;
		}
	}
}