/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
cObject->cMovableObject->cCreature
*/


#ifndef _CREATURE_HPP_
    #define _CREATURE_HPP_
#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/object.hpp"

class cCreature:public cObject
{
	private:
		SDL_Texture* image
		; 
    public:
        cCreature();
        ~cCreature();
        void Draw();
};

#endif

