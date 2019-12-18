#pragma once

#include "Human.h"
#include "Doctor.h"

class Field
{
public:
	Field(size_t numberOfHumans = 0, double width = 0, double height = 0, double partOfDoctors = 0.3);
	Field(const Field& other);

	void update(double deltaT);

	DList<Human*> getHumansInArea(Position a, Position b) const;
	DList<Human*> getHumansInArea(Position a, double R) const;

	const Field& operator = (const Field& other);

private:

	DList<Human*> m_humans;

	double	m_width;
	double	m_height;
};

