#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Bullet
{
private:
	sf::Sprite shape;
	sf::Vector2f direction;
	float movementspeed;

public:
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dirX, float dirY, float movement_speed);
	virtual ~Bullet();
	
	const sf::FloatRect getbounds() const;
	
	void update();
	void render(sf::RenderTarget& target);
};

