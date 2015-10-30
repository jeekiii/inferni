#include "hud.hpp"

Hud::~Hud()
{
	;
}

Hud::Hud()
{
	;
}
Hud::Hud(Player *player)
{
	player_ = player;
}
void Hud::onRender()
{
	//printf("hud hp: %d \n",player->getHp());
}