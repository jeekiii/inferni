/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
cObject->cMovableObject->cCreature
*/


#ifndef _CREATURE_HPP_
    #define _CREATURE_HPP_
#include "movable_object.hpp"

class cObject;
class cMovableObject;

class cCreature: public cMovableObject
{
    public:
        cCreature();
        ~cCreature();

    public:
        void Draw();
};

#endif

