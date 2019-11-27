#pragma once

#include "Human.h"
#include "Doctor.h"

class Field
{
public:
	Field(size_t numberOfHumans = 0, size_t numberOfDoctors = 0, double width = 0, double height = 0);

	void update();

	Human* getHumansInArea(Position a, Position b) const;
	Doctor* getDoctorsInArea(Position a, Position b) const;

private:

	Human* m_humans;
	Doctor* m_doctors;

	double	m_width;
	double	m_height;

};

