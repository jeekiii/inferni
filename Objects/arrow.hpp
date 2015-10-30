
#ifndef ARROW_HPP
	#define ARROW_HPP
#include "../Objects/object.hpp"



class Arrow:public Object
{
	private:
		Coord toMove_;
	public:
		Arrow();
		Arrow(int positionX, int positionY);
		~Arrow();

		void onRender(Coord positionMap);
		void onMove(std::vector<Object*> *objects);
		void onUpdate(std::vector<Object*> *objects);
		void launch(Coord direction);
		void takeDamage(int amount);
		ReactionType reaction(Object *object, bool ground);
};


#endif