#ifndef PLAYER_HPP
	#define PLAYER_HPP
#include "../Util/command.hpp"
#include "../Objects/possessable.hpp"
#include "../Objects/demon.hpp"

class Possessable;//solves mutual inclusion

class Player:public Object
{
	private:
		Possessable *possessed_;
		Demon *demon_;
		bool demonForm_;
		int specialCD_;
		int specialCurrentCD_;
	public:
		Player();
		Player(int positionX, int positionY);
		~Player();
		void onRender(Coord positionMap);
		void onMove(std::vector<Object*> *objects);
		ReactionType reaction(Object *object, bool ground);
		void onCommand(std::vector<Object*> *objects, std::vector<CommandType> keys);
        void onUpdate(std::vector<Object*> *objects);
		void takeDamage(int amount);
		void possess(Possessable *target);
		void leaveBody();
		int getPossessedId();
        int getHp();

};


#endif