#ifndef LINE_H
#define LINE_H

#include "SDL_Graphics.h"


class Line
{
    private:
        int x1,y1,x2,y2;
        int i;

    public:
        Line(int x11 ,int y11 , int x22,int y22):x1(x11),y1(y11),x2(x22),y2(y22){}
        Line();

        void plot_line(COLOR_POINT);
        virtual ~Line();

};

#endif // LINE_H
