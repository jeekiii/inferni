/// *********************16/02/2013***********************///


#include "global.hpp"
#include "play_state.hpp"
#include "menu_state.hpp"
#include "../Util/image_func.hpp"
#include "../Util/fps_counter.hpp"

#include "../Objects/wall.hpp"
#include "../Objects/creature.hpp"

#include "../Objects/object.hpp"
#include "../Objects/collision_object.hpp"


int cPlayState::OnInit()
{
m_tex_bg=NULL;
m_tex_bg=ImageFunc::LoadSprites("Images/Map1.bmp");

//init other members
m_wall=new cWall;
m_creature=new cCreature;

    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();
return 0;
}


int cPlayState::OnCleanUp()
{
    delete m_wall;
    delete m_creature;

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
    /*SDL_RenderClear(Global::renderer);
        ImageFunc::RenderTexture(0,0,m_tex_bg,Global::renderer);
                m_creature->Draw();
                m_wall->Draw();
        
    SDL_RenderPresent(Global::renderer);*/
}


void cPlayState::OnUpdate()
{
    mp_fps->CheckFPS();

    mp_fps->GetNewTick();
return;
}
