/// *********************16/02/2013***********************///
/* Base class of the game object,
for example, human, wall, flower....
*/


#ifndef _OBJECT_HPP_
    #define _OBJECT_HPP_
#include <SDL2/SDL.h>
#include "../Util/tools.hpp"
#include <vector>

typedef enum ReactionType
{
    WATER, SOLID, DAMAGE, EVENT, NONE
}ReactionType;


class cObject
{
    protected:
        SDL_Texture *image;
        coord position;
        coord relativeGroundHitbox;
        coord relativeAboveHitbox;
    public:
        virtual void OnRender(coord positionMap)=0;
        virtual void OnMove(std::vector<cObject*> *objects)=0;
        virtual ReactionType Reaction(cObject *object)=0;
        virtual void OnInit(int positionX, int positionY)=0;
        coord GetPosition();
        coord GetGroundHitbox();
        coord GetAboveHitbox();
        std::vector <ReactionType> GetCollision(std::vector<cObject*> *objects);
};


bool compareObjects(cObject *obj1, cObject *obj2);

#endif
