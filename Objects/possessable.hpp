/// *********************16/02/2013***********************///


#ifndef POSSESSABLE_HPP_
    #define POSSESSABLE_HPP_
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
class cPossessable:public cObject
{
        protected:
            coord toMove;
	    public:
            virtual void OnInit(int positionX, int positionY)=0;
            virtual void OnRender(coord positionMap)=0;
            virtual void OnMove(std::vector<cObject*> *objects)=0;
            virtual ReactionType Reaction(cObject *object)=0;
            virtual void OnUP(std::vector<cObject*> *objects)=0;
            virtual void OnDOWN(std::vector<cObject*> *objects)=0;
            virtual void OnLEFT(std::vector<cObject*> *objects)=0;
            virtual void OnRIGHT(std::vector<cObject*> *objects)=0;

};

#endif

