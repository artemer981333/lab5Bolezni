#pragma once

#include "Game.h"
#include "Viewport.h"
#include "InputController.h"
#include <ctime>

class Controller
{

public:
	Controller(Game* game);

	void update();

	void draw();

	void inputKey(char key, bool pressed);	//��������� ������� ����������
	void inputMouse(int x, int y);			//�������� ������� ����

	const Human* getControlledHuman();
	const Field& getField();
	Viewport& getViewport();

private:
	Game* m_game;
	Viewport m_viewport;
	InputController m_inputController;

	clock_t m_lastUpdateTime;
};

