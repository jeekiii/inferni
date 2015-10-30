#include "../Objects/arrow.hpp"
#include "../Core/global.hpp"
#include "../Util/image_func.hpp"
Arrow::Arrow(int positionX, int positionY)
{
	position_.x = positionX;
	position_.y = positionY;
	image_=ImageFunc::loadSprites("Images/Arrow.bmp", true, 255,0,0);

	SDL_QueryTexture(image_, NULL, NULL, &position_.w, &position_.h);

	relativeGroundHitbox_.x = 0;
	relativeGroundHitbox_.y = 0;
	relativeGroundHitbox_.w = 0;
	relativeGroundHitbox_.h = 0;
	relativeAboveHitbox_.x = 3;
	relativeAboveHitbox_.y = 3;
	relativeAboveHitbox_.w = 44;
	relativeAboveHitbox_.h = 5;
}

Arrow::~Arrow()
{
	SDL_DestroyTexture(image_);
}

void Arrow::onRender(Coord positionMap)
{
	Coord positionBlit;
	positionBlit.x = position_.x + positionMap.x;
	positionBlit.y = position_.y + positionMap.y;
	positionBlit.h = position_.h;
	positionBlit.w = position_.w;
	ImageFunc::renderTexture(image_, Global::renderer, false, positionBlit, positionBlit);

}

void Arrow::onMove(std::vector<Object*> *objects)
{
	position_.x+=toMove_.x;
	position_.y+=toMove_.y;
}

void Arrow::onUpdate(std::vector<Object*> *objects)
{
	;
}

ReactionType Arrow::reaction(Object *object, bool ground)
{
	if(!ground)
	{
		object->takeDamage(10);//move this to OnUpdate in the future?
		return DAMAGE_REACTION;
	}
	else
	{
		return NONE_REACTION;
	}
}


void Arrow::launch(Coord direction)
{
	toMove_ = direction;
}
void Arrow::takeDamage(int amount){;}