/// *********************16/02/2013***********************///


#include "creature.hpp"
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
	coord positionBlit;
	positionBlit.x = position.x + positionMap.x;
	positionBlit.y = position.y + positionMap.y;
	positionBlit.h = position.h;
	positionBlit.w = position.w;
	ImageFunc::RenderTexture(image, Global::renderer, false, positionBlit, positionBlit);
}

void cCreature::OnMove(std::vector<cObject*> *objects)
{
	std::vector <ReactionType> reactions;
	ReactionType solid = SOLID;
	position.x += toMove.x;
	position.y += toMove.y;
	reactions = GetCollision(objects);
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

ReactionType cCreature::Reaction(cObject *object)
{
	ReactionType result = SOLID;
	return result;
}

void cCreature::OnInit(int positionX, int positionY)
{
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

}

void cCreature::OnRIGHT(std::vector<cObject*> *objects)
{
	toMove.x = 10;
	printf("right");
}
void cCreature::OnLEFT(std::vector<cObject*> *objects)
{
	toMove.x = -10;
	printf("left");
}
void cCreature::OnUP(std::vector<cObject*> *objects)
{
	toMove.y = -10;
	printf("up");
}
void cCreature::OnDOWN(std::vector<cObject*> *objects)
{
	toMove.y = 10;
	printf("down");
}

