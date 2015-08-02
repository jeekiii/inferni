/// *********************16/02/2013***********************///

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/arrow.hpp"
#include "../Objects/player.hpp"
#include "creature.hpp"
#include "../Objects/ai_tuto.hpp"
#include <algorithm>

cCreature::cCreature()
{

}

cCreature::~cCreature()
{
    SDL_DestroyTexture(image);
}


void cCreature::OnRender(coord positionMap)
{
	coord positionBlit;//this code should be moved somewhere it's copied in arrow.cpp
	positionBlit.x = position.x + positionMap.x;
	positionBlit.y = position.y + positionMap.y;
	positionBlit.h = position.h;
	positionBlit.w = position.w;
	ImageFunc::RenderTexture(image, Global::renderer, false, positionBlit, positionBlit);
}

void cCreature::OnMove(std::vector<cObject*> *objects)
{
	
	std::vector <ReactionType> reactions;
	std::vector <ReactionObject> collisions;
	ReactionType solid = SOLID;
	position.x += toMove.x;
	position.y += toMove.y;
	collisions = GetCollision(objects, true, true);
	for(unsigned int i = 0; i < collisions.size(); i++)
	{
		reactions.push_back(collisions.at(i).reaction);
	}
	if(std::find(reactions.begin(), reactions.end(), POSSESS)!= reactions.end())
	{

	}
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position.x -= toMove.x;// in case you can still move on the y axis
	}
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position.x += toMove.x;// in case you can still move on the x axis
		position.y -= toMove.y;
	}
	if(std::find(reactions.begin(), reactions.end(), solid)!= reactions.end())
	{
		position.x -= toMove.x;// if you can't move on any axis.
	}
	toMove.x = 0;
	toMove.y = 0;

		
}


void cCreature::OnUpdate(std::vector<cObject*> *objects)
{
	leaving = false;
	if(attackCurrentCD >0)
		attackCurrentCD--;
	if(!possessed)
	{
		OnCommand(objects, AI->GiveCommands());
	}
	if(hp <= 0)
	{
		if(possessed)
		{
			leaving = true;
			printf("game over?");//change this whole if-else...
		}
		else
		{
			objects->erase(std::find(objects->begin(), objects->end(), this));
			delete this;//keep at the end of the loop till we delete it. "delete this" ain't good like that.
		}
	}


}


ReactionType cCreature::Reaction(cObject *object, bool ground)
{
	if(ground)
		return SOLID;
	else
		return NONE;
}

void cCreature::OnInit(int positionX, int positionY)
{
	possessed = false;
	attackCD = 200;
	attackCurrentCD = 200;
	leaving = false;
	possessable = true;
	hp = 10;
	image=ImageFunc::LoadSprites("Images/HeroDown.bmp",true,255,0,0);
	position.x = positionX;
	position.y = positionY;
	relativeGroundHitbox.x = 5;
	relativeGroundHitbox.w = 37;
	relativeGroundHitbox.y = 67;
	relativeGroundHitbox.h = 26;
	relativeAboveHitbox.x = 5;
	relativeAboveHitbox.w = 38;
	relativeAboveHitbox.y = 2;
	relativeAboveHitbox.h = 65;
	toMove.x = 0;
	toMove.y = 0;
	SDL_QueryTexture(image, NULL, NULL, &position.w, &position.h);
	AI = new cAITuto;

}

void cCreature::TakeDamage(int amount)
{
	hp -= amount;
}

void cCreature::OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> commands)
{
	if(std::find(commands.begin(), commands.end(), RIGHT)!= commands.end())
		toMove.x = 5;
	else if(std::find(commands.begin(), commands.end(), LEFT)!= commands.end())
		toMove.x = -5;
	else if(std::find(commands.begin(), commands.end(), DOWN)!= commands.end())
		toMove.y = 5;
	else if(std::find(commands.begin(), commands.end(), UP)!= commands.end())
		toMove.y = -5;
	else if(std::find(commands.begin(), commands.end(), ATTACK)!= commands.end())
	{
		if(attackCurrentCD ==0)
		{
			cArrow *arrow = new cArrow;
			coord direction;
			coord position;
			direction.x = 5;
			direction.y = 0;

			position.x = this->position.x+relativeAboveHitbox.x+relativeAboveHitbox.w;
			position.y = this->position.y+30;
			arrow->OnInit(position.x, position.y);
			arrow->Launch(direction);
			objects->push_back(arrow);
			attackCurrentCD = attackCD;
		}

	}
	else if(std::find(commands.begin(), commands.end(), SPECIAL)!= commands.end())
	{
		leaving = true;
	}

}

