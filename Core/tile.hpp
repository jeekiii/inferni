
#ifndef _TILE_HPP_
    #define _TILE_HPP_
#include <SDL2/SDL.h>
#include "../Util/tools.hpp"
#include "../Util/image_func.hpp"


//need to declare all our enum behind namespaces because of shitty enum scope...
typedef enum TileType
{
	//get more of those. or allow user-created ones? if they specify the path?
	W, G, D
}TileType;

class cTile
{
	private:
		SDL_Texture *texture;
		//bool water;
		//bool slow;//for terrain that limits movements
	public:
		void OnInit(TileType type);
		void OnRender(coord position);
		//bool isSlow();
		//bool isWater();
};



#endif