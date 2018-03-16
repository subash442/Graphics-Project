#include "Line.h"

Line::Line()
{
    x1=0;
    y1=0;
    z1=0;
    x2=0;
    y2=0;
    z2=0;
    dx = 0;
    dy = 0;
}

Line::Line(int x11 ,int y11, int z11 , int x22,int y22, int z22)
{
    x1 = x11;
    y1 = y11;
    z1 = z11;
    x2 = x22;
    y2 = y22;
    z2 = z22;
}

void Line::Set_Coordinate(int x11 ,int y11, int z11 , int x22,int y22, int z22)
{
    x1 = x11;
    y1 = y11;
    z1 = z11;
    x2 = x22;
    y2 = y22;
    z2 = z22;
}

void Line::dda_plot_line(COLOR_POINT)
{
    int x , y;
  float xinc,yinc,steps; //increment in x and y coordinate
  Set_PointColor(COLOR_VALUE);
  dx = x2-x1;
  dy = y2-y1;
  x = x1;
  y = y1;
  steps = abs(dx) > abs(dy)? abs(dx) : abs(dy);
  xinc = dx / steps;
  yinc = dy / steps;
  for(int i = 0; i < steps; i++)
  {
      x = x+xinc;
      y = y+yinc;
      Put_Point(x,y);
  }
}

void Line::bres_plot_line(COLOR_POINT)
{
    int p,x,y,lastval;
    bool slope = false;
    //cout <<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<endl;
    dy = y2 - y1;
    dx = x2 - x1;
    Set_PointColor(COLOR_VALUE);
    if (dx == 0)
      {
          if (dy>0)
          {
            x = x1;
            y = y1;
            lastval = y2;
          }
          else
          {
              x = x2;
              y = y2;
              lastval = y1;
          }
          while(y<=lastval)
          {
              Put_Point(x,y);
              y++;
          }
      }
     if (dx > 0)
     {
         x = x1;
         y = y1;
         if (dy > 0)
            slope = true;
        else
            slope = false;
         lastval = x2;
     }
     else
     {
         x = x2;
         y = y2;
         if (dy < 0)
            slope = true;
         else
            slope = false;

         lastval = x1;
     }
     dy = abs(dy);
     dx = abs(dx);
     p = 2*dy - dx;
     Put_Point(x,y);

     //cout<< "start"<<endl<<endl;

     while(x <= lastval)
     {
         if (p<0)
             p += 2*dy;
         else
         {
             p += 2*dy - 2*dx;
             if (slope)
                y++;
            else
                y--;
         }
         x++;
         Put_Point(x,y);
         //cout << x <<"  "<<y<<endl;
     }
}


void Line::Plot_line(COLOR_POINT,int angle)
{
    int x, y,z;
    if (angle == 0)
    {
        bres_plot_line(COLOR_VALUE);
        //cout<<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<endl;
        return;
    }
    else
    {
        rotate_matrix = rotate_matrix.Rotate(angle,0,0,1);
        x = x1 * rotate_matrix.M[0][0] + y1 * rotate_matrix.M[0][1] + z1* rotate_matrix.M[0][2] + rotate_matrix.M[0][3];
        y = x1 * rotate_matrix.M[1][0] + y1 * rotate_matrix.M[1][1] + z1* rotate_matrix.M[1][2] + rotate_matrix.M[1][3];
        z = x1 * rotate_matrix.M[2][0] + y1 * rotate_matrix.M[2][1] + z1* rotate_matrix.M[2][2] + rotate_matrix.M[2][3];
        x1 = x;
        y1 = y;
        z1 = z;
        x = x2 * rotate_matrix.M[0][0] + y2 * rotate_matrix.M[0][1] + z2* rotate_matrix.M[0][2] + rotate_matrix.M[0][3];
        y = x2 * rotate_matrix.M[1][0] + y2 * rotate_matrix.M[1][1] + z2* rotate_matrix.M[1][2] + rotate_matrix.M[1][3];
        z = x2 * rotate_matrix.M[2][0] + y2 * rotate_matrix.M[2][1] + z2* rotate_matrix.M[2][2] + rotate_matrix.M[2][3];
        x2 = x;
        y2 = y;
        z2 = z;
        bres_plot_line(COLOR_VALUE);
        for(int i = 0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout<<rotate_matrix.M[i][j]<<" ";
            cout<<endl;
        }

        //cout<<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<endl;

    }

}

Line::~Line()
{

}
