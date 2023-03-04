#include "Game.h"

void Game::initFont()
{
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << "! ERROR::GAME::INITFONT::Couldn't not Load Fonts, PixelletterFUll.ttf" << "\n";
	}
}

void Game::initText()
{
	this->guitext.setFont(this->font);
	this->guitext.setFillColor(sf::Color::White);
	this->guitext.setCharacterSize(20);

	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::White);
	this->endGameText.setCharacterSize(20);
	this->endGameText.setPosition(40, 300);
	this->endGameText.setString("Thank you for playing");
}

void Game::initVariables()
{
	this->window = nullptr;
	this->gameOver = false;
	this->spawnTimerMax = 20.0f;
	this->spawnTImer = this->spawnTimerMax;
	this->maxSwagBall = 20;
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game_2", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getGameOver()
{
	return this->gameOver;
}

const bool Game::running()
{
	return this->window->isOpen() && !this->gameOver ;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateCollision()
{
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getshape().getGlobalBounds().intersects(this->swagBalls[i].getshpe().getGlobalBounds()))
		{
			switch (this->swagBalls[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				this->points++;
				break;
			case SwagBallTypes::DAMAGING:
				this->player.playergetdamage(1);
				if (this->points > 0)
				{
					this->points--;
				}
				break;
			case SwagBallTypes::HEALING:
				this->player.playergetheal(1);
				this->points++;
				break;
			default:
				break;
			}
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}
}

void Game::updateScoreCount()
{
	if (this->player.getHp() <= 0)
	{
		this->gameOver = true;
	}
}

void Game::updateGui()
{
	std::stringstream ss;
	ss << "- Points: " << this->points << "\n"
		<< "- Health: " << this->player.getHp() << " / " << this->player.getHpMax() << "\n";
	this->guitext.setString(ss.str());
}

void Game::spawnSwagBalls()
{
	if (this->spawnTImer < this->spawnTimerMax)
	{

		this->spawnTImer += 1.0f; 
	}
	else
	{
		if (this->swagBalls.size() < this->maxSwagBall)
		{
			this->swagBalls.push_back(SwagBall(*this->window, this->randBallType()));
			this->spawnTImer = 0.0f;
		}
	}
}

const int Game::randBallType() const
{
	int type = SwagBallTypes::DEFAULT;
	int randvalue = rand() % 100 + 1;
	if (randvalue > 50)
	{
		type = SwagBallTypes::DAMAGING;
	}
	if (randvalue > 30 && randvalue <= 50)
	{
		type = SwagBallTypes::HEALING;
	}
	return type;
}

void Game::updatePlayer()
{
	this->player.update(this->window);
}

void Game::update()
{
	this->pollEvents();
	if (!this->gameOver)
	{
		this->spawnSwagBalls();
		this->updatePlayer();
		this->updateCollision();
		this->updateScoreCount();
		this->updateGui();
	}

}

void Game::renderPlayer()
{
	this->player.render(this->window);
}

void Game::render()
{
	this->window->clear();
	this->renderPlayer();
	this->window->draw(this->guitext);
	for (auto i : swagBalls)
	{
		i.render(this->window);
	}
	if (this->gameOver == true)
	{
		window->clear(sf::Color::Black);
		this->window->draw(this->endGameText);
	}
	this->window->display();
} 

