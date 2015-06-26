/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
cObject->cMovableObject->cCreature
*/


#ifndef POSSESSABLE_HPP_
    #define POSESSABLE_HPP_
#include "../Objects/object.hpp"

class cPossessable:public cObject
{
	    public:
        virtual void OnInit()=0;
        virtual void OnRender()=0;
        virtual void OnMove()=0;
        virtual void Reaction(cObject *object)=0;
        virtual void OnUP()=0;
        virtual void OnDOWN()=0;
        virtual void OnLEFT()=0;
        virtual void OnRIGHT()=0;

};

#endif

