#pragma once
class Bullet
{
public:
	/*
	constructor
	receive bullet pointer texture
	it's initial position
	Size scale
	direction that a bullet heading
	*/
	Bullet(sf::Texture *texture, sf::Vector2f initPosition, sf::Vector2f scale, sf::Vector2f direction = sf::Vector2f(1.0f, 0.f));
	virtual ~Bullet();

private:
	//Texture, Sprite
	sf::Texture *bulletTexture;
	sf::Sprite bulletSprite;


	//physics
	sf::Vector2f currentVelocity;
	float maxVelocity;
	float acceleration;

	//direction
	sf::Vector2f direction;

	//initializer
	void initVariables(sf::Vector2f direction);
	void initBulletSprite(sf::Texture* texture, sf::Vector2f initPosition, sf::Vector2f scale );
public:
	//Accessor
	inline sf::FloatRect getglobalBounds() const { return this->bulletSprite.getGlobalBounds(); }
	inline const sf::Vector2f getPosition() const { return this->bulletSprite.getPosition(); }

	//Update
	void update();
	void updateMovement();

	//Rendering
	void render(sf::RenderTarget &target);
};

