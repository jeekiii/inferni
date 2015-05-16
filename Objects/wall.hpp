/// *********************16/02/2013***********************///
/* wall class, used to block player
cObject->cCollisionObject->cWall
*/


#ifndef _WALL_HPP_
    #define _WALL_HPP_
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
class cWall: public cObject
{
    public:
        cWall();
        ~cWall();

    public:
        void Draw();
};

#endif

