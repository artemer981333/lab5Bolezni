#include "InputController.h"
#include "Controller.h"
#include "Constants.h"
#include "glut.h"
#include <typeinfo>

InputController::InputController(Controller* pController, MovingObject* controlledObject)
{
	m_controlledObject = controlledObject;
	m_controller = pController;
}

void InputController::setControlledObject(MovingObject& object)
{
	m_controlledObject = &object;
}

void InputController::handleInput(char key)
{
	if (m_controlledObject == nullptr)
		return;

	switch (key)
	{
	case 'w':case 'W':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() + Direction(0, 1));
		break;
	}
	case 'a':case 'A':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() + Direction(-1, 0));
		break;
	}
	case 's':case 'S':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() + Direction(0, -1));
		break;
	}
	case 'd':case 'D':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() + Direction(1, 0));
		break;
	}
	case 'q':case 'Q':
	{
		cure();
		break;
	}
	case 'e':case 'E':
	{
		heal();
		break;
	}
	}
}

void InputController::handleUpInput(char key)
{
	if (m_controlledObject == nullptr)
		return;

	switch (key)
	{
	case 'w':case 'W':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() - Direction(0, 1));
		break;
	}
	case 'a':case 'A':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() - Direction(-1, 0));
		break;
	}
	case 's':case 'S':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() - Direction(0, -1));
		break;
	}
	case 'd':case 'D':
	{
		m_controlledObject->setDirection(m_controlledObject->getDirection() - Direction(1, 0));
		break;
	}
	case 'q':case 'Q':
	{
		cure();
		break;
	}
	case 'e':case 'E':
	{
		heal();
		break;
	}
	}
}

void InputController::handleInput(Position pos)
{
	DList<Human*> humans = m_controller->getField().getHumansInArea(pos, HUMAN_SIZE_R);
	if (humans.amountElements() == 0)
	{
		Viewport* viewport = &m_controller->getViewport();
		if (m_controlledObject != nullptr && m_controlledObject != viewport)
		{
			viewport->setDirection(m_controlledObject->getDirection());
			m_controlledObject->setDirection(Direction(0, 0));
		}
		m_controlledObject = viewport;
		return;
	}

	if (m_controlledObject != humans[0] && m_controlledObject != nullptr)
	{
		humans[0]->setDirection(m_controlledObject->getDirection());
		m_controlledObject->setDirection(Direction(0, 0));
	}

	m_controlledObject = humans[0];
}

const MovingObject* InputController::getControledObject()
{
	return m_controlledObject;
}

void InputController::heal()
{
	if (typeid(*m_controlledObject) == typeid(Doctor))
		((Doctor*)m_controlledObject)->healHumans(m_controller->getField().getHumansInArea(m_controlledObject->getPosition(), DOCTOR_HEAL_R));
}

void InputController::cure()
{
	if (typeid(*m_controlledObject) == typeid(Doctor))
		((Doctor*)m_controlledObject)->cureHumans(m_controller->getField().getHumansInArea(m_controlledObject->getPosition(), DOCTOR_CURE_R));
}
