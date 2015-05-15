#include "button.hpp"

void cButton::Init(coord position, string imagePath)
{
	this->position = position;
	this->image = ImageFunc::LoadSprites(imagePath.c_str());
	SDL_QueryTexture(image, NULL, NULL, &(this->position.w), &(this->position.h));
}

bool cButton::IsClicked(coord position)
{
	if(Tools::Collision(this->position, position))
		return true;
	return false;
}
void cButton::OnRender()
{
    ImageFunc::RenderTexture(image, Global::renderer, false, position, position);
}