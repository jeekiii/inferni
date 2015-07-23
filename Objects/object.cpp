#include "../Objects/object.hpp"

coord cObject::GetPosition()
{
	return position;
}
coord cObject::GetGroundHitbox()
{
	coord result;
	result.x = position.x+relativeGroundHitbox.x;
	result.y = position.y+relativeGroundHitbox.y;
	result.w = relativeGroundHitbox.w;
	result.h = relativeGroundHitbox.h;
	return result;
}
coord cObject::GetAboveHitbox()
{
	coord result;
	result.x = position.x+relativeAboveHitbox.x;
	result.y = position.y+relativeAboveHitbox.y;
	result.w = relativeAboveHitbox.w;
	result.h = relativeAboveHitbox.h;
	return result;
}

std::vector <ReactionObject> cObject::GetCollision(std::vector<cObject*> *objects, bool ground, bool above)
{
	std::vector <ReactionObject> result;
	for(unsigned int i = 0; i < objects->size(); i++)
	{
		ReactionObject temp;
		if(this != objects->at(i))
		{
			if(ground)
			{
				if(Tools::Collision(this->GetGroundHitbox(), objects->at(i)->GetGroundHitbox()))
				{
					temp.object = objects->at(i);
					temp.reaction = objects->at(i)->Reaction(this, true);
					temp.ground = true;
					result.push_back(temp);
				}	
			}
			if(above)
			{
				if(Tools::Collision(this->GetAboveHitbox(), objects->at(i)->GetAboveHitbox()))
				{
					temp.object = objects->at(i);
					temp.reaction = objects->at(i)->Reaction(this, false);
					temp.ground = false;
					result.push_back(temp);
				}	
			}
		}
	}
	return result;
}

bool compareObjects(cObject *obj1, cObject *obj2)
{
	return (obj1->GetPosition().y+obj1->GetPosition().h < obj2->GetPosition().y+obj2->GetPosition().h);
}


