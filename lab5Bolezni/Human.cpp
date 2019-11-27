#include "Human.h"

Human::Human(Position pos, double speed, double health)
{
	m_pos = pos;
	m_speed = speed;
	m_health = health;
}

Position Human::getPosition() const
{
	return m_pos;
}

Direction Human::getDirection() const
{
	return Direction();
}

double Human::getSpeed() const
{
	return m_speed;
}

double Human::getHealth() const
{
	return m_health;
}

Illness Human::getIllness(size_t index) const
{
	return m_illnessesList[index];
}

size_t Human::getNumberOfIllness() const
{
	return m_illnessesList.amountElements();
}

bool Human::isIll(Illness ill) const
{
	return m_illnessesList.search(ill) >= 0;
}

void Human::update()
{
	m_pos += m_dir.move(m_speed);

	size_t numberIlls = m_illnessesList.amountElements();
	for (size_t i = 0; i < numberIlls; i++)
		m_illnessesList[i].effect(*this);
}

void Human::infect(Illness ill)
{
	if (!isIll(ill))
		m_illnessesList.addTail(ill);
}

void Human::cureIll(size_t index)
{
	m_illnessesList.del(index);
}

void Human::move(Position pos)
{
	m_pos = pos;
}

void Human::setDirection(Direction dir)
{
	m_dir = dir;
}

void Human::slow(double speedDown)
{
	if (speedDown >= 1)
	{
		m_speed /= speedDown;
		m_speed = (m_speed > HUMAN_MAX_SPEED) ? HUMAN_MAX_SPEED : m_speed;
	}
}

void Human::hast(double speedUp)
{
	if (speedUp <= 1 && speedUp > 0)
	{
		m_speed *= speedUp;
		m_speed = (m_speed > HUMAN_MAX_SPEED) ? HUMAN_MAX_SPEED : m_speed;
	}
}

void Human::heal(double health)
{
	m_health += health;
	m_health = (m_health > HUMAN_MAX_HP) ? HUMAN_MAX_HP : m_health;
}
