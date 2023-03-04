#pragma once
#include "Entity.h"

class Tail : public Entity
{
public:
	Tail(sf::Vector2f position, sf::Texture* texture);
	void update(double deltaT) override;
	~Tail();
};

