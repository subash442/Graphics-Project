#include "Line.h"


int main( int argc, char* args[] )
{
    if (!Init_Graphics())
    {
        cout<<"SDL initialization failed."<<SDL_GetError()<<endl;
        return 1;
    }
    Line L1(0,0,100,100);
    L1.dda_plot_line(RED);
    Line L2(100,100,100,250);
    L2.bres_plot_line(BLACK);
    Update_Screen();
    Handle_event();
    Close_Graphics();
	return 0;
}


