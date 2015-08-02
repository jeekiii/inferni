/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
cObject->cMovableObject->cCreature
*/


#ifndef _CREATURE_HPP_
    #define _CREATURE_HPP_
#include "../Objects/object.hpp"
#include "../Objects/possessable.hpp"
#include "../Util/command.hpp"
#include "../Objects/player.hpp"
#include "../Objects/ai.hpp"

class cCreature:public cPossessable
{
	private:
        int attackCD;
        int attackCurrentCD;
        cAI *AI;
    public:
        cCreature();
        ~cCreature();
        void OnInit(int positionX, int positionY);
        void OnRender(coord positionMap);
        void OnMove(std::vector<cObject*> *objects);
        void OnUpdate(std::vector<cObject*> *objects);
        void TakeDamage(int amount);
        ReactionType Reaction(cObject *object, bool ground);
        void OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> commands);
};

#endif

