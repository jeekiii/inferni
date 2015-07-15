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

void cPlayer::OnRender(coord positionMap)
{
	possessed->OnRender(positionMap);
}

void cPlayer::OnMove(std::vector<cObject*> *objects)
{
	possessed->OnMove(objects);
	position = possessed->GetPosition();//allow for sorting in level->onrender to render things in the right order.

}

ReactionType cPlayer::Reaction(cObject *object)
{
	if(object == possessed)
		return NONE;
	return possessed->Reaction(object);
}

void cPlayer::OnInit(int positionX, int positionY)
{
	cmd =  new cCommand;
	possessed = new cCreature;
	possessed->OnInit(positionX, positionY);
	position = possessed->GetPosition();
	relativeGroundHitbox = possessed->GetGroundHitbox();
	relativeGroundHitbox.x -= position.x;
	relativeGroundHitbox.y -= position.y;
	relativeAboveHitbox = possessed->GetAboveHitbox();
	relativeAboveHitbox.x -= position.x;
	relativeAboveHitbox.y -= position.y;
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
