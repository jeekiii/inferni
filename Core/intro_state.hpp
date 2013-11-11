/// *********************16/02/2013***********************///
/* the state class when player first enters the game(welcome page)
cGameState->cIntroState
*/

#ifndef _INTRO_HPP_
    #define _INTRO_HPP_

#include "game_state.hpp"

class cIntroState:public cGameState
{
    private:
        SDL_Texture* m_tex_bg;      //abbrev: member-surface-background

    public:
        cIntroState(){;}
        ~cIntroState(){;};

    public:
         int OnInit();
         int OnCleanUp();

         void OnEvent();
         void OnRender();
         void OnUpdate();
};

#endif
