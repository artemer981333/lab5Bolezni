#pragma once

#include "Constants.h"
#include "Position.h"
#include "Direction.h"
#include "DualList.h"
#include "Illness.h"

class Human
{
public:
	Human(Position pos = Position(0, 0), double speed = HUMAN_STD_SPEED, double health = HUMAN_MAX_HP);

	Position getPosition() const;
	Direction getDirection() const;
	double getSpeed() const;
	double getHealth() const;
	Illness getIllness(size_t index) const;
	size_t getNumberOfIllness() const;
	bool isIll(Illness ill) const;

	void update();

	void infect(Illness ill);
	void cureIll(size_t index);

	void move(Position pos);
	void setDirection(Direction dir);
	void slow(double speedUp);
	void hast(double speedDown);
	void heal(double health);

protected:
	Position m_pos;
	Direction m_dir;
	double m_speed;
	double m_health;
	DList<Illness> m_illnessesList;
};

