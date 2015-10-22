#include "tile.hpp"

void cTile::OnInit(TileType type)
{
	if(type == W)
	{
		texture = ImageFunc::LoadSprites("Images/Tiles/Water.bmp",true,255,0,0);
	}
}
void cTile::OnRender(coord position)
{
		ImageFunc::RenderTexture(texture, Global::renderer, false, position, position);
}
