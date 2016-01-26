#include "tile.hpp"
#include "../Util/image_func.hpp"
#include "../Loader/loader.hpp"

Tile::Tile(TileType type)
{
	if(type == WATER_TILE)
	{
		texture_ = ImageFunc::loadSprites("Images/Tiles/Water.bmp",true,255,0,0);
	}
}

Tile::Tile(int id)
{
	texture_ = get_tile_texture(id);
}

void Tile::onRender(Coord position)
{
	ImageFunc::renderTexture(texture_, Global::renderer, false, position, position);
}
