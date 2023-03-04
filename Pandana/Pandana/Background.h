#pragma once
class Background
{
public:
	//Constructor //Destructor
	Background();
	virtual ~Background();

private:
	//Texture, Sprite variables
	sf::Sprite pandananaSprite;
	sf::Texture pandananaTexture;

	//Init function
	void initBackground();

public:
	void update();
	void render(sf::RenderTarget &target);
};

