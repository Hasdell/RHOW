#pragma once
#include <Windows.h>
#include "Point.h"
#include "IPathFindingAlgorithm.h"

class PathFindingAI
{
public:
	PathFindingAI();
	~PathFindingAI();

	static PathFindingAI& GetInstance();
public:
	void Draw();
	void Update();
public:
	inline void SetPathFindingAlgorithm(IPathFindingAlgorithm& pathFindingAlgorithm) { mPathFindingAlgorithm = &pathFindingAlgorithm; }
	inline void SetPosition(Point newPosition) { mCurrentPosition = newPosition; }

	inline const Point& GetPosition() { return mCurrentPosition; }
private:
	Point mCurrentPosition;
	IPathFindingAlgorithm* mPathFindingAlgorithm;
	TCHAR mDrawText[2];
};

