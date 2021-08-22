#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include<cstdlib>
#include "Snake.h"

int snakeDirection=2;
int snakeLen=5;
int snakePosX[100]={24,23,22,21,20};
int snakePosY[100]={20,20,20,20,20};
Point foodPos;
bool eatFood=true;

int score=0;

bool Snake::isInRestrictArea(Point p)
{
    if((p.x>=11 and p.x<30 and (p.y==14 or p.y==28)) or
       (((p.x>=0 and p.x<=10) or (p.x>29 and p.x<41)) and (p.y==0 or p.y==40)) or
       ((p.x==0 or p.x==39) and((p.y>=0 and p.y<11) or(p.y>28 and p.y<41)))
       )
    {
        return true;
    }
    return false;
}

bool Snake::ownBody()
{
    for(int i=2;i<snakeLen;i++)
    {
        if(snakePosX[i]==snakePosX[0] and snakePosY[i]==snakePosY[0])
        {
            return true;
        }
    }
    return false;
}

void Snake::drawSnake()
{
    for(int i=snakeLen-1;i>0;i--)
    {
        snakePosX[i]=snakePosX[i-1];
        snakePosY[i]=snakePosY[i-1];
    }

    switch(snakeDirection)
    {
    case 1:
        snakePosY[0]++;
        break;
    case -1:
        snakePosY[0]--;
        break;
    case 2:
        snakePosX[0]++;
        break;
    default:
        snakePosX[0]--;
    }

    ///if(restrict) game over
    if(isInRestrictArea(Point(snakePosX[0],snakePosY[0])) or ownBody())
    {
        char msg[10];
        itoa(score,msg,10);
        char text[50]="Your Score : ";
        strcat(text,msg);
        MessageBox(NULL,text,"Game Over!",0);
        exit(0);
    }

    if(snakePosX[0]==-1) snakePosX[0]=40;
    else if(snakePosX[0]==40) snakePosX[0]=0;
    else if(snakePosY[0]==-1) snakePosY[0]=40;
    else if(snakePosY[0]==41) snakePosY[0]=0;

    glColor3f(1,1,1);
    Draw draw;

    for(int i=0;i<snakeLen;i++)
    {
        draw.unitDraw(Point(snakePosX[i],snakePosY[i]),Color(0,0,1));
    }

    if(foodPos.x==snakePosX[0] and foodPos.y==snakePosY[0])
    {
        score++;
        eatFood=true;
        if(snakeLen+1<90) snakeLen++;
    }
}

void Snake::drawFood()
{
    if(eatFood)
    {
        do{
        foodPos=randomLocation();
        }while(isInRestrictArea(foodPos));
        eatFood=false;
    }
    Draw draw;
    draw.unitDraw(foodPos,Color(0,1,0));
}

Point Snake::randomLocation()
{
    Point food;
    srand(time(NULL));
    food.x = rand()%38 + 1;
    food.y = rand()%38 + 1;
    return food;
}

