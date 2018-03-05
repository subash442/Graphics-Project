#ifndef SDL_GRAPHICS_H_INCLUDED
#define SDL_GRAPHICS_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include "Colors.h"
#define SCREEN_WIDTH   700
#define SCREEN_HEIGHT  700

using namespace std;



extern bool quit;

extern SDL_Event mouse_event;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

bool Init_Graphics();
void Set_PointColor(COLOR_POINT);
void Put_Point(int x,int y);
void Update_Screen();
void Put_Points(SDL_Point* points,int num);
void Close_Graphics();
void Handle_event();

#endif // SDL_GRAPHICS_H_INCLUDED
