#include "../Objects/object.hpp"

coord cObject::GetPosition()
{
	return position;
}

ReactionType cObject::GetCollision(std::vector<cObject*> *objects)
{
	printf("GetCollision working");

	for(unsigned int i = 0; i < objects->size(); i++)
	{
		if(Tools::Collision(this->GetPosition(), objects->at(i)->GetPosition()))
			return objects->at(i)->Reaction(this);
	}
	return NONE;
}

bool compareObjects(cObject *obj1, cObject *obj2)
{
	return (obj1->GetPosition().y < obj2->GetPosition().y );
}

