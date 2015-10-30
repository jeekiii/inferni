#include "tile.hpp"
#include "../Util/image_func.hpp"

Tile::Tile(TileType type)
{
	if(type == WATER_TILE)
	{
		texture_ = ImageFunc::loadSprites("Images/Tiles/Water.bmp",true,255,0,0);
	}
}
void Tile::onRender(Coord position)
{
		ImageFunc::renderTexture(texture_, Global::renderer, false, position, position);
}
