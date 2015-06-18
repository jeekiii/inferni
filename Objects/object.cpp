#include "../Objects/object.hpp"
bool cObject::operator< (cObject *obj2)
{
	return(GetPosition().y < obj2->GetPosition().y);
}
coord cObject::GetPosition()
{
	return position;
}