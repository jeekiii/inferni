/// *********************16/02/2013***********************///


#include "menu_state.hpp"
#include "global.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"




MenuState::MenuState()
{
    tex_=NULL;
    tex_=ImageFunc::loadSprites("Images/Menu.bmp");
    fps_=new FpsCounter(25);
    fps_->startCount();

}


MenuState::~MenuState()
{
    delete fps_;
    SDL_DestroyTexture(tex_);
}


void MenuState::onEvent()
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
                if(event.key.keysym.sym==SDLK_q)
                {
                    Global::state.pop_back();
                }
                break;
            }
        }
}


void MenuState::onRender()
{
    //SDL_RenderClear(Global::renderer);
    //    ImageFunc::renderTexture(0,0,m_tex_bg,Global::renderer);
    //SDL_RenderPresent(Global::renderer);
}


void MenuState::onUpdate()
{
    fps_->checkFPS();

    fps_->getNewTick();
    return;
}
