#include <iostream>

#include "tree.h"


int main()
{
    Tree t;

    t.insert(7,"");
    t.insert(30,"L");
    t.insert(5,"R");
    t.insert(50,"RL");
    t.insert(7,"LR");
    t.insert(90,"LRL");

    t.printDot();
}