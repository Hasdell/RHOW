#include "RightHandOnWall.h"
#include "MazeMap.h"
#include "Point.h"

RightHandOnWall::RightHandOnWall() : mNextPath(0, 0), mNextPathDirection(1)
{

}
RightHandOnWall& RightHandOnWall::GetInstance()
{
	static RightHandOnWall instance;

	return instance;
}

void RightHandOnWall::PathFinding(const Point& currentPosition)
{
	int x = currentPosition.mX;
	int y = currentPosition.mY;

	TurnRight();
	while (WallAhead(x, y))
	{
		TurnLeft();
	}
	GoForward(x, y);
}
void RightHandOnWall::TurnRight()
{
	if (mNextPathDirection == (int)Direction::LEFT)
		mNextPathDirection = (int)Direction::UP;
	else
		mNextPathDirection <<= 1;
	mNextPathDirection = (mNextPathDirection == 0 ? (int)Direction::LEFT : mNextPathDirection);
}
bool RightHandOnWall::WallAhead(int x, int y)
{
	x = (mNextPathDirection == (int)Direction::LEFT ? --x :
		mNextPathDirection == (int)Direction::RIGHT ? ++x : x);
	y = (mNextPathDirection == (int)Direction::UP ? --y :
		mNextPathDirection == (int)Direction::DOWN ? ++y : y);

	return MazeMap::GetInstance().GetMapData(x, y);
}
void RightHandOnWall::TurnLeft()
{
	mNextPathDirection >>= 1;
	mNextPathDirection = (mNextPathDirection > (int)Direction::LEFT ? (int)Direction::UP : mNextPathDirection);
}
void RightHandOnWall::GoForward(int x, int y)
{
	x = (mNextPathDirection == (int)Direction::LEFT ? --x :
		mNextPathDirection == (int)Direction::RIGHT ? ++x : x);
	y = (mNextPathDirection == (int)Direction::UP ? --y :
		mNextPathDirection == (int)Direction::DOWN ? ++y : y);

	mNextPath.mX = x;
	mNextPath.mY = y;
}
const Point& RightHandOnWall::GetNextPath()
{
	return mNextPath;
}
const int& RightHandOnWall::GetNextPathDirection()
{
	return mNextPathDirection;
}