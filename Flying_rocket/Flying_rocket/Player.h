#pragma once
class Player
{
public:
	/*Constructor / destructor
	Takes player's texture, weapon texture, player's initial position,
	keyboard events keys. up, down, left, right, shooting, weapon change, and number of bullets per shooting
	*/
	Player(sf::Texture& playertexture, 
		std::vector<sf::Texture>& weaponTextures, sf::Vector2f setposition,
		int UP =22, int DOWN = 18, int LEFT = 0, int RIGHT = 3, int SHOOT = 57, int CHANGEWEAPON = 25, int NUMBULLET =23
		);
	virtual ~Player();

private:
	//player texture 
	sf::Sprite playerSprite;
	sf::Sprite gunSprite;

	//player position
	sf::Vector2f weaponPosition;


	//Physics
	sf::Vector2f currentVelocity;
	float maxVelocity;
	float acceleration;
	sf::Vector2f direction;
	// force against movement
	float drag;

	//keycontrol
	int keycontrol[7];

	//Weapontimer
	float shootTimerMax;
	float shootTimer;
	
	//hp vairable
	int hp;
	int hpMax;
	
	//dmg variable
	int damage;
	int damageMax;


	//Bullets, Bullet texture
	std::vector<Bullet> bullets;
	sf::Texture *bullet1;
	sf::Texture *bullet2;
	sf::Texture *laser1;
	sf::Texture *laser2;
	sf::Texture *laser3;

	//current bullet style and number per shooting settings
	int currentBullet;
	bool threeBullet;


	//initializer
	void initVariables();
	void initPlayerSprite(sf::Texture& playertexture, sf::Vector2f setposition);
	void initWeaponSprite(std::vector<sf::Texture>& weaponTextures);
	void KeySet(int UP, int DOWN, int LEFT, int RIGHT, int SHOOT,int CHANGEWEAPON, int NUMBULLET);



public:
	//Accessor

	inline std::vector<Bullet>& getBullets() { return this->bullets; }
	inline const int getHp() const { return this->hp; }
	inline const int getHpMax() const { return this->hpMax; }
	inline const int getDamage() const { return rand() % this->damageMax + this->damage; }
	inline const sf::Vector2f& getPosition() const { return this->playerSprite.getPosition(); }
	inline const std::string getHpAsString() const { return std::to_string(this->hp) + "/" + std::to_string(this->hpMax); }
	inline const sf::FloatRect getGlobalBounds() const { return this->playerSprite.getGlobalBounds(); }
	inline const bool isDead() const { return this->hp <= 0; }
	
	//Modifier
	//once the player get hits, it reduce its hp
	void reduceHp(const int dmg);
	//if player is going out of the screen, set up a player inside of screen boundary
	void setPosition(const float x, const float y);


	//updates
	void update();
	void updatedirection();
	void updateDrag();
	void updateMove();
	void updateGunPosition();
	void updateGunBoundary();
	void updatetNumBullet();
	void updateWeapontype();
	void updateFireBullet();
	void updateShootTimer();
	void updateBullet();

	//render
	void render(sf::RenderTarget &target);
	void renderBullet(sf::RenderTarget& target);
};

