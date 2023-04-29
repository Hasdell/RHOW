#pragma once
#include "IPathFindingAlgorithm.h"

class RightHandOnWall : public IPathFindingAlgorithm
{
public:
	RightHandOnWall();

	static RightHandOnWall& GetInstance();
public:
	void PathFinding(const Point& currentPosition);
	const Point& GetNextPath();
	const int& GetNextPathDirection();
public:
	void TurnRight();
	bool WallAhead(int x, int y);
	void TurnLeft();
	inline void GoForward(int x, int y);
private:
	Point mNextPath;
	int mNextPathDirection;
};

