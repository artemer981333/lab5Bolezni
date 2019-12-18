#pragma once

#include "Human.h"

class Doctor :
	public Human
{
public:

	Doctor(Position pos = Position(1, 1), double speed = HUMAN_STD_SPEED, double health = HUMAN_MAX_HP, double power = DOCTOR_STD_POWER, size_t level = DOCTOR_STD_LEVEL, size_t xp = DOCTOR_STD_XP);

	virtual void cureHumans(DList<Human*> humans);
	virtual void healHumans(DList<Human*> humans);
	virtual void checkLevelUP();

	virtual void update(double deltaT);

	virtual double getCureDistance();
	virtual double getHealDistance();

	size_t getPower() const;

private:
	double m_power;
	size_t m_level;
	size_t m_xp;

	double m_cureDistance;
	double m_healDistance;
	double m_cureP;
};

