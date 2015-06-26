
#ifndef _LEVEL_HPP_
    #define _LEVEL_HPP_
#include <vector>
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
#include "../Util/command.hpp"
class cLevel
{
	private:
		std::vector<cObject*> objects;
		SDL_Texture* map;
		coord positionMap;
    public:

        int OnInit();
        int OnCleanUp();
        void OnRender();
        void OnUpdate();
        void OnEvent(std::vector<int> keys);
};


#endif
