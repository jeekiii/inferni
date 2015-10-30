#include "level.hpp"
#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/creature.hpp"
#include "../Objects/demon.hpp"

#include <algorithm>
#include <vector>
#include "global.hpp"

Level::Level():map_(1), hud_(player_)
{
	Creature *creature=new Creature(200, 100);
	player_ = new Player(100, 100);

	objects_.push_back(player_);
    objects_.push_back(creature);


    positionMap_ = map_.getStartingPosition();


    
}

Level::~Level()
{
    objects_.clear();
    map_.~Map();
}

void Level::onRender()
{
	positionMap_.x = (Global::screenWidth/2) - (player_->getPosition().x + player_->getPosition().w/2);
	positionMap_.y = (Global::screenHeight/2) - (player_->getPosition().y + player_->getPosition().w/2);
	if(positionMap_.x > 0)
	{
		positionMap_.x = 0;
	}
	if(positionMap_.x + positionMap_.w < Global::screenWidth)
	{
		positionMap_.x = Global::screenWidth-positionMap_.w;
	}
	if(positionMap_.y > 0)
	{
		positionMap_.y = 0;
	}
	if(positionMap_.y +positionMap_.h < Global::screenHeight)
	{
		positionMap_.y = Global::screenHeight-positionMap_.h;
	}
	//ImageFunc::renderTexture(map,Global::renderer, false, positionMap, positionMap);
	map_.onRender(positionMap_);
	std::sort(objects_.begin(), objects_.end(), compareObjects);
	for(unsigned int i = 0; i < objects_.size(); i++)// not optimal? maybe use an iterator
	{
		objects_[i]->onRender(positionMap_);
	}
	hud_.onRender();
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

