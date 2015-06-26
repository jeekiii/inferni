#include "player.hpp"
#include "../Objects/creature.hpp"
cPlayer::cPlayer()
{

}

cPlayer::~cPlayer()
{
	free(possessed);//damn, that's one sweet-ass piece of code!
}

void cPlayer::OnRender()
{
	possessed->OnRender();
}

void cPlayer::OnMove()
{

}

void cPlayer::Reaction(cObject *object)
{

}

void cPlayer::OnInit()
{
	possessed = new cCreature;
	possessed->OnInit();
}

