#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include <map>
#include <sstream>


class Game
{
private:
	//window
	sf::VideoMode videoMode;
	sf::RenderWindow *window;

	//GUI
	sf::Font font;
	sf::Text PointText;
	sf::Text gameOverText;
	//Player Gui
	
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	//Points
	unsigned points;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	//Player
	Player* player;
	
	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	/*Enemy* enemy;*/

	//initialize
	void initSystems();
	void initWindow();
	void initTextures();
	void initWorld();
	void initGui();
	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();


	//functions
	void running();


	//update
	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void updateCollision();
	void updateWorld();
	void updateCombat();
	void updateGui();
	void update();
	//render
	void renderGui();
	void renderWorld();
	void render();
};

#endif
