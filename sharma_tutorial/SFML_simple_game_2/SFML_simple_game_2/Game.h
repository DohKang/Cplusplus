#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <ctime>
#include "Player.h"
#include "SwagBall.h"
#include <vector>
#include <sstream>

class Game
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Font, Text
	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	void initFont();
	void initText();


	//Game logic
	bool endGame;
	int points;

	//Player
	Player player;

	std::vector<SwagBall> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	//function
	void initVariables();
	void initWindow();
	


public:
	//Constructor and Destructor
	Game();
	~Game();

	//Accessors
	const bool& getEndGame() const;
	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();

	void spwanSwagBalls();
	const int randBallType() const;
	void updatePlayer();
	void updateCollision();
	void updateGui();
	void update();
	void renderGui(sf::RenderTarget* targeet);
	void render();
};

#endif
