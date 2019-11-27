#pragma once

#include "Position.h"
#include <cmath>

struct Direction
{
	double x, y;

	Position move(double speed)
	{
		Position a;
		double len = sqrt(x * x + y * y);
		a.x = x * speed / len;
		a.y = y * speed / len;
		return a;
	}
};