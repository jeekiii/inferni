#include "quest.hpp"
#include "../Objects/creature.hpp"

Quest::Quest(int id, Player *player, std::vector<Object*> *objects, std::vector<Objective *> *objectives, int next)
{
	id_         = id;
	player_     = player;
    objects_    = objects;
	objectives_ = objectives;
}

Quest::~Quest()
{

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
	for (unsigned int i = 0; i < objectives_->size(); i++)
		if (!objectives_->at(i)->isCompleted(player_, objects_))
			return false;

	return true;
}
bool Quest::hasLost()
{
	for (unsigned int i = 0; i < objectives_->size(); i++)
		if (objectives_->at(i)->isLost(player_, objects_))
			return true;

	return false;
}
