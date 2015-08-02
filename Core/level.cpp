#include "level.hpp"
#include "../Util/image_func.hpp"
#include "../Core/global.hpp"
#include "../Objects/creature.hpp"
#include "../Objects/player.hpp"
#include "../Objects/demon.hpp"
#include <algorithm>
#include <vector>
#include "global.hpp"

int cLevel::OnInit()
{
	cCreature *creature=new cCreature;
	player = new cPlayer;

	hud.OnInit(player);
	objects.push_back(player);
    objects.push_back(creature);

    map=NULL;
    map=ImageFunc::LoadSprites("Images/Map1.bmp");
    positionMap.x = 0;
    positionMap.y = 0;

    for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnInit(200+(i*400), 400);
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
	positionMap.x = (Global::screen_width/2) - (player->GetPosition().x + player->GetPosition().w/2);
	positionMap.y = (Global::screen_height/2) - (player->GetPosition().y + player->GetPosition().w/2);
	if(positionMap.x > 0)
	{
		positionMap.x = 0;
	}
	if(positionMap.x + positionMap.w < Global::screen_width)
	{
		positionMap.x = Global::screen_width-positionMap.w;
	}
	if(positionMap.y > 0)
	{
		positionMap.y = 0;
	}
	if(positionMap.y +positionMap.h < Global::screen_height)
	{
		positionMap.y = Global::screen_height-positionMap.h;
	}
	ImageFunc::RenderTexture(map,Global::renderer, false, positionMap, positionMap);
	std::sort(objects.begin(), objects.end(), compareObjects);
	for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnRender(positionMap);
	}
	hud.OnRender();
}

void cLevel::OnUpdate(std::vector <CommandType> commands)
{
	player->OnCommand(&objects, commands);
	for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnUpdate(&objects);

	}//separate loops in case one of those deletes the object.
	for(unsigned int i = 0; i < objects.size(); i++)// not optimal? maybe use an iterator
	{
		objects[i]->OnMove(&objects);

	}

}

