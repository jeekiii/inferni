/// *********************16/02/2013***********************///

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/arrow.hpp"
#include "../Objects/player.hpp"
#include "creature.hpp"
#include "../Objects/ai_tuto.hpp"
#include <algorithm>

Creature::Creature(int positionX, int positionY, int id)
{
	id_ = id;
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
	ai_ = new AiTuto(this);
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
//it doesn't work properly here.
void Creature::onMove(std::vector<Object*> *objects)
{
	
	std::vector <ReactionType> reactions;
	std::vector <ReactionObject> collisions;
	ReactionType solid = SOLID_REACTION;
	position_.x += toMove_.x;
	position_.y += toMove_.y;
	

	getReaction(objects, &reactions);
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position_.x -= toMove_.x;// in case you can still move on the y axis
	}

	getReaction(objects, &reactions);
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position_.x += toMove_.x;
		position_.y -= toMove_.y;
	}

	getReaction(objects, &reactions);
	if(std::find(reactions.begin(), reactions.end(), solid) != reactions.end())
	{
		position_.x -= toMove_.x;
	}
	if(std::find(reactions.begin(), reactions.end(), POSSESS_REACTION)!= reactions.end())
	{

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
			printf("game over?\n");//change this whole if-else...
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
	//printf("command size: %d\n", (int) commands.size());
	bool moved = false;

	if(std::find(commands.begin(), commands.end(), MOVE_RIGHT_COMMAND)!= commands.end())
	{
		moved = true;
		right_ = true;
		left_ = false;
		up_ = false;
		down_ = false;
	}
	else if(std::find(commands.begin(), commands.end(), MOVE_LEFT_COMMAND)!= commands.end())
	{
		moved = true;
		left_ = true;
		right_ = false;
		up_ = false;
		down_ = false;
	}
	if(std::find(commands.begin(), commands.end(), MOVE_DOWN_COMMAND)!= commands.end())
	{
		down_ = true;
		up_ = false;
		if(!moved)
		{
			left_ = false;
			right_ = false;
		}
		moved = true;

	}
	else if(std::find(commands.begin(), commands.end(), MOVE_UP_COMMAND)!= commands.end())
	{
		up_ = true;
		down_ = false;
		if(!moved)
		{
			left_ = false;
			right_ = false;
		}
		moved = true;
	}
	if(std::find(commands.begin(), commands.end(), ATTACK_COMMAND)!= commands.end())
	{
		if(attackCurrentCD_ ==0)
		{
			Coord direction;
			Coord position;
			if(right_)
			{
				position.x = position_.x+relativeAboveHitbox_.x+relativeAboveHitbox_.w+10;
				position.y = position_.y+30;
				direction.x = 5;
				direction.y = 0;
			}
			else
			{
				position.x = position_.x+relativeAboveHitbox_.x-75;//dunnno how to get an absolute value for this, it's the arrow's direction.
				position.y = position_.y+30;
				direction.x = -5;
				direction.y = 0;
			}
			
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

	if(right_ && moved)
	{
		if(!left_ && !up_ && !down_)
			toMove_.x+=5;
		else
			toMove_.x+=3;//moving diagonally
	}
	if(left_ && moved)
	{
		if(!right_ && !up_ && !down_)
			toMove_.x-=5;
		else
			toMove_.x-=3;
	}
	if(up_ && moved)
	{
		if(!left_ && !right_ && !down_)
			toMove_.y-=5;
		else
			toMove_.y-=3;
	}
	if(down_ && moved)
	{
		if(!left_ && !up_ && !right_)
			toMove_.y+=5;
		else
			toMove_.y+=3;
	}
	if(std::find(commands.begin(), commands.end(), TURN_RIGHT_COMMAND)!= commands.end())
		right_ = true;
	if(std::find(commands.begin(), commands.end(), TURN_LEFT_COMMAND)!= commands.end())
		left_ = true;
	if(std::find(commands.begin(), commands.end(), TURN_UP_COMMAND)!= commands.end())
		up_ = true;
	if(std::find(commands.begin(), commands.end(), TURN_DOWN_COMMAND)!= commands.end())
		down_ = true;

}

