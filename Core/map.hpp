#ifndef MAP_HPP
	#define MAP_HPP

#include "tile.hpp"
#include "../Util/tools.hpp"
class Map
{
	private:
		Tile **tiles_;
		Coord mapSize_;
		Coord position_;
	public:
		Map();
		~Map();
		void onRender(Coord positionPlayer);
		Coord getPosition();
};

#endif
