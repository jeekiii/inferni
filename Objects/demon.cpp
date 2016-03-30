
#include "demon.hpp"
#include <algorithm>
#include <vector>
#include "../Util/image_func.hpp"
Demon::Demon()
{

}
Demon::~Demon()
{
	SDL_DestroyTexture(image_);
}

Demon::Demon(int positionX, int positionY, int id)
{
	id_ = id;
	hp_ = 100;
	leaving_ = false;
	possessable_ = true;
	image_=ImageFunc::loadSprites("Images/HeroDown.bmp",true,255,0,0);
	position_.x = positionX;
	position_.y = positionY;
	SDL_QueryTexture(image_, NULL, NULL, &position_.w, &position_.h);
	relativeGroundHitbox_.x = 5;
	relativeGroundHitbox_.w = 37;
	relativeGroundHitbox_.y = 67;
	relativeGroundHitbox_.h = 26;
	relativeAboveHitbox_.x = 5;
	relativeAboveHitbox_.w = 38;
	relativeAboveHitbox_.y = 2;
	relativeAboveHitbox_.h = 65;
	toMove_.x = 0;
	toMove_.y = 0;
}

void Demon::onRender(Coord positionMap)
{
	Coord positionBlit;//this code should be moved somewhere it's copied in arrow.cpp
	positionBlit.x = position_.x + positionMap.x;
	positionBlit.y = position_.y + positionMap.y;
	positionBlit.h = position_.h;
	positionBlit.w = position_.w;
	ImageFunc::renderTexture(image_, Global::renderer, false, positionBlit, positionBlit);
}

void Demon::onMove(std::vector<Object*> *objects)
{
	position_.x += toMove_.x;
	position_.y += toMove_.y;
	toMove_.x = 0;
	toMove_.y = 0;


}
void Demon::onUpdate(std::vector<Object*> *objects)
{
	leaving_ = false;

}

ReactionType Demon::reaction(Object *object, bool ground)
{

	return NONE_REACTION;
}



void Demon::onCommand(std::vector<Object*> *objects, std::vector<CommandType> commands)
{
	bool right, left, up, down;
	right = left = up = down = false;
	if(std::find(commands.begin(), commands.end(), MOVE_RIGHT_COMMAND)!= commands.end())
		right = true;
	if(std::find(commands.begin(), commands.end(), MOVE_LEFT_COMMAND)!= commands.end())
		left = true;
	if(std::find(commands.begin(), commands.end(), MOVE_DOWN_COMMAND)!= commands.end())
		down = true;
	if(std::find(commands.begin(), commands.end(), MOVE_UP_COMMAND)!= commands.end())
		up = true;
	else if(std::find(commands.begin(), commands.end(), SPECIAL_COMMAND)!= commands.end())
	{
		leaving_ = true;

	}

	if(right)
	{
		if(!left && !up && !down)
			toMove_.x+=5;
		else
			toMove_.x+=3;
	}
	if(left)
	{
		if(!right && !up && !down)
			toMove_.x-=5;
		else
			toMove_.x-=3;
	}
	if(up)
	{
		if(!left && !right && !down)
			toMove_.y-=5;
		else
			toMove_.y-=3;
	}
	if(down)
	{
		if(!left && !up && !right)
			toMove_.y+=5;
		else
			toMove_.y+=3;
	}
}

void Demon::setPosition(Coord position)
{
	position_ = position;
}
