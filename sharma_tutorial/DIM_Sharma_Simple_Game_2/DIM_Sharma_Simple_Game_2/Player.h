#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <ctime>




class Player
{
	//player shape
	sf::RectangleShape shape;

	//Variables
	float moveSpeed;
	int hp;
	int hp_max;


	//initializer
	void initVariable();
	void initShape();


public:
	Player(float x = 0.0f, float y = 0.0f);
	virtual ~Player();

	//Accessors
	const sf::RectangleShape& getshape() const;

	//damage, heal
	void playergetdamage(const int damage);
	void playergetheal(const int heal);
	const int& getHp() const;
	const int& getHpMax() const;
	//update

	void updateInput();
	void updateWindowBoundCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	

	//render
	void render(sf::RenderTarget* target);
};




#endif