#pragma once
class Point
{
public:
	Point(int x, int y) : mX(x), mY(y) {}
	bool operator == (const Point& anotherPoint)
	{
		if (mX == anotherPoint.mX && mY == anotherPoint.mY)
			return true;
		return false;
	}

	int mX;
	int mY;
};

