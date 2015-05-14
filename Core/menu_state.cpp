/// *********************16/02/2013***********************///


#include "menu_state.hpp"
#include "global.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"




int cMenuState::OnInit()
{
m_tex_bg=NULL;
m_tex_bg=ImageFunc::LoadSprites("Images/Menu.bmp");
    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();
return 0;
}


int cMenuState::OnCleanUp()
{
        delete mp_fps;
    SDL_DestroyTexture(m_tex_bg);

return 0;
}


void cMenuState::OnEvent()
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
                    Global::state.back()->OnCleanUp();
                    delete Global::state.back();
                    Global::state.pop_back();
                }
                break;
            }
        }
}


void cMenuState::OnRender()
{
    //SDL_RenderClear(Global::renderer);
    //    ImageFunc::RenderTexture(0,0,m_tex_bg,Global::renderer);
    //SDL_RenderPresent(Global::renderer);
}


void cMenuState::OnUpdate()
{
    mp_fps->CheckFPS();

    mp_fps->GetNewTick();
return;
}
