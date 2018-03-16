#include "Line.h"
#include "Circle.h"


/********
*****Caution::don't use variable r,g,b because it is used in colors
********/

bool quit;
bool key_left;
bool key_right;
SDL_Event event_preses;



void Draw_flag(int ang = 0);
void Handle_event();

int main( int argc, char* args[] )
{
    quit = false;
    key_left = false;
    key_right = false;

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



void Draw_flag(int ang)
{
    //Border of the flag
    Line L1(100,0,0,100,100,0);
    //Line L1(0,0,25,100,0,25);
    //Line L2(0,0,25,0,134,25);
    //Line L3(100,76,25,0,134,25);
    //Line L4(25,75,25,100,75,25);
    //Line L5(100,1,25,25,75,25);
    L1.Plot_line(DARK_BLUE,ang);
    //L2.Plot_line(DARK_BLUE,ang);
    //L3.Plot_line(DARK_BLUE,ang);
    //L4.Plot_line(DARK_BLUE,ang);
    //L5.Plot_line(DARK_BLUE,ang);


    Update_Screen();
}

void Handle_event()
{
     while (!quit)
    {
        while(SDL_PollEvent(&event_preses) != 0)
        {
            if (event_preses.type == SDL_QUIT)
                quit = true;
            if (event_preses.type == SDL_KEYDOWN)
            {
                switch(event_preses.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        //update right variable
                        key_right = true;
                        Clear_Screen();
                        Draw_flag(90);
                        break;
                    case SDLK_LEFT:
                        //update left variable
                        key_left = true;
                        Clear_Screen();
                        Draw_flag(-90);
                        break;
                }
            }

        }
    }
}
