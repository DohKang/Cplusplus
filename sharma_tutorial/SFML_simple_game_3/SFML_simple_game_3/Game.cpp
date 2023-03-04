#include "Game.h"

void Game::initSystems()
{
	this->points = 0;
}

//private functions
void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game_3", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Texture/bullet.png");

}
void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Texture/background1.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT  LOAD BACKGROUND TEXTURE" << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
}
void Game::initGui()
{
	//Load fonts
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED to load font" << "\n";
	}

	//Init point text
	this->PointText.setPosition(700.f, 25.f);
	this->PointText.setFont(this->font);
	this->PointText.setCharacterSize(20);
	this->PointText.setFillColor(sf::Color::White);

	//this->PointText.setString("test");
	//I)nit point text

		//Init player Gui
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color::Green);

	
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width /2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);
}
void Game::initPlayer()
{
	this->player = new Player();
	//this->enemy = new Enemy(20.f, 20.f);
}
void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}
//constructor/ destructor.
Game::Game()
{
	this->initSystems();
	this->initWindow();
	this->initPlayer();
	this->initWorld();
	this->initTextures();
	this->initEnemies();
	this->initGui();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	
	//delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	for (auto* i : this->bullets)
	{
		delete i;
	}
	for (auto* i : this->enemies)
	{
		delete i;
	}

}

void Game::running()
{
	while (window->isOpen())
	{
		this->updatePollEvents();
		if (this->player->getHp() > 0)
		{
		
			this->update();
			this->render();
		}
	}

}

void Game::updatePollEvents()
{

}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.f, 1.f);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], 
			this->player->getPos().x+ this->player->getBounds().width/2.f,
			this->player->getPos().y,
			0.f, -1.f, 5.f));
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			//--counter;

			//std::cout << this->bullets.size() << "\n";
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	//Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
		this->spawnTimer = 0.f;
		
	}
	//updatedasdw
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//Enemy hit bottom
		if (enemy->getbounds().top > this->window->getSize().y)
		{
			//Delete bullet
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			//--counter;

			//std::cout << this->bullets.size() << "\n";
		}
		//enemy player collision
		else if (enemy->getbounds().intersects(this->player->getBounds()))
		{
			
			
			//--counter;
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}
}

void Game::updateCollision()
{
	//leftworld collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//right
	if (this->player->getBounds().left > this->window->getSize().x - this->player->getBounds().width)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	if (this->player->getBounds().top > this->window->getSize().y - this->player->getBounds().height)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateWorld()
{
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted ==false; k++)
		{
			if(this->enemies[i]->getbounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getpoints();
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
				
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				
				
				enemy_deleted = true;
			}
		}
	}
}

void Game::updateGui()
{
	std::stringstream ss;
	ss << "-Points: " << this->points << "\n";
	this->PointText.setString(ss.str());

	//Update player Gui
	//this->player->setHp(1);
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::update()
{

	this->updateInput();
	this->updateCombat();
	this->updateBullets();
	this->player->update();
	this->updateCollision();
	this->updateEnemies();
	this->updateWorld();
	this->updateGui();

}

void Game::renderGui()
{
	this->window->draw(this->PointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	//Draw world
	this->renderWorld();
	//draw all the stuffs
	this->player->render(*this->window);
	
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	this->renderGui();
	//this->enemy->render(this->window);
	//Game over screen
	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
	}
	this->window->display();

}