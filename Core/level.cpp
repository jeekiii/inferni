#include "level.hpp"
#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/creature.hpp"

int cLevel::OnInit()
{

	cCreature *creature=new cCreature;
    objects.push_back(creature);
    map=NULL;
    map=ImageFunc::LoadSprites("Images/Map1.bmp");
    positionMap.x = 0;
    positionMap.y = 0;
    for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnInit();
	}
    SDL_QueryTexture(map, NULL, NULL, &positionMap.w, &positionMap.h);
    return 0;
}

int cLevel::OnCleanUp()
{
    objects.clear();
    SDL_DestroyTexture(map);
    return 0;
}

void cLevel::OnRender()
{
	ImageFunc::RenderTexture(map,Global::renderer, false, positionMap, positionMap);        
	for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnRender();
	}
}

void cLevel::OnUpdate()
{
	for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnMove();
	}
}