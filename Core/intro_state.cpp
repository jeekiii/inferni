/// *********************16/02/2013***********************///


#include "intro_state.hpp"
#include "global.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"
#include "play_state.hpp"
#include "game_state.hpp"

IntroState::IntroState()
{
    Coord positionPlay = {100, 100, 0, 0}; //position.h and w are automatically calculated!
    tex_=ImageFunc::loadSprites("Images/IntroPage.bmp");
    fps_=new FpsCounter(25);
    fps_->startCount();
    buttonPlay_ = new Button(positionPlay, "Images/ButtonPlay.bmp");
    positionBg_.x = 0;
    positionBg_.y = 0;
    SDL_QueryTexture(tex_, NULL, NULL, &positionBg_.w, &positionBg_.h);
}


IntroState::~IntroState()
{
    delete fps_;
    delete buttonPlay_;
    SDL_DestroyTexture(tex_);
}


void IntroState::onEvent()
{
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    delete Global::state.back(); //does this work?
                    Global::state.clear();   /// need cleanup !!! //not anymoree.
                break;
                case SDL_KEYDOWN:
                {
                    if(event.key.keysym.sym==SDLK_y)
                    {
                        PlayState *p_play=new PlayState;
                        //p_play->OnInit();
                        Global::state.push_back(p_play);
                    }

                   if(event.key.keysym.sym==SDLK_q)
                    {
                            Global::state.clear();
                    }
                }
                break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    Coord mousePosition;
                    mousePosition.h = 1;
                    mousePosition.w = 1;
                    mousePosition.x = event.motion.x;
                    mousePosition.y = event.motion.y;
                    if(buttonPlay_->isClicked(mousePosition))
                    {
                        PlayState *p_play=new PlayState;
                        Global::state.push_back(p_play);
                    }
                }   
                break;
            } //end of switch

        } //end of event


}


void IntroState::onRender()
{
    SDL_RenderClear(Global::renderer);
    ImageFunc::renderTexture(tex_, Global::renderer, false, positionBg_, positionBg_);
    buttonPlay_->onRender();
    SDL_RenderPresent(Global::renderer);
}


void IntroState::onUpdate()
{
    fps_->checkFPS();

    fps_->getNewTick();
}
