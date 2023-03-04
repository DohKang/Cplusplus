#pragma once
class Banana
{
public:
	//construct/Destruct
	Banana(sf::Texture* texture, float posX, float posY);
	virtual ~Banana();

private:
	//sprite
	sf::Sprite shape;

	//x,y direction where banana go
	sf::Vector2f direction;
	float movementspeed;

	//Animation
	sf::IntRect currentFrame;
	sf::Clock bananaAnimationTimer;
	
	//init, move function
	void initVariables();
	void move();
public:
	//Accessor
	const sf::FloatRect getBounds() const;
	
	//updates
	void updateAnimation();
	void update();

	//rendering
	void render(sf::RenderTarget& target);
};