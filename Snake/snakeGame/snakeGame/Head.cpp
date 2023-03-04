#include "stdafx.h"
#include "Head.h"

Head::Head(sf::Vector2f position, sf::Texture* texture)
	:Entity(position, texture)
{
	this->dir = RIGHT;

	this->counter = 0;

	this->tailTexture.loadFromFile("SXprites/tail.png");

	this->tail.push_back(new Tail(Entity::getPos(), texture));
}

Head::~Head()
{
	for (int i = 0; i < tail.size(); i++)
	{
		delete tail[i];
	}
}

void Head::draw(sf::RenderWindow* w)
{
	w->draw(Entity::getBody());
	for (int i = 0; i < tail.size(); i++)
	{
		w->draw(tail[i].Entity::getBody());
	}
}

void Head::update(double deltaT)
{
	Head::keyboardInput();
	
	if (counter >= 0.6)
	{
		if (this->dir == UP)
		{
			Entity::setPos(Entity::getPos() + sf::Vector2f(0.f, -Entity::getSize().y));
		}
		if (this->dir == RIGHT)
		{
			Entity::setPos(Entity::getPos() + sf::Vector2f(Entity::getSize().x, 0.f));
		}
		if (this->dir == DOWN)
		{
			Entity::setPos(Entity::getPos() + sf::Vector2f(0.f, Entity::getSize().y));
		}
		if (this->dir == LEFT)
		{
			Entity::setPos(Entity::getPos() + sf::Vector2f(-Entity::getSize().x, 0.f));
		}
		this->updateTails();
		counter = 0;
	}
	counter += deltaT;
}

void Head::keyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dir = UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir = DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dir = RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		dir = LEFT;
	}
}

void Head::growTial()
{
	if (this->tail.size() == 0)
	{
		this->tail.push_back(new Tail(Entity::getPos(), &this->tailTexture));
	}
	else
	{
		this->tail.push_back(new Tail(Entity::getPos(), &this->tailTexture));
	}
}

void Head::updateTails()
{
	for (int i = tail.size() - 1; i > 0; i--)
	{
		tail[i]->setPos(tail[i - 1]->getPos());
	}
	if (tail.size() >= 1)
	{
		tail[0]->setPos(Entity::getPos());
	}
}

bool Head::headToTail()
{
	if (this->tail.size() > 2)
	{
		for (int i = 1; i < this->tail.size(); i++)
		{
			if (Entity::getCollider().checkCollision(this->tail[i]->getCollider()) == true)
			{
				return true;
			}
		}
	}
	return false;
}
