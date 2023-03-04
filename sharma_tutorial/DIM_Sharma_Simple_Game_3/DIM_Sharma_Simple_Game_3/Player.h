#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class Player
{
private:

	//character
	sf::Sprite sprite;
	sf::Texture texture;
	//variables
	float movementSpeed;
	float attackCoolDown;
	float attackCoolDownMax;

	int hp;
	int hpMax;


	//function
	void initVariables();
	void initCharacter();

public:
	Player();
	virtual ~Player();

	//Accessor
	const sf::Vector2f& getPos() const;
	sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//Modifiers

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setup(const int hp);
	void loseHp(const int value);

	void move(const float dir_x, const float dir_y);
	const bool canAttack();


	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

