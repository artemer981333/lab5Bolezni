#pragma once

#include "Position.h"
#include <cmath>

struct Direction
{
	double x, y;

	Direction(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	Position move(double deltaXY)
	{
		if (x == 0 && y == 0)
			return Position(0, 0);
		Position a;
		double len = sqrt(x * x + y * y);
		a.x = x * deltaXY / len;
		a.y = y * deltaXY / len;
		return a;
	}

	const Direction& operator + (const Direction& other)
	{
		return Direction(x + other.x, y + other.y);
	}

	const Direction& operator - (const Direction& other)
	{
		return Direction(x - other.x, y - other.y);
	}

	bool operator == (const Direction& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator != (const Direction& other)
	{
		return x != other.x || y != other.y;
	}
};