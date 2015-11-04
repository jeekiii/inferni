/// *********************16/02/2013***********************///
/* Base class of the game object,
for example, human, wall, flower....
*/


#ifndef OBJECT_HPP
    #define OBJECT_HPP
#include <SDL2/SDL.h>
#include "../Util/tools.hpp"
#include <vector>

class Player;

typedef enum ReactionType
{
    WATER_REACTION, SOLID_REACTION, DAMAGE_REACTION, EVENT_REACTION, NONE_REACTION, POSSESS_REACTION
}ReactionType;

struct ReactionObject;


class Object
{
    protected:
        SDL_Texture *image_;
        Coord position_;
        Coord relativeGroundHitbox_;
        Coord relativeAboveHitbox_;
        bool possessable_;
    public:
        virtual ~Object(){}
        virtual void onRender(Coord positionMap)=0;
        virtual void onMove(std::vector<Object*> *objects)=0;
        virtual ReactionType reaction(Object *object, bool ground)=0;
        virtual void onUpdate(std::vector<Object*> *objects)=0;
        virtual void takeDamage(int amount)=0;//maybe damageType in the future.
        Coord getPosition();
        Coord getGroundHitbox();
        Coord getAboveHitbox();
        std::vector <ReactionObject> getCollision(std::vector<Object*> *objects, bool ground, bool above);
        void getReaction(std::vector<Object*> *objects, std::vector<ReactionType> *reaction);
        bool isPossessable(){return possessable_;}
};

typedef struct ReactionObject
{
    Object *object;
    ReactionType reaction;
    bool ground;
}ReactionObject;

bool compareObjects(Object *obj1, Object *obj2);

#endif
