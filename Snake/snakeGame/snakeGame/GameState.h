#pragma once
#include "State.h"

class GameState : public State
{
public:
	GameState();
	virtual ~GameState();

	void update(double deltaT) override;
	void draw(sf::RenderWindow* w) override;
	void processStuff(double deltaT, sf::Vector2f mousePos) override;

	void updateKeyBinds(double deltaT) override;

	void initBorder();

private:
	
};

