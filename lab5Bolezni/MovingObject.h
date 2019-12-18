#pragma once
#include "Position.h"
#include "Direction.h"

class MovingObject
{
public:

	MovingObject(Position pos = Position(), Direction dir = Direction(), double speed = 0);

	virtual void move(double deltaT) = 0;

	void setDirection(Direction dir);

	Position getPosition() const;
	Direction getDirection() const;
	double getSpeed() const;

protected:
	Position m_pos;
	Direction m_dir;
	double m_speed;
};

