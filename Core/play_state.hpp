/// *********************16/02/2013***********************///
/* the state class when player enters the game
cGameState->cPlayState
*/


#ifndef _PLAYSTATE_HPP_
    #define _PLAYSTATE_HPP_
class cCreature;
class cGameState;
class cWall;

class cPlayState:public cGameState
{
    //core members
    private:
        SDL_Texture* m_tex_bg;

    //other members
    private:
        cWall *m_wall;
        cCreature *m_creature;

    public:
      //  cPlayState();

    public:
         int OnInit();
         int OnCleanUp();

         void OnEvent();
         void OnRender();
         void OnUpdate();

};

#endif
