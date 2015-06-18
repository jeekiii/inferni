/// *********************16/02/2013***********************///


#include "play_state.hpp"



int cPlayState::OnInit()
{

    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();
    level.OnInit();
    return 0;
}


int cPlayState::OnCleanUp()
{
    level.OnCleanUp();
    delete mp_fps;
    return 0;
}


void cPlayState::OnEvent()
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
                            cMenuState *p_menu=new cMenuState;
                            p_menu->OnInit();
                            Global::state.push_back(p_menu);
                }

                if(event.key.keysym.sym==SDLK_q)
                {
                    Global::state.back()->OnCleanUp();
                    delete Global::state.back();
                    Global::state.pop_back();
                }
                break;
            }
        }
}


void cPlayState::OnRender()
{
    SDL_RenderClear(Global::renderer);
    level.OnRender();
    SDL_RenderPresent(Global::renderer);
}


void cPlayState::OnUpdate()
{
    level.OnUpdate();
    mp_fps->CheckFPS();
    mp_fps->GetNewTick();
    return;
}
