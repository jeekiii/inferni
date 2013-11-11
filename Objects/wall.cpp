/// *********************16/02/2013***********************///


#include "object.hpp"
#include "collision_object.hpp"
#include "wall.hpp"

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"

cWall::cWall()
{
    img=ImageFunc::LoadSprites("Images/brick.bmp");
}

cWall::~cWall()
{
    SDL_DestroyTexture(img);
}


void cWall::Draw()
{
        for(int j=3;j<7;j++)
        {
            ImageFunc::RenderTexture(j*XSCALE,8*YSCALE,img,Global::renderer);
        }

        for(int j=4;j<8;j++)
        {
            ImageFunc::RenderTexture(j*XSCALE,14*YSCALE,img,Global::renderer);
        }

        for(int j=10;j<16;j++)
        {
            ImageFunc::RenderTexture(j*XSCALE,10*YSCALE,img,Global::renderer);
        }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<20;j++)
        {
            ImageFunc::RenderTexture(j*XSCALE,(18+i)*YSCALE,img,Global::renderer);
        }

    }
}
