#include "../Objects/object.hpp"

Coord Object::getPosition()
{
	return position_;
}
Coord Object::getGroundHitbox()
{
	Coord result;
	result.x = position_.x+relativeGroundHitbox_.x;
	result.y = position_.y+relativeGroundHitbox_.y;
	result.w = relativeGroundHitbox_.w;
	result.h = relativeGroundHitbox_.h;
	return result;
}
Coord Object::getAboveHitbox()
{
	Coord result;
	result.x = position_.x+relativeAboveHitbox_.x;
	result.y = position_.y+relativeAboveHitbox_.y;
	result.w = relativeAboveHitbox_.w;
	result.h = relativeAboveHitbox_.h;
	return result;
}

void Object::getReaction(std::vector<Object*> *objects, std::vector<ReactionType> *reactions)
{
	reactions->clear();
	std::vector<ReactionObject> collisions;
	collisions = getCollision(objects, true, true);
	for(unsigned int i = 0; i < collisions.size(); i++)
	{
		reactions->push_back(collisions.at(i).reaction);
	}
}

std::vector <ReactionObject> Object::getCollision(std::vector<Object*> *objects, bool ground, bool above)
{
	std::vector <ReactionObject> result;
	for(unsigned int i = 0; i < objects->size(); i++)
	{
		ReactionObject temp;
		if(this != objects->at(i))
		{
			if(ground)
			{
				if(Tools::collision(this->getGroundHitbox(), objects->at(i)->getGroundHitbox()))
				{
					temp.object = objects->at(i);
					temp.reaction = objects->at(i)->reaction(this, true);
					temp.ground = true;
					result.push_back(temp);
				}	
			}
			if(above)
			{
				if(Tools::collision(this->getAboveHitbox(), objects->at(i)->getAboveHitbox()))
				{
					temp.object = objects->at(i);
					temp.reaction = objects->at(i)->reaction(this, false);
					temp.ground = false;
					result.push_back(temp);
				}	
			}
		}
	}
	return result;
}

bool compareObjects(Object *obj1, Object *obj2)
{
	return (obj1->getPosition().y+obj1->getPosition().h < obj2->getPosition().y+obj2->getPosition().h);
}


