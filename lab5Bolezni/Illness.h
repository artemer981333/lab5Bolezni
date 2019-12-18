#pragma once

#include <string>
#include <time.h>
using namespace std;

class Human;

class Illness
{
public:
	static Illness generate();

	Illness(double healChange = 1, double speedChange = 1, double infectP = 0, double cureP = 1);

	void affect(Human& human, double deltaT);
	void infectEffect(Human& human) const;
	void cureEffect(Human& human) const;
	double getInfectP() const;
	double getCureP() const;

	bool operator==(Illness other);

private:

	double m_healChange;
	double m_speedChange;
	double m_infectP;
	double m_cureP;
};

