#include "Line.h"
#include "Circle.h"

/********
*****Caution::don't use variable r,g,b because it is used in colors
********/

void Draw_flag();

int main( int argc, char* args[] )
{
    if (!Init_Graphics())
    {
        cout<<"SDL initialization failed."<<SDL_GetError()<<endl;
        return 1;
    }
    Draw_flag();
    Handle_event();
    Close_Graphics();
	return 0;
}

void Draw_flag()
{

    Update_Screen();
}

