#pragma once
class Bat
{
	//Constructor, destructor
public:
	Bat();
	virtual ~Bat();

private:
	//sprite, texture variables
	sf::Sprite shape;
	sf::Texture texture;

	//animation
	sf::IntRect currentFrame;
	sf::Clock batAnimationTimer;

	/*
	point: when a player kill a bat
	dmg :when a player collides with a bat
	movementspeed: bat moving speed
	*/
	int point;
	int dmg;
	float movementSpeed;
	

	//initiating
	void initTexture();
	void initVariables();


public:
	//Accessor
	const sf::FloatRect getBounds() const;
	int getPoints();
	int getDamage();

	//updates
	void updateAnimation();
	void updateMove();
	void update();

	//rendering
	void render(sf::RenderTarget& target);
};

