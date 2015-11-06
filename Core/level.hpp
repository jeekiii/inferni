/*
#ifndef LEVEL_HPP
    #define LEVEL_HPP
#include <vector>
#include "../Objects/object.hpp"
#include "../Util/command.hpp"
#include "../Objects/player.hpp"
#include "../Util/hud.hpp"
#include "../Core/map.hpp"
#include "../Util/tools.hpp"

class Level
{
	private:
		std::vector<Object*> objects_;
        Map *map_;
        Player *player_;
        Hud *hud_;

    public:

        Level();
        ~Level();
        void onRender();
        void onUpdate(std::vector <CommandType> commands);
};


#endif
*/