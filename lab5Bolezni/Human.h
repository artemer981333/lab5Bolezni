#pragma once

#include "Constants.h"
#include "Position.h"
#include "Direction.h"
#include "DualList.h"
#include "Illness.h"
#include "MovingObject.h"
#include <time.h>

class Human
	: public MovingObject
{
public:
	Human(Position pos = Position(), double speed = HUMAN_STD_SPEED, double health = HUMAN_MAX_HP, Illness ill = Illness::generate());

	double getHealth() const;
	Illness getIllness(size_t index) const;
	size_t getNumberOfIllness() const;
	bool isIll(const Illness& ill) const;
	bool isIll() const;

	virtual void update(double deltaT);

	void infect(Illness ill);
	void cureIll(size_t index);

	void move(double DeltaT);
	void setDirection(Direction dir);
	void changeSpeed(double speedKoef);
	void changeHealth(double health);

	const Human& operator = (const Human& other);

protected:
	double m_health;
	DList<Illness> m_illnessesList;
};

