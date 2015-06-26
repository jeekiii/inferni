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
#include "../Objects/possessable.hpp"

class cCreature:public cPossessable
{
	private:
    public:
        cCreature();
        ~cCreature();
        void OnInit();
        void OnRender();
        void OnMove();
        void Reaction(cObject *object);
        void OnUP();
        void OnDOWN();
        void OnLEFT();
        void OnRIGHT();

};

#endif

