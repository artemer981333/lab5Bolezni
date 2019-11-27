#include "Game.h"

Game::Game()
{
	initialised = false;
	isGame = false;
	m_illnesses = nullptr;
}

Game::Game(const char* configName)
{
	isGame = false;
	init(configName);
}

Game::~Game()
{
	delete[] m_illnesses;
}

void Game::startGame()
{
	if (!initialised)
		return;

	isGame = true;
}

void Game::init(const char* configName)
{
	m_field = Field(1, 1, FIELD_WIDTH, FIELD_HEIGHT);
	m_viewport = Viewport(Position(0, 0), VIEWPORT_STD_WIDTH, VIEWPORT_STD_HEIGHT);

	initialised = true;
}

void Game::endGame()
{
	isGame = false;
}

void Game::draw()
{
}

void Game::update()
{
	m_field.update();
}
