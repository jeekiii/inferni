/// *********************16/02/2013***********************///


#ifndef POSSESSABLE_HPP_
    #define POSSESSABLE_HPP_
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
#include "../Util/command.hpp"


class cPossessable:public cObject
{
        protected:
            coord toMove;
            bool leaving;//signals that the demon is leaving!
	    public:
            virtual ~cPossessable(){}
            virtual void OnInit(int positionX, int positionY)=0;
            virtual void OnRender(coord positionMap)=0;
            virtual void OnMove(std::vector<cObject*> *objects)=0;
            virtual ReactionType Reaction(cObject *object, bool ground)=0;
            virtual void OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> commands)=0;
            bool IsLeaving(){return leaving;}
};

#endif

