#include "stdafx.h"
#include "Game.h"

//enum for players textures
enum PLAYERTEXTURE {player1 = 0, player2 = 1};

//enum for weapon textures
enum WEAPONTEXTURE {maingun = 0, weapon1 = 1, weapon2, laser1, laser2, laser3};

/*
constructor
*/
Game::Game()
{
	//initialize various variables
	this->initVariables();
	//initialize window
	this->initWindows();
	//initialize background
	this->initBackground();
	//initialize player and boss texture
	this->initPlayerBoss();
	//initialize enemy
	this->initEnemy();
	//initialize text, hpbar
	this->initText();
	this->initHpBar();
	

}

/*
destructor
*/
Game::~Game()
{
	delete this->window;
	if(this->boss && !this->bosskilled)
		delete this->boss;
}

void Game::initVariables()
{
	//enemy spawn timer initialization
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;

	//point
	this->points = 0;

	//boss related
	//does it reach points for boss 
	this->bosspoint = false;
	//boss pointer to nullptr
	this->boss = nullptr;
	//is boss dead?
	this->bosskilled = false;

}

/*
window initializer
*/
void Game::initWindows()
{
	this->videoMode = sf::VideoMode(1920, 1080);
	this->window = new sf::RenderWindow(this->videoMode, "Flying_rocket", sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

/*
set up background
*/
void Game::initBackground()
{
	/*
	load the background file.
	set subrect for texture
	initialize animation sf::clock variable 
	*/
	if (!this->backgroundTexture.loadFromFile("Texture/spaceBackground.png"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD BACKGROUND" << "\n";
	}
	else
	{
		this->backgroundSprite.setTexture(this->backgroundTexture);
		this->backgroundFrame = sf::IntRect(0, 0, 1920, 2000);
		this->backgroundSprite.setTextureRect(this->backgroundFrame);
		this->backgroundSprite.setScale(1.f, 0.5f);
	}
	this->backgroundAnimationTimer.restart();
}

/*
initialize playerand boss texture
initialize player class object
*/
void Game::initPlayerBoss()
{
	//Add players Textures
	this->playerTextures.push_back(sf::Texture());
	this->playerTextures[player1].loadFromFile("Texture/player2.png");
	this->playerTextures.push_back(sf::Texture());
	this->playerTextures[player2].loadFromFile("Texture/player1.png");

	//Add weapons Textures
	this->bulletTextures.push_back(sf::Texture());
	this->bulletTextures[maingun].loadFromFile("Texture/maingun.png");
	this->bulletTextures.push_back(sf::Texture());
	this->bulletTextures[weapon1].loadFromFile("Texture/weapon1.png");
	this->bulletTextures.push_back(sf::Texture());
	this->bulletTextures[weapon2].loadFromFile("Texture/weapon2.png");
	this->bulletTextures.push_back(sf::Texture());
	this->bulletTextures[laser1 ].loadFromFile("Texture/laser1.png");
	this->bulletTextures.push_back(sf::Texture());
	this->bulletTextures[laser2].loadFromFile("Texture/laser2.png");
	this->bulletTextures.push_back(sf::Texture());
	this->bulletTextures[laser3].loadFromFile("Texture/laser3.png");


	//Boss texture;
	this->bossTexture.loadFromFile("Texture/monster.png");
	this->bossBulletTexture.loadFromFile("Texture/bossbullet.png");

	//initialize player
	this->players.push_back(Player(this->playerTextures[0], this->bulletTextures, sf::Vector2f(0.f, this->window->getSize().y/3)));
	this->players.push_back(Player(this->playerTextures[1], this->bulletTextures, sf::Vector2f(0.f, this->window->getSize().y / 3 * 2),
		sf::Keyboard::Numpad8, sf::Keyboard::Numpad5,
		sf::Keyboard::Numpad4, sf::Keyboard::Numpad6, 
		sf::Keyboard::Numpad0, sf::Keyboard::Numpad7,
		sf::Keyboard::Numpad9));
}

//enemy texture set up
void Game::initEnemy()
{
	this->enemyTextures.push_back(sf::Texture());
	this->enemyTextures[0].loadFromFile("Texture/enemy.png");
}



/*
initialize text Gui
*/
void Game::initText()
{
	//text style set up
	if (!this->font.loadFromFile("Font/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD FONT" << "\n";
	}
	for (size_t i = 0; i < this->players.size(); i++)
	{
		//Player header number text set up
		sf::Text tempText;
		tempText.setFont(this->font);
		tempText.setCharacterSize(30);
		tempText.setFillColor(sf::Color::Cyan);
		tempText.setString("P" + std::to_string(i + 1));

		this->playerText.push_back(sf::Text(tempText));

	}
	//point text set up
	this->textpoint.setFont(this->font);
	this->textpoint.setPosition(this->window->getSize().x / 2.f - this->textpoint.getGlobalBounds().width / 2.f,
		20.f);
	this->textpoint.setCharacterSize(50);
	this->textpoint.setFillColor(sf::Color::Yellow);
	this->textpoint.setStyle(sf::Text::Bold);

	//gameover text set up
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setString("		  Game Over\n Thank you for playing");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

}

/*
hp bar initializer
*/
void Game::initHpBar()
{
	//players hp bar set up
	sf::RectangleShape hpBar;
	sf::RectangleShape hpBarMax;
	hpBar.setSize(sf::Vector2f(100.f, 5.f));
	hpBar.setFillColor(sf::Color::Green);
	
	
	hpBarMax = hpBar;
	hpBarMax.setFillColor(sf::Color::Color(0, 0, 0, 0));
	hpBarMax.setOutlineColor(sf::Color::White);
	hpBarMax.setOutlineThickness(4.f);
	for (size_t i = 0; i < this->players.size(); i++)
	{
		//set up hpbar and hpbar max position for players
		hpBar.setPosition(this->players[i].getPosition().x + 30.f,
			this->players[i].getPosition().y + 80.f);
		this->playerHpBarList.push_back(sf::RectangleShape(hpBar));
		hpBarMax.setPosition(this->players[i].getPosition().x + 30.f,
			this->players[i].getPosition().y + 80.f);
		this->playerHpBarMaxList.push_back(sf::RectangleShape(hpBarMax));
	}

	//boss hpbar set upt
	this->bossHpBar.setSize(sf::Vector2f(200.f, 5.f));
	this->bossHpBar.setFillColor(sf::Color::Red);
	this->bossHpBarMax.setSize(sf::Vector2f(200.f, 5.f));
	this->bossHpBarMax.setFillColor(sf::Color::Color(0, 0, 0, 0));
	this->bossHpBarMax.setOutlineThickness(4.f);
}

/*
Game engine running
*/
void Game::running()
{
	while (this->window->isOpen())
	{
		this->pollEvents();
		this->update();
		this->render();
	}
}

/*
any events happening ?
*/
void Game::pollEvents()
{
	//keep tracking event happening
	while (this->window->pollEvent(this->ev))
	{	
		switch (this->ev.type)
		{
		case sf::Event::Closed: // if player clicks x button, close the screen
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) //if player pressed esc, close the screen
				this->window->close();
			break;

		}
	}
}

/*
all updates
*/
void Game::update()
{
	//background
	this->updateBackgroundAnimation();
	//player
	this->updatePlayer();
	//check boundaries
	this->updatePlayerBoundary();
	this->updateBulletBoundary();
	//enemy updates
	this->updateSpawnEnemy();
	this->updateEnemy();
	this->updateEnemyBoundary();
	//collision check
	this->updateCombat();
	//Boss updates
	this->updatePointToBoss();
	if (!this->bosskilled && this->bosspoint)
	{
		this->boss->update();
		this->updateBossCombat();
		this->updateBossBulletBoundary();
	}
	//update text, hpbar
	this->updateText();
	this->updateHpbar();

	
}

/*
Move background little by little
*/
void Game::updateBackgroundAnimation()
{
	//background moves every 0.1sec
	if (this->backgroundAnimationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		this->backgroundFrame.top = 0.f;
		this->backgroundFrame.left += 10.f;
		//if background subrect hit halt of original image, set up to 0
		if (this->backgroundFrame.left >= 1900.f)
		{
			this->backgroundFrame.left = 0;
		}
		//everytime animation move, set up reset timer
		this->backgroundAnimationTimer.restart();
		this->backgroundSprite.setTextureRect(this->backgroundFrame);
	}
	
}

/*
player update
*/
void Game::updatePlayer()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].update();
	}
}


/*
player boundary update
*/
void Game::updatePlayerBoundary()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		//if player goes all the way to the  left
		if (this->players[i].getGlobalBounds().left < 0.f)
		{
			this->players[i].setPosition(0.f, this->players[i].getGlobalBounds().top);

		}
		//if player goes all the way to the right
		else if (this->players[i].getGlobalBounds().left > this->window->getSize().x - this->players[i].getGlobalBounds().width)
		{
			this->players[i].setPosition(this->window->getSize().x - this->players[i].getGlobalBounds().width, this->players[i].getGlobalBounds().top);
		}
		//if player goes to all the way to up
		if (this->players[i].getGlobalBounds().top < 0.f)
		{
			this->players[i].setPosition(this->players[i].getGlobalBounds().left, 0.f);
		}
		//if player goes to all the way bottom
		else if (this->players[i].getGlobalBounds().top > this->window->getSize().y - this->players[i].getGlobalBounds().height)
		{
			 this->players[i].setPosition(this->players[i].getGlobalBounds().left, this->window->getSize().y - this->players[i].getGlobalBounds().height *2);
		}
	}
}

/*
if player's bullet go all the way to right, delete it from the vector
*/
void Game::updateBulletBoundary()
{
	for (size_t i = 0; i < this->players[i].getBullets().size(); i++)
	{
		for (size_t j = 0; j < this->players[i].getBullets().size(); j++)
		{
			if (this->players[i].getBullets()[j].getglobalBounds().left >
				this->window->getSize().x + this->players[i].getBullets()[j].getglobalBounds().width)
			{
				this->players[i].getBullets().erase(this->players[i].getBullets().begin() + j);
			}
		}
	}
}

/*
update enemy respawning time
if respawn condition met, respawn the enemy
*/
void Game::updateSpawnEnemy()
{
	if (this->enemySpawnTimer < this->enemySpawnTimerMax)
	{
		this->enemySpawnTimer++;
	}
	if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
	{
		this->enemies.push_back(Enemy(&this->enemyTextures[0], this->window->getSize(),
			 sf::Vector2f(-1.f, -0.3f)));
		this->enemySpawnTimer = 0;
	}
}

/*
updates all enemy on the screen
*/
void Game::updateEnemy()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].update();
	}
}


/*
if enemy hits left side of the screen, delete it from the vector
*/
void Game::updateEnemyBoundary()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		if (this->enemies[i].getPosition().x < 0.f || this->enemies[i].getglobalBounds().top < 0.f)
			this->enemies.erase(this->enemies.begin() + i);
	}

}

/*
check player and enemy collision
check player's bullet and enemy collision
check player's bullet and boss character collision
*/
void Game::updateCombat()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		for (size_t k = 0; k < this->enemies.size(); k++)
		{
			//check whether player and enemy get collided
			if (this->players[i].getGlobalBounds().intersects(this->enemies[k].getglobalBounds()))
			{
				//if collides, playere loses 3 hp
				this->players[i].reduceHp(3);
				//delete that collided enemy 
				this->enemies.erase(this->enemies.begin() + k);
				return;
			}
			//check whether player bullet and enemy get collided
			for (size_t j = 0; j < this->players[i].getBullets().size(); j++)
			{
				//if collides
				if (this->players[i].getBullets()[j].getglobalBounds().intersects(this->enemies[k].getglobalBounds()))
				{
					//erase that player's bullet
					this->players[i].getBullets().erase(this->players[i].getBullets().begin() + j);

					//if enemies hp is over 1
					if (this->enemies[k].getHp() >= 1)
					{
						//reduce enemies current hp
						this->enemies[k].updatetakeDamage(this->players[i].getDamage());
						//enemy kickback little bit
						this->enemies[k].enemyGotHit();
						/*
						if enemies hp <= 0
						delete that enemy from the vector
						get points for destroying the enemy
						*/
						if (this->enemies[k].isDead() == true)
						{
							this->points += this->enemies[k].getPoints();
							this->enemies.erase(this->enemies.begin() + k);
							//std::cout << this->enemies.size() << std::endl;
						}
						return;
					}
				
				}
				/*
				if player's bullet hits the boss
				*/
				else if (this->boss && !this->bosskilled&& this->players[i].getBullets()[j].getglobalBounds().intersects(this->boss->getglobalBounds()))
				{
					//delete tha player's bullet
					this->players[i].getBullets().erase(this->players[i].getBullets().begin() + j);
					if (this->boss->getHp() >= 1)
					{
						//boss takes damage
						this->boss->updatetakeDamage(this->players[i].getDamage());
						/*
						if boss hp <= 0
						set bosskillled variable to true
						delete that boss
						*/
						if (this->boss->isDead())
						{
							delete this->boss;
							this->bosskilled = true;
						}
						return;
					}
					
				}
		
			}
		}
	} 
}

/*
update text gui
*/
void Game::updateText()
{
	//player header set position
	//player header string set up
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->playerText[i].setPosition(this->players[i].getPosition().x+this->players[i].getGlobalBounds().width/2, this->players[i].getPosition().y - 10.f);
	}
	std::stringstream ss;
	ss << "POINT: " << this->points << "\n";
	this->textpoint.setString(ss.str());
}

/*
update hp bar
*/
void Game::updateHpbar()
{
	/*
	set up hp bar and hpmax bar
	calculate percentile of current hp based on hpmax.
	apply current hp to hpbar
	*/
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->playerHpBarList[i].setPosition(this->players[i].getPosition().x + 30.f,
			this->players[i].getPosition().y + 80.f);
		this->playerHpBarMaxList[i].setPosition(this->players[i].getPosition().x + 30.f,
			this->players[i].getPosition().y + 80.f);
		float playerhpPercent = static_cast<float>(this->players[i].getHp()) / this->players[i].getHpMax();
		this->playerHpBarList[i].setSize(sf::Vector2f(100.f * playerhpPercent, this->playerHpBarList[i].getSize().y));
	}
	/*
	hp bar, hpmax bar for boss character
	apply current hp to hpbar
	*/
	if (this->points > 60 && !this->bosskilled && this->bosspoint)
	{
		this->bossHpBar.setPosition(this->boss->getPosition().x + 60.f, this->boss->getPosition().y + 350);
		float bosshpPercent = static_cast<float>(this->boss->getHp()) / this->boss->getHpMax();
		this->bossHpBar.setSize(sf::Vector2f(200.f * bosshpPercent, this->bossHpBar.getSize().y));
		this->bossHpBarMax.setPosition(this->boss->getPosition().x + 60.f, this->boss->getPosition().y + 350.f);
	}
	
}

/*
check whether points meet boss condition
*/
void Game::updatePointToBoss()
{
	//if points above 60, let boss appear on the screen
	//std::cout << this->points << std::endl;
	if (this->points > 60 && !this->bosskilled && !this->bosspoint)
	{
		this->bosspoint = true;
		this->boss = new Boss(this->bossTexture, this->bossBulletTexture, this->window->getSize());
	}
}

/*
check player and boss's bullet collision
*/
void Game::updateBossCombat()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		for (size_t j = 0; j < this->boss->getBullets().size(); j++)
		{
			//if player gets hit by boss's bullet
			//delete that boss's bullet from the vector
			if (this->players[i].getGlobalBounds().intersects(this->boss->getBullets()[j].getglobalBounds()))
			{
				this->boss->getBullets().erase(this->boss->getBullets().begin() + j);
				//player loses 3 hp
				this->players[i].reduceHp(3);
				return;
			}

		}
	}
}

/*
update boss bullet boundary.
if it hits left side of the screen
erase it from the vector
*/
void Game::updateBossBulletBoundary()
{
	for (size_t i = 0; i < this->boss->getBullets().size(); i++)
	{
		if (this->boss->getBullets()[i].getPosition().x < 0.f)
			this->boss->getBullets().erase(this->boss->getBullets().begin() + i);
	}
	std::cout << this->boss->getBullets().size() << std::endl;
}



/*
Render
*/
void Game::render()
{
	//clear window
	this->window->clear();

	//draw background
	this->window->draw(this->backgroundSprite);
	//draw player
	this->renderPlayer();
	//draw enemy
	this->renderEnemy();
	//if boss appeared, render boss related section
	if(this->bosspoint && !this->bosskilled)
		this->boss->render(*this->window);
	//draw text and hpbar related
	this->renderText();
	this->renderHpBar();
	this->renderGameOver();

	//display
	this->window->display();

}

/*
render player
if player hp =<0, do not render 
*/
void Game::renderPlayer()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		if(!this->players[i].isDead())
			this->players[i].render(*this->window);
	}
}

/*
render enemy
*/
void Game::renderEnemy()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].render(*this->window);
	}
}

/*
render text,
if player hp <= 0, do not render players header
*/
void Game::renderText()
{
	for (size_t i = 0; i < this->playerText.size(); i++)
	{
		if (!this->players[i].isDead())
			this->window->draw(this->playerText[i]);
	}
	this->window->draw(this->textpoint);
}

/*
render hpbars
if player hp <= 0, do not render players hpbar
if boss appears, render boss's hpbar
*/
void Game::renderHpBar()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		if (!this->players[i].isDead())
		{
			this->window->draw(this->playerHpBarMaxList[i]);
			this->window->draw(this->playerHpBarList[i]);
		}
	}
	if (this->points > 20 && !this->bosskilled && this->bosspoint)
	{
		this->window->draw(this->bossHpBarMax);
		this->window->draw(this->bossHpBar);
	}
}

/*
if boss is dead or player1 is dead.
Make screen black and show gameover gui
*/
void Game::renderGameOver()
{
	if (this->bosskilled || (this->players[0].isDead()))
	{
		this->window->clear(sf::Color::Black);
		this->window->draw(this->gameOverText);
	}


}
