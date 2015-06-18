/// *********************16/02/2013***********************///


#include "creature.hpp"


cCreature::cCreature()
{

}

cCreature::~cCreature()
{
    SDL_DestroyTexture(img);
}


void cCreature::OnRender()
{
	ImageFunc::RenderTexture(img, Global::renderer, false, position, position);
}

void cCreature::OnMove()
{

}
void cCreature::Reaction(cObject *object)
{
	
}

void cCreature::OnInit()
{
	img=ImageFunc::LoadSprites("Images/HeroDown.bmp",true,255,0,0);
	position.x = rand()%100;
	position.y = rand()%100;
	SDL_QueryTexture(img, NULL, NULL, &position.w, &position.h);

}
coord cCreature::GetPosition()
{
	return position;
}