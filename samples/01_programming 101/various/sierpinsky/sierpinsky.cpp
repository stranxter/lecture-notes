/*
Стартов файл за използване на SDL обвиваката paint.
Кпирайте и модифицирайте този файл, за да създадете своята програма.
*/


#include "cpppainter/sdlwrapper.h"


void sierpinsky(int order, double size)
{
    if(order==0)
    {
        for(int i=0;i<3;i++)
        {
            paint::turtle::forward(size);
            paint::turtle::right(120);
        }
        return;
    }

    //Рисуване на горния триъгълник
    sierpinsky(order-1,size/2);

    //Рисуване на десния триъгълник
    paint::turtle::forward(size/2);
    sierpinsky(order-1,size/2);
    paint::turtle::backward(size/2);

    //рисуване на левия триъгълник
    paint::turtle::right(60);
    paint::turtle::forward(size/2);
    paint::turtle::left(60);
    sierpinsky(order-1,size/2);

    // Връщаме костенурката в началната позиция
    paint::turtle::right(60);
    paint::turtle::backward(size/2);
    paint::turtle::left(60);

}

int main()
{
    paint::turtle::jump(400,50);
    paint::turtle::down();
    
    paint::turtle::right(60);
    sierpinsky(5,300);
    
    paint::updateGraphics();
    paint::waitKeypress();

    return 0;
}

int SDL_main(int argc, char* argv[]) {
    // Това е необходимо за SDL под Windows: 
    // библиотекат сменя входната точка на програмата
    return main(); 
}

