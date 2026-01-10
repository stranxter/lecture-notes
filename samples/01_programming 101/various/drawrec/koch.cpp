/*
Стартов файл за използване на SDL обвиваката paint
*/
#include "cpppainter/sdlwrapper.h"


void koch(double lenght)
{
    if(lenght<10)
    {
        paint::turtle::forward(lenght);
        return;
    }

    double segment=lenght/3.0;

    koch(segment);
    paint::turtle::left(60);
    koch(segment);
    paint::turtle::right(120);
    koch(segment);
    paint::turtle::left(60);
    koch(segment);

}

void snowflake(double lenght)
{
    for(int i=0;i<3;i++)
    {
        koch(lenght);
        paint::turtle::right(120);
    }
}

int main()
{
    paint::turtle::jump(50,150);
    paint::turtle::down();
    //koch(700);
    snowflake(400);

    paint::updateGraphics();
    paint::waitKeypress();

    return 0;
}

int SDL_main(int argc, char* argv[]) {
    /* Това е необходимо за SDL под Windows: 
       библиотекат сменя входната точка на програмата*/
    return main(); 
}