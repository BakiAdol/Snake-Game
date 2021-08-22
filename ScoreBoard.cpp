#include<string>
#include<stdio.h>
#include "ScoreBoard.h"

void ScoreBoard::showScore(Point topPoint, double lineWidth, Color c, int score)
{
    Draw draw;
    int x=topPoint.x;
    int y=topPoint.y;

    draw.lineDraw(Point(x,y-1),Point(x,y),lineWidth,c); /// left top
    draw.lineDraw(Point(x+2,y-2),Point(x+2,y-1),lineWidth,c); /// right bottom

    int times=5;
    for(;times--;x+=3)
    {
        draw.lineDraw(Point(x,y),Point(x+2,y),lineWidth,c); /// top line
        if(times!=2 and times!=3)draw.lineDraw(Point(x,y-1),Point(x+2,y-1),lineWidth,c); /// middle line
        if(times!=4)draw.lineDraw(Point(x,y-2),Point(x,y),lineWidth,c); /// left line
        if(times==2 or times==1)draw.lineDraw(Point(x+2,y-2),Point(x+2,y),lineWidth,c); /// right line
        if(times!=1)draw.lineDraw(Point(x,y-2),Point(x+2,y-2),lineWidth,c); /// bottom line
    }

    draw.lineDraw(Point(x,y),Point(x+1,y),lineWidth,c);
    draw.lineDraw(Point(x,y-2),Point(x+1,y-2),lineWidth,c);
    x+=2;
    std::string s="";
    do
    {
        s+='0'+score%10;
        score/=10;

    }while(score);

    for(int i=(int)(s.size())-1;i>=0;i--)
    {
        int a=s[i]-'0';
        if(a!=1 and a!=4) draw.lineDraw(Point(x,y),Point(x+2,y),lineWidth,c); /// top line
        if(a!=0 and a!=1 and a!=7)draw.lineDraw(Point(x,y-1),Point(x+2,y-1),lineWidth,c); /// middle line
        if(a==0 or a==6 or a==8)draw.lineDraw(Point(x,y-2),Point(x,y),lineWidth,c); /// left line
        if(a!=5 and a!=6 and a!=2)draw.lineDraw(Point(x+2,y-2),Point(x+2,y),lineWidth,c); /// right line
        if(a!=1 and a!=4 and a!=7)draw.lineDraw(Point(x,y-2),Point(x+2,y-2),lineWidth,c); /// bottom line
        if(a==2) draw.lineDraw(Point(x+2,y-1),Point(x+2,y),lineWidth,c); /// right top
        if(a==4 or a==5 or a==9) draw.lineDraw(Point(x,y-1),Point(x,y),lineWidth,c); /// left top
        if(a==2) draw.lineDraw(Point(x,y-2),Point(x,y-1),lineWidth,c); /// left bottom
        if(a==5 or a==6) draw.lineDraw(Point(x+2,y-2),Point(x+2,y-1),lineWidth,c); /// right bottom
        x+=3;
    }
}
