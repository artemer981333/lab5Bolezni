#pragma once

#include "Human.h"

class Doctor :
	public Human
{
public:

	Doctor(Position pos = Position(), double speed = HUMAN_STD_SPEED, double health = HUMAN_MAX_HP, size_t power = DOCTOR_STD_POWER, size_t level = DOCTOR_STD_LEVEL, size_t xp = DOCTOR_STD_XP);

	void cureHumans(Human* humanArray, size_t numOfHuman);
	void healHumans(Human* humanArray, size_t numOfHuman);
	void levelUP();

	void update();

private:
	size_t m_power;
	size_t m_level;
	size_t m_xp;
};

