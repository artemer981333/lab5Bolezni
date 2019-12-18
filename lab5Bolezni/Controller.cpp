#include "Controller.h"
#include "Game.h"
#include "Viewport.h"
#include "InputController.h"
#include "glut.h"
#include <typeinfo>

Controller::Controller(Game* game)
{
	m_game = game;
	m_lastUpdateTime = clock();

	m_viewport = Viewport(this, Position(0, 0), 10, VIEWPORT_STD_WIDTH, VIEWPORT_STD_HEIGHT);
	m_inputController = InputController(this, &m_viewport);
}

void Controller::update()
{
	clock_t dT = clock() - m_lastUpdateTime;
	m_lastUpdateTime += dT;
	double deltaT = dT / 1000.;

	m_viewport.move(deltaT);
	m_game->update(deltaT);
}

void Controller::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	m_viewport.drawField(m_game->m_field);

	glutSwapBuffers();
	glFlush();
}

void Controller::inputKey(char key, bool pressed)
{
	if (pressed)
		m_inputController.handleInput(key);
	else
		m_inputController.handleUpInput(key);
}

void Controller::inputMouse(int x, int y)
{
	Position mousePos(x * 2 / (double)WINDOW_WIDTH, y * 2 / (double)WINDOW_HEIGHT);

	mousePos.x *= m_viewport.getWidth() / 2;
	mousePos.y *= m_viewport.getHeight() / 2;

	mousePos += m_viewport.getPosition();

	m_inputController.handleInput(mousePos);
}

const Human* Controller::getControlledHuman()
{
	const MovingObject* controlledObject = m_inputController.getControledObject();
	if (typeid(*controlledObject) == typeid(Human) || typeid(*controlledObject) == typeid(Doctor))
		return (Human*)controlledObject;
	else
		return nullptr;
}

const Field& Controller::getField()
{
	return m_game->getField();
}

Viewport& Controller::getViewport()
{
	return m_viewport;
}
