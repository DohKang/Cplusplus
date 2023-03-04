#pragma once
#include "stdafx.h"
#include "Player.h"

class Game
{
private:

	sf::RenderWindow window;
	sf::Event ev;
	
	//Player
	Player* player;
	
	//initializer
	void initWindow();
	void initPlayer();




public:

	Game();
	virtual ~Game();

	//
	void updateCollision();
	void update();
	




	void renderPlayer();
	void render();

	//Functions
	const sf::RenderWindow& getWindow() const;
	

};

