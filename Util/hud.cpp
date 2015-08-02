#include "hud.hpp"

cHud::~cHud()
{
	;
}

cHud::cHud()
{
	;
}

void cHud::OnInit(cPlayer *player)
{
	this->player = player;
}
void cHud::OnRender()
{
	printf("hud hp: %d \n",player->GetHp());
}