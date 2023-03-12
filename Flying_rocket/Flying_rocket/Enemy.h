#pragma once
class Enemy
{
public:
	/*
	construtor.
	get Enemy texture as a pointer, screen size, and enemy's heading direction
	*/
	Enemy(sf::Texture* texture, sf::Vector2u windowBounds,
		 sf::Vector2f direction);
	virtual ~Enemy();

private:
	//set up enemy sprite
	sf::Texture* enemyTexture;
	sf::Sprite enemySprite;

	//set up enemy heading direction and window screen size
	sf::Vector2u windowBounds;
	sf::Vector2f direction;

	//hp and damage variables
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;

	//each enemies point
	int points;

	//initiaiize variables
	void initVariables();

public:
	//Modifier
	//if enemy get hit by player's bullet, it will reduce it's hp
	void enemyGotHit();

	//Accessors

	//return a enemy collision damage
	inline const int getDamage() const { return rand() % this->damageMax + this->damageMin; }
	
	//return the enemy's hp
	inline const int getHp() const { return this->hp; }
	
	//return the enemy's hpMax
	inline const int getHpMax() const { return this->hpMax; }
	
	//check the enemy is alive or dead. if dead->true0
	inline const bool isDead() const { return this->hp <= 0; }
	
	//once enemy is destroyed by player's bullet, player gets point
	inline const int getPoints() const { return this->points; }

	//return the enemy's sprite globalbounds
	inline const sf::FloatRect getglobalBounds() const { return this->enemySprite.getGlobalBounds(); }
	
	//return enemy's current position
	inline const sf::Vector2f getPosition() const { return this->enemySprite.getPosition(); }
	
	//check whether enemy position is out of left side of the screen or not
	bool const hitBoundary();
	
	//update
	void update();
	void updatetakeDamage(const int damage);
	
	//render
	void render(sf::RenderTarget& target);
};