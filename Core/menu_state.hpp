/// *********************16/02/2013***********************///
/* the state class when player enters the menu (like press ESC)
GameState->MenuState
*/


#ifndef MENUSTATE_HPP
    #define MENUSTATE_HPP

#include "game_state.hpp"
#include <SDL2/SDL.h>

class MenuState:public GameState
{
    private:
        SDL_Texture* tex_;

    public:
		MenuState();
		~MenuState();
        void onEvent();
        void onRender();
        void onUpdate();

};

#endif
