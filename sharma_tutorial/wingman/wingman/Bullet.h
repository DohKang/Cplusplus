#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <ctime>
using namespace sf;
class Bullet
{
private:
	Texture *texture;
	Sprite sprite;

	Vector2f currentVelocity;
	float maxVelocity;
	float acceleration;
	Vector2f direction;
	
public:
	Bullet(Texture* texture, Vector2f position, Vector2f scale,
		Vector2f direction, float initialVelocity,
		float maxVelocity,  float acceleration);
	virtual ~Bullet();

	//Accessors
	inline const FloatRect getGlobalBounds() const { return this->sprite.getGlobalBounds(); }
	inline const Vector2f getPosition() const { return this->sprite.getPosition(); }

	//FUnctions
	void Movement();

	void update();
	void Draw(RenderTarget &target);
};

