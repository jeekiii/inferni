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
        coord GetPosition();// to know if it's above or under another element when rendering.
        bool operator<(cObject *obj2);
};

#endif
