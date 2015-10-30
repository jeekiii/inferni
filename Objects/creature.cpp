/// *********************16/02/2013***********************///

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/arrow.hpp"
#include "../Objects/player.hpp"
#include "creature.hpp"
#include "../Objects/ai_tuto.hpp"
#include <algorithm>

Creature::Creature(int positionX, int positionY)
{
	position_.x = positionX;
	position_.y = positionY;
	possessed_ = false;
	attackCD_ = 200;
	attackCurrentCD_ = 200;
	leaving_ = false;
	possessable_ = true;
	hp_ = 10;
	image_=ImageFunc::loadSprites("Images/HeroDown.bmp",true,255,0,0);

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
	SDL_QueryTexture(image_, NULL, NULL, &position_.w, &position_.h);
	ai_ = new AiTuto;
}

Creature::~Creature()
{
    SDL_DestroyTexture(image_);
}


void Creature::onRender(Coord positionMap)
{
	Coord positionBlit;//this code should be moved somewhere it's copied in arrow.cpp
	positionBlit.x = position_.x + positionMap.x;
	positionBlit.y = position_.y + positionMap.y;
	positionBlit.h = position_.h;
	positionBlit.w = position_.w;
	ImageFunc::renderTexture(image_, Global::renderer, false, positionBlit, positionBlit);
}

void Creature::onMove(std::vector<Object*> *objects)
{
	
	std::vector <ReactionType> reactions;
	std::vector <ReactionObject> collisions;
	ReactionType solid = SOLID_REACTION;
	position_.x += toMove_.x;
	position_.y += toMove_.y;
	collisions = getCollision(objects, true, true);
	for(unsigned int i = 0; i < collisions.size(); i++)
	{
		reactions.push_back(collisions.at(i).reaction);
	}
	if(std::find(reactions.begin(), reactions.end(), POSSESS_REACTION)!= reactions.end())
	{

	}
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position_.x -= toMove_.x;// in case you can still move on the y axis
	}
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position_.x += toMove_.x;// in case you can still move on the x axis
		position_.y -= toMove_.y;
	}
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position_.x -= toMove_.x;// if you can't move on any axis.
	}
	toMove_.x = 0;
	toMove_.y = 0;

		
}


void Creature::onUpdate(std::vector<Object*> *objects)
{
	leaving_ = false;
	if(attackCurrentCD_ >0)
		attackCurrentCD_--;
	if(!possessed_)
	{
		onCommand(objects, ai_->GiveCommands());
	}
	if(hp_ <= 0)
	{
		if(possessed_)
		{
			leaving_ = true;
			printf("game over?");//change this whole if-else...
		}
		else
		{
			objects->erase(std::find(objects->begin(), objects->end(), this));
			delete this;//keep at the end of the loop till we delete it. "delete this" ain't good like that.
		}
	}


}


ReactionType Creature::reaction(Object *object, bool ground)
{
	if(ground)
		return SOLID_REACTION;
	else
		return NONE_REACTION;
}


void Creature::takeDamage(int amount)
{
	hp_ -= amount;
}

void Creature::onCommand(std::vector<Object*> *objects, std::vector<CommandType> commands)
{
	if(std::find(commands.begin(), commands.end(), RIGHT_COMMAND)!= commands.end())
		toMove_.x = 5;
	else if(std::find(commands.begin(), commands.end(), LEFT_COMMAND)!= commands.end())
		toMove_.x = -5;
	else if(std::find(commands.begin(), commands.end(), DOWN_COMMAND)!= commands.end())
		toMove_.y = 5;
	else if(std::find(commands.begin(), commands.end(), UP_COMMAND)!= commands.end())
		toMove_.y = -5;
	else if(std::find(commands.begin(), commands.end(), ATTACK_COMMAND)!= commands.end())
	{
		if(attackCurrentCD_ ==0)
		{
			Coord direction;
			Coord position;
			direction.x = 5;
			direction.y = 0;

			position.x = position_.x+relativeAboveHitbox_.x+relativeAboveHitbox_.w;
			position.y = position_.y+30;
			
			Arrow *arrow = new Arrow(position.x, position.y);
			arrow->launch(direction);
			objects->push_back(arrow);
			attackCurrentCD_ = attackCD_;
		}

	}
	else if(std::find(commands.begin(), commands.end(), SPECIAL_COMMAND)!= commands.end())
	{
		leaving_ = true;
	}

}

