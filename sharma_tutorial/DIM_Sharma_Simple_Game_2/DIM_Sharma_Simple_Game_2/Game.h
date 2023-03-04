#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "SwagBall.h"
#include <vector>
#include <sstream>
class Game
{

	//window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//Fonts, Text
	sf::Font font;
	sf::Text guitext;
	sf::Text endGameText;

	void initFont();
	void initText();
	
	//init variables
	bool gameOver;
	int points;
	

	//Player
	Player player;

	//Swag balls
	float spawnTImer;
	float spawnTimerMax;
	int maxSwagBall;
	std::vector<SwagBall> swagBalls;
	//initializer
	void initVariables();
	void initWindow();
	
public:
	Game();
	virtual ~Game();

	//Accessors
	const bool getGameOver();
	const bool running();

	//swag balls
	void spawnSwagBalls();
	const int randBallType() const;
	//Update
	void pollEvents();
	void updatePlayer();
	void updateCollision();
	void updateScoreCount();
	void updateGui();
	void update();

	//Render
	void renderPlayer();
	void render();
};
#endif