/// *********************16/02/2013***********************///
/* the state class when player first enters the game(welcome page)
cGameState->cIntroState
*/

#ifndef _INTRO_HPP_
    #define _INTRO_HPP_

#include <SDL2/SDL.h>
#include "global.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"
#include "../Util/button.hpp"
#include "../Util/tools.hpp"
#include "play_state.hpp"
#include "game_state.hpp"

class cIntroState:public cGameState
{
    private:
        SDL_Texture* m_tex_bg;      //abbrev: member-surface-background
        cButton button;
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
