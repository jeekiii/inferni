/// *********************16/02/2013***********************///
/* Some Global functions in namespace ImageFunc,
used for ease of processing images
*/


#ifndef IMAGE_FUNC_HPP
    #define IMAGE_FUNC_HPP

#include <SDL2/SDL.h>
#include "../Core/global.hpp"
#include "../Util/tools.hpp"
namespace ImageFunc
{

	SDL_Texture* loadSprites(const char* filemame,bool alpha=false,
	                         int r=0, int g=0, int b=0);

	int renderTexture(SDL_Texture*src, SDL_Renderer*des,
	                bool clip,Coord position, Coord toClip);

}



#endif
