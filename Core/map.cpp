#include "map.hpp"
#include "../Core/global.hpp"

void cMap::OnInit(int mapNumber)
{
	//this is all temporary, should load the map instead.
	//this is where the whole mapSize x or y becomes complicated careful not to mess up...

	mapSize.x = 30;
	mapSize.y = 30;

	posInit.x = 0;
	posInit.y = 0;
	posInit.w = mapSize.x*50;
	posInit.h = mapSize.y*50;
	tiles = new cTile*[mapSize.x];
	for(int i = 0; i < mapSize.x; i++)
	{
		tiles[i] = new cTile[mapSize.y];
	}

	for(int i = 0; i < mapSize.x; i++)
	{
		for(int j = 0; j < mapSize.y; j++)
		{
			(tiles[i][j]).OnInit(W);
		}
	}


}
void cMap::OnRender(coord positionMap)
{
	coord positionTile;
	positionTile.x = positionMap.x;
	positionTile.y = positionMap.y;
	positionTile.w = 50;
	positionTile.h = 50;
	for(int i = 0; i < mapSize.x; i++)
	{
		for(int j = 0; j < mapSize.y; j++)
		{
			if(positionTile.x > -50 && positionTile.x  < Global::screen_width)//check if it's on the screen
			{
				if(positionTile.y> -50 && positionTile.y < Global::screen_height)
				{
					tiles[i][j].OnRender(positionTile);
				}
			}
			positionTile.y+=50;
		}
		positionTile.x+=50;
		positionTile.y = positionMap.y;
	}
}

coord cMap::GetPosInit()
{
	return posInit;
}

cMap::~cMap()
{

	//care with your frees, don't mess up between mapSize.x and y;
	for(int i = 0; i < mapSize.x; i++)
	{
		delete[] tiles[i];
	}
	delete tiles;
}

cMap::cMap()
{
	;
}