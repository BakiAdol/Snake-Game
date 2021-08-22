#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "Draw.h"


class Snake{
    public:
    void drawSnake();
    Point randomLocation();
    bool isInRestrictArea(Point);
    bool ownBody();
    void drawFood();
};

#endif // SNAKE_H_INCLUDED
