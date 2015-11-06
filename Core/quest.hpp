#ifndef QUEST_HPP
    #define QUEST_HPP
#include "../Objects/object.hpp"
#include "../Objects/player.hpp"
#include <algorithm>
#include "../Util/tools.hpp"
#include "../Core/map.hpp"

class Quest
{
	private:
		/*be very careful... you can't free things here because it might be used elsewhere, the frees have to happen in the play_state file*/
		int id;
		Map *map_;
		std::vector<Object*> *objects_;
		std::vector<int> toSaveId_;
		std::vector<int> toPossessId_;
		Player *player_;
		//std::vector<int> preRequise_;
	public:
		Quest(int id, Player *player, std::vector<Object*> *objects);
		Quest(Player *player);
		~Quest();
		std::vector<Object*>* getObjects();
		Map* getMap();
		Player* getPlayer();
		bool hasWon();
		bool hasLost();


}; 
#endif
