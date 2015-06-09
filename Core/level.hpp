
#ifndef _LEVEL_HPP_
    #define _LEVEL_HPP_
#include <vector>
#include "../Objects/object.hpp"
#include "../Util/tools.hpp"
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
};


#endif
