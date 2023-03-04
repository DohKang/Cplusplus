#include "stdafx.h"
#include "Background.h"

/*
Constructor
initiating all variables
*/
Background::Background()
{
	this->initBackground();
}

/*
Destructor
*/
Background::~Background()
{
}

/*
Bring the background texture from the folder
*/
void Background::initBackground()
{
	if (!this->pandananaTexture.loadFromFile("Texture/background.png"))
	{
		std::cout << "!! ERROR::BACKGROUND:: CAN NOT LOAD THE BACKGROUND IMAGE" << "\n";
	}
	this->pandananaSprite.setTexture(this->pandananaTexture);
}

void Background::update()
{
}

/*
Draw background in the screen
*/
void Background::render(sf::RenderTarget& target)
{
	target.draw(this->pandananaSprite);
}
