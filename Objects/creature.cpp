/// *********************16/02/2013***********************///


#include "creature.hpp"


cCreature::cCreature()
{
    img=ImageFunc::LoadSprites("Images/HeroDown.bmp",true,255,0,0);
}

cCreature::~cCreature()
{
    SDL_DestroyTexture(img);
}


void cCreature::Draw()
{
     //ImageFunc::RenderTexture(3*XSCALE,15*YSCALE,img,Global::renderer);
}
