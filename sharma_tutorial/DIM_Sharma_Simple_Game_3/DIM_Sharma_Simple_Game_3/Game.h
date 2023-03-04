#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Player.h"
#include <vector>
#include "Enemy.h"	
#include <map>
#include "Bullet.h"
#include <sstream>
class Game
{
private:
	//Window event
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event ev;

	//font gui
	sf::Font font;
	sf::Text text;
	sf::Text gameOverText;

	//player
	Player *player;
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarMax;
	//enemy
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	//Bullet
	std::map < std::string, sf::Texture*> textures;
	std::vector<Bullet*> Bullets;

	//variables
	
	unsigned points;
	//background
	sf::Texture BackgroundTex;
	sf::Sprite background;

	//Init
	void initHpBar();
	void initVariables();
	void initWindow();
	void initTexture();
	void initSprite();
	void initPlayer();
	void initEnemies();
	void initBullets();
	void initFonts();

public:
	//const./ destruct
	Game();
	virtual ~Game();

	//game running
	void running();


	//updates
	void updateText();
	void updateCombat();
	void updateBulletts();
	void updateplayerBoundary();
	void pollevents();
	void updateInput();
	void updateEnemies();
	void update();


	//render
	void renderBackground();
	void renderEnemies();
	void renderPlayer();
	void renderBullets();
	void renderText();
	void render();
};


