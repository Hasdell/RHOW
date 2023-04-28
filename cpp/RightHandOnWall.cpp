#include "RightHandOnWall.h"
#include "MazeMap.h"
#include "Point.h"

RightHandOnWall::RightHandOnWall() : mNextPath(0, 0), currentDirection(1)
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
	if (currentDirection == (int)Direction::LEFT)
		currentDirection = (int)Direction::UP;
	else
		currentDirection <<= 1;
	currentDirection = (currentDirection == 0 ? (int)Direction::LEFT : currentDirection);
}
bool RightHandOnWall::WallAhead(int x, int y)
{
	x = (currentDirection == (int)Direction::LEFT ? --x :
		currentDirection == (int)Direction::RIGHT ? ++x : x);
	y = (currentDirection == (int)Direction::UP ? --y :
		currentDirection == (int)Direction::DOWN ? ++y : y);

	return MazeMap::GetInstance().GetMapData(x, y);
}
void RightHandOnWall::TurnLeft()
{
	currentDirection >>= 1;
	currentDirection = (currentDirection > (int)Direction::LEFT ? (int)Direction::UP : currentDirection);
}
void RightHandOnWall::GoForward(int x, int y)
{
	x = (currentDirection == (int)Direction::LEFT ? --x :
		currentDirection == (int)Direction::RIGHT ? ++x : x);
	y = (currentDirection == (int)Direction::UP ? --y :
		currentDirection == (int)Direction::DOWN ? ++y : y);

	mNextPath.mX = x;
	mNextPath.mY = y;
}
const Point& RightHandOnWall::GetNextPath()
{
	return mNextPath;
}