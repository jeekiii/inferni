#include "quest.hpp"
#include "../Objects/creature.hpp"
Quest::Quest(Player *player)
{
;
}
Quest::Quest(int id, Player *player, std::vector<Object*> *objects)
{
	player_ = player;
    objects->clear();//memory leaks!
    objects_ = objects;
    map_ = new Map(1);
	if(id == 1)
	{

		Creature *creature=new Creature(200, 100, 2);
		objects_->push_back(creature);

	}
	objects_->push_back(player_);
	toPossessId_.push_back(2);
}
Quest::~Quest()
{
	delete map_;
}
Map* Quest::getMap()
{
	return map_;
}

Player* Quest::getPlayer()
{
	return player_;
}

std::vector<Object*>* Quest::getObjects()
{
	return objects_;
}

bool Quest::hasWon()
{
	int possessedId = player_->getPossessedId();
	for(unsigned int i = 0; i < toPossessId_.size(); i++)
	{
		if(toPossessId_[i] == possessedId)
		{
			return true;
		}
	}
	
	return false;
}
bool Quest::hasLost()
{
	return false;
}