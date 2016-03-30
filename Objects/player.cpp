#include "player.hpp"
#include "../Objects/creature.hpp"
#include <algorithm>
Player::Player(int positionX, int positionY)
{
	id_ = 1;

	position_.x = positionX;
	position_.y = positionY;
	specialCurrentCD_=0;
	specialCD_ = 10;
	demonForm_ = false;
	possessable_ = false;
	possessed_ = new Creature(0, positionX, positionY);
	possessed_->setPossessed(true);

	demon_ = new Demon(positionX, positionY);
	position_ = possessed_->getPosition();
	relativeGroundHitbox_ = possessed_->getGroundHitbox();
	relativeGroundHitbox_.x -= position_.x;
	relativeGroundHitbox_.y -= position_.y;
	relativeAboveHitbox_ = possessed_->getAboveHitbox();
	relativeAboveHitbox_.x -= position_.x;
	relativeAboveHitbox_.y -= position_.y;
}

Player::~Player()
{
	free(possessed_);//damn, that's one sweet-ass piece of code!
}

void Player::onRender(Coord positionMap)
{
	possessed_->onRender(positionMap);
}

void Player::onMove(std::vector<Object*> *objects)
{
	possessed_->onMove(objects);
	position_ = possessed_->getPosition();//allow for sorting in level->onrender to render things in the right order.

}
void Player::onUpdate(std::vector<Object*> *objects)
{

	if(specialCurrentCD_ > 0)
		specialCurrentCD_--;
	if(possessed_->isLeaving())
	{
		if(specialCurrentCD_ == 0)
		{
			if(!demonForm_)
			{
				possessed_->setPossessed(false);
				objects->push_back(possessed_);
				leaveBody();
			}
			else
			{
				std::vector<ReactionObject> collisions;
				collisions = getCollision(objects, true, true);
				bool found = false;

				for(unsigned int i = 0; i < collisions.size() && !found; i++)
				{
					if(collisions.at(i).object->isPossessable())
					{
						objects->erase(std::find(objects->begin(), objects->end(), collisions.at(i).object));
						possess(static_cast<Possessable*>(collisions.at(i).object));
						found = true;
					}
				}
			}
			specialCurrentCD_ = specialCD_;
		}
	}
	possessed_->onUpdate(objects);
}

ReactionType Player::reaction(Object *object, bool ground)
{
	if(object == possessed_)
		return NONE_REACTION;
	return possessed_->reaction(object, ground);
}


void Player::onCommand(std::vector<Object*> *objects, std::vector<CommandType> commands)//should get a vector of keys to react correctly in case multiple keys are pressed
{
	possessed_->onCommand(objects, commands);
}
void Player::takeDamage(int amount)
{
	possessed_->takeDamage(amount);
}

void Player::possess(Possessable *target)
{
	demonForm_ = false;
	possessed_ = target;
	target->setPossessed(true);
}

void Player::leaveBody()
{
	possessed_ = demon_;
	demonForm_ = true;
	demon_->setPosition(position_);
}

int Player::getHp()
{
	return possessed_->getHp();
}

int Player::getPossessedId()
{
	return possessed_->getId();
}
