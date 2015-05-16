/// *********************16/02/2013***********************///


#include "intro_state.hpp"


int cIntroState::OnInit()
{
    coord positionPlay = {100, 100, 0, 0}; //position.h and w are automatically calculated!
    m_tex_bg=ImageFunc::LoadSprites("Images/IntroPage.bmp");
    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();
    buttonPlay.Init(positionPlay, "Images/ButtonPlay.bmp");//must free memory
    positionBg.x = 0;
    positionBg.y = 0;
    SDL_QueryTexture(m_tex_bg, NULL, NULL, &positionBg.w, &positionBg.h);

    return 0;
}


int cIntroState::OnCleanUp()
{
    delete mp_fps;
    SDL_DestroyTexture(m_tex_bg);
    return 0;
}


void cIntroState::OnEvent()
{
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    Global::state.back()->OnCleanUp();
                    Global::state.clear();   /// need cleanup !!!
                break;
                case SDL_KEYDOWN:
                {
                    if(event.key.keysym.sym==SDLK_y)
                    {
                        cPlayState *p_play=new cPlayState;
                        p_play->OnInit();
                        Global::state.push_back(p_play);
                    }

                   if(event.key.keysym.sym==SDLK_q)
                    {
                            Global::state.back()->OnCleanUp();
                            Global::state.clear();
                    }
                }
                break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    coord mousePosition;
                    mousePosition.h = 1;
                    mousePosition.w = 1;
                    mousePosition.x = event.motion.x;
                    mousePosition.y = event.motion.y;
                    if(buttonPlay.IsClicked(mousePosition))
                    {
                        cPlayState *p_play=new cPlayState;
                        p_play->OnInit();
                        Global::state.push_back(p_play);
                    }
                }   
                break;
            } //end of switch

        } //end of event


}


void cIntroState::OnRender()
{
    SDL_RenderClear(Global::renderer);
    ImageFunc::RenderTexture(m_tex_bg,Global::renderer, false, positionBg, positionBg);
    buttonPlay.OnRender();
    SDL_RenderPresent(Global::renderer);
}


void cIntroState::OnUpdate()
{
    mp_fps->CheckFPS();

    mp_fps->GetNewTick();
return;
}
