#include <iostream>

#include "dllist.h"


int main()
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4;


    std::cout << list << std::endl;
    //operator<< <int>(std::cout,list);
 //   list.print();
}