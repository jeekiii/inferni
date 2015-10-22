#ifndef _MAP_HPP_
	#define _MAP_HPP_

#include "tile.hpp"
#include "../Util/tools.hpp"
class cMap
{
	private:
		cTile **tiles;
		coord mapSize;
		coord posInit;
	public:
		cMap();
		~cMap();
		void OnInit(int mapNumber);
		void OnRender(coord positionMap);
		coord GetPosInit();
};

#endif