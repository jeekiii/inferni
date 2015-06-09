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
        virtual void OnRender()=0;
        virtual void OnMove()=0;
        virtual void Reaction(cObject *object)=0;
        virtual void OnInit()=0;
        virtual coord GetPosition()=0;// to know if it's above or under another element when rendering.
};

#endif
