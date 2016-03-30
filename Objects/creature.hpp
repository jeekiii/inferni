/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
Object->cMovableObject->Creature
*/


#ifndef CREATURE_HPP
    #define CREATURE_HPP
#include "../Objects/object.hpp"
#include "../Objects/possessable.hpp"
#include "../Util/command.hpp"
#include "../Objects/ai.hpp"

class Creature:public Possessable
{
	private:
        int attackCD_;
        int attackCurrentCD_;
        Ai *ai_;
    public:
        Creature(int id, int positionX, int positionY);
        ~Creature();

        void onRender(Coord positionMap);
        void onMove(std::vector<Object*> *objects);
        void onUpdate(std::vector<Object*> *objects);
        void takeDamage(int amount);
        ReactionType reaction(Object *object, bool ground);
        void onCommand(std::vector<Object*> *objects, std::vector<CommandType> commands);
};

#endif
