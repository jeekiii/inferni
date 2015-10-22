#ifndef _COMMAND_HPP_
	#define _COMMAND_HPP_
#include <SDL2/SDL.h>
#include <vector>
typedef enum CommandType
{
	OTHER, UP, DOWN, LEFT, RIGHT, ATTACK, SPECIAL
} CommandType;

class cCommand
{
	private:
		SDL_Keycode up, down, left, right, attack, possess;
		std::vector <CommandType> commands;
		std::vector<CommandType> toRemove;
	public:
		cCommand();
		~cCommand();
		std::vector<CommandType> GetCommand();
		void AddCommand(SDL_Keycode key);
		void RemoveCommand(SDL_Keycode key);

};


#endif