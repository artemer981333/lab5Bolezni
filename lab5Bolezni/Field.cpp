#include "Field.h"
#include <time.h>
#include <random>
#include <iostream>
#include <typeinfo>

Field::Field(size_t numberOfHumans, double width, double height, double partOfDoctors)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, RAND_MAX);

	for (size_t i = 0; i < numberOfHumans; i++)
	{
		Position pos = Position::generate(-width / 2, width / 2, height / 2, -height / 2);
		if (distribution(generator) / (double)RAND_MAX >= partOfDoctors)
			m_humans.addTail(new Human(pos, HUMAN_STD_SPEED, HUMAN_MAX_HP));
		else
			m_humans.addTail(new Doctor(pos, HUMAN_STD_SPEED, HUMAN_MAX_HP));
		std::cout << typeid(*(m_humans[i])).name() << std::endl;
	}

	m_height = height;
	m_width = width;
}

Field::Field(const Field& other)
{
	*this = other;
}

void Field::update(double deltaT)
{
	size_t numberOfHumans = m_humans.amountElements();
	for (size_t i = 0; i < numberOfHumans; i++)
	{
		m_humans[i]->update(deltaT);
		if (m_humans[i]->getHealth() == 0)
		{
			m_humans.del(i);
			numberOfHumans--;
			i--;
		}
	}
}

DList<Human*> Field::getHumansInArea(Position a, Position b) const
{
	DList<Human*> humans;

	size_t numberOfHumans = m_humans.amountElements();

	for (size_t i = 0; i < numberOfHumans; i++)
		if (m_humans[i]->getPosition() >= a && m_humans[i]->getPosition() <= b)
			humans.addTail(m_humans[i]);

	return humans;
}

DList<Human*> Field::getHumansInArea(Position a, double R) const
{
	DList<Human*> humans;

	size_t numberOfHumans = m_humans.amountElements();

	for (size_t i = 0; i < numberOfHumans; i++)
		if (m_humans[i]->getPosition().distance(a) <= R)
			humans.addTail(m_humans[i]);

	return humans;
}

const Field& Field::operator=(const Field& other)
{
	m_height = other.m_height;
	m_width = other.m_width;

	size_t numberOfHumans = other.m_humans.amountElements();
	for (size_t i = 0; i < numberOfHumans; i++)
	{
		if (typeid(*(other.m_humans[i])) == typeid(Human))
			m_humans.addTail(new Human);
		else
			m_humans.addTail(new Doctor);
		*(m_humans[i]) = *(other.m_humans[i]);
	}

	return *this;
}
