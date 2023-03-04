#include "stdafx.h"
#include "bat.h"

Bat::Bat()
{
	this->initVariables();
	this->initTexture();
}

Bat::~Bat()
{
}

void Bat::initVariables()
{
	this->point = 10;
	this->movementSpeed = 2.f;
	this->dmg = 5;
	
}

void Bat::initTexture()
{
	this->texture.loadFromFile("Texture/bat.png");
	this->shape.setTexture(this->texture);
	this->shape.setPosition(rand() & 700 + 20, -20.f);
	this->currentFrame = sf::IntRect(0, 0, 70, 70);
	this->shape.setTextureRect(this->currentFrame);
}

const sf::FloatRect Bat::getBounds() const
{
	return this->shape.getGlobalBounds();
}

int Bat::getPoints()
{
	return this->point;
}



int Bat::getDamage()
{
	return this->dmg;
}

void Bat::updateAnimation()
{
	if (this->batAnimationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
	
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 70.f;
		if (currentFrame.left > 280)
			currentFrame.left = 0;
		this->batAnimationTimer.restart();
		this->shape.setTextureRect(this->currentFrame);
		this->shape.setScale(1.f, 1.f);
	}

}

void Bat::updateMove()
{
	this->shape.move(-.2f * movementSpeed, 2.f * movementSpeed);;
}

void Bat::update()
{
	this->updateMove();
	this->updateAnimation();
}

void Bat::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
