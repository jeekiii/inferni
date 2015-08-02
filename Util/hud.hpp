#ifndef _HUD_HPP_
	#define _HUD_HPP_
#include "../Objects/player.hpp"
class cHud
{
	private:
		cPlayer *player;
	public:
		cHud();
		~cHud();
		void OnInit(cPlayer *player);
		void OnRender();
		
};

#endif