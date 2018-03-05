#include "Line.h"

Line::Line()
{
    x1=0;
    y1=0;
    x2=0;
    y2=0;
    dx = 0;
    dy = 0;
}

Line::Line(int x11 ,int y11 , int x22,int y22)
{
    x1 = x11;
    y1 = y11;
    x2 = x22;
    y2 = y22;
    dx = x2-x1;
    dy = y2-y1;
}

void Line::Set_Coordinate(int x11 ,int y11 , int x22,int y22)
{
    x1 = x11;
    y1 = y11;
    x2 = x22;
    y2 = y22;
    dx = x2-x1;
    dy = y2-y1;
}

void Line::dda_plot_line(COLOR_POINT)
{
  float xinc,yinc,steps; //increment in x and y coordinate
  Set_PointColor(COLOR_VALUE);
  steps = abs(dx) > abs(dy)? abs(dx) : abs(dy);
  xinc = dx / steps;
  yinc = dy / steps;
  for(int i = 0; i < steps; i++)
  {
      x1 = x1+xinc;
      y1 = y1+yinc;
      Put_Point(x1,y1);
  }
}

void Line::bres_plot_line(COLOR_POINT)
{
    int p,x,y,lastval;
    Set_PointColor(COLOR_VALUE);
     if (dx > 0)
     {
         x = x1;
         if (dy > 0)
            y = y1;
         else
            y = -y1;
         lastval = x2;
     }
     else
     {
         x = x2;
         if (dy < 0)
            y = y2;
         else
            y = -y2;

         lastval = x1;
     }
     dy = abs(dy);
     dx = abs(dx);
     p = 2*dy - dx;
     Put_Point(x,abs(y));

     while(x <= lastval)
     {
         if (p<0)
             p += 2*dy;
         else
         {
             p += 2*dy - 2*dx;
             y++;
         }
         x++;
         Put_Point(x,abs(y));
     }
}

Line::~Line()
{

}
