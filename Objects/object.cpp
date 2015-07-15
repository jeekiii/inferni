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

std::vector <ReactionType> cObject::GetCollision(std::vector<cObject*> *objects)
{
	std::vector <ReactionType> result;
	result.push_back(NONE);
	for(unsigned int i = 0; i < objects->size(); i++)
	{

		if(this != objects->at(i))
		{
			printf("x1 %d, x2 %d, r %d \n", this->GetGroundHitbox().x, objects->at(i)->GetGroundHitbox().x, objects->at(i)->Reaction(this));
			if(Tools::Collision(this->GetGroundHitbox(), objects->at(i)->GetGroundHitbox()))
				result.push_back(objects->at(i)->Reaction(this));
		}
	}
	return result;
}

bool compareObjects(cObject *obj1, cObject *obj2)
{
	return (obj1->GetPosition().y+obj1->GetPosition().h < obj2->GetPosition().y+obj2->GetPosition().h);
}

