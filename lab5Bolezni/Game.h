#pragma once

#include "Field.h"

class Controller;

class Game
{
public:
	Game();
	Game(const char* configName);

	void startGame();						//начать игру
	void init(const char* configName);		//инициализация проводится путем чтения конфигурационного файла
	void endGame();							//закончить игру

	void update(double deltaT);			//обновление параметров

	const Field& getField();

	friend class Controller;

private:
	bool initialised;				//прошла ли инициализация
	bool isGame;					//идет ли игра
	Field m_field;					//поле
};

