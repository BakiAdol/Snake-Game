#include<stdio.h>
#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include "Draw.h"
#include "ScoreBoard.h"
#include "Snake.h"

#define FPS 10
#define COL 40
#define ROW 45

int w_width = 500;
int w_height = 520;

extern int snakeDirection;
extern int score;

void init();
void display();
void timer(int);
void reshape(int,int);
void keyboard(int,int,int);

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w_width,w_height);
    glutInitWindowPosition(290,100);
    glutCreateWindow("Snake Game");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return EXIT_SUCCESS;
}

void init()
{
    /// clear background color
    glClearColor(0.0,0.0,0.0,1.0);
}

void display()
{
    /// clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    Draw draw;
    draw.lineDraw(Point(0,41),Point(40,41),3,Color(0.3,0.3,0.3));
    draw.boardDraw(Point(0,0),Point(COL,ROW-5),Color(1,0,0));

    ScoreBoard scoreBoard;
    scoreBoard.showScore(Point(1,ROW-1),5,Color(0,1,0),score);

    Snake snake;
    snake.drawSnake();
    snake.drawFood();

    glutSwapBuffers();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    /// initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /// graph size
    glOrtho(0.0,COL,0.0,ROW,-1.0,1.0);

    glMatrixMode(GL_MODELVIEW);
}

void timer(int t)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}

void keyboard(int key, int,int)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(snakeDirection!=-1) snakeDirection=1;
        break;
    case GLUT_KEY_DOWN:
        if(snakeDirection!=1) snakeDirection=-1;
        break;
    case GLUT_KEY_RIGHT:
        if(snakeDirection!=-2) snakeDirection=2;
        break;
    case GLUT_KEY_LEFT:
        if(snakeDirection!=2) snakeDirection=-2;
        break;
    }
}
