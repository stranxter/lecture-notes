#include "circle.h"
#include "square.h"
#include "triangle.h"
#include <iostream>


double sumArea(Figure* figures[], int size)
{
    double sum = 0;

    for(int i = 0; i < size; ++i)
    {
        sum += figures[i]->area();
    }
    return sum;
}


int main()
{
    Figure* figures[] = {new Circle({0,0},1),
                         new Square({0,0},{1,0},{1,1}),
                         new Triangle({0,0},{1,0},{1,1})};


    std::cout << sumArea(figures, 3) << std::endl;

}