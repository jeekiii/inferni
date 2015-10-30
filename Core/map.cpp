#include "map.hpp"
#include "../Core/global.hpp"

Map::Map(int mapNumber)
{
	//this is all temporary, should load the map instead.
	//this is where the whole mapSize x or y becomes complicated careful not to mess up...

	mapSize_.x = 30;
	mapSize_.y = 30;

	startingPosition_.x = 0;
	startingPosition_.y = 0;
	startingPosition_.w = mapSize_.x*50;
	startingPosition_.h = mapSize_.y*50;
	tiles_ = new Tile*[mapSize_.x];
	for(int i = 0; i < mapSize_.x; i++)
	{
		tiles_[i] = new Tile[mapSize_.y];
	}

	for(int i = 0; i < mapSize_.x; i++)
	{
		for(int j = 0; j < mapSize_.y; j++)
		{
			(tiles_[i][j]) = Tile(WATER_TILE);
		}
	}


}
void Map::onRender(Coord positionMap)
{
	Coord positionTile;
	positionTile.x = positionMap.x;
	positionTile.y = positionMap.y;
	positionTile.w = 50;
	positionTile.h = 50;
	for(int i = 0; i < mapSize_.x; i++)
	{
		for(int j = 0; j < mapSize_.y; j++)
		{
			if(positionTile.x > -50 && positionTile.x  < Global::screenWidth)//check if it's on the screen
			{
				if(positionTile.y> -50 && positionTile.y < Global::screenHeight)
				{
					tiles_[i][j].onRender(positionTile);
				}
			}
			positionTile.y+=50;
		}
		positionTile.x+=50;
		positionTile.y = positionMap.y;
	}
}

Coord Map::getStartingPosition()
{
	return startingPosition_;
}

Map::~Map()
{

	//care with your frees, don't mess up between mapSize.x and y;
	for(int i = 0; i < mapSize_.x; i++)
	{
		delete[] tiles_[i];
	}
	delete tiles_;
}

Map::Map()
{
	;
}