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
#include "../Core/quest.hpp"
#include "../Core/objective.hpp"

#include "../Objects/object.hpp"
#include "../Objects/player.hpp"
#include "../Objects/creature.hpp"

#define OBJECT 1
#define GROUND 2

typedef struct tex {
	SDL_Texture *texture;
	int type;
	int id;
} texture_t;

int open_level(std::string);
void close_level(void);

Tile **get_tiles(void);
int get_map_width(void);
int get_map_height(void);

Quest *get_quest(Player *player, std::vector<Object *> *objects, int id);

SDL_Texture *get_texture(int type, int id);
std::vector<Object *> *get_content(void);
SDL_Texture *get_tile_texture(int id);
SDL_Texture *get_object_texture(int id);

#endif
