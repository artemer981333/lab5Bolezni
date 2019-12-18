#include "Doctor.h"
#include <math.h>
#include <iostream>
#include <time.h>

Doctor::Doctor(Position pos, double speed, double health, double power, size_t level, size_t xp)
	: Human(pos, speed, health)
{
	m_power = power;
	m_level = level;
	m_xp = xp;
	m_cureDistance = DOCTOR_CURE_R;
	m_healDistance = DOCTOR_HEAL_R;
	m_cureP = DOCTOR_CURE_P;
}

void Doctor::cureHumans(DList<Human*> humans)
{
	if (m_level < DOCTOR_CURE_LEVEL || m_power < DOCTOR_POWER_FOR_CURE)
		return;

	size_t numOfHumans = humans.amountElements();

	srand(clock() * numOfHumans);
	for (size_t i = 0; i < numOfHumans; i++)
	{
		size_t numberOfIllness = humans[i]->getNumberOfIllness();
		for (size_t j = 0; j < numberOfIllness && m_power >= DOCTOR_POWER_FOR_CURE; j++)
			if (humans[i]->getIllness(j).getCureP() * m_cureP > rand() / (double)RAND_MAX)
			{
				humans[i]->cureIll(j);
				m_xp += DOCTOR_XP_FOR_CURE;
				m_power -= DOCTOR_POWER_FOR_CURE;
			}
	}
}

void Doctor::healHumans(DList<Human*> humans)
{
	if (m_power < DOCTOR_POWER_FOR_HEAL)
		return;

	size_t numOfHumans = humans.amountElements();

	for (size_t i = 0; i < numOfHumans && m_power >= DOCTOR_POWER_FOR_HEAL; i++)
	{
		humans[i]->changeHealth(DOCTOR_HEAL * log(m_level + 1));
		m_xp += DOCTOR_XP_FOR_HEAL;
		m_power -= DOCTOR_POWER_FOR_HEAL;
	}
}

void Doctor::checkLevelUP()
{
	if (m_xp >= DOCTOR_LEVELUP_XP * pow(DOCTOR_LEVELUP_COEF, m_level - 1))
	{
		m_level++;
		m_cureDistance *= DOCTOR_R_COEF;
		m_healDistance *= DOCTOR_R_COEF;
		m_cureP *= DOCTOR_P_COEF;
		std::cout << "Level up!" << std::endl;
	}
}

void Doctor::update(double deltaT)
{
	Human::update(deltaT);
	m_power += DOCTOR_POWER_UP * deltaT;
	m_power = (m_power > DOCTOR_STD_POWER) ? HUMAN_MAX_HP : m_power;
	m_power = (m_power < 0) ? 0 : m_power;

	checkLevelUP();
}

double Doctor::getCureDistance()
{
	return m_cureDistance;
}

double Doctor::getHealDistance()
{
	return m_healDistance;
}

size_t Doctor::getPower() const
{
	return m_power;
}
