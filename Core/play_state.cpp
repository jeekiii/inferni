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

    fps_=new FpsCounter(100);
    fps_->startCount();
    map_ = new Map(1);
    hud_ = new Hud();
    Creature *creature=new Creature(200, 100);
    player_ = new Player(100, 100);

    objects_.push_back(player_);
    objects_.push_back(creature);
    
}


PlayState::~PlayState()
{
    objects_.clear();
    delete map_;
    delete hud_;
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
    

    map_->onRender(player_->getPosition());
    std::sort(objects_.begin(), objects_.end(), compareObjects);
    for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
    {
        objects_[i]->onRender(map_->getPosition());
    }
    hud_->onRender();


    SDL_RenderPresent(Global::renderer);
}


void PlayState::onUpdate()
{
    std::vector <CommandType> commands = command_.getCommand();
    player_->onCommand(&objects_, commands);
    for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
    {
        objects_[i]->onUpdate(&objects_);

    }//separate loops in case one of those deletes the object.
    for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
    {
        objects_[i]->onMove(&objects_);

    }

    fps_->checkFPS();
    fps_->getNewTick();
    return;
}
