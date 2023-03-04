#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 5.0f;
	this->hp_max = 10;
	this->hp = this->hp_max;
	
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y); //set player initial position
	this->initVariables(); //set variables
	this->initShape(); // initialize player
}

Player::~Player()
{

}

//Accessor
const sf::RectangleShape& Player::getshape() const
{

	return this->shape;
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMAx() const
{
	return this->hp_max;
}

//Functions
void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
	{
		this->hp -= damage;
	}
	if (this->hp < 0)
	{
		this->hp = 0;
	}

}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hp_max)
	{
		this->hp += health;
	}
	if (this->hp >= this->hp_max)
	{
		this->hp = this->hp_max;
	}
	
}

void Player::updateInput()
{//keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // don't let user press A, D at the same time.
	{
		this->shape.move(this->movementSpeed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.0f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // don't let user press A, D at the same time.
	{
		this->shape.move(0.0f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->shape.getGlobalBounds().left <= 0.0f)
	{
		this->shape.setPosition(0.0f, this->shape.getGlobalBounds().top);
	}
	//right
	else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
	{
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}
	//top
	if (this->shape.getGlobalBounds().top <= 0.0f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.0f);
	}
	//bottom
	else if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left ,target->getSize().y - this->shape.getGlobalBounds().height);
	}
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateWindowBoundsCollision(target);
	//Window bounds collision
	this->updateInput();
	


}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
