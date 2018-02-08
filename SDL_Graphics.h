#ifndef SDL_GRAPHICS_H_INCLUDED
#define SDL_GRAPHICS_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include "Colors.h"

using namespace std;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

bool quit;

SDL_Event mouse_event;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


bool Init_Graphics()
{
     //  Initialize the sdl and it's function

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
	    return false;
	}

	 SDL_CreateWindowAndRenderer(SCREEN_HEIGHT, SCREEN_WIDTH, 0, &window, &renderer);    //create window and default renderer

    if( window == NULL || renderer == NULL )
    {
       return false;
	}

    SDL_RenderSetLogicalSize( renderer, SCREEN_HEIGHT, SCREEN_WIDTH );  // Get device independent resolution for rendering

    SDL_SetRenderDrawColor( renderer, LIGHT_CYAN ); //set the renderer colour
    SDL_RenderClear( renderer );    //clear the screen with given renderer colour
    quit = false;
    return true;
}

void Set_PointColor(COLOR_POINT)
{
    SDL_SetRenderDrawColor( renderer, r,g,b,alpha );
}

void Put_Point(int x,int y)
{
    SDL_RenderDrawPoint(renderer,x,y);  //draw a point of renderer colour in given location
}

void Update_Screen()
{
     SDL_RenderPresent(renderer);//update the screen with the rendering function called
}

void Put_Points(SDL_Point* points,int num)
{
    SDL_RenderDrawPoints(renderer,points,num);
}

void Close_Graphics()
{
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow( window );
    SDL_Quit();
}

void Handle_event()
{
     while (!quit)
    {
        while(SDL_PollEvent(&mouse_event) != 0)
        {
            if (mouse_event.type == SDL_QUIT)
                quit = true;
        }
    }
}

#endif // SDL_GRAPHICS_H_INCLUDED
