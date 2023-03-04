#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

class Game
{
private:
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
	
	//Game logic
	bool gameOver;
	int maxEnemies;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int health;
	unsigned point;
	bool mouseHeld;

	//Game objects
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

private:
	//init_functions
	void initVairables();
	void initWindow();
	void initEnemies();
	void initFonts();
	void initText();




public:
	//Constructor, destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getGameOver() const;
	
	//Functions
	void pollEvents();
	
	//Update
	void spawnEnemies();
	void updateMousePosition();
	void updateEnemies();
	void updateText();
	void update();
	

	//Render
	void renderEnemies(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void render();
};

#endif
