#ifndef LOADER_HPP
	#define LOADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "stdlib.h"

extern "C"
{
    #include "parser.h"
}

#include "../Util/image_func.hpp"
#include "../Core/tile.hpp"

int open_level(std::string);
void close_level(void);

Tile **get_tiles(void);
int get_map_width(void);
int get_map_height(void);

SDL_Texture *get_tile_texture(int id);

#endif
