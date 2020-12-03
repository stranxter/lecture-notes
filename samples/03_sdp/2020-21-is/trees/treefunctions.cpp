#ifndef __TREEFUNC_CPP
#define __TREEFUNC_CPP

#include "treefunctions.h"

template <class T>
T sumTree (typename BinTree<T>::Position current)
{
    if (current.empty())
    {
        return 0;
    }

    return current.get() +
           sumTree<T>(current.left()) +
           sumTree<T>(current.right());

}

template <class T>
bool member (const T& x, typename BinTree<T>::Position current)
{
    if (current.empty())
    {
        return false;
    }

    return current.get() == x ||
           member (x, current.left()) ||
           member (x, current.right());

}

template <class T>
void insertBot (const T& x, typename BinTree<T>::Position current)
{
    if (current.empty())
    {
        current.set(x);
        return;
    }

    if (x <= current.get())
    {
        insertBot (x, current.left());
    } else
    {
        insertBot (x, current.right());
    }

}


#endif