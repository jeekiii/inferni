
//#include <SDL_image.h>
#include "image_func.hpp"
#include "../Core/global.hpp"

// load images from file to the SDL_surface memory
SDL_Texture* ImageFunc::LoadSprites(const char* filemame,bool alpha,int r, int g, int b)
{
        SDL_Surface* old_image=NULL;
        SDL_Texture* new_image=NULL;

        old_image=SDL_LoadBMP(filemame);
        if(alpha)
        { 
            SDL_SetColorKey( old_image, SDL_TRUE, SDL_MapRGB( old_image->format,r, g,b ) );
        }
        
        
        new_image=SDL_CreateTextureFromSurface(Global::renderer,old_image);
        SDL_FreeSurface(old_image);

        return new_image;
}



int ImageFunc::RenderTexture(int dx, int dy, SDL_Texture*src, SDL_Renderer*des, bool clip,int cx, int cy,int cw, int ch)
{
        SDL_Rect rc_d;
        rc_d.x=dx;
        rc_d.y=dy;

        if(clip)
        {
            SDL_Rect rc_s;
            rc_s.x=cx;
            rc_s.y=cy;
            rc_s.w=cw;
            rc_s.h=ch;
            SDL_RenderCopy(des,src,NULL,&rc_d);
        }

        else
           SDL_RenderCopy(des,src,NULL,&rc_d);

        return 0;
}







