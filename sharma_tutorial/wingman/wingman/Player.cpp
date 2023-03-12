#include "Player.h"

unsigned Player::playerNr = 0;

enum controls {UP=0,DOWN,LEFT,RIGHT,SHOOT};
enum weapons {LASER = 0, MISSILE01, MISSILE02};
Player::Player(std::vector<Texture>& textures,
	int UP, int DOWN , 
	int LEFT, int RIGHT,
	int SHOOT )
	:level(1), exp(0), expNext(100),
	hp(10), hpMax(10), damage(1), damageMax(2),
	score(0)

{
	//texture sprite
	this->sprite.setTexture(textures[0]);
	this->sprite.setScale(0.15f, 0.15f);

	this->playerCenter.x = this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2;
	this->playerCenter.y = this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2;
	this->mainGunSprite.setPosition(
		this->playerCenter.x + 20.f,
		this->playerCenter.y - this->mainGunSprite.getGlobalBounds().height / 2);
	this->laserTexture = &textures[1];
	this->bulletTexture = &textures[2];
	this->missileTexture = &textures[3];
	this->mainGunSprite.setTexture(textures[3]);
	this->mainGunSprite.setScale(2.f, 2.f);

	//this->mainGunSprite.setOrigin(
	//	this->mainGunSprite.getGlobalBounds().width / 2,
	//	this->mainGunSprite.getGlobalBounds().height / 2
	//);
	//this->mainGunSprite.rotate(90);

	//timer
	this->shootTimerMax = 15;
	this->shootTimer = this->shootTimerMax;
	this->damageTimerMax = 25;
	this->damageTimer = this->damageTimerMax;


	//controls
	this->controls[controls::UP] = UP;
	this->controls[controls::DOWN] = DOWN;
	this->controls[controls::LEFT] = LEFT;
	this->controls[controls::RIGHT] = RIGHT;
	this->controls[controls::SHOOT] = SHOOT;

	//Velocity & Acceleration
	this->maxVelocity = 30.f;
	this->acceleration = 0.8f;
	this->stabilizerDrag = 0.3f;
	
	//Upgrades
	this->mainGunLevel = 0;
	this->currentWeapon = LASER;
	this->dualMissiles01 = false;
	this->dualMissiles02 = false;

	//Add number of players for coop
	this->playerNum = Player::playerNr;
	Player::playerNr++;
	
	std::cout << playerNum << "\n";
}

Player::~Player()
{
}

void Player::Movement()
{
	//UP
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::UP])))
	{
		this->direction.x = 0.f; 
		this->direction.y = -1.f;

		if (this->currentVelocity.y > -this->maxVelocity && this->direction.y < 0)
			this->currentVelocity.y += this->direction.y * this->acceleration;
		//this->sprite.move(0.f, -10.f);
		std::cout << this->direction.x << " " << this->currentVelocity.y << " " << this->acceleration << "\n";
	}

	//DOWN
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::DOWN])))
	{
		this->direction.x = 0.f;
		this->direction.y = 1.f;

		if (this->currentVelocity.y < this->maxVelocity && this->direction.y > 0)
			this->currentVelocity.y += this->direction.y * this->acceleration;
		//this->sprite.move(0.f, 10.f);
	}

	//Left
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::LEFT])))
	{
		this->direction.x = -1.f;
		this->direction.y = 0.f;
		if (this->currentVelocity.x > -this->maxVelocity && this->direction.x < 0)
			this->currentVelocity.x += this->direction.x * this->acceleration;
		//this->sprite.move(-10.f, 0.f);
	}
	//RIGHT
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::RIGHT])))
	{
		this->direction.x = 1.f;
		this->direction.y = 0.f;
		if (this->currentVelocity.x < this->maxVelocity && this->direction.x > 0)
			this->currentVelocity.x += this->direction.x * this->acceleration;
		//this->sprite.move(10.f, 0.f);
	}
	//Drag force
	if (this->currentVelocity.x > 0)
	{
		this->currentVelocity.x -= this->stabilizerDrag;
		if (this->currentVelocity.x < 0)
			this->currentVelocity.x = 0;
	}
	else if (this->currentVelocity.x < 0)
	{
		this->currentVelocity.x += this->stabilizerDrag;
		if (this->currentVelocity.x > 0)
			this->currentVelocity.x = 0;
	}

	if (this->currentVelocity.y > 0)
	{
		this->currentVelocity.y -= this->stabilizerDrag;
		if (this->currentVelocity.y < 0)
			this->currentVelocity.y = 0;
	}
	else if (this->currentVelocity.y < 0)
	{
		this->currentVelocity.y += this->stabilizerDrag;
		if (this->currentVelocity.y > 0)
			this->currentVelocity.y = 0;
	}

	//Final move
	this->sprite.move(this->currentVelocity);
	

}
void Player::Combat()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::SHOOT]))
		&& this->shootTimer >= this->shootTimerMax)
	{
		
		if (this->currentWeapon == LASER)
		{
			//Create bullet 
			if (this->mainGunLevel == 0)
			{
			
			this->bullets.push_back(Bullet(laserTexture,
				Vector2f(this->playerCenter.x + 115, this->playerCenter.y),
				Vector2f(1.f, 1.f),
				Vector2f(1.f, 0.f),
				5.f, 30.f, 0.1f));
			}
			else if (this->mainGunLevel == 1)
			{

			}
			else if (this->mainGunLevel == 2)
			{

			}
		}
		else if (this->currentWeapon == MISSILE01)
		{
			//Create bullet
			this->bullets.push_back(Bullet(missileTexture,
				Vector2f(this->playerCenter.x + 115, this->playerCenter.y),
				Vector2f(1.f, 1.f),
				Vector2f(1.f, 0.f),
				7.f, 30.f, 0.1f));
			if(this->dualMissiles01)
				this->bullets.push_back(Bullet(missileTexture,
					Vector2f(this->playerCenter.x + 115, this->playerCenter.y+ 25.f),
					Vector2f(1.f, 1.f),
					Vector2f(1.f, 0.f),
					7.f, 30.f, 0.1f));
		}
		else if (this->currentWeapon == MISSILE02)
		{

		}

		//Animate gun
		this->mainGunSprite.move(-30.f, 0.f);
		
		
		this->shootTimer = 0; //Reset timer
	
	
	}
}

void Player::UpdateAccessories()
{
	//Set the position of gun to follow player
	this->mainGunSprite.setPosition(
		this->mainGunSprite.getPosition().x,
		this->playerCenter.y - this->mainGunSprite.getGlobalBounds().height /2
	);
	//Animate the gun and correct it after firing
	if (this->mainGunSprite.getPosition().x < this->playerCenter.x + 20.f)
	{
		this->mainGunSprite.move(2.f + this->currentVelocity.x, 0.f);
	}

	else if (this->mainGunSprite.getPosition().x > this->playerCenter.x + 20.f)
	{
		this->mainGunSprite.setPosition(
			this->playerCenter.x+ 20.f,
			this->playerCenter.y - this->mainGunSprite.getGlobalBounds().height / 2
		);
	}
}

void Player::Update(Vector2u windowBounds)
{
	if (this->shootTimer < this->shootTimerMax)
	{
		this->shootTimer++;
	}
	if (this->damageTimer < this->damageTimerMax)
	{
		this->damageTimer++;
	}
	this->Movement();
	//update position
	this->playerCenter.x = this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2;
	this->playerCenter.y = this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2;


	this->UpdateAccessories();
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].update();

	}
	
	this->Combat();
}



void Player::Draw(RenderTarget &target)
{
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(target);
	}
	target.draw(this->mainGunSprite);
	target.draw(this->sprite);
}
