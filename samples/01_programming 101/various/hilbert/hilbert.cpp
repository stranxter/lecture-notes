/*
Стартов файл за използване на SDL обвиваката paint.
Кпирайте и модифицирайте този файл, за да създадете своята програма.
*/


#include "cpppainter/sdlwrapper.h"


void down(double dist)
{
    paint::turtle::turnto(90);
    paint::turtle::forward(dist);
}

void up(double dist)
{
    paint::turtle::turnto(-90);
    paint::turtle::forward(dist);
}

void left(double dist)
{
    paint::turtle::turnto(180);
    paint::turtle::forward(dist);
}

void right(double dist)
{
    paint::turtle::turnto(0);
    paint::turtle::forward(dist);
}

void hilbertdown(int order,double length);
void hilbertleft(int order,double length);
void hilbertright(int order,double length);
void hilbertup(int order,double length)
{
    if(order > 1) hilbertleft(order-1,length);
    down(length);
    if(order > 1) hilbertup(order-1,length);
    right(length);
    if(order > 1) hilbertup(order-1,length);
    up(length);
    if(order > 1) hilbertright(order-1,length);
}

void hilbertleft(int order,double length)
{
    if(order > 1) hilbertup(order-1,length);
    right(length);
    if(order > 1) hilbertleft(order-1,length);
    down(length);
    if(order > 1) hilbertleft(order-1,length);
    left(length);
    if(order > 1) hilbertdown(order-1,length);
}

void hilbertdown(int order,double length)
{
    if(order > 1) hilbertright(order-1,length);
    up(length);
    if(order > 1) hilbertdown(order-1,length);
    left(length);
    if(order > 1) hilbertdown(order-1,length);
    down(length);
    if(order > 1) hilbertleft(order-1,length);
}


void hilbertright(int order,double length)
{
    if(order > 1) hilbertdown(order-1,length);
    left(length);
    if(order > 1) hilbertright(order-1,length);
    up(length);
    if(order > 1) hilbertright(order-1,length);
    right(length);
    if(order > 1) hilbertup(order-1,length);
}


int main()
{

    paint::turtle::jump(300,300);
    paint::turtle::down();

    hilbertdown(5,20);

    paint::updateGraphics();
    paint::waitKeypress();

    return 0;
}

int SDL_main(int argc, char* argv[]) {
    // Това е необходимо за SDL под Windows: 
    // библиотекат сменя входната точка на програмата
    return main(); 
}

