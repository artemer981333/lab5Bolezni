#include "MovingObject.h"

MovingObject::MovingObject(Position pos, Direction dir, double speed)
{
	m_dir = dir;
	m_pos = pos;
	m_speed = speed;
}

void MovingObject::setDirection(Direction dir)
{
	m_dir = dir;
}

Position MovingObject::getPosition() const
{
	return m_pos;
}

Direction MovingObject::getDirection() const
{
	return m_dir;
}

double MovingObject::getSpeed() const
{
	return m_speed;
}
