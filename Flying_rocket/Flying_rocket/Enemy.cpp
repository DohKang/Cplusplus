#include "stdafx.h"
#include "Enemy.h"

/*
constructor
initialize variables
set up enemy sprite, scale, position
initialize direction variables
*/
Enemy::Enemy(sf::Texture* texture, sf::Vector2u windowBounds,
	 sf::Vector2f direction)
{	
	this->initVariables();
	this->enemyTexture = texture;
	this->enemySprite.setTexture(*this->enemyTexture);
	this->enemySprite.setScale(0.1f, 0.1f);
	this->enemySprite.setPosition(windowBounds.x, rand() % windowBounds.y + this->enemySprite.getGlobalBounds().height);
	this->direction = direction;
}

Enemy::~Enemy()
{
}

/*
initialize hp, damage, point variables
*/
void Enemy::initVariables()
{
	this->hpMax = 3;
	this->hp = this->hpMax;
	this->damageMin = 1;
	this->damageMax = 3;
	this->points = 10;
}

/*
Update enemy moves
*/
void Enemy::enemyGotHit()
{
	this->enemySprite.move(30.f, 15.f);
}

//check whether the enemy hit the left side of screen or not
bool const Enemy::hitBoundary()
{
	if (this->enemySprite.getPosition().x + this->enemySprite.getGlobalBounds().width < 0)
	{
		return true;
	}
}

/*
when the enemy get hit by player's bullet, reduce its current hp
*/
void Enemy::updatetakeDamage(const int damage)
{
	this->hp -= damage;
	if (this->hp <= 0)
		this->hp = 0;
}

/*
update
*/
void Enemy::update()
{
	this->enemySprite.move(this->direction.x * 10.f, this->direction.y * 10.f);
}


//render
void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemySprite);
}
