#include "Player.h"

void Player::initVariable()
{
	this->moveSpeed = 10.0f;
	this->hp_max = 10;
	this->hp = this->hp_max;
}

void Player::initShape()
{
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->shape.setFillColor(sf::Color::Green);

}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y); // set player init position
	this->initVariable(); // initailize all variables
	this->initShape(); // initialize shape
}

Player::~Player()
{
}

const sf::RectangleShape& Player::getshape() const
{
	return this->shape;
}

void Player::playergetdamage(const int damage)
{
	if (this->hp >= 0)
	{
		this->hp -= damage;
	}
	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

void Player::playergetheal(const int heal)
{
	if (this->hp < this->hp_max)
	{
		this->hp += heal;
	}
	if (this->hp >= this->hp_max)
	{
		this->hp = this->hp_max;
	}
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hp_max;
}

void Player::updateInput()
{
	//keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->moveSpeed, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->moveSpeed, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.0f, -this->moveSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.0f, this->moveSpeed);
	}

}

void Player::updateWindowBoundCollision(const sf::RenderTarget* target)
{
	//left
	if (this->shape.getGlobalBounds().left <= 0.0f)
	{
		this->shape.setPosition(0.0f, this->shape.getGlobalBounds().top);
	}
	else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
	{
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}
	if (this->shape.getGlobalBounds().top <= 0.0f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.0f);
	}
	else if(this->shape.getGlobalBounds().top >= target->getSize().y - this->shape.getGlobalBounds().height)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
	}

}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();
	this->updateWindowBoundCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}




