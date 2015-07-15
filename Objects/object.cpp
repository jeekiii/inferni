#include "../Objects/object.hpp"

coord cObject::GetPosition()
{
	return position;
}

std::vector <ReactionType> cObject::GetCollision(std::vector<cObject*> *objects)
{
	std::vector <ReactionType> result;
	result.push_back(NONE);
	for(unsigned int i = 0; i < objects->size(); i++)
	{

		if(this != objects->at(i))
		{
			printf("%d, %d, %d \n", this->GetPosition().x, objects->at(i)->GetPosition().x, objects->at(i)->Reaction(this));
			if(Tools::Collision(this->GetPosition(), objects->at(i)->GetPosition()))
				result.push_back(objects->at(i)->Reaction(this));
		}
	}
	return result;
}

bool compareObjects(cObject *obj1, cObject *obj2)
{
	return (obj1->GetPosition().y+obj1->GetPosition().h < obj2->GetPosition().y+obj2->GetPosition().h );
}

