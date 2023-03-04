#include "Game.h"

void Game::initVairables()
{
	this->window = nullptr;

	//game logic
	this->gameOver = false;
	this->maxEnemies = 10;
	this->enemySpawnTimerMax = 20.0f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->health = 20;
	this->point = 0;
	this->mouseHeld = false;

}

void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 1200;
	this->window = new sf::RenderWindow(this->videoMode, "Game_1", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	this->enemy.setSize(sf::Vector2f(250.0f, 50.0f));
	/*this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));*/
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Blue);
	//this->enemy.setOutlineThickness(5.0f);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "Error::Game::INITFONTS::Fail to load font!" << "\n";
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::Yellow);
	this->uiText.setString("Hello");
}



Game::Game()
{
	this->initVairables();
	this->initWindow();
	this->initEnemies();
	this->initText();
	this->initFonts();

}
Game::~Game()
{
	delete this->window;
}



const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getGameOver() const
{
	return this->gameOver;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();;
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::spawnEnemies()
{
	/*
	* spawn enemy at random position
	
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.0f/* static_cast<float>(rand()% static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))*/
	);

	//randomize enemy type
	int type = rand() % 5;
	switch (type)
	{
	case 0:
		this->enemy.setFillColor(sf::Color::Magenta);
		this->enemy.setSize(sf::Vector2f(120.0f, 60.0f));
		break;
	case 1:
		this->enemy.setFillColor(sf::Color::Blue);
		this->enemy.setSize(sf::Vector2f(145.0f, 60.0f));
		break;
	case 2:
		this->enemy.setFillColor(sf::Color::Cyan);
		this->enemy.setSize(sf::Vector2f(175.0f, 60.0f));
		break;
	case 3:
		this->enemy.setFillColor(sf::Color::Yellow);
		this->enemy.setSize(sf::Vector2f(200.0f, 60.0f));
		break;
	case 4:
		this->enemy.setFillColor(sf::Color::Red);
		this->enemy.setSize(sf::Vector2f(250.0f, 60.0f));
		break;
	default:
		this->enemy.setFillColor(sf::Color::White);
		this->enemy.setSize(sf::Vector2f(100.0f, 60.0f));
		break;
	}
	//spawn enemy
	this->enemies.push_back(this->enemy);
	
}

void Game::updateMousePosition()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}

void Game::updateEnemies()
{
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemies();
			this->enemySpawnTimer = 0.0f;
		}

		else
		{
			this->enemySpawnTimer += 1.0f;
		}
	}
	
	for (int i = 0; i < this->enemies.size(); i++)
	{
		if (this->enemies[i].getFillColor() == sf::Color::Magenta)
		{
			this->enemies[i].move(0.0f, 15.0f);
		}
		else if (this->enemies[i].getFillColor() == sf::Color::Blue)
		{
			this->enemies[i].move(0.0f, 2.0f);
		}
		else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
		{
			this->enemies[i].move(0.0f, 12.0f);
		}
		else if (this->enemies[i].getFillColor() == sf::Color::Yellow)
		{
			this->enemies[i].move(0.0f, 10.0f);
		}
		else if (this->enemies[i].getFillColor() == sf::Color::Red)
		{
			this->enemies[i].move(0.0f, 5.0f);
		}
		else if (this->enemies[i].getFillColor() == sf::Color::White)
		{
			this->enemies[i].move(0.0f, 7.0f);
		}
		
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health--;
			std::cout << "Health: " << this->health << "\n";
		}
	}

	//mouse action

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i <this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					if (this->enemies[i].getFillColor() == sf::Color::Magenta)
					{
						this->point += 10;
					}
					else if (this->enemies[i].getFillColor() == sf::Color::Blue)
					{
						this->point += 7;
					}
					else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
					{
						this->point += 5;
					}
					else if (this->enemies[i].getFillColor() == sf::Color::Yellow)
					{
						this->point += 3;
					}
					else if (this->enemies[i].getFillColor() == sf::Color::Red)
					{
						this->point += 1;
					}
					else if (this->enemies[i].getFillColor() == sf::Color::White)
					{
						this->point += 100000;
					}
					std::cout << "Points: " << this->point << "\n";
					
					//delete enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}

}

void Game::updateText()
{
	std::stringstream ss;
	ss << "points: " << this->point << "\n"
		<< "Health " << this->health << "\n";
	this->uiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();
	if (!this->gameOver)
	{
		this->updateMousePosition();
		this->updateEnemies();
		this->updateText();
	}
	if (this->health <= 0)
	{
		this->gameOver = true;
	}
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	for (auto &e: this->enemies)
	target.draw(e);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::render()
{
	this->window->clear();

	//draw game object
	this->renderEnemies(*this->window);
	this->renderText(*this->window);
	
	this->window->display();
}
