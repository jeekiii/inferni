/// *********************16/02/2013***********************///
/* the state class when player enters the game
cGameState->cPlayState
*/


#ifndef _PLAYSTATE_HPP_
    #define _PLAYSTATE_HPP_
#include "menu_state.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"
#include "../Util/tools.hpp"

#include "../Objects/wall.hpp"
#include "../Objects/creature.hpp"

#include "../Objects/object.hpp"
#include "global.hpp"

class cCreature;
class cGameState;
class cWall;

class cPlayState:public cGameState
{
    //core members
    private:
        SDL_Texture* m_tex_bg;

    //other members
    private:
        std::vector<cObject> objects;
        coord positionBg;

    public:
      //  cPlayState();

    public:
         int OnInit();
         int OnCleanUp();

         void OnEvent();
         void OnRender();
         void OnUpdate();

};

#endif
