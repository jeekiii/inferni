/// *********************16/02/2013***********************///
/* the state class when player enters the game
GameState->PlayState
*/


#ifndef PLAYSTATE_HPP
    #define PLAYSTATE_HPP

#include "../Core/level.hpp"
#include "../Util/command.hpp"
#include "../Core/game_state.hpp"

class Creature;
class Wall;

class PlayState:public GameState
{

    private:
        Level level_;
        Command command_;
    public:
         PlayState();
         ~PlayState();
         void onEvent();
         void onRender();
         void onUpdate();

};

#endif
