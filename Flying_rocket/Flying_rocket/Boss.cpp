#include "stdafx.h"
#include "Boss.h"

/*
Constructor
set up the boss texture, bullet, and bring screen size as a parameter
*/
Boss::Boss(sf::Texture& bossTexture, sf::Texture& BosBulletTexture, sf::Vector2u windowBounds)
{
	//initializer
	this->initVariables();
	this->initSprite(bossTexture, BosBulletTexture, windowBounds);
}

//destructor
Boss::~Boss()
{
}

//initialize various variables
void Boss::initVariables()
{
	//hp variables
	this->hpMax = 120;
	this->hp = this->hpMax;
	//damage variables
	this->damageMin = 3;
	this->damageMax = 5;
	//movement
	this->movementSpeed = 10.f;
	this->direction = sf::Vector2f(0.f, -1.f);
	//bullet shooting respawn variables
	this->shootingTimer = 0.f;
	this->shootingTimerMax = 50.f;
	
}

/*
Initialize the Boss character sprite, initial position, scale size,
set up the bullet texture
*/
void Boss::initSprite(sf::Texture& bossTexture, sf::Texture& BosBulletTexture, sf::Vector2u windowBounds)
{
	this->bossSprite.setTexture(bossTexture);
	this->bossSprite.setPosition(windowBounds.x -400.f, windowBounds.y-500.f);
	this->bossSprite.setScale(3.f, 3.f);

	//set up the boss's bullet texture
	this->bossBulletTexutre = &BosBulletTexture;
}

/*
Update boss's movement
*/
void Boss::updateBossMove()
{
	this->bossSprite.move(this->direction * this->movementSpeed); 
}

/*
when the boss get hit, it reduces its hp
*/
void Boss::updatetakeDamage(const int damage)
{
	this->hp -= damage;
}

/*
update the boss's vertical direction
*/
void Boss::update()
{
	/*
	If the boss hits the top of the screen, it changes its direction to downward
	if the boss hits the bottom of the screen, it changes its direction to upward
	*/
	if (this->bossSprite.getGlobalBounds().top < 0.f)
		this->direction = sf::Vector2f(0.f, 1.f);
	if (this->bossSprite.getGlobalBounds().top > 630.f)
		this->direction = sf::Vector2f(0.f, -1.f);

	//update the boss's movement
	this->updateBossMove();
	
	//creating boss's bullet object
	this->updateFireBossBullet();
	//update the boss's shooting respawn time
	this->updateBulletspawnTime();
	//update bullet objects
	this->updateBossBullet();
}

/*
If shooting timer hits its max,
the boss shoots a bullet
*/
void Boss::updateFireBossBullet()
{
	if (this->shootingTimer >= this->shootingTimerMax)
	{
		this->bossbullets.push_back(Bullet(this->bossBulletTexutre,
			sf::Vector2f(this->getPosition().x+ 200.f, this->getPosition().y + 90.f),
			sf::Vector2f(-0.5f, 1.f), sf::Vector2f(-1.0f, 0.f)));
		this->shootingTimer = 0;
	}
}

/*
updating the boss's bullet respawn time
*/
void Boss::updateBulletspawnTime()
{
	if (this->shootingTimer < this->shootingTimerMax)
		this->shootingTimer += 0.3f;
}

//update the boss's bullet object
void Boss::updateBossBullet()
{
	for (size_t i = 0; i < this->bossbullets.size(); i++)
	{
		this->bossbullets[i].update();
	}
}




void Boss::render(sf::RenderTarget& target)
{
	target.draw(this->bossSprite);
	for (size_t i = 0; i < this->bossbullets.size(); i++)
	{
		this->bossbullets[i].render(target);
	}
}
