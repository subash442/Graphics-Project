#include "Line.h"

Line::Line()
{
    x1=0;
    y1=0;
    x2=0;
    y2=0;
}
void Line::plot_line(COLOR_POINT)
{
  Set_PointColor(COLOR_VALUE);
  for (i=0;i<500;i++)
     Put_Point(i,i);
  Update_Screen();
}

Line::~Line()
{

}
