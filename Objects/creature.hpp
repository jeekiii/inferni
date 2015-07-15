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
        void OnInit(int positionX, int positionY);
        void OnRender(coord positionMap);
        void OnMove(std::vector<cObject*> *objects);
        ReactionType Reaction(cObject *object);
        void OnUP(std::vector<cObject*> *objects);
        void OnDOWN(std::vector<cObject*> *objects);
        void OnLEFT(std::vector<cObject*> *objects);
        void OnRIGHT(std::vector<cObject*> *objects);

};

#endif

