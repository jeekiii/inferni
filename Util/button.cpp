#include "button.hpp"

Button::Button(Coord position, string imagePath)
{
	position_ = position;
	image_ = ImageFunc::loadSprites(imagePath.c_str());
	SDL_QueryTexture(image_, NULL, NULL, &position_.w, &position_.h);
	printf("%d, %d, %d, %d \n", position_.x, position_.y, position_.h, position_.w);
}

Button::Button()
{
	;
}
bool Button::isClicked(Coord position)
{
	if(Tools::collision(position_, position))
		return true;
	return false;
}
void Button::onRender()
{	
    ImageFunc::renderTexture(image_, Global::renderer, false, position_, position_);
}

Button::~Button()
{
	if(image_ != NULL)
	{
		SDL_DestroyTexture(image_);
	}
}