#ifndef __TREEFUNC_CPP
#define __TREEFUNC_CPP

#include "treefunctions.h"

template <class T>
bool member (const T &x, typename BinTree<T>::Position current)
{
    return !current.empty() &&
            (x == current.get() ||
             member (x, current.left()) ||
             member (x, current.right()));

}

template <class T>
T sum (typename BinTree<T>::Position current)
{
    if (current.empty())
    {
        return 0;
    }

    return current.get() + sum<T> (current.left()) + sum<T> (current.right());
}

template <class T>
void insertOrdered (const T &x, typename BinTree<T>::Position current)
{
    if (current.empty())
    {
        current.set(x);
        return;
    }

    //-------------------------

    if (x <= current.get())
    {
      insertOrdered (x, current.left());        
    } else 
    {
      insertOrdered (x, current.right());
    }

}



#endif