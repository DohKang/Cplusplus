#pragma once

#include "Bullet.h"

class Player
{
private:
	unsigned playerNum;

	int shootTimer;
	int shootTimerMax;
	int damageTimer;
	int damageTimerMax;

	
	Sprite sprite;
	RectangleShape hitBox;

	//Accessories
	Sprite mainGunSprite;
	

	Vector2f playerCenter;


	std::vector<Bullet> bullets;
	Texture* laserTexture;
	Texture* bulletTexture;
	Texture* missileTexture;


	int controls[5];
	Vector2f currentVelocity;
	float maxVelocity;
	float acceleration;
	Vector2f direction;
	float stabilizerDrag;

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;

	//Upgrades
	int currentWeapon;
	
	//Upgrades
	int mainGunLevel;
	bool dualMissiles01;
	bool dualMissiles02;

public:
	Player(std::vector<Texture>& textures,
		int UP = 22, int DOWN = 18,
		int LEFT = 0, int RIGHT = 3,
		int SHOOT = 57);
	virtual ~Player();

	//Accessors
	inline std::vector<Bullet>& getBullets() { return this->bullets; }
	inline const Vector2f& getPosition() const { return this->sprite.getPosition(); }
	inline const std::string getHpAsString() const { return std::to_string(this->hp) + "/" + std::to_string(this->hpMax); }
	inline const int getDamage() const { return rand() % this->damageMax + this->damage; }
	
	//Functions
	void Combat();
	void Movement();
	void UpdateAccessories();
	void Update(Vector2u windowBounds);

	void Draw(RenderTarget &target);

	//statics
	static unsigned playerNr;
};

