#pragma once

#include <iostream>

class IntVector
{
    //...
    public:
    void add(int data);
    int *contents;
    size_t size;


};

std::ostream& operator<<(std::ostream&,IntVector);

