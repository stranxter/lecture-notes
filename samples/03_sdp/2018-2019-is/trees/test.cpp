#include "btree.h"
#include "btree.cpp"
#include <fstream>


int main ()
{
    BTree<int> t;
    t.insert (10,"");
    t.insert (20,"L");
    t.insert (8,"R");
    t.insert (17,"LL");
    t.insert (19,"RL");

    BTree<int> t2 (t);

    t.insert (99,"LR");

    std::ofstream f ("tree.dot");
    t.printToDotty (f);

    std::ofstream f2 ("tree2.dot");
    t2.printToDotty (f2);

    return 0;
}
