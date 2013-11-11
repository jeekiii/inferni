/// *********************16/02/2013***********************///
/* the state class when player enters the menu (like press ESC)
cGameState->cMenuState
*/


#ifndef _MENUSTATE_HPP_
    #define _MENUSTATE_HPP_

#include "game_state.hpp"
#include <SDL.h>

class cMenuState:public cGameState
{
    private:
        SDL_Texture* m_tex_bg;

    public:
        cMenuState(){m_tex_bg=NULL;}

    public:
         int OnInit();
         int OnCleanUp();

         void OnEvent();
         void OnRender();
         void OnUpdate();

};

#endif
