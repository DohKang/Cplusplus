#pragma once

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, SHOOTING};

class Player
{
public :

	//Construct, Destruct
	Player();
	virtual ~Player();

private:
	//Init function
	void initTexture();
	void initVariables();
	void initAnimation();
	//Texture, sprite Variables
	sf::Texture playerTexture;
	sf::Sprite PlayerSprite;

	/*
	Player Variables
	*/
	float movementSpeed;
	int hp;
	int hpMax;
	float attackCoolDown;
	float attackCoolDownMax;

	//Animation
	short animState;
	sf::Clock animationTimer;
	bool animationSwitch;
	sf::IntRect currentFrame;

	//Player move
	void move(const float dirX, const float dirY);
	void updateMove();
	
public:
	//Modifier
	void setPosition(const float x, const float y);
	void getDamage(const int damage);
	void resetAnimationTimer();
	sf::FloatRect getBounds();

	//Accessor
	const sf::Vector2f& getPos() const;
	const bool& geteAnimSwitch();
	const bool canAttack();
	const int getHp() const;
	const int getHpMax() const;


	//updates
	void updateAttack();
	void updateAnimaition();
	void update();

	//rendering
	void render(sf::RenderTarget &target);

};


