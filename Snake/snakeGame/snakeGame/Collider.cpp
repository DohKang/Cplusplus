#include "stdafx.h"
#include "Collider.h"

Collider::Collider(sf::RectangleShape* body)
	:body(body)
{
}

Collider::~Collider()
{
}

bool Collider::checkCollision(const Collider& other)
{
	sf::Vector2f delta(this->getPos() - other.getPos());

	sf::Vector2f halfSize(this->getHalfSize() + other.getHalfSize());

	if (abs(delta.x) - halfSize.x < 0 && abs(delta.y) - halfSize.y < 0)
	{
		return true;
	}
	return false;
}

sf::Vector2f Collider::getHalfSize() const
{
	return sf::Vector2f(body->getSize().x /2.0f, body->getSize().y / 2.0f);
}

sf::Vector2f Collider::getPos() const
{
	return sf::Vector2f(body->getPosition());
}
