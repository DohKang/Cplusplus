#pragma once

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"


class Game
{
private:
	RenderWindow *window;
	
	Font font;
	std::vector<Text> followPlayerText;
	std::vector<Text> staticPlayerText;

	//Player
	std::vector<Texture> textures;
	std::vector<Player> players;

	//Enemy
	std::vector<Enemy> enemies;
	std::vector<Enemy> enemiesSaved;
	Text enemyText;

	int enemySpawnTimer;
	int enemySpawnTimerMax;

	Texture playerTexture;
	Texture bulletTexture;
	Texture mainGunTexture01;


	void initUI();
public:
	Game(RenderWindow *window);
	virtual ~Game();


	//Accessors
	inline RenderWindow &getwindow() { return *this->window; }


	//Setters

	
	//Functions
	void UIupdate();
	void CombatUpdate();
	void Update();
	void Draw();
	void DrawUI();
};

