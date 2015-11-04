#ifndef COMMAND_HPP
	#define COMMAND_HPP
#include <SDL2/SDL.h>
#include <vector>
typedef enum CommandType
{
	OTHER_COMMAND,
	MOVE_UP_COMMAND, MOVE_DOWN_COMMAND, MOVE_LEFT_COMMAND, MOVE_RIGHT_COMMAND,
	TURN_UP_COMMAND, TURN_DOWN_COMMAND, TURN_LEFT_COMMAND, TURN_RIGHT_COMMAND,
	ATTACK_COMMAND, SPECIAL_COMMAND

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