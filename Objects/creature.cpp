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

void cCreature::OnMove()
{

}
void cCreature::Reaction(cObject *object)
{
	
}

void cCreature::OnInit()
{
	image=ImageFunc::LoadSprites("Images/HeroDown.bmp",true,255,0,0);
	position.x = rand()%100;
	position.y = rand()%100;
	SDL_QueryTexture(image, NULL, NULL, &position.w, &position.h);

}

void cCreature::OnRIGHT()
{
	printf("right");
}
void cCreature::OnLEFT()
{
	printf("left");
}
void cCreature::OnUP()
{
	printf("up");
}
void cCreature::OnDOWN()
{
	printf("down");
}

