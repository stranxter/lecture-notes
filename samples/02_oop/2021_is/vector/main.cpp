#include "vector.h"
#include <iostream>


int main()
{
    IntVector v;
    v.add(1);
    v.add(2);
    v.add(3);

    v.add(4);//!
    v.add(5);

    std::cout << v << std::endl;
}