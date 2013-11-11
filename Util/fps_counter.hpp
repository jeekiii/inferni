/// *********************16/02/2013***********************///
/* utility class used for counting Game fps
*/


#ifndef _FPSCOUNTER_HPP_
    #define _FPSCOUNTER_HPP_

class cFPSCounter
{
    private:
        int m_init_time;
        int m_time_flag;
        int m_time_per_frame;

    public:
         cFPSCounter(int fps=50){m_time_per_frame=1000/fps;}

         void StartCount();
         void CheckFPS();
         void GetNewTick();

};






#endif
