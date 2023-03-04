#pragma once
class Game
{
private:
	

	void initStates();

	void run();
	void processStuff();
	
	void update();
	void draw();

public:
	Game();
	virtual ~Game();

	//function
	void start();

private:
	sf::RenderWindow window;
	
	std::stack<State *> states;

	double deltaT;
	int score;
};

