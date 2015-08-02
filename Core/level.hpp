
#ifndef _LEVEL_HPP_
    #define _LEVEL_HPP_
#include <vector>
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
#include "../Util/command.hpp"
#include "../Objects/player.hpp"
#include "../Util/hud.hpp"

class cLevel
{
	private:
		std::vector<cObject*> objects;
		SDL_Texture* map;
		coord positionMap;
        cPlayer *player;
        cHud hud;

    public:

        int OnInit();
        int OnCleanUp();
        void OnRender();
        void OnUpdate(std::vector <CommandType> commands);
};


#endif
