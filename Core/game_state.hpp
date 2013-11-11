/// *********************16/02/2013***********************///
/* Abstract game state class for inheritance,
must be inherited
*/


#ifndef _GAMESTATE_HPP_
    #define _GAMESTATE_HPP_

class cFPSCounter;

class cGameState
{
    protected:
       cFPSCounter *mp_fps;

    public:
        virtual int OnInit()=0;
        virtual int OnCleanUp()=0;

        virtual void OnEvent()=0;
        virtual void OnRender()=0;
        virtual void OnUpdate()=0;

    public:
         cGameState();
         virtual ~cGameState();
};

#endif
