/// *********************16/02/2013***********************///
/* wall class, used to block player
Object->cCollisionObject->Wall
*/


#ifndef WALL_HPP
    #define WALL_HPP
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
class Wall: public Object
{
    public:
        Wall();
        ~Wall();

    public:
        void draw();
};

#endif

