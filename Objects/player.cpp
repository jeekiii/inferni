#include "player.hpp"
#include "../Objects/creature.hpp"
#include <algorithm>
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

void cPlayer::OnMove(std::vector<cObject*> *objects)
{

}

ReactionType cPlayer::Reaction(cObject *object)
{
	return SOLID;
}

void cPlayer::OnInit()
{
	cmd =  new cCommand;
	possessed = new cCreature;
	possessed->OnInit();
	position = possessed->GetPosition();
}

void cPlayer::OnCommand(std::vector<SDL_Keycode> keys, std::vector<cObject*> *objects)//should get a vector of keys to react correctly in case multiple keys are pressed
{
	CommandType input = cmd->getCommand(keys);//should get a vector of keys
	if(input == UP)
		possessed->OnUP(objects);
	else if(input == DOWN)
		possessed->OnDOWN(objects);
	else if(input == LEFT)
		possessed->OnLEFT(objects);
	else if(input == RIGHT) 
		possessed->OnRIGHT(objects);
}