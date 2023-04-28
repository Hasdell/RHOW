#pragma once

class IConsoleProgramBase;
class ConsoleProgramMainManager
{
public:
	ConsoleProgramMainManager(IConsoleProgramBase& consoleProgram, bool bprogramRuntimeCheck, int fps);
	~ConsoleProgramMainManager();
};

