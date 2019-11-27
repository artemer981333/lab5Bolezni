#include "Doctor.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

Doctor::Doctor(Position pos, double speed, double health, size_t power, size_t level, size_t xp) : Human(pos, speed, health)
{
	m_power = power;
	m_level = level;
	m_xp = xp;
}

void Doctor::cureHumans(Human* humanArray, size_t numOfHuman)
{
	if (m_level < DOCTOR_CURE_LEVEL || m_power < DOCTOR_POWER_FOR_CURE)
		return;
	srand(clock() * numOfHuman);
	for (size_t i = 0; i < numOfHuman; i++)
	{
		double distance = m_pos.distance(humanArray[i].getPosition());
		if (distance <= DOCTOR_CURE_R * pow(DOCTOR_R_COEF, m_level - 1))
		{
			size_t numberOfIllness = humanArray[i].getNumberOfIllness();
			for (size_t j = 0; j < numberOfIllness && m_power >= DOCTOR_POWER_FOR_CURE; j++)
				if (humanArray[i].getIllness(i).getCureP() * DOCTOR_P * pow(DOCTOR_P_COEF, m_level - 1) > rand() / (double)RAND_MAX)
				{
					humanArray[i].cureIll(j);
					m_power -= DOCTOR_POWER_FOR_CURE;
					m_xp += DOCTOR_XP_FOR_CURE / humanArray[i].getIllness(i).getCureP();
				}
		}
	}
}

void Doctor::healHumans(Human* humanArray, size_t numOfHuman)
{
	if (m_power < DOCTOR_POWER_FOR_HEAL)
		return;
	srand(clock() * numOfHuman);
	for (size_t i = 0; i < numOfHuman && m_power >= DOCTOR_POWER_FOR_HEAL; i++)
	{
		double distance = m_pos.distance(humanArray[i].getPosition());
		if (distance <= DOCTOR_HEAL_R * pow(DOCTOR_R_COEF, m_level - 1))
			humanArray[i].heal(humanArray[i].getHealth() + DOCTOR_HEAL * log(m_level));
	}
}

void Doctor::levelUP()
{
	if (m_xp >= DOCTOR_LEVELUP_XP * pow(DOCTOR_LEVELUP_COEF, m_level - 1))
		m_level++;
}

void Doctor::update()
{
}
