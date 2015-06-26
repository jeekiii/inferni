#ifndef _COMMAND_HPP_
	#define _COMMAND_HPP_
#include <SDL2/SDL.h>
typedef enum CommandType{
	UP, DOWN, LEFT, RIGHT
} CommandType;

class cCommand
{
	private:
		SDL_Keycode up, down, left, right; 
	public:
		cCommand();
		~cCommand();
		CommandType getCommand(SDL_Keycode key);
};


#endif