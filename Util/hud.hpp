#ifndef HUD_HPP
	#define HUD_HPP
#include "../Objects/player.hpp"
class Hud
{
	private:
		Player *player_;
	public:
		Hud(Player *player);
		Hud();
		~Hud();
		void onRender();
		
};

#endif