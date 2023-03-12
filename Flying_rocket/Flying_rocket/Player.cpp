#include "stdafx.h"
#include "player.h"


//enum for direction keys
enum KEYS {UP=0, DOWN, LEFT, RIGHT, SHOOT, CHANGEWEAPON, NUMBULLET};
//enum for weapon texture
enum WEAPONS {maingun_ = 0, bullet1_, bullet2_, laser1_, laser2_, laser3_ };
//enum for bullet style
enum BULLETS {bullet1 = 0, bullet2, laser};

/*
constructor
initialize variables.
set up player sprite
set up weapon and bullet sprite
set up keyboard console keys
*/
Player::Player(sf::Texture& playertexture, 
	std::vector<sf::Texture>& weaponTextures , sf::Vector2f setposition,
	int UP, int DOWN, int LEFT, int RIGHT, int SHOOT,
	int CHANGEWEAPON, int NUMBULLET)
{
	this->initVariables();
	this->initPlayerSprite(playertexture, setposition);
	this->initWeaponSprite(weaponTextures);
	this->KeySet(UP, DOWN, LEFT, RIGHT, SHOOT, CHANGEWEAPON, NUMBULLET);

}

Player::~Player()
{
	
}

/*
set up various variablese
*/
void Player::initVariables()
{
	//shooting respawn timer
	this->shootTimerMax = 15.f;
	this->shootTimer = this->shootTimerMax;
	
	//set up hp, hpmax
	this->hpMax = 20;
	this->hp = this->hpMax;

	//set up damage, damage max
	this->damageMax = 3;
	this->damage = 1;
	
	//set up current speed
	this->currentVelocity = sf::Vector2f(0.f, 0.f);
	//set up max player's speed
	this->maxVelocity = 35.f;

	//physics
	this->acceleration = 1.f;
	this->drag = 0.3f;
	
	//heading direction setting
	this->direction = sf::Vector2f(0.f, 0.f);

	//little weapon inside the player setting
	this->weaponPosition.x = this->playerSprite.getPosition().x + this->playerSprite.getGlobalBounds().width / 2;
	this->weaponPosition.y = this->playerSprite.getPosition().y + this->playerSprite.getGlobalBounds().height / 2;
	
	//set up initial bullet style and number of shooting
	this->currentBullet = BULLETS::bullet2;
	this->threeBullet = false;

}

//set up player sprite
void Player::initPlayerSprite(sf::Texture& playertexture, sf::Vector2f setposition)
{
	this->playerSprite.setTexture(playertexture);
	this->playerSprite.setScale(0.15f, 0.15f);
	this->playerSprite.setPosition(setposition);
}

//set up weapon sprite and bullet texture 
void Player::initWeaponSprite(std::vector<sf::Texture>& weaponTextures)
{
	//gun texture
	this->gunSprite.setTexture(weaponTextures[maingun_]);
	this->gunSprite.setPosition(this->weaponPosition.x + 17.f, this->weaponPosition.y);
	this->gunSprite.setScale(1.f, 1.f);

	//bullet texture
	this->bullet1 = &weaponTextures[WEAPONS::bullet1_];
	this->bullet2 = &weaponTextures[WEAPONS::bullet2_];
	this->laser1 = &weaponTextures[WEAPONS::laser1_];
	this->laser2 = &weaponTextures[WEAPONS::laser2_];
	this->laser3 = &weaponTextures[WEAPONS::laser3_];

}

/*
set up keyboard consoles
*/
void Player::KeySet(int UP, int DOWN, int LEFT, int RIGHT, int SHOOT, int CHANGEWEAPON, int NUMBULLET)
{
	//direction key
	this->keycontrol[KEYS::UP] = UP;
	this->keycontrol[KEYS::DOWN] = DOWN;
	this->keycontrol[KEYS::LEFT] = LEFT;
	this->keycontrol[KEYS::RIGHT] = RIGHT;
	this->keycontrol[KEYS::SHOOT] = SHOOT;
	this->keycontrol[KEYS::CHANGEWEAPON] = CHANGEWEAPON;
	this->keycontrol[KEYS::NUMBULLET] = NUMBULLET;
}


//if player gets hit, reduce its current hp
void Player::reduceHp(const int dmg)
{
	this->hp -= dmg;
	if (this->hp <= 0)
		this->hp = 0;
}

//if player goes outside of boundary, set back inside boundary
void Player::setPosition(const float x, const float y)
{
	this->playerSprite.setPosition(x, y);
}

//all updates
void Player::update()
{
	this->updatedirection();
	this->updateDrag();
	this->updateMove();
	this->updateGunPosition();
	this->updateGunBoundary();
	this->updatetNumBullet();
	this->updateWeapontype();
	this->updateShootTimer();
	this->updateFireBullet();
	this->updateBullet();
	
	
}

/*
based on keyboard key,
update its direction and player's speed
*/
void Player::updatedirection()
{
	//player hit up key, then a sprite go up with current velocity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::UP])))
	{
		this->direction.x = 0.f;
		this->direction.y = -1.f;
		if (this->currentVelocity.y > -this->maxVelocity && this->direction.y < 0)
		{
			this->currentVelocity.y += this->direction.y * this->acceleration;
		}
	}
	//player hit down key, then a sprite go down with current velocity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::DOWN])))
	{
		this->direction.x = 0.f;
		this->direction.y = 1.f;
		if (this->currentVelocity.y < this->maxVelocity && this->direction.y > 0)
		{
			this->currentVelocity.y += this->direction.y * this->acceleration;
		}
	}
	//player hit left key, then a sprite go left with current velocity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::LEFT])))
	{
		this->direction.x = -1.f;
		this->direction.y = 0.f;
		if (this->currentVelocity.x > -this->maxVelocity && this->direction.x < 0)
		{
			this->currentVelocity.x += this->direction.x * this->acceleration;
		}
	}
	//player hit right key, then a sprite go right with current velocity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::RIGHT])))
	{
		this->direction.x = 1.f;
		this->direction.y = 0.f;
		if (this->currentVelocity.x < this->maxVelocity && this->direction.x > 0)
		{
			this->currentVelocity.x += this->direction.x * this->acceleration;
		}
	}
}

void Player::updateDrag()
{
	//if a player go right 
	if (this->currentVelocity.x > 0)
	{	//reduece speed gradually
		this->currentVelocity.x -= this->drag;
		if (this->currentVelocity.x <= 0)
			this->currentVelocity.x = 0;
	}
	//if a player go left
	else if (this->currentVelocity.x < 0)
	{	//reduce speed gradually
		this->currentVelocity.x += this->drag;
		if (this->currentVelocity.x >= 0)
			this->currentVelocity.x = 0;
	}
	//if a player go down
	if (this->currentVelocity.y > 0)
	{
		this->currentVelocity.y -= this->drag;
		if (this->currentVelocity.y <= 0)
			this->currentVelocity.y = 0;
	}
	//if a player go up
	else if (this->currentVelocity.y < 0)
	{
		this->currentVelocity.y += this->drag;
		if (this->currentVelocity.y >= 0)
			this->currentVelocity.y = 0;
	}

}

//update player sprite move
void Player::updateMove()
{
	this->playerSprite.move(this->currentVelocity);
	//update weaponPosition position based on player's move
	this->weaponPosition.x = this->playerSprite.getPosition().x + this->playerSprite.getGlobalBounds().width / 2;
	this->weaponPosition.y = this->playerSprite.getPosition().y + this->playerSprite.getGlobalBounds().height /2;
}



void Player::updateGunPosition()
{
	/*
	set up gun's image x axis as it was.
	set up vertical position based on player's move
	*/
	this->gunSprite.setPosition(this->gunSprite.getPosition().x,
		this->weaponPosition.y - this->gunSprite.getGlobalBounds().height / 4 );

	/*
	weapon image annimation`
	*/
	//after players shooting, it comes back slowly
	if (this->gunSprite.getPosition().x < this->weaponPosition.x + 20)
	{
		this->gunSprite.move(1.5f + this->currentVelocity.x, 0.f);
	}

	//update weaponposition.
	else if (this->gunSprite.getPosition().x > this->weaponPosition.x + 20)
	{
		this->gunSprite.setPosition(
			this->weaponPosition.x + 20.f,
			this->weaponPosition.y - this->gunSprite.getGlobalBounds().height / 4 );
	}
}

/*
if player goes out of left screen boundary,
set up it's current speed to 0; so that the gun image does not go  beyond
*/
void Player::updateGunBoundary()
{
	if (this->playerSprite.getGlobalBounds().left < 0.f ||
		this->playerSprite.getGlobalBounds().top < 0.f)
		this->currentVelocity = sf::Vector2f(0.f, 0.f);
}

/*
based on keyboard consle, change number of bullets per shooting
*/
void Player::updatetNumBullet()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::NUMBULLET]))
		&& this->threeBullet == false)
	{
		this->threeBullet = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::NUMBULLET]))
		&& this->threeBullet == true)
	{
		this->threeBullet = false;
	}
	
}

/*
based on keyboard console
change bullet style
*/
void Player::updateWeapontype()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::CHANGEWEAPON]))
		&& this->currentBullet == BULLETS::bullet1)
	{
		this->currentBullet = BULLETS::bullet2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::CHANGEWEAPON]))
		&& this->currentBullet == BULLETS::bullet2)
	{
		this->currentBullet = BULLETS::laser;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::CHANGEWEAPON]))
		&& this->currentBullet == BULLETS::laser)
	{
		this->currentBullet = BULLETS::bullet1;
	}

}

/*
once player press space bar,
it will fire a bullet.
check current bullet style and number of bullets per shooting variables.
create bullet object based on that
*/
void Player::updateFireBullet()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keycontrol[KEYS::SHOOT]))
		&& this->shootTimer >= this->shootTimerMax)
	{
		//if current style is bullet 1
		if (this->currentBullet == BULLETS::bullet1)
		{
			//check threebullet variable is true, create three bullet objects at once
			if (this->threeBullet)
			{
				this->bullets.push_back(Bullet(this->bullet1,
					sf::Vector2f(this->weaponPosition.x + 70, this->weaponPosition.y- 30),
					sf::Vector2f(0.1f, 0.1f)));
				this->bullets.push_back(Bullet(this->bullet1,
					sf::Vector2f(this->weaponPosition.x + 70, this->weaponPosition.y),
					sf::Vector2f(0.1f, 0.1f)));
				this->bullets.push_back(Bullet(this->bullet1,
					sf::Vector2f(this->weaponPosition.x + 70, this->weaponPosition.y+ 30),
					sf::Vector2f(0.1f, 0.1f)));
			}
			//if threebullet variable is false, shoot single shot
			else if (!this->threeBullet)
			{
				this->bullets.push_back(Bullet(this->bullet1,
					sf::Vector2f(this->weaponPosition.x + 120, this->weaponPosition.y),
					sf::Vector2f(0.3f, 0.2f)));
			}
			
		}
		//if current style is bullet 2
		else if (this->currentBullet == BULLETS::bullet2)
		{
			//check threebullet variable is true, create three bullet objects at once
			if (this->threeBullet)
			{
				this->bullets.push_back(Bullet(this->bullet2,
					sf::Vector2f(this->weaponPosition.x + 90, this->weaponPosition.y - 30),
					sf::Vector2f(3.f, 1.f)));
				this->bullets.push_back(Bullet(this->bullet2,
					sf::Vector2f(this->weaponPosition.x + 90, this->weaponPosition.y),
					sf::Vector2f(3.f, 1.f)));
				this->bullets.push_back(Bullet(this->bullet2,
					sf::Vector2f(this->weaponPosition.x + 90, this->weaponPosition.y + 30),
					sf::Vector2f(3.f, 1.f)));
			}
			//if threebullet variable is false, shoot single shot
			else if (!this->threeBullet)
			{
				this->bullets.push_back(Bullet(this->bullet2,
					sf::Vector2f(this->weaponPosition.x + 120, this->weaponPosition.y),
					sf::Vector2f(4.f, 2.f)));
			}
			
			
		}
		//if current style is laser
		else if (this->currentBullet == BULLETS::laser)
		{
			//check threebullet variable is true, create three bullet objects at once
			if (this->threeBullet)
			{
				this->bullets.push_back(Bullet(this->laser1,
					sf::Vector2f(this->weaponPosition.x + 100, this->weaponPosition.y - 30),
					sf::Vector2f(0.4f, 0.4f)));
				this->bullets.push_back(Bullet(this->laser2,
					sf::Vector2f(this->weaponPosition.x + 100, this->weaponPosition.y),
					sf::Vector2f(0.4f, 0.4f)));
				this->bullets.push_back(Bullet(this->laser3,
					sf::Vector2f(this->weaponPosition.x + 100, this->weaponPosition.y + 30),
					sf::Vector2f(0.4f, 0.4f)));

			}
			//if threebullet variable is false, shoot single shot
			else if (!this->threeBullet)
			{
				this->bullets.push_back(Bullet(this->laser2,
					sf::Vector2f(this->weaponPosition.x + 200, this->weaponPosition.y),
					sf::Vector2f(1.f, 0.7f)));
			}
			
		}

		//gun's kickback
		this->gunSprite.move(-40.f, 0.f);
		//reset shooting timer to 0;
		this->shootTimer = 0;
	}

}

//update bullet shooting timer
void Player::updateShootTimer()
{
	this->shootTimer += 0.5f;
	if (this->shootTimer >= this->shootTimerMax)
	{
		this->shootTimer = this->shootTimerMax;
	}
}

//update all bullets on the screen
void Player::updateBullet()
{
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].update();
	}
}

//render bullet and player, gun sprite
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->gunSprite);
	this->renderBullet(target);
	target.draw(this->playerSprite);

}

//render all bullets on the screen
void Player::renderBullet(sf::RenderTarget& target)
{
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].render(target);
	}
}
