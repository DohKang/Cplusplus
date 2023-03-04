#include "stdafx.h"
#include "Game.h"

/*
Constructor
Initiating all variables needed.
*/
Game::Game()
{
	this->initVariables();
	this->initWindows();
	this->initBackground();
	this->initPlayer();
	this->initBananas();
	this->initBat();
	this->initText();
	this->initHpBar();
}
/*
Destructor
Memory leak/loss prevention
*/
Game::~Game()
{
	delete this->window;
	delete this->background;
	delete this->player;
	for (auto* banana : this->bananas)
	{
		delete banana;
	}
	for (auto* Bat : this->bats)
	{
		delete Bat;
	}
}
/*
Creating winow screen
Set frame rate
*/
void Game::initWindows()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Pandanana", sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

/*
Creating Background object
*/
void Game::initBackground()
{
	this->background = new Background();
}
/*
Creating Player object,
Set player position middle of x asix, bottom of y axis
*/
void Game::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(this->window->getSize().x / 2 - this->player->getBounds().width / 2, this->window->getSize().y - this->player->getBounds().height);
}

/*
creating map holds texture of banana
*/
void Game::initBananas()
{
	this->textures["BANANA"] = new sf::Texture();
	this->textures["BANANA"]->loadFromFile("Texture/banana.png");
}

/*
Creating variables for bats spawning routine
*/
void Game::initBat()
{
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
}

/*
Set up fonts
Text for points
Text for Gameover
*/
void Game::initText()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD FONT" << "\n";
	}
	this->textpoint.setFont(this->font);
	this->textpoint.setPosition(20.f, 30.f);
	this->textpoint.setCharacterSize(25);
	this->textpoint.setFillColor(sf::Color::Black);
	this->textpoint.setStyle(sf::Text::Bold);

	this->textHp.setFont(this->font);
	this->textHp.setPosition(0.f, 20.f);
	this->textHp.setCharacterSize(15);
	this->textHp.setFillColor(sf::Color::Black);
	this->textHp.setStyle(sf::Text::Bold);
	
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setString("		  Game Over\n Thank you for playing");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);
	

}
/*
Set up Player Hp Bar
*/
void Game::initHpBar()
{
	this->playerHpBar.setSize(sf::Vector2f(200.f, 20.f));
	this->playerHpBar.setFillColor(sf::Color::Green);
	this->playerHpBar.setPosition(20.f, 10.f);

	this->playerHpMaxBar = this->playerHpBar;
	this->playerHpMaxBar.setFillColor(sf::Color(250, 0, 0));
}

/*
initiating window pointer variable
*/
void Game::initVariables()
{
	this->window = nullptr;
}




/*
Game running function
*/
void Game::running()
{
	
	while (this->window->isOpen())
	{
		this->pollevents();
		if (this->player->getHp() > 0) //if player hp is less than 0, stop updating
		{		
			this->update();
			this->render();
		}

	}
}
/*
Poll any events happening in the screen
*/
void Game::pollevents()
{
	while( this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed: // click x button, close the screen
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) // press esc button, close the screen
				this->window->close();
			break;
		}
		if (this->ev.type == sf::Event::KeyReleased && //if user release keyboard key, reseting animation elapsed time
			(
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D )
			)
		{
			this->player->resetAnimationTimer();
		}
	}
}

/*
all updates
*/

void Game::update()
{
	this->player->update();
	this->updatePlayerBoundary();
	this->updateBananas();
	this->updateBananaBoundary();
	this->updateBat();
	this->updateBatBoundary();
	this->updateBB();
	this->updateBP();
	this->updateText();
	this->updateHpBar();

}
/*
updating the player's current hp status into bar format
*/
void Game::updateHpBar()
{
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(200.f * hpPercent, this->playerHpBar.getSize().y));
}


/*
Counting points
*/
void Game::updateText()
{
	std::stringstream ss;
	ss << "POINT: " << this->points << "\n";
	this->textpoint.setString(ss.str());

}

/*
If a bat collides with the player
player gets damage,
delete the bat pointer
erase the bat from the array
*/
void Game::updateBP()
{
	for (int i = 0; i < this->bats.size(); ++i)
	{
		if (this->bats[i]->getBounds().intersects(this->player->getBounds()))
		{
		
			this->player->getDamage(this->bats[i]->getDamage());
			delete this->bats[i];
			this->bats.erase(this->bats.begin() + i);
		}
	}
}

/*
when a banana collides with a bat
points increase
bat, banana pointers delete
bat, banana erase from its array
*/
void Game::updateBB()
{
	for (int i = 0; i < this->bananas.size(); i++)
	{
		bool enemyDeleted = false;
		for (int j = 0; j < this->bats.size() && enemyDeleted == false; j++)
		{
			if (this->bananas[i]->getBounds().intersects(this->bats[j]->getBounds()))
			{
				this->points += this->bats[j]->getPoints();
				delete this->bats[j];
				this->bats.erase(this->bats.begin() + j);

				delete this->bananas[i];
				this->bananas.erase(this->bananas.begin() + i);
				enemyDeleted = true;
			}
		}
	}
}

/*
control how quick bat respawn
*/
void Game::updateBat()
{
	this->spawnTimer += 1.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->spawnTimer = 0;
		this->bats.push_back(new Bat());
	}
}

/*
if a bat his the floor or completely go out of the  leftside of the screen
delete the bat pointer
erases the bat from the array
*/
void Game::updateBatBoundary()
{
	for (int i = 0; i < this->bats.size(); i++)
	{
		this->bats[i]->update();
		if (this->bats[i]->getBounds().top > this->window->getSize().y || this->bats[i]->getBounds().left + this->bats[i]->getBounds().width < 0.f)
		{
			delete this->bats[i];
			this->bats.erase(this->bats.begin() + i);
		}
	}
}

/*
if banana hits the top of the screen
delete the banana pointer
erase the banana from the array
*/
void Game::updateBananaBoundary()
{
	for (int i = 0; i < this->bananas.size(); i++)
	{
		this->bananas[i]->update();
		if (this->bananas[i]->getBounds().top + this->bananas[i]->getBounds().height < 0.f)
		{
			delete this->bananas[i];
			this->bananas.erase(this->bananas.begin() + i);
		}
	}
}

/*
whenever mouse left button is clicked and player attack availabilty is true
create a new banana object with arguement of *texture, x,y position for the banana
position is set to be middle of the player's width and player's y position
*/
void Game::updateBananas()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bananas.push_back(new Banana(this->textures["BANANA"],
			this->player->getPos().x+this->player->getBounds().width/2.f, this->player->getPos().y));
		
	}
}

/*
if player tries to go out of screen boundary,
set to left or right end of the screen
*/
void Game::updatePlayerBoundary()
{
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	if (this->player->getBounds().left > this->window->getSize().x - this->player->getBounds().width)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
}
/*
all rendering
*/
void Game::render()
{
	this->window->clear();
	this->renderBackground();
	this->renderPlayer();
	this->renderBanana();
	this->renderBat();
	this->renderText();
	this->renderHpBar();
	this->renderGameOver();
	this->window->display();
}
/*
background rendering
*/
void Game::renderBackground()
{
	this->background->render(*this->window);
}
/*
player rendering
*/
void Game::renderPlayer()
{
	this->player->render(*this->window);
}
/*
banana rendering
*/
void Game::renderBanana()
{
	for (auto* banana : this->bananas)
	{
		banana->render(*this->window);
	}
}
/*
bat rendering
*/
void Game::renderBat()
{
	for (auto* Bat : this->bats)
	{
		Bat->render(*this->window);
	}
}
/*
point text rendering
*/
void Game::renderText()
{
	this->window->draw(this->textpoint);
}
/*
hpbar rendering
*/
void Game::renderHpBar()
{
	this->window->draw(this->playerHpMaxBar);
	this->window->draw(this->playerHpBar);
}
/*
rendering
*/
void Game::renderGameOver()
{
	if (this->player->getHp() <= 0)
	{
		this->window->clear(sf::Color::Black);
		this->window->draw(this->gameOverText);
	}
}


