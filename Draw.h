#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "MyType.cpp"

class Draw{
    public:
    void unitDraw(Point,Color);
    void boardDraw(Point,Point,Color);
    void lineDraw(Point,Point,double,Color);

};


#endif // DRAW_H_INCLUDED
