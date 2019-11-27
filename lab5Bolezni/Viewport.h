#pragma once

#include "Position.h"
#include "Field.h"
#include "Human.h"
#include "Doctor.h"
#include "glut.h"

class Viewport
{
public:
	Viewport(Position pos = Position(0, 0), double width = 0, double height = 0);

	Position getPosition() const;

	void setPosition(const Position& pos);

	void drawField(const Field& field) const;

private:
	void drawHuman(const Human& human) const;
	void drawDoctor(const Doctor& human) const;

	Position m_pos;
	double	m_width;
	double 	m_height;
};

