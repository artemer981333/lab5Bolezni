#pragma once

#include <string>
#include <time.h>
using namespace std;

class Human;

class Illness
{
public:
	Illness(string name = "Illness", double healChange = 1, double speedChange = 1, double infectP = 0, double cureP = 1, Illness* efectIll = nullptr, clock_t efectIllTime = 0);

	void effect(Human& human) const;
	void infectEffect(Human& human) const;
	void cureEffect(Human& human) const;
	double getInfectP() const;
	double getCureP() const;

	bool operator==(Illness other);

private:
	clock_t m_lastEffectTime;
	clock_t m_infectTime;

	string m_name;
	double m_healChange;
	double m_speedChange;
	Illness* m_efectIll;
	clock_t m_efectIllTime;
	double m_infectP;
	double m_cureP;
};

