#pragma once
#include "Point.h"
#include "MazeProgramDefineHeader.h"

enum class Direction;
class IPathFindingAlgorithm
{
public:
	virtual void PathFinding(const Point& currentPosition) = 0;
	virtual const Point& GetNextPath() = 0;
	virtual const int& GetNextPathDirection() = 0;
};

