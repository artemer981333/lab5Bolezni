#pragma once

#include <cmath>

struct Position
{
	double x, y;

	Position(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	double distance(Position pos)
	{
		return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
	}

	const Position& operator += (const Position& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	const Position& operator -= (const Position& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Position operator + (const Position& other) const
	{
		return Position(x + other.x, y + other.y);
	}

	Position operator - (const Position& other) const
	{
		return Position(x - other.x, y - other.y);
	}
};

