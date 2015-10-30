#ifndef COMMAND_HPP
	#define COMMAND_HPP
#include <SDL2/SDL.h>
#include <vector>
typedef enum CommandType
{
	OTHER_COMMAND, UP_COMMAND, DOWN_COMMAND, LEFT_COMMAND, RIGHT_COMMAND, ATTACK_COMMAND, SPECIAL_COMMAND
} CommandType;

class Command
{
	private:
		SDL_Keycode up_, down_, left_, right_, attack_, possess_;
		std::vector <CommandType> commands_;
		std::vector<CommandType> toRemove_;
	public:
		Command();
		~Command();
		std::vector<CommandType> getCommand();
		void addCommand(SDL_Keycode key);
		void removeCommand(SDL_Keycode key);

};


#endif