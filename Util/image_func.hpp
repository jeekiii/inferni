/// *********************16/02/2013***********************///
/* Some Global functions in namespace ImageFunc,
used for ease of processing images
*/


#ifndef _IMAGE_FUNC_HPP_
    #define _IMAGE_FUNC_HPP_

#include <SDL.h>
namespace ImageFunc
{

SDL_Texture* LoadSprites(const char* filemame,bool alpha=false,
                         int r=0, int g=0, int b=0);

int RenderTexture(int dx, int dy, SDL_Texture*src, SDL_Renderer*des,
                bool clip=false,int cx=0, int cy=0,int cw=0, int ch=0);

}



#endif
