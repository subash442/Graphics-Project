#ifndef LINE_H
#define LINE_H

#include "SDL_Graphics.h"
#include "Matrix.h"


class Line
{
    private:
        int x1,y1,z1,x2,y2,z2,dx,dy;
        Matrix rotate_matrix;

    public:
        Line(int x11 ,int y11, int z11 , int x22,int y22, int z22);
        Line();

        void Set_Coordinate(int x11 ,int y11, int z11 , int x22,int y22, int z22);
        void dda_plot_line(COLOR_POINT);
        void bres_plot_line(COLOR_POINT);
        void Plot_line(COLOR_POINT,int angle);

        virtual ~Line();

};

#endif // LINE_H
