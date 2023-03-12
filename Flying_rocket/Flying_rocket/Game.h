#pragma once
class Game
{
public:
	//contructor, destructor
	Game();
	virtual ~Game();

private:
	//Window related variables
	sf::VideoMode videoMode;
	sf::RenderWindow *window;
	sf::Event ev;

	//Text related
	sf::Font font;
	std::vector<sf::Text> playerText;
	sf::Text gameOverText;
	sf::Text textpoint;

	//Player
	std::vector<sf::Texture> playerTextures;
	std::vector<sf::Texture> bulletTextures;
	std::vector<Player> players;
	

	//Enemy
	std::vector<sf::Texture> enemyTextures;
	std::vector<Enemy>enemies;
	//contorl hot fast a enemy respawns
	float enemySpawnTimerMax;
	float enemySpawnTimer;
	
	//Background
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::IntRect backgroundFrame;

	//background animation timer
	sf::Clock backgroundAnimationTimer;

	//points
	int points;

	//boss
	sf::Texture bossTexture;
	sf::Texture bossBulletTexture;
	Boss *boss;
	bool bosskilled;
	bool bosspoint;

	//player hpbar
	std::vector<sf::RectangleShape> playerHpBarList;
	std::vector<sf::RectangleShape> playerHpBarMaxList;

	//boss hpbar
	sf::RectangleShape bossHpBar;
	sf::RectangleShape bossHpBarMax;

	
	/*
	initializer
	*/
	//initialize various variables
	void initVariables();
	//initialize window
	void initWindows();
	//initialize background
	void initBackground();
	//initialize player and boss texture
	void initPlayerBoss();
	//enemy texture set up
	void initEnemy();
	//initialize text, hpbar
	void initText();
	void initHpBar();
	

public:
	//basic game engine
	void running();
	void pollEvents();

	/*
	Update
	*/
	void update();
	//background
	void updateBackgroundAnimation();
	//player
	void updatePlayer();
	//check boundaries
	void updatePlayerBoundary();
	void updateBulletBoundary();
	//enemy updates
	void updateSpawnEnemy();
	void updateEnemy();
	void updateEnemyBoundary();
	//collision check
	void updateCombat();
	//Boss updates
	void updatePointToBoss();
	void updateBossCombat();
	void updateBossBulletBoundary();
	//update text, hpbar
	void updateHpbar();
	void updateText();


	/*
	Rendering
	*/
	void render();
	//player rendering
	void renderPlayer();
	//enemy rendering
	void renderEnemy();

	//text and hpbar rendering
	void renderText();
	void renderHpBar();
	void renderGameOver();

};

