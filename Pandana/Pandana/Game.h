#pragma once
class Game
{
public:

	//Construct/Destruct
	Game();
	virtual ~Game();
	
private:
	
	//Init functions
	void initVariables();
	void initWindows();
	void initBackground();
	void initPlayer();
	void initBananas();
	void initBat();
	void initText();
	void initHpBar();

private:
	//Window related Variables
	sf::VideoMode videoMode;
	sf::RenderWindow *window;
	sf::Event ev;

	//Background 
	Background *background;

	//Player 
	Player *player;

	//Banana
	std::map<std::string, sf::Texture*> textures;
	std::vector<Banana*> bananas;
	
	//Bat
	std::vector<Bat*> bats;
	float spawnTimer; //Bat spawning time
	float spawnTimerMax;

	//Font/text
	
	sf::Font font;
	sf::Text textpoint;
	sf::Text textHp;
	sf::Text gameOverText;
	
	//HPBAR
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpMaxBar;

	//point
	int points;

public:
	//Game running, polling event
	void running();
	void pollevents();

	//updates
	void update();
	void updatePlayerBoundary(); //set Player & screen boundary
	void updateBananas(); //update banana
	void updateBananaBoundary(); //set Banana & screen boundary
	void updateBat(); //update bat
	void updateBatBoundary();// set Bat & screen boundary
	void updateBB();//when Bat & Banana Collide
	void updateBP();//when Bat & Player collide
	void updateText(); //update Texts
	void updateHpBar(); //update HpBar

	//rendering
	void render();
	void renderBackground();
	void renderPlayer();
	void renderBanana();
	void renderBat();
	void renderText();
	void renderHpBar();
	void renderGameOver();

};

