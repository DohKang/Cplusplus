#include "Game.h"

void Game::initHpBar()
{
	this->playerHpBarMax.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBarMax.setFillColor(sf::Color::Red);
	this->playerHpBarMax.setPosition(sf::Vector2f(20.f, 20.f));
	
	this->playerHpBar = this->playerHpBarMax;
	this->playerHpBar.setFillColor(sf::Color::Green);

}

void Game::initVariables()
{
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window= new sf::RenderWindow(this->videoMode, "Game_3", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
}

void Game::initTexture()
{
	if (!this->BackgroundTex.loadFromFile("Texture/background1.png"))
	{
		std::cout << "ERROR:INITTEXTURE::COULDN'T NOT LOAD BACKGROUND IMAGE";
	}
	this->background.setTexture(this->BackgroundTex);
}

void Game::initSprite()
{
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initBullets()
{
	this->textures["Bullet"] = new sf::Texture();
	this->textures["Bullet"]->loadFromFile("Texture//bullet.png");
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED to load font" << "\n";
	}
	this->text.setPosition(700.f, 25.f);
	this->text.setFont(this->font);
	this->text.setCharacterSize(20);
	this->text.setFillColor(sf::Color::White);


	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game over");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f
	);
}
	

Game::Game()
{

	this->initBullets();
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initPlayer();
	this->initEnemies();
	this->initFonts();
	this->initHpBar();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	for (auto* i : this->Bullets)
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
	while (this->window->isOpen())
	{
		
		this->pollevents();
		
		if (this->player->getHp() > 0)
		{
		
			this->update();
			this->render();
		}
		else
		{
			break;
		}
	}
}



void Game::pollevents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
		{
			this->window->close();
		}
		if(this->ev.KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
		{ 
			this->window->close();
		}
	}

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
		this->Bullets.push_back(new Bullet(this->textures["Bullet"],
			this->player->getPos().x + this->player->getBounds().width/2.f,
			this->player->getPos().y,
			0.f, -1.f, 5.f));

	}

}
void Game::updateEnemies()
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 10.f, -50.f));
		this->spawnTimer = 0.f;
	}
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		if (enemy->getBounds().top > this->window->getSize().y)
		{
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
	}


}
void Game::updateText()
{
	std::stringstream ss;
	ss << "-Points: " << this->points << "\n";
	this->text.setString(ss.str());

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));


}
void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->Bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->Bullets[k]->getbounds()))
			{
				this->points += this->enemies[i]->getPoints();
				delete this->enemies[i];
				this->enemies.erase(enemies.begin() + i);

				delete this->Bullets[k];
				this->Bullets.erase(this->Bullets.begin() + k);
				
				enemy_deleted = true;
			}
		}
	}
}
void Game::updateBulletts()
{
	unsigned counter = 0;
	for (auto* bullet : this->Bullets)
	{
		bullet->update();

		//bullet culling
		if (bullet->getbounds().top + bullet->getbounds().height < 0.f)
		{
			delete this->Bullets.at(counter);
			this->Bullets.erase(this->Bullets.begin() + counter);
		}
		++counter;
	}
}
void Game::updateplayerBoundary()
{
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
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

void Game::update()
{
	this->updateInput();
	this->updateplayerBoundary();
	this->updateEnemies();
	this->player->update();
	this->updateBulletts();
	this->updateCombat();
	this->updateText();
}

void Game::renderBackground()
{
	this->window->draw(this->background);
}

void Game::renderEnemies()
{
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
}

void Game::renderPlayer()
{
	if (this->player->getHp() > 0)
	{
	
	this->player->render(*this->window);

	}
}
void Game::renderBullets()
{
	for (auto* bullet : this->Bullets)
	{
		bullet->render(*this->window);
	}
}

void Game::renderText()
{
	this->window->draw(this->text);
	this->window->draw(this->playerHpBarMax);
	this->window->draw(this->playerHpBar);
	if (this->player->getHp() <= 0)
	{
		this->window->clear(sf::Color::Black);
		this->window->draw(this->gameOverText);
	}
}

void Game::render()
{
	this->window->clear();

	this->renderBackground();
	this->renderText();
	this->renderPlayer();
	this->renderEnemies();
	this->renderBullets();

	this->window->display();
}
