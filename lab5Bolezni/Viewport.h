#pragma once

#include "Position.h"
#include "Field.h"
#include "Human.h"
#include "Doctor.h"
#include "MovingObject.h"

class Controller;

class Viewport
	: public MovingObject
{
public:
	Viewport(Controller* controller = nullptr, Position pos = Position(0, 0), double width = 0, double height = 0);

	double getWidth() const;
	double getHeight() const;

	virtual void move(double deltaT);

	void drawField(const Field& field) const;

private:
	void drawHuman(const Human& human) const;

	double m_width;
	double m_height;
	double m_pixToMeter;
	Controller* m_controlller;
};

