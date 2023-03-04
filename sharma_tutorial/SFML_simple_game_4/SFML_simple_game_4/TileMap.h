#pragma once

#include "Tile.h"

class TileMap
{
private:
	std::vector<std::vector<Tile*>> tiles;

public:
	TileMap();
	~TileMap();

	//Function
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned.y);

	void update();
	void render();
};

