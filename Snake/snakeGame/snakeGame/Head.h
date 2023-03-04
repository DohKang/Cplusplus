#pragma once
#include "Tail.h"

enum DIRECTION {UP=0, RIGHT,DOWN, LEFT};

class Head : public Entity
{
	Head(sf::Vector2f position, sf::Texture* texture);
	~Head();

	void draw(sf::RenderWindow* w) override;
	void update(double deltaT) override;
	void keyboardInput();
	void growTial();
	void updateTails();
	bool headToTail();

private:
	DIRECTION dir;

	double counter;
	std::vector<Tail *> tail;
	sf::Texture tailTexture;
};

