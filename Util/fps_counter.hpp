/// *********************16/02/2013***********************///
/* utility class used for counting Game fps
*/


#ifndef FPSCOUNTER_HPP
    #define FPSCOUNTER_HPP

class FpsCounter
{
    private:
        int initTime;
        int timeFlag;
        int timePerFrame;

    public:
         FpsCounter(int fps=50){timePerFrame=1000/fps;}

         void startCount();
         void checkFPS();
         void getNewTick();

};






#endif
