/*#include "level.hpp"
#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/creature.hpp"
#include "../Objects/demon.hpp"

#include <algorithm>
#include <vector>
#include "global.hpp"

Level::Level()
{
	map_ = new Map(1);
	hud_ = new Hud();
	Creature *creature=new Creature(200, 100);
	player_ = new Player(100, 100);

	objects_.push_back(player_);
    objects_.push_back(creature);

    
}

Level::~Level()
{
    objects_.clear();
    delete map_;
    delete hud_;
}

void Level::onRender()
{
	
	map_->onRender(player_->getPosition());
	std::sort(objects_.begin(), objects_.end(), compareObjects);
	for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
	{
		objects_[i]->onRender(map_->getPosition());
	}
	hud_->onRender();
}

void Level::onUpdate(std::vector <CommandType> commands)
{
	player_->onCommand(&objects_, commands);
	for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
	{
		objects_[i]->onUpdate(&objects_);

	}//separate loops in case one of those deletes the object.
	for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
	{
		objects_[i]->onMove(&objects_);

	}

}

*/