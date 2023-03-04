#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Enemy
{
	//variables

	sf::CircleShape shape;
	unsigned pointCount;
	float speed;
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;

	//function
	void initVariables();
	void initShape();



public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();
	
	//Accessor
	sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Function
	void update();
	void render(sf::RenderTarget*target);
};

