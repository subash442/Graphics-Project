#ifndef LINE_H
#define LINE_H

#include "SDL_Graphics.h"


class Line
{
    private:
        int x1,y1,x2,y2,dx,dy;

    public:
        Line(int x11 ,int y11 , int x22,int y22);
        Line();

        void Set_Coordinate(int x11 ,int y11 , int x22,int y22);
        void dda_plot_line(COLOR_POINT);
        void bres_plot_line(COLOR_POINT);
        virtual ~Line();

};

#endif // LINE_H
