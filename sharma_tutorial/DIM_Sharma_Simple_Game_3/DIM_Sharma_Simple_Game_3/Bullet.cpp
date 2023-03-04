#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dirX, float dirY, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x= dirX;
	this->direction.y=dirY;
	this->movementspeed = movement_speed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getbounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	this->shape.move(this->movementspeed * this->direction);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
