/// *********************16/02/2013***********************///


#include "creature.hpp"


cCreature::cCreature()
{

}

cCreature::~cCreature()
{
    SDL_DestroyTexture(image);
}


void cCreature::OnRender()
{
	ImageFunc::RenderTexture(image, Global::renderer, false, position, position);
}

void cCreature::OnMove(std::vector<cObject*> *objects)
{
	//GetCollision(objects);
	position.x += toMove.x;
	position.y += toMove.y;
	toMove.x = 0;
	toMove.y = 0;
}
ReactionType cCreature::Reaction(cObject *object)
{
	printf("Reaction working");
	ReactionType result = SOLID;
	return result;
}

void cCreature::OnInit()
{
	image=ImageFunc::LoadSprites("Images/HeroDown.bmp",true,255,0,0);
	position.x = rand()%100;
	position.y = rand()%100;
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

