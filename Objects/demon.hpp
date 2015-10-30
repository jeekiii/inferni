#ifndef DEMON_HPP
	#define DEMON_HPP
#include "../Objects/object.hpp"
#include "../Objects/possessable.hpp"
#include "../Util/command.hpp"

class Player;
class Demon:public Possessable
{
	private:
	public:
		Demon();
		~Demon();
		Demon(int positionX, int positionY);
		void onRender(Coord positionMap);
		void onMove(std::vector<Object*> *objects);
		void takeDamage(int amount){;}
		ReactionType reaction(Object *object, bool ground);
		void onCommand(std::vector<Object*> *objects, std::vector<CommandType> commands);
		void onUpdate(std::vector<Object*> *objects);
		void setPosition(Coord position);
		Possessable* getTarget();
};

#endif