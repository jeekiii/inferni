/// *********************16/02/2013***********************///


#ifndef POSSESSABLE_HPP
    #define POSSESSABLE_HPP
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
#include "../Util/command.hpp"


class Possessable:public Object
{
        protected:
            int hp_;
            Coord toMove_;
            bool leaving_;//signals that the demon is leaving!
            bool possessed_;
            bool right_, left_, up_, down_;
	    public:
            virtual ~Possessable(){}
            virtual void onRender(Coord positionMap)=0;
            virtual void onMove(std::vector<Object*> *objects)=0;
            virtual ReactionType reaction(Object *object, bool ground)=0;
            virtual void onCommand(std::vector<Object*> *objects, std::vector<CommandType> commands)=0;
            void setPossessed(bool value){possessed_ = value;}
            bool isLeaving(){return leaving_;}
            int getHp(){return hp_;}
};

#endif

