#include "stdafx.h"
#include "Player.h"

/*
constructer
*/
Player::Player()
{
	this->initVariables();
	this->initTexture();
}

/*
destructor
*/
Player::~Player()
{
}

/*
set texture and sprite
*/
void Player::initTexture()
{
	if (!this->playerTexture.loadFromFile("Texture/panda.png"))
	{
		std::cout << "!! ERROR::PLAYER::CAN NOT LOAD THE PLAYER IMAGE" << "\n";
	}
	this->PlayerSprite.setTexture(this->playerTexture);
	this->currentFrame = sf::IntRect(0,0,32,33);
	this->PlayerSprite.setTextureRect(this->currentFrame);
	this->PlayerSprite.setScale(3.f, 3.f);
}

/*
initiating variables
*/
void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->hpMax = 50;
	this->hp = this->hpMax;
	this->attackCoolDownMax = 5.f;
	this->attackCoolDown = this->attackCoolDownMax;
	
}

/*
animation related variable initiation
*/
void Player::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

/*
Player moves based on argument 
*/
void Player::move(const float dirX, const float dirY)
{
	this->PlayerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}


/*
player move
update animation current frame stage
*/
void Player::updateMove()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE; //set as a defuallt
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->animState = PLAYER_ANIMATION_STATES::SHOOTING;
	}
}

//Modifier
/*
setting player position for starting game
*/
void Player::setPosition(const float x, const float y)
{
	this->PlayerSprite.setPosition(x, y);
}

/*
if the player collides with a bat, it takes dmg
*/
void Player::getDamage(const int damage)
{
	this->hp -= damage;
	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

/*
if keyboard releaed, set switch to true so that currentframe can be changed once keyboard is pressed.
*/
void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

/*
return the player boundary
*/
sf::FloatRect Player::getBounds()
{
	return this->PlayerSprite.getGlobalBounds();
}

//Accessor
/*
return the player current position
*/
const sf::Vector2f& Player::getPos() const
{
	return this->PlayerSprite.getPosition();
}

/*
if keyboard is currently pressed, don't let other frame to overlap.
*/
const bool& Player::geteAnimSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;
}

/*
banana cooldown
if true: the player shoot
else: not
*/
const bool Player::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 0;
		return true;
	}
	return false;
}
/*
return the player hp
*/
const int Player::getHp() const
{
	return this->hp;
}
/*
return the player max hp
*/
const int Player::getHpMax() const
{
	return this->hpMax;
}


//updates
/*
banana attack cooltime
*/
void Player::updateAttack()
{
	this->attackCoolDown += 0.5f;
}


/*
based on the animation stage,
show different currentframe.
*/
void Player::updateAnimaition()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)//when the player is not moving
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->geteAnimSwitch()) //every 0.1sec, update the current frame.
		{
			this->currentFrame.top = 31.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 60.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->PlayerSprite.setTextureRect(this->currentFrame);
			this->PlayerSprite.setScale(3.f, 3.f);
			this->PlayerSprite.setOrigin(0.f, 0.f);
		}
	}
	if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)//when the player is moving right
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->geteAnimSwitch())
		{
			this->currentFrame.top = 96.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left > 64.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->PlayerSprite.setTextureRect(this->currentFrame);
		}
	}
	if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)//when the player is moving left
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->geteAnimSwitch())
		{
			this->currentFrame.top = 96.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left > 64.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->PlayerSprite.setTextureRect(this->currentFrame);
			
		}
		this->PlayerSprite.setScale(-3.f, 3.f);
		this->PlayerSprite.setOrigin(this->PlayerSprite.getGlobalBounds().width / 3.f, 0.f);
	}
	if (this->animState == PLAYER_ANIMATION_STATES::SHOOTING)//when the player is shooting banana
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->geteAnimSwitch())
		{
			this->currentFrame.top = 64.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left > 64.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->PlayerSprite.setTextureRect(this->currentFrame);

		}
	}

}

/*
all updates
*/
void Player::update()
{
	this->updateMove();
	this->updateAnimaition();
	this->updateAttack();
}
/*
rendering
*/
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->PlayerSprite);


}


