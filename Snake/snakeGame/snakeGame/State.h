#pragma once
class State
{

public:

	State();
	virtual ~State();

	virtual void update(double deltaT) = 0;
	virtual void draw(sf::RenderWindow* w) = 0;
	virtual void processStuff(double deltaT, sf::Vector2f mousePos) = 0;

	virtual void updateKeyBinds(double deltaT) = 0;

	virtual void checkForQuit();

	void setQuit(bool newQuit); 

	bool getQuit() const;

	void setHolderScore(int newScore);

	int getHolderScore(int newScore);

	virtual bool switchState();
private:
	bool quit;
	int holderScore;
};

