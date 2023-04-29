#pragma once
class Point
{
public:
	Point(int x, int y) : mX(x), mY(y) {}
	friend bool operator == (const Point& point1, const Point& point2)
	{
		if (point1.mX == point2.mX && point1.mY == point2.mY)
			return true;
		return false;
	}

	int mX;
	int mY;
};

