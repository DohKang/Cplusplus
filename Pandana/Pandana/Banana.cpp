#include "stdafx.h"
#include "Banana.h"

/*
costructor
take texture, position info as parameter
set texture rect
*/
Banana::Banana(sf::Texture* texture, float posX, float posY)
{
	this->initVariables();
	this->shape.setTexture(*texture);
	this->shape.setPosition(posX, posY);
	this->currentFrame = sf::IntRect(0, 0, 50, 25);
	this->shape.setTextureRect(this->currentFrame);
}

Banana::~Banana()
{
}

/*
initiate variables
*/
void Banana::initVariables()
{
	this->direction = sf::Vector2f(0.f, -1.f);
	this->movementspeed = 5.f;
}

//set direction where bats are falling
void Banana::move()
{
	this->shape.move(this->movementspeed * this->direction);
}

//return banana boundary info
const sf::FloatRect Banana::getBounds() const
{
	return this->shape.getGlobalBounds();
}

/*
Animate banana's movement
*/
void Banana::updateAnimation()
{
	if (this->bananaAnimationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
	
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 50.f;
		if (this->currentFrame.left >= 450)
			this->currentFrame.left = 0;
		this->bananaAnimationTimer.restart();
		this->shape.setTextureRect(this->currentFrame);
		this->shape.setScale(1.f, 1.f);
	}
}

//update banana's vertical move
//update banana's animation
void Banana::update()
{
	this->move();
	this->updateAnimation();
}

//rendering
void Banana::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
