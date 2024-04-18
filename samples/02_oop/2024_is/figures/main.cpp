#include "square.h"
#include "circle.h"

#include <iostream>

double area(Figure* figure[], int size)
{
    double sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += figure[i]->area();
    }

    return sum;
}

int main()
{
  
    Figure* figures[] = {new Circle({0,0},1),
                         new Square({-0.5,-0.5},{0.5,0.5})};


    std::cout << area(figures,2) << std::endl;

}