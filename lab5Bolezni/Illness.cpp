#include "Illness.h"
#include "Human.h"
#include <random>

Illness Illness::generate()
{
	static std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, RAND_MAX);

	Illness ill;
	ill.m_cureP = distribution(generator) / (double)RAND_MAX;
	ill.m_healChange = distribution(generator) / (double)RAND_MAX * 10;
	ill.m_infectP = distribution(generator) / (double)RAND_MAX;
	ill.m_speedChange = distribution(generator) / (double)RAND_MAX;

	return ill;
}

Illness::Illness(double healChange, double speedChange, double infectP, double cureP)
{
	m_healChange = healChange;
	m_speedChange = speedChange;
	m_infectP = infectP;
	m_cureP = cureP;
}

void Illness::affect(Human& human, double deltaT)
{
	human.changeHealth(-m_healChange * deltaT);
}

void Illness::infectEffect(Human& human) const
{
	human.changeSpeed(m_speedChange);
}

void Illness::cureEffect(Human& human) const
{
	human.changeSpeed(1 / m_speedChange);
}

double Illness::getInfectP() const
{
	return m_infectP;
}

double Illness::getCureP() const
{
	return m_cureP;
}

bool Illness::operator==(Illness other)
{
	return 
		m_healChange == other.m_healChange && 
		m_speedChange == other.m_speedChange && 
		m_infectP == other.m_infectP && 
		m_cureP == other.m_cureP;
}
