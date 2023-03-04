#include "stdafx.h"
#include "Game.h"
#include "State.h"

Game::Game():
	window(sf::VideoMode(800, 800), "snakeGame", sf::Style::Close)
{
	this->deltaT = 0;
	this->initStates();
	this->score = 0;
}



Game::~Game()
{
}

void Game::start()
{
	this->run();
}

void Game::run()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		this->deltaT = clock.restart().asSeconds(); //gets the speed of our specific computer
		sf::Event evnt;
		while (this->window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				this->window.close();
			}
		}
		this->window.clear();
		Game::update();
		Game::processStuff();
		Game::draw();

		this->window.display();
	}
}

void Game::update()
{

}

void Game::draw()
{
}
void Game::initStates()
{
}