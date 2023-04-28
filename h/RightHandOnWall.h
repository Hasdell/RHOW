#pragma once
#include "IPathFindingAlgorithm.h"

enum class Direction
{
	UP = 1, RIGHT = 2, DOWN = 4, LEFT = 8
};
class RightHandOnWall : public IPathFindingAlgorithm
{
public:
	RightHandOnWall();

	static RightHandOnWall& GetInstance();
public:
	void PathFinding(const Point& currentPosition);
	const Point& GetNextPath();
public:
	void TurnRight();
	bool WallAhead(int x, int y);
	void TurnLeft();
	inline void GoForward(int x, int y);
private:
	Point mNextPath;
	int currentDirection;
	int PathFindingCount;
};

