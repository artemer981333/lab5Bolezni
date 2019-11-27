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

	void startGame();					//������ ����
	void init(const char* configName);	//������������� ���������� ����� ������ ����������������� �����
	void endGame();						//��������� ����

	void draw();
	void update();

private:
	bool initialised;		//������ �� �������������
	bool isGame;			//���� �� ����
	Field m_field;			//����
	Viewport m_viewport;	//������� ���������
	Illness* m_illnesses;	//�������
};

