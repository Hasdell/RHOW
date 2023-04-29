#pragma once

class IConsoleProgramBase;
class ConsoleProgramMainManager
{
public:
	ConsoleProgramMainManager(IConsoleProgramBase& consoleProgram, const bool bprogramRuntimeCheck, const int fps);
	~ConsoleProgramMainManager();
};

