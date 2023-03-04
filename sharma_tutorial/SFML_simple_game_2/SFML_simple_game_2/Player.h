#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape shape;


	float movementSpeed;
	int hp;
	int hp_max;
	

	void initVariables();
	void initShape();
public:
	Player(float x = 0.0f, float y = 0.0f);
	virtual ~Player();

	//Accessor

	const sf::RectangleShape& getshape() const;
	const int& getHp() const;
	const int& getHpMAx() const;

	void takeDamage(const int damage);
	void gainHealth(const int health);
	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

#endif
