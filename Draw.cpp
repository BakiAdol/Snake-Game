#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include<stdio.h>
#include<cstdlib>
#include "Draw.h"


void Draw::unitDraw(Point p, Color c)
{
    glColor3f(c.r,c.g,c.b);
    glRectd(p.x,p.y,p.x+1,p.y+1);
}

void Draw::boardDraw(Point leftBottom, Point rightTop, Color c)
{
    for(int x=0;x<11;x++)
    {
        unitDraw(Point(x,leftBottom.y),c); /// left bottom line
        unitDraw(Point(x,rightTop.y),c); /// left top line
        unitDraw(Point(x+30,leftBottom.y),c); /// right bottom line
        unitDraw(Point(x+30,rightTop.y),c); /// right top line

        unitDraw(Point(0,x),c); /// left bottom left line
        unitDraw(Point(0,x+29),c); /// left top left line

        unitDraw(Point(rightTop.x-1,x),c); ///right bottom right
        unitDraw(Point(rightTop.x-1,x+29),c); /// right top right
    }

    for(int x=11;x<30;x++) /// middle two line
    {
        unitDraw(Point(x,14),c);
        unitDraw(Point(x,28),c);
    }
}

void Draw::lineDraw(Point leftP,Point rightP, double lineWidth, Color c)
{
    glLineWidth(lineWidth);
    glColor3f(c.r,c.g,c.b);
    glBegin(GL_LINE_LOOP);

    if(leftP.x!=rightP.x) /// draw horizontal line
    {
        for(int x=leftP.x;x<=rightP.x;x++)
        {
            glVertex2d(x,leftP.y);
        }
    }
    else /// draw vertical line
    {
        for(int y=leftP.y;y<=rightP.y;y++)
        {
            glVertex2d(leftP.x,y);
        }
    }


    glEnd();
}
