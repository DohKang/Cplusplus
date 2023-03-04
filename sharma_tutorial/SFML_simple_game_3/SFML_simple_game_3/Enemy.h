#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	unsigned pointCount;
	sf::CircleShape shape;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	void initVairables();
	void initShape();


public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();
	
	//Accessor
	sf::FloatRect getbounds() const;
	const int& getpoints() const;
	const int& getDamage() const;
	//Functions
	
	void update();
	void render(sf::RenderTarget* target);
};

#endif