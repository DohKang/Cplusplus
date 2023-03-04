#include "Game.h"

void Game::initFont()
{
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << " ! ERROR::GAME::INITFONT::Couldn't not LOAD Fonts/PixellettersFull.ttf" << "\n";
	}
}

void Game::initText()
{
	//gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(24);

	//End game text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::White);
	this->endGameText.setCharacterSize(60);
	this->endGameText.setPosition(sf::Vector2f(20, 300));
	this->endGameText.setString("Thank you for playing");

}

void Game::initVariables()
{
	this->endGame = false;
	this->window = nullptr;
	this->spawnTimerMax = 10.0f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
	this->points = 0;

}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game_2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
	

}


//Destructor
Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

//Functions


const bool Game::running() const
{
	return this->window->isOpen() && this->getEndGame() == false;
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

void Game::spwanSwagBalls()
{
	//Timer
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 1.0f;
	}
	else 
	{
		if (this->swagBalls.size() < this->maxSwagBalls)
		{
			this->swagBalls.push_back(SwagBall(*this->window, this->randBallType()));
			this->spawnTimer = 0.0f;
		}
		
		
	}
}

const int Game::randBallType() const
{
	int type = SwagBallTypes::DEFAULT;
	int randValue = rand() % 100 + 1;
	if (randValue > 30 && randValue <= 80)
		type = SwagBallTypes::DAMAGING;
	else if (randValue > 80 && randValue <= 100)
		type = SwagBallTypes::HEALING;


	return type;
}

void Game::updatePlayer()
{
	this->player.update(this->window);
	if (this->player.getHp() <= 0)
	{
		this->endGame = true;
	}
}

void Game::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getshape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			switch (this->swagBalls[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				break;
			case SwagBallTypes::DAMAGING:
				this->player.takeDamage(1);
				break;
			case SwagBallTypes::HEALING:
				this->player.gainHealth(1);
				break;
			default:
				break;
			}

			//Add points
			this->points++;
			//Remove the ball
			this->swagBalls.erase(this->swagBalls.begin() + i);
			
		}
	}

}

void Game::updateGui()
{
	std::stringstream ss;
	ss << "- Points: " << this->points << "\n"
		<< "- Health: " << this->player.getHp() << " / " << this->player.getHpMAx() << "\n";

	this->guiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();
	if (this->endGame == false)
	{
		this->spwanSwagBalls();
		this->updatePlayer();
		this->updateCollision();
		this->updateGui();
	}
	
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();
	this->player.render(this->window);
	for (auto i : this->swagBalls)
	{
		i.render(*this->window);
	}
	//Render
	//Render gui
	this->renderGui(this->window);

	if (this->endGame == true)
	{
		this->window->draw(this->endGameText);
	}

	this->window->display(); // frame drawing
}
