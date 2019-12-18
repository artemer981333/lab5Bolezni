#pragma once

#include "Field.h"

class Controller;

class Game
{
public:
	Game();
	Game(const char* configName);

	void startGame();						//������ ����
	void init(const char* configName);		//������������� ���������� ����� ������ ����������������� �����
	void endGame();							//��������� ����

	void update(double deltaT);			//���������� ����������

	const Field& getField();

	friend class Controller;

private:
	bool initialised;				//������ �� �������������
	bool isGame;					//���� �� ����
	Field m_field;					//����
};

