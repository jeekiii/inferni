
#include "image_func.hpp"


// load images from file to the SDL_surface memory
SDL_Texture* ImageFunc::LoadSprites(const char* filename,bool alpha,int r, int g, int b)
{
        SDL_Surface* old_image=NULL;
        SDL_Texture* new_image=NULL;

        old_image=SDL_LoadBMP(filename);
        if(!old_image)
            printf("image loadinf failure: image func: SDL_LoadBMP \n");

        if(alpha)
        { 
            SDL_SetColorKey( old_image, SDL_TRUE, SDL_MapRGB( old_image->format,r, g,b ) );
        }
        
        
        new_image=SDL_CreateTextureFromSurface(Global::renderer,old_image);
        if(!new_image)
            printf("image loading failure: image_func\n");
        SDL_FreeSurface(old_image);

        return new_image;
}



int ImageFunc::RenderTexture(SDL_Texture*src, SDL_Renderer*des, bool clip, coord position, coord toClip)//where does clip comes from?? why is it here?
{
        int error;
        SDL_Rect rectPosition = Tools::CoordToRect(position);
        if(clip)
        {
            SDL_Rect rectToClip = Tools::CoordToRect(toClip);

            error = SDL_RenderCopy(des,src, &rectToClip, &rectPosition);
            if(error)
                printf("render failure: image_func, code: %d\n", error);
        }

        else
        {
            error = SDL_RenderCopy(des,src,NULL, &rectPosition);
            if(error)
                printf("render failure: image_func, code: %s\n", SDL_GetError());
        }
        
        return 0;
}







