#include "../Objects/arrow.hpp"
#include "../Core/global.hpp"
#include "../Util/image_func.hpp"
cArrow::cArrow()
{

}

cArrow::~cArrow()
{
	SDL_DestroyTexture(image);
}

void cArrow::OnRender(coord positionMap)
{
	coord positionBlit;
	positionBlit.x = position.x + positionMap.x;
	positionBlit.y = position.y + positionMap.y;
	positionBlit.h = position.h;
	positionBlit.w = position.w;
	ImageFunc::RenderTexture(image, Global::renderer, false, positionBlit, positionBlit);

}

void cArrow::OnMove(std::vector<cObject*> *objects)
{
	position.x+=toMove.x;
	position.y+=toMove.y;
}
ReactionType cArrow::Reaction(cObject *object, bool ground)
{
	if(!ground)
	{
		object->TakeDamage(10);
		return DAMAGE;
	}
	else
	{
		return NONE;
	}
}
void cArrow::OnInit(int positionX, int positionY)
{
	image=ImageFunc::LoadSprites("Images/Arrow.bmp", true, 255,0,0);
	position.x = positionX;
	position.y = positionY;
	SDL_QueryTexture(image, NULL, NULL, &position.w, &position.h);

	relativeGroundHitbox.x = 0;
	relativeGroundHitbox.y = 0;
	relativeGroundHitbox.w = 0;
	relativeGroundHitbox.h = 0;
	relativeAboveHitbox.x = 3;
	relativeAboveHitbox.y = 3;
	relativeAboveHitbox.w = 44;
	relativeAboveHitbox.h = 5;
}

void cArrow::Launch(coord direction)
{
	toMove = direction;
}
void cArrow::TakeDamage(int amount){;}