/// *********************16/02/2013***********************///
/* the state class when player enters the game
GameState->PlayState
*/


#ifndef PLAYSTATE_HPP
    #define PLAYSTATE_HPP

#include "../Core/level.hpp"
#include "../Util/command.hpp"
#include "../Core/game_state.hpp"
#include "../Objects/object.hpp"
#include "../Core/map.hpp"
#include "../Objects/player.hpp"
#include "../Util/hud.hpp"

class Creature;
class Wall;

class PlayState:public GameState
{

    private:
        Command command_;
        std::vector<Object*> objects_;
        Map *map_;
        Player *player_;
        Hud *hud_;

    public:
         PlayState();
         ~PlayState();
         void onEvent();
         void onRender();
         void onUpdate();

};

#endif
