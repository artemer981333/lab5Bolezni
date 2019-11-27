#pragma once

#include "Viewport.h"
#include "Field.h"
//#include "Illness.h"

class Game
{
public:
	Game();
	Game(const char* configName);
	~Game();

	void startGame();					//начать игру
	void init(const char* configName);	//инициализация проводится путем чтения конфигурационного файла
	void endGame();						//закончить игру

	void draw();
	void update();

private:
	bool initialised;		//прошла ли инициализация
	bool isGame;			//идет ли игра
	Field m_field;			//поле
	Viewport m_viewport;	//область отрисовки
	Illness* m_illnesses;	//болезни
};

