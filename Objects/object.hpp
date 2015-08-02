/// *********************16/02/2013***********************///
/* Base class of the game object,
for example, human, wall, flower....
*/


#ifndef _OBJECT_HPP_
    #define _OBJECT_HPP_
#include <SDL2/SDL.h>
#include "../Util/tools.hpp"
#include <vector>

class cPlayer;

typedef enum ReactionType
{
    WATER, SOLID, DAMAGE, EVENT, NONE, POSSESS
}ReactionType;

struct ReactionObject;


class cObject
{
    protected:
        SDL_Texture *image;
        coord position;
        coord relativeGroundHitbox;
        coord relativeAboveHitbox;
        bool possessable;
    public:
        virtual ~cObject(){}
        virtual void OnRender(coord positionMap)=0;
        virtual void OnMove(std::vector<cObject*> *objects)=0;
        virtual ReactionType Reaction(cObject *object, bool ground)=0;
        virtual void OnInit(int positionX, int positionY)=0;
        virtual void OnUpdate(std::vector<cObject*> *objects)=0;
        virtual void TakeDamage(int amount)=0;//maybe damageType in the future.
        coord GetPosition();
        coord GetGroundHitbox();
        coord GetAboveHitbox();
        std::vector <ReactionObject> GetCollision(std::vector<cObject*> *objects, bool ground, bool above);
        bool IsPossessable(){return possessable;}
};

typedef struct ReactionObject
{
    cObject *object;
    ReactionType reaction;
    bool ground;
}ReactionObject;

bool compareObjects(cObject *obj1, cObject *obj2);

#endif
