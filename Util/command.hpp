#ifndef _COMMAND_HPP_
	#define _COMMAND_HPP_
#include <SDL2/SDL.h>
#include <vector>
typedef enum CommandType{
	OTHER, UP, DOWN, LEFT, RIGHT
} CommandType;

class cCommand
{
	private:
		SDL_Keycode up, down, left, right; 
	public:
		cCommand();
		~cCommand();
		CommandType getCommand(std::vector<SDL_Keycode> keys);
};


#endif