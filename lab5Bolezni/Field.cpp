#include "Field.h"

Field::Field(size_t numberOfHumans, size_t numberOfDoctors, double width, double height)
{
	m_humans = new Human[numberOfHumans];
}

void Field::update()
{

}

Human* Field::getHumansInArea(Position a, Position b) const
{
	return nullptr;
}

Doctor* Field::getDoctorsInArea(Position a, Position b) const
{
	return nullptr;
}
