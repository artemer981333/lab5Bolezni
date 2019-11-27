#include "Viewport.h"

Viewport::Viewport(Position pos, double width, double height)
{
	m_pos = pos;
	m_width = width;
	m_height = height;
}

Position Viewport::getPosition() const
{
	return m_pos;
}

void Viewport::setPosition(const Position& pos)
{
	m_pos = pos;
}

void Viewport::drawField(const Field& field) const
{
	Position border(m_width / 2, m_height / 2);
	Human* humans = field.getHumansInArea(m_pos - border, m_pos + border);
	Doctor* doctors = field.getDoctorsInArea(m_pos - border, m_pos + border);


}

void Viewport::drawHuman(const Human& human) const
{
	Position posInViewport = m_pos - human.getPosition();

}

void Viewport::drawDoctor(const Doctor& human) const
{

}
