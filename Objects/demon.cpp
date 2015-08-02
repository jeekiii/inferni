
#include "demon.hpp"
#include <algorithm>
#include <vector>
#include "../Util/image_func.hpp"
cDemon::cDemon()
{

}
cDemon::~cDemon()
{
	SDL_DestroyTexture(image);
}

void cDemon::OnRender(coord positionMap)
{
	coord positionBlit;//this code should be moved somewhere it's copied in arrow.cpp
	positionBlit.x = position.x + positionMap.x;
	positionBlit.y = position.y + positionMap.y;
	positionBlit.h = position.h;
	positionBlit.w = position.w;
	ImageFunc::RenderTexture(image, Global::renderer, false, positionBlit, positionBlit);
}

void cDemon::OnMove(std::vector<cObject*> *objects)
{
	position.x += toMove.x;
	position.y += toMove.y;
	toMove.x = 0;
	toMove.y = 0;


}
void cDemon::OnUpdate(std::vector<cObject*> *objects)
{
	leaving = false;

}

ReactionType cDemon::Reaction(cObject *object, bool ground)
{

	return NONE;
}

void cDemon::OnInit(int positionX, int positionY)
{
	hp = 100;
	leaving = false;
	possessable = true;
	image=ImageFunc::LoadSprites("Images/HeroUp.bmp",true,255,0,0);
	position.x = positionX;
	position.y = positionY;
	SDL_QueryTexture(image, NULL, NULL, &position.w, &position.h);
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
}


void cDemon::OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> commands)
{
	if(std::find(commands.begin(), commands.end(), RIGHT)!= commands.end())
		toMove.x = 5;
	else if(std::find(commands.begin(), commands.end(), LEFT)!= commands.end())
		toMove.x = -5;
	else if(std::find(commands.begin(), commands.end(), DOWN)!= commands.end())
		toMove.y = 5;
	else if(std::find(commands.begin(), commands.end(), UP)!= commands.end())
		toMove.y = -5;
	else if(std::find(commands.begin(), commands.end(), SPECIAL)!= commands.end())
	{
		leaving = true;

	}
}

void cDemon::SetPosition(coord position)
{
	this->position = position;
}
