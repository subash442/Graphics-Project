#include "SDL_Graphics.h"



SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool Init_Graphics()
{
     //  Initialize the sdl and it's function

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
	    return false;
	}

	 SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);    //create window and default renderer
	 SDL_SetWindowTitle(window,"Graphics project");
    if( window == NULL || renderer == NULL )
    {
       return false;
	}

    SDL_RenderSetLogicalSize( renderer, SCREEN_WIDTH, SCREEN_HEIGHT );  // Get device independent resolution for rendering

    SDL_SetRenderDrawColor( renderer, WHITE ); //set the renderer colour
    SDL_RenderClear( renderer );    //clear the screen with given renderer colour
    return true;
}

void Set_PointColor(COLOR_POINT)
{
    SDL_SetRenderDrawColor( renderer, COLOR_VALUE );
}

void Put_Point(int x,int y)
{
    SDL_RenderDrawPoint(renderer,x,SCREEN_HEIGHT-y);  //draw a point of renderer colour in given location
}

void Clear_Screen()
{
    SDL_SetRenderDrawColor(renderer,WHITE);
    SDL_RenderClear(renderer);
    Update_Screen();
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




/*template <class T>
T scale(T object,float Scale_factor)
{
    if (T.obj_prp == 'c')
        return T;
}*/
