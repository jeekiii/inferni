/// *********************16/02/2013***********************///
/* wall class, used to block player
cObject->cCollisionObject->cWall
*/


#ifndef _WALL_HPP_
    #define _WALL_HPP_
#include "collision_object.hpp"

class cObject;
class cCollisionObject;

class cWall:public cCollisionObject
{
    public:
        cWall();
        ~cWall();

    public:
        void Draw();
};

#endif

