
//#include <SDL_image.h>
#include "image_func.hpp"


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



int ImageFunc::RenderTexture(SDL_Texture*src, SDL_Renderer*des, bool clip, coord position, coord toClip)//where does clip comes from?? why is it here?
{
        SDL_Rect rectPosition = Tools::CoordToRect(position);
        if(clip)
        {
            SDL_Rect rectToClip = Tools::CoordToRect(toClip);


            SDL_RenderCopy(des,src, &rectToClip, &rectPosition);
        }

        else
        {
            SDL_RenderCopy(des,src,NULL, &rectPosition);
        }
        
        return 0;
}







