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
	if(possessed->IsLeaving())
	{
		if(specialCurrentCD > 0)
			specialCurrentCD--;
		if(specialCurrentCD == 0)
		{
			if(!demonForm)
			{
				objects->push_back(possessed);
				LeaveBody();
			}
			else
			{
				std::vector<ReactionObject> collisions;
				collisions = GetCollision(objects, true, true);
				bool found = false;
				for(unsigned int i = 0; i < collisions.size() && !found; i++)
				{
					if(collisions.at(i).object->IsPossessable())
					{
						objects->erase(std::find(objects->begin(), objects->end(), collisions.at(i).object));
						Possess(static_cast<cPossessable*>(collisions.at(i).object));
						found = true;
					}
				}
			}
			specialCurrentCD = specialCD;
		}
	}
		

	possessed->OnMove(objects);
	position = possessed->GetPosition();//allow for sorting in level->onrender to render things in the right order.

}

ReactionType cPlayer::Reaction(cObject *object, bool ground)
{
	if(object == possessed)
		return NONE;
	return possessed->Reaction(object, ground);
}

void cPlayer::OnInit(int positionX, int positionY)
{
	specialCurrentCD =0;
	specialCD = 10;
	demonForm = false;
	possessable = false;
	cmd =  new cCommand;
	possessed = new cCreature;
	possessed->OnInit(positionX, positionY);
	demon = new cDemon;
	demon->OnInit(positionX, positionY);
	position = possessed->GetPosition();
	relativeGroundHitbox = possessed->GetGroundHitbox();
	relativeGroundHitbox.x -= position.x;
	relativeGroundHitbox.y -= position.y;
	relativeAboveHitbox = possessed->GetAboveHitbox();
	relativeAboveHitbox.x -= position.x;
	relativeAboveHitbox.y -= position.y;
}

void cPlayer::OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> commands)//should get a vector of keys to react correctly in case multiple keys are pressed
{
	possessed->OnCommand(objects, commands);
}
void cPlayer::TakeDamage(int amount)
{
	possessed->TakeDamage(amount);
}

void cPlayer::Possess(cPossessable *target)
{
	demonForm = false;
	possessed = target;
}

void cPlayer::LeaveBody()
{
	possessed = demon;
	demonForm = true;
	demon->SetPosition(position);
}