#include "Line.h"


int main( int argc, char* args[] )
{
    if (!Init_Graphics())
    {
        cout<<"SDL initialization failed."<<SDL_GetError()<<endl;
        return 1;
    }
    Line L1;
    L1.plot_line();
    Handle_event();
    Close_Graphics();
	return 0;
}


