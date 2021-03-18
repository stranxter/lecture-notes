/*#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"*/
//TEST_CASE("Simple Mapping"){}


#include "vector.cpp"
#include <iostream>


int main()
{
    Vector<int> v;

    v.add(1); 

    v.add(2);
    v.add(3);
    v.add(4);
    v.add(5);
    v.add(6);

    std::cout << v << std::endl;

    Vector<int> v2(v);
    std::cout << v2 << std::endl;

    std::cout << v2 << std::endl;


}