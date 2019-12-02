#include "bintree.h"
#include "bintree.hpp"

template <class T> 
T sumElements (const Position<T> tp)
{
    if (tp.empty())
    {
        return 0;
    }

    return *tp + sumElements (tp.left()) + sumElements (tp.right());

}

BinTree<int> createIdealTree (int n)
{
    assert (n >= 0);
    if (n == 0)
    {
        return BinTree<int>();
    }

   return BinTree<int> (n,
                        createIdealTree (n-1),
                        createIdealTree (n-1));

}