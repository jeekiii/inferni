
#ifndef TILE_HPP
    #define TILE_HPP
#include <SDL2/SDL.h>
#include "../Util/tools.hpp"



//need to declare all our enum behind namespaces because of shitty enum scope...
typedef enum TileType
{
	//get more of those. or allow user-created ones? if they specify the path?
	WATER_TILE, GROUND_TILE, STONE_TILE
}TileType;

class Tile
{
	private:
		SDL_Texture *texture_;
		//bool water;
		//bool slow;//for terrain that limits movements
	public:
		Tile(){;}
		Tile(TileType type);
		void onRender(Coord position);
		//bool isSlow();
		//bool isWater();
};



#endif