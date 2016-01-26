#include "map.hpp"
#include "../Core/global.hpp"
#include "../Loader/loader.hpp"

Map::Map(int mapNumber)
{
	//this is all temporary, should load the map instead.
	//this is where the whole mapSize x or y becomes complicated careful not to mess up...

	open_level("Data/level.xml");

	mapSize_.x = get_map_width();
	mapSize_.y = get_map_height();

	position_.x = 0;
	position_.y = 0;
	position_.w = mapSize_.x*50;
	position_.h = mapSize_.y*50;

	tiles_ = get_tiles();

	/*tiles_ = new Tile*[mapSize_.x];
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
	}*/


}
void Map::onRender(Coord positionPlayer)
{
	position_.x = (Global::screenWidth/2) - (positionPlayer.x + positionPlayer.w/2);
	position_.y = (Global::screenHeight/2) - (positionPlayer.y + positionPlayer.w/2);
	if(position_.x > 0)
	{
		position_.x = 0;
	}
	if(position_.x + position_.w < Global::screenWidth)
	{
		position_.x = Global::screenWidth-position_.w;
	}
	if(position_.y > 0)
	{
		position_.y = 0;
	}
	if(position_.y +position_.h < Global::screenHeight)
	{
		position_.y = Global::screenHeight-position_.h;
	}


	Coord positionTile;
	positionTile.x = position_.x;
	positionTile.y = position_.y;
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
		positionTile.y = position_.y;
	}
}

Coord Map::getPosition()
{
	return position_;
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
