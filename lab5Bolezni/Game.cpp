#include "Game.h"

Game::Game()
{
	initialised = false;
	isGame = false;
}

Game::Game(const char* configName)
{
	isGame = false;
	init(configName);
}

void Game::startGame()
{
	if (!initialised)
		return;

	isGame = true;
}

void Game::init(const char* configName)
{
	m_field = Field(10, FIELD_WIDTH, FIELD_HEIGHT);

	initialised = true;
}

void Game::endGame()
{
	isGame = false;
}

void Game::update(double deltaT)
{
	m_field.update(deltaT);
}

const Field& Game::getField()
{
	return m_field;
}
