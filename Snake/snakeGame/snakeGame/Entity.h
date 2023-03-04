#pragma once
#include "Collider.h"
class Entity
{
public:
	Entity(sf::Vector2f position, sf::Texture *texture);
	virtual ~Entity();

	virtual void draw(sf::RenderWindow* w);
	virtual void update(double deltaT) = 0;
	//getter
	sf::Vector2f getPos();
	Collider getCollider();
	sf::RectangleShape getBody();
	sf::Vector2f getSize();

	//setter
	void setPos(sf::Vector2f newPos);
	void setSize(sf::Vector2f newSize);

	void setFillCol(sf::Color newColor);

private:
	sf::RectangleShape body;
	Collider* c;
};

