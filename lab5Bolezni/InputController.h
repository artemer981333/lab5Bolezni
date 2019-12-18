#pragma once
#include "MovingObject.h"
//#include "Controller.h"

class Controller;

class InputController
{
public:
	InputController(Controller* pController = nullptr, MovingObject* controlledObject = nullptr);

	void handleInput(char key);
	void handleUpInput(char key);
	void handleInput(Position pos);
	const MovingObject* getControledObject();

private:

	void setControlledObject(MovingObject& human);
	void heal();
	void cure();

	MovingObject* m_controlledObject;
	Controller* m_controller;
};

