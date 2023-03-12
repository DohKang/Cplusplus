#include "stdafx.h"
#include "Bullet.h"


/*
Constructor
initialize bullet sprite, and various variables
*/
Bullet::Bullet(sf::Texture* texture, sf::Vector2f initPosition, sf::Vector2f scale,
	sf::Vector2f direction)
{
	this->initBulletSprite(texture, initPosition, scale);
	this->initVariables(direction);
}

Bullet::~Bullet()
{
}

/*
Set bullet heading direction
Set bullet's physics. Initial speed of 7 and increase 0.3 every frame
*/
void Bullet::initVariables(sf::Vector2f direction)
{
	this->direction = direction;
	this->maxVelocity = 30.f;
	this->acceleration = 0.3f;
	this->currentVelocity = sf::Vector2f(7.f, 0.f);
}

/*
Set up a bullet sprite texture, scale, and its initial position
*/
void Bullet::initBulletSprite(sf::Texture* texture, sf::Vector2f initPosition, sf::Vector2f scale)
{
	this->bulletTexture = texture;
	this->bulletSprite.setTexture(*this->bulletTexture);
	this->bulletSprite.setScale(scale);
	this->bulletSprite.setPosition(
		sf::Vector2f(initPosition.x -this->bulletSprite.getGlobalBounds().width/2,
					initPosition.y -this->bulletSprite.getGlobalBounds().height /2));
}

//update bullets move
void Bullet::update()
{
	this->updateMovement();
}

/*
if bullet's current speed didn't reach the max speed,
it will continuosuly increased by number from acceleration

update bullet sprite movement
*/
void Bullet::updateMovement()
{
	
	if (this->currentVelocity.x < this->maxVelocity)
	{
		this->currentVelocity.x += this->acceleration * this->direction.x;
	}
	
	this->bulletSprite.move(this->currentVelocity);
}

//render it on the screen
void Bullet::render(sf::RenderTarget& target)
{
	
	target.draw(this->bulletSprite);
}
