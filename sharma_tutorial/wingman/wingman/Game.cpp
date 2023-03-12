#include "Game.h"

enum textures { player = 0, laser01, missile01, maingun01, enemy01 };

Game::Game(RenderWindow *window)
{
	this->window = window;
	this->window->setFramerateLimit(60);

	this->font.loadFromFile("Fonts/Dosis-Light.ttf");

	//init textures
	this->textures.push_back(Texture());
	this->textures[player].loadFromFile("Textures/ship.png");
	this->textures.push_back(Texture());
	this->textures[laser01].loadFromFile("Textures/bullet.png");
	this->textures.push_back(Texture());
	this->textures[missile01].loadFromFile("Textures/missileTex01.png");
	this->textures.push_back(Texture());
	this->textures[maingun01].loadFromFile("Textures/spr_missile.png");
	this->textures.push_back(Texture());
	this->textures[maingun01].loadFromFile("Textures/spr_missile.png");
	this->textures.push_back(Texture());
	this->textures[enemy01].loadFromFile("Textures/enemy.png");

	//init player
	this->players.push_back(Player(this->textures));
	Enemy e1(&this->textures[enemy01], this->window->getSize(),
		Vector2f(0.f, 0.f), Vector2f(-1.f, -1.f), Vector2f(0.1f, 0.1f),
		0, rand() % 3 + 1, 3, 1);

	this->enemiesSaved.push_back(Enemy(e1));
	this->enemySpawnTimerMax = 25;
	this->enemySpawnTimer = this->enemySpawnTimerMax;

	/*this->enemies.push_back(Enemy(&this->textures[enemy01], this->window->getSize(),
		Vector2f(0.f, 0.f), Vector2f(-1.f, 0.f), Vector2f(0.1f, 0.1f),
		0, rand() % 3 + 1, 3, 1));*/

	//this->players.push_back(Player(this->textures,
	//Keyboard::Numpad8, Keyboard::Numpad5, 
	//Keyboard::Numpad4, Keyboard::Numpad6, 
	//Keyboard::Numpad0));
	this->initUI();
}

Game::~Game()
{

}


void Game::initUI()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		//Follow Text init
		Text tempText;
		tempText.setFont(this->font);
		tempText.setCharacterSize(12);
		tempText.setFillColor(sf::Color::White);
		tempText.setString(std::to_string(i));

		this->followPlayerText.push_back(Text(tempText));

		//Static Text Init
		tempText.setFont(this->font);
		tempText.setCharacterSize(12);
		tempText.setFillColor(sf::Color::White);
		tempText.setString("");
		this->staticPlayerText.push_back(Text(tempText));
	}
	this->enemyText.setFont(this->font);
	this->enemyText.setCharacterSize(21);
	this->enemyText.setFillColor(sf::Color::White);
	
}   



void Game::UIupdate()
{
	for (size_t i = 0; i < this->followPlayerText.size(); i++)
	{
		this->followPlayerText[i].setPosition(this->players[i].getPosition().x, this->players[i].getPosition().y-20.f);
		this->followPlayerText[i].setString(std::to_string(i+1) + " | " + this->players[i].getHpAsString());
	}
	for (size_t i = 0; i < this->staticPlayerText.size(); i++)
	{

	}
}

void Game::CombatUpdate()
{
}

void Game::Update()
{
	//Update timers
	if (this->enemySpawnTimer < this->enemySpawnTimerMax)
	{
		this->enemySpawnTimer++;
	}
	if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
	{
		this->enemies.push_back(Enemy(&this->textures[enemy01], this->window->getSize(),
			Vector2f(0.f, 0.f), Vector2f(-1.f, 0.f), Vector2f(0.1f, 0.1f),
			0, rand() % 3 + 1, 3, 1));
		this->enemySpawnTimer = 0; //Reset timer
	}

	//player update
	for (size_t i = 0; i < this->players.size(); i++)
	{	//Update player

		this->players[i].Update(this->window->getSize());

		//bullet update
		for (size_t j = 0; j < this->players[i].getBullets().size(); j++)
		{
			this->players[i].getBullets()[j].update();
			//enemy collision update
			for (size_t k = 0; k < this->enemies.size(); k++)
			{
				
				if (this->players[i].getBullets()[j].getGlobalBounds().intersects(this->enemies[k].getglobalBounds()))
				{

					this->players[i].getBullets().erase(this->players[i].getBullets().begin() + j);
					if (this->enemies[k].getHp() > 0)
						this->enemies[k].takeDamage(this->players[i].getDamage());
					if (this->enemies[k].getHp() <= 0)
					{
						this->enemies.erase(this->enemies.begin() + k);
						return;
					}
					
				}
				
			}
			if(this->players[i].getBullets()[j].getPosition().x > this->window->getSize().x)
			{
				
				this->players[i].getBullets().erase(this->players[i].getBullets().begin() + j);
				return;
			}	
		}
	}
	//enemy window boundary//update
	for (size_t i = 0; i < this->enemies.size(); i++)
	{ 
		for (size_j)
		this->enemies[i].Update();
		 if (this->enemies[i].getPosition().x + this->enemies[i].getglobalBounds().width < 0)
		{
			this->enemies.erase(this->enemies.begin() + i);
			return;
		}
	}
	//Update ui
	this->UIupdate();
}

void Game::Draw()
{
	this->window->clear();
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].Draw(*this->window);
	}
	this->DrawUI();
	this->window->display();
}

void Game::DrawUI()
{
	for (size_t i = 0; i < this->followPlayerText.size(); i++)
	{
		this->window->draw(this->followPlayerText[i]);
	}
	for (size_t i = 0; i < this->staticPlayerText.size(); i++)
	{
		this->window->draw(this->staticPlayerText[i]);
	}
	for (size_t i = 0; i < enemies.size(); i++)
	{
		this->enemyText.setPosition(this->enemies[i].getPosition());
		this->enemyText.setString(std::to_string(this->enemies[i].getHp())+ 
											"/" +
								 std::to_string(this->enemies[i].getHpMax()));
		this->enemies[i].Draw(*this->window);
		this->window->draw(this->enemyText);
	}

}
