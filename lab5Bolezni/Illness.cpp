#include "Illness.h"
#include "Human.h"

Illness::Illness(string name, double healChange, double speedChange, double infectP, double cureP, Illness* efectIll, clock_t efectIllTime)
{
	m_name = name;
	m_healChange = healChange;
	m_speedChange = speedChange;
	m_infectP = infectP;
	m_cureP = cureP;
	m_efectIll = efectIll;
	m_efectIllTime = efectIllTime;
}

void Illness::effect(Human& human) const
{
	human.heal(m_healChange * (clock() - m_lastEffectTime));
	if (m_efectIll != nullptr && clock() - m_infectTime >= m_efectIllTime)
		human.infect(*m_efectIll);
}

void Illness::infectEffect(Human& human) const
{
	human.slow(m_speedChange);
}

void Illness::cureEffect(Human& human) const
{
	human.hast(m_speedChange);
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
		m_efectIll == other.m_efectIll && 
		m_efectIllTime == other.m_efectIllTime && 
		m_infectP == other.m_infectP && 
		m_cureP == other.m_cureP;
}
