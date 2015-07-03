#include "player.hpp"
#include "../Objects/creature.hpp"
cPlayer::cPlayer()
{

}

cPlayer::~cPlayer()
{
	free(possessed);//damn, that's one sweet-ass piece of code!
	free(cmd);
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
	cmd =  new cCommand;
	possessed = new cCreature;
	possessed->OnInit();
	position = possessed->GetPosition();
}

void cPlayer::OnCommand(SDL_Keycode key)
{
	CommandType input = cmd->getCommand(key);
	if(input == UP)
		possessed->OnUP();
	else if(input == DOWN)
		possessed->OnDOWN();
	else if(input == LEFT)
		possessed->OnLEFT();
	else if(input == RIGHT) 
		possessed->OnRIGHT();
}