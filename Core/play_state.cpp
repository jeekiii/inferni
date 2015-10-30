/// *********************16/02/2013***********************///

#include "play_state.hpp"

#include "../Core/menu_state.hpp"


#include "../Objects/wall.hpp"
#include "../Objects/creature.hpp"
#include "../Objects/object.hpp"

#include "global.hpp"
#include "../Util/tools.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"

#include <algorithm>


PlayState::PlayState()
{

    fps_=new FpsCounter(25);
    fps_->startCount();
    
}


PlayState::~PlayState()
{
    delete fps_;
}


void PlayState::onEvent()//unappropriate name? It's not a callback! <= Nah, probably fine
{
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    Global::state.clear();
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym==SDLK_y)
                    {
                        MenuState *p_menu=new MenuState;
                        Global::state.push_back(p_menu);
                    }

                    if(event.key.keysym.sym==SDLK_ESCAPE)
                    {
                        Global::state.pop_back();
                    }
                    else
                    {
                        command_.addCommand(event.key.keysym.sym);
                    }
                    break;
                case SDL_KEYUP:
                    command_.removeCommand(event.key.keysym.sym);
                    break;
            }
        }
}


void PlayState::onRender()
{
    SDL_RenderClear(Global::renderer);
    level_.onRender();
    SDL_RenderPresent(Global::renderer);
}


void PlayState::onUpdate()
{
    level_.onUpdate(command_.getCommand());
    fps_->checkFPS();
    fps_->getNewTick();
    return;
}
