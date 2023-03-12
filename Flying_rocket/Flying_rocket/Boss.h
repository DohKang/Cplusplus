#pragma once
class Boss
{
public:
	/*
	Constructor
	get boss character texture, boss bullet texture, and screen size as a parmaeter
	*/
	Boss(sf::Texture& bossTexture, sf::Texture& bossBulletTexture, sf::Vector2u windowBounds);
	virtual ~Boss();

private:
	//boss character sprite
	sf::Sprite bossSprite;
	
	//boss hp and bullet damage
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;

	//boss movement speed
	float movementSpeed;

	//boss vertical direction
	sf::Vector2f direction;

	//boss shooting bullet respawn timer
	float shootingTimer;
	float shootingTimerMax;

	//bullet
	std::vector<Bullet> bossbullets;
	sf::Texture *bossBulletTexutre;

	//initializer
	void initVariables();
	void initSprite(sf::Texture& playerTexture, sf::Texture& bossBulletTexture, sf::Vector2u windowBounds);
	

public:
	//Accessor
	
	//return all current bullets in the screen
	inline std::vector<Bullet>& getBullets() { return this->bossbullets; }

	//return a bullet damage
	inline const int getDamage() const { return rand() % this->damageMax + this->damageMin; }
	
	//return the boss's hp
	inline const int getHp() const { return this->hp; }
	
	//return the boss's hpMax
	inline const int getHpMax() const { return this->hpMax; }
	
	//check the boss is alive or dead. if dead->true0
	inline const bool isDead() const { return this->hp <= 0; }
	
	//return the boss's sprite globalbounds
	inline const sf::FloatRect getglobalBounds() const { return this->bossSprite.getGlobalBounds(); }
	
	//return boss's current position
	inline  sf::Vector2f getPosition() const { return this->bossSprite.getPosition(); }
	
	//update
	void update();
	void updateBossMove();
	void updatetakeDamage(const int damage);
	void updateFireBossBullet();
	void updateBulletspawnTime();
	void updateBossBullet();

	//render
	void render(sf::RenderTarget& target);

};

