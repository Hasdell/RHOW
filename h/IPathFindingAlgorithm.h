#pragma once
#include "Point.h"
#include "MazeProgramDefineHeader.h"

interface IPathFindingAlgorithm
{
public:
	virtual void PathFinding(const Point& currentPosition) = 0;
	virtual const Point& GetNextPath() = 0;
};

