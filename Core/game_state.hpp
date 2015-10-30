/// *********************16/02/2013***********************///
/* Abstract game state class for inheritance,
must be inherited
*/


#ifndef _GAMESTATE_HPP_
    #define _GAMESTATE_HPP_

class FpsCounter;

class GameState
{
    protected:
       FpsCounter *fps_;

    public:
        

        virtual void onEvent()=0;
        virtual void onRender()=0;
        virtual void onUpdate()=0;

    public:
         GameState();
         virtual ~GameState();
};

#endif
