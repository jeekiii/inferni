#ifndef MAP_HPP
	#define MAP_HPP

#include "tile.hpp"
#include "../Util/tools.hpp"
class Map
{
	private:
		Tile **tiles_;
		Coord mapSize_;
		Coord startingPosition_;
	public:
		Map();
		Map(int mapNumber);
		~Map();
		void onRender(Coord positionMap);
		Coord getStartingPosition();
};

#endif