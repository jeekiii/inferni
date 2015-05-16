/// *********************16/02/2013***********************///
/* Base class of the game object,
for example, human, wall, flower....
*/


#ifndef _OBJECT_HPP_
    #define _OBJECT_HPP_
#include <SDL2/SDL.h>
#include "../Util/tools.hpp"
class cObject
{
    protected:
        SDL_Texture *img;
        coord position;
    public:
        void OnRender();
        void OnMove();
        void Reaction(cObject object);
};

#endif
