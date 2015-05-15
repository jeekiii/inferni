 /// *********************16/02/2013***********************///
/* utility class used for buttons
*/


#ifndef _BUTTON_HPP_
    #define _BUTTON_HPP_
#include "../Core/global.hpp"
#include "../Util/image_func.hpp"
#include "../Util/tools.hpp"
#include "../Util/fps_counter.hpp"
#include <string>
#include <SDL2/SDL.h>
using namespace std;
class cButton
{
    private:
		coord position;
		SDL_Texture *image;
    public:
    	cButton(){;}
    	void Init(coord position, string imagePath);
    	bool IsClicked(coord position);
    	void OnRender();
};
#endif
