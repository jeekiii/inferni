 /// *********************16/02/2013***********************///
/* utility class used for buttons
*/


#ifndef BUTTON_HPP
    #define BUTTON_HPP
#include "../Util/image_func.hpp"
#include "../Util/tools.hpp"
#include <SDL2/SDL.h>
#include <string>

using namespace std;
class Button
{
    private:
		Coord position_;
		SDL_Texture* image_;
    public:
    	~Button();
    	Button();
    	Button(Coord position, string path);
    	bool isClicked(Coord position);
    	void onRender();
};
#endif
