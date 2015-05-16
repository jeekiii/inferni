/// *********************16/02/2013***********************///


#include "play_state.hpp"



int cPlayState::OnInit()
{
    m_tex_bg=NULL;
    m_tex_bg=ImageFunc::LoadSprites("Images/Map1.bmp");

    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();
    positionBg.x = 0;
    positionBg.y = 0;
    SDL_QueryTexture(m_tex_bg, NULL, NULL, &positionBg.w, &positionBg.h);
    return 0;
}


int cPlayState::OnCleanUp()
{

    objects.clear();
    delete mp_fps;
    SDL_DestroyTexture(m_tex_bg);
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
    ImageFunc::RenderTexture(m_tex_bg,Global::renderer, false, positionBg, positionBg);        
    SDL_RenderPresent(Global::renderer);
}


void cPlayState::OnUpdate()
{
    mp_fps->CheckFPS();
    mp_fps->GetNewTick();
return;
}
