#pragma once

#define Maze_Size_Y 10
#define Maze_Size_X 20

#define AI_Update_Cycle 100

enum class MazeData
{
	EMPTY, WALL
};
enum class Direction
{
	UP = 1, RIGHT = 2, DOWN = 4, LEFT = 8
};