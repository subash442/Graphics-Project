#include "Circle.h"

Circle::Circle()
{
    xc = 0;
    yc = 0;
    rad = 0;
    obj_prp = 'c';
}

Circle::Circle(int h,int k,int radius)
{
    xc = h;
    yc = k;
    rad = radius;
}

void Circle::set_circle_parameter(int h,int k,int radius)
{
    xc = h;
    yc = k;
    rad = radius;
}


void Circle::plot_semicircle(COLOR_POINT,char d)
{
    int p, x = 0, y = rad;
    p = 1 - rad;
    Set_PointColor(COLOR_VALUE);

    if (d == 'u')
    {
        //upper part of semi-circle
        while(x <= y)
        {
            Put_Point(xc+x,yc+y);
            Put_Point(xc-x,yc+y);
            Put_Point(xc+y,yc+x);
            Put_Point(xc-y,yc+x);
            x++;
            if (p<0)
                p += 2*x +3;
            else
            {
                y--;
                p += 2*(x-y) +5;
            }

        }

    }
    else if (d == 'd')
    {
        //lower part of semicircle
        while(x <= y)
        {
            Put_Point(xc+x,yc-y);
            Put_Point(xc-x,yc-y);
            Put_Point(xc+y,yc-x);
            Put_Point(xc-y,yc-x);
            x++;
            if (p<0)
                p += 2*x +3;
            else
            {
                y--;
                p += 2*(x-y) +5;
            }

        }
    }
    else if (d == 'l')
    {
       //left part of the circle
        while(x <= y)
        {
            Put_Point(xc-x,yc+y);
            Put_Point(xc-x,yc-y);
            Put_Point(xc-y,yc+x);
            Put_Point(xc-y,yc-x);
            x++;
            if (p<0)
                p += 2*x +3;
            else
            {
                y--;
                p += 2*(x-y) +5;
            }

        }
    }
    else if (d == 'r')
    {
        //right part of the circle
        while(x <= y)
        {
            Put_Point(xc+x,yc+y);
            Put_Point(xc+x,yc-y);
            Put_Point(xc+y,yc+x);
            Put_Point(xc+y,yc-x);
            x++;
            if (p<0)
                p += 2*x +3;
            else
            {
                y--;
                p += 2*(x-y) +5;
            }

        }
    }
}

void Circle::plot_circle(COLOR_POINT) //midpoint algorithm
{
    int p, x = 0, y = rad;
    p = 1 - rad;
    Set_PointColor(COLOR_VALUE);
    while(x <= y)
    {
        Put_Point(xc+x,yc+y);
        Put_Point(xc-x,yc+y);
        Put_Point(xc+x,yc-y);
        Put_Point(xc-x,yc-y);
        Put_Point(xc+y,yc+x);
        Put_Point(xc-y,yc+x);
        Put_Point(xc+y,yc-x);
        Put_Point(xc-y,yc-x);
        x++;
        if (p<0)
            p += 2*x +3;
        else
        {
            y--;
            p += 2*(x-y) +5;
        }

    }

}

Circle::~Circle()
{

}


