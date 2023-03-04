

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <iostream>
#include <vector>
#include <ctime>
#include <sstream> // let user use string with different data types inside


/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game
{
private:
	//private variables
	//window
	
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	
	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Game Logic
	bool endGame;
	unsigned points; //only positive
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game objects
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;
	
	//private functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Functions
	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
};

#endif

