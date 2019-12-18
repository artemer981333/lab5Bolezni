#include "Human.h"
#include <iostream>

Human::Human(Position pos, double speed, double health, Illness ill)
	: MovingObject(pos, Direction(), speed)
{
	m_health = health;
	infect(ill);
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

bool Human::isIll(const Illness& ill) const
{
	return m_illnessesList.search(ill) > 0;
}

bool Human::isIll() const
{
	return m_illnessesList.amountElements() > 0;
}

void Human::update(double deltaT)
{
	move(deltaT);

	size_t numberIlls = m_illnessesList.amountElements();
	for (size_t i = 0; i < numberIlls; i++)
		m_illnessesList[i].affect(*this, deltaT);
}

void Human::infect(Illness ill)
{
	if (!isIll(ill))
	{
		ill.infectEffect(*this);
		m_illnessesList.addTail(ill);
	}
}

void Human::cureIll(size_t index)
{
	m_illnessesList.del(index).cureEffect(*this);
}

void Human::move(double deltaT)
{
	m_pos += m_dir.move(m_speed * deltaT);
}

void Human::setDirection(Direction dir)
{
	m_dir = dir;
}

void Human::changeSpeed(double speedKoef)
{
	if (speedKoef >= 0)
	{
		m_speed *= speedKoef;
		m_speed = (m_speed > HUMAN_MAX_SPEED) ? HUMAN_MAX_SPEED : m_speed;
	}
}

void Human::changeHealth(double health)
{
	m_health += health;
	m_health = (m_health > HUMAN_MAX_HP) ? HUMAN_MAX_HP : m_health;
	m_health = (m_health < 0) ? 0 : m_health;
}

const Human& Human::operator=(const Human& other)
{
	if (&other == this)
		return *this;
	m_pos = other.m_pos;
	m_dir = other.m_dir;
	m_speed = other.m_speed;
	m_health = other.m_health;
	m_illnessesList = other.m_illnessesList;
	return *this;
}
