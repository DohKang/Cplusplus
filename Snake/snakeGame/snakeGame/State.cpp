#include "stdafx.h"
#include "State.h"

State::State()
{
	this->quit = false;
	this->holderScore = 0;
}

State::~State()
{
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->setQuit(true);
	}
}

void State::setQuit(bool newQuit)
{
	this->quit = newQuit;
}

bool State::getQuit() const
{
	return this->quit;
}

void State::setHolderScore(int newScore)
{
	this->holderScore = newScore;
}

int State::getHolderScore(int newScore)
{
	return this->holderScore;
}

bool State::switchState()
{
	return false;
}

