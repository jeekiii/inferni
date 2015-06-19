#include "../Objects/object.hpp"

coord cObject::GetPosition()
{
	return position;
}

bool compareObjects(cObject *obj1, cObject *obj2)
{
	return ( obj1->GetPosition().y < obj2->GetPosition().y );
}