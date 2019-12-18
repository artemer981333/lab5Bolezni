#include "Viewport.h"
#include "glut.h"
#include "GL.H"
#include "GLU.H"
#include "Controller.h"
#include <typeinfo>
#include <iostream>

Viewport::Viewport(Controller* controller, Position pos, double speed, double width, double height)
	: MovingObject(pos, Direction(), speed)
{
	m_pos = pos;
	m_width = width;
	m_height = height;
	m_pixToMeter = WINDOW_WIDTH / m_width;
	m_controlller = controller;
}

double Viewport::getWidth() const
{
	return m_width;
}

double Viewport::getHeight() const
{
	return m_height;
}

void Viewport::move(double deltaT)
{
	m_pos += m_dir.move(m_speed * deltaT);
}

void Viewport::drawField(const Field& field) const
{
	//ג מעהוכüםûי לועמה
	//const Human* controlledHuman = m_controlller->getControlledHuman();
	//if (controlledHuman != nullptr)
	//	m_pos = controlledHuman->getPosition();

	Position border(m_width / 2, m_height / 2);
	DList<Human*> humans = field.getHumansInArea(m_pos - border, m_pos + border);

	glBegin(GL_POLYGON);
	{
		glColor3f(1, 0 ,0);
		glVertex2d(-FIELD_HEIGHT / 2 - m_pos.x, -FIELD_HEIGHT / 2 - m_pos.y);

		glColor3f(0, 1, 0);
		glVertex2d(-FIELD_WIDTH / 2 - m_pos.x, FIELD_HEIGHT / 2 - m_pos.y);

		glColor3f(0, 0, 1);
		glVertex2d(FIELD_WIDTH / 2 - m_pos.x, FIELD_HEIGHT / 2 - m_pos.y);

		glColor3f(0, 1, 1);
		glVertex2d(FIELD_WIDTH / 2 - m_pos.x, -FIELD_HEIGHT / 2 - m_pos.y);
	}
	glEnd();

	size_t numberOfHumans = humans.amountElements();

	for (size_t i = 0; i < numberOfHumans; i++)
		drawHuman(*humans[i]);
}

void Viewport::drawHuman(const Human& human) const
{
	Position posInViewport = human.getPosition() - m_pos;


	glTranslated(posInViewport.x, posInViewport.y, 0);
	if (typeid(human) == typeid(Doctor))
	{
		glColor3f(1 - ((Doctor*)(&human))->getPower() / (double)DOCTOR_STD_POWER, 0, ((Doctor*)(&human))->getPower() / (double)DOCTOR_STD_POWER);
		glTranslated(0, HUMAN_SIZE_R * 6, 0);
		glutSolidCube(HUMAN_SIZE_R);
		glTranslated(0, -HUMAN_SIZE_R * 6, 0);
		glColor3f(DOCTOR_COLOR);
	}
	else
		glColor3f(HUMAN_COLOR);
	glutSolidSphere(HUMAN_SIZE_R, 10, 10);

	double health = human.getHealth() / (double)HUMAN_MAX_HP;

	glColor3f(1 - health, health, 0);
	glTranslated(0, HUMAN_SIZE_R * 2, 0);
	glutSolidCube(HUMAN_SIZE_R);
	glTranslated(0, -HUMAN_SIZE_R * 2, 0);

	glColor3f(human.isIll(), 1 - human.isIll(), 0);
	glTranslated(0, HUMAN_SIZE_R * 4, 0);
	glutSolidCube(HUMAN_SIZE_R);
	glTranslated(0, -HUMAN_SIZE_R * 4, 0);


	glTranslated(-posInViewport.x, -posInViewport.y, 0);
}