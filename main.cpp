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
    /*//Border of the flag
    Line L1(150,100,550,100);
    Line L2(150,100,150,635);
    Line L3(550,400,150,635);
    Line L4(250,399,550,399);
    Line L5(550,101,250,399);
    L1.bres_plot_line(DARK_BLUE);
    L2.bres_plot_line(DARK_BLUE);
    L3.bres_plot_line(DARK_BLUE);
    L4.bres_plot_line(DARK_BLUE);
    L5.bres_plot_line(DARK_BLUE);

    //semi-circle for moon and full circle for sun
    Circle C1(250,480,50);
    Circle C2(250,510,60);
    Circle C3(250,457,25);
    Circle C4(250,250,50);
    C1.plot_semicircle(CRIMSON,'d');
    C2.plot_semicircle(CRIMSON,'d');
    C3.plot_semicircle(CRIMSON,'u');
    C4.plot_circle(CRIMSON);*/



    Update_Screen();
}

