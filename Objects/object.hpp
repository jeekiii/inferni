/// *********************16/02/2013***********************///
/* Base class of the game object,
for example, human, wall, flower....
*/


#ifndef _OBJECT_HPP_
    #define _OBJECT_HPP_
#include <SDL.h>

class cObject
{
  protected:
    //grid position of the object
        int xGrid;
        int yGrid;
    //x position= xGrid*xScale;
        static const int XSCALE=40;
        static const int YSCALE=30;

        SDL_Texture *img;

    public:

};

#endif
