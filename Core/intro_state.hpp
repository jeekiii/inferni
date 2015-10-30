/// *********************16/02/2013***********************///
/* the state class when player first enters the game(welcome page)
GameState->IntroState
*/

#ifndef INTRO_HPP
    #define INTRO_HPP

#include <SDL2/SDL.h>


#include "../Util/button.hpp"
#include "../Util/tools.hpp"


class IntroState:public GameState
{
    private:
        SDL_Texture* tex_;      //abbrev: member-surface-background
        Button *buttonPlay_;
        Coord positionBg_;
    public:
        IntroState();
        ~IntroState();

    public:
         void onEvent();
         void onRender();
         void onUpdate();
};

#endif
