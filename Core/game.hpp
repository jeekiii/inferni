/// *********************16/02/2013***********************///
/* The Game core class used to run the game
you can manage the whole game, do cmd stuffs here
*/

#ifndef _GAME_HPP_
    #define _GAME_HPP_


class cGame
{
    public:
        cGame();
        ~cGame();

        int OnInitCmd();
        int OnInitGlobal();
        int Run();   //NOTE: from main, it enters here


};


#endif
