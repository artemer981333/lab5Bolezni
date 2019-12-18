#pragma once

#include <cmath>
#include <random>

struct Position
{
	double x, y;

	static Position generate(double left, double right, double top, double bottom)
	{
		std::random_device rd;   // non-deterministic generator
		std::mt19937 gen(rd());  // to seed mersenne twister.
		std::uniform_int_distribution<> dist(1, RAND_MAX);

		Position pos;

		pos.x = dist(gen) / (double)RAND_MAX * (right - left) + left;
		pos.y = dist(gen) / (double)RAND_MAX * (top - bottom) + bottom;
		return pos;
	}

	Position(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	double distance(Position pos)
	{
		return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
	}

	bool operator <= (const Position& other)
	{
		return x <= other.x && y <= other.y;
	}

	bool operator >= (const Position& other)
	{
		return x >= other.x && y >= other.y;
	}

	bool operator < (const Position& other)
	{
		return x < other.x && y < other.y;
	}

	bool operator > (const Position& other)
	{
		return x > other.x && y > other.y;
	}

	Position operator * (double a) const
	{
		return Position(x * a, y * a);
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

