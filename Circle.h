#ifndef CIRCLE_H
#define CIRCLE_H

#include "SDL_Graphics.h"

class Circle
{
    private:
        int xc,yc,rad;
        char obj_prp;
    public:
        Circle();
        Circle(int h,int k,int radius);

        void set_circle_parameter(int h,int k,int radius);
        void plot_circle(COLOR_POINT);
        void plot_semicircle(COLOR_POINT,char d);

        virtual ~Circle();
};

#endif
