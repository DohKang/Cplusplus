#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 7.f;
	this->attackCoolDownMax = 10.f;
	this->attackCoolDown = this->attackCoolDownMax;
	this->hpMax = 50;
	this->hp = this->hpMax;
}

void Player::initCharacter()
{
	if (!this->texture.loadFromFile("Texture/ship.png"))
	{
		std::cout << "ERORR:CHARACTER TEXTURE:: COULD NOT LOAD THE IMG" << "\n";
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.1f, 0.1f);
}

Player::Player()
{
	this->initVariables();
	this->initCharacter();
}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setup(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

void Player::move(const float dir_x, const float dir_y)
{
	this->sprite.move(this->movementSpeed * dir_x, this->movementSpeed * dir_y);
}

const bool Player::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 0;
		return true;
	}
	return false;
}


void Player::updateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
	{
		this->attackCoolDown += 0.5f;
	}
	
}

void Player::update()
{
	this->updateAttack();

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
