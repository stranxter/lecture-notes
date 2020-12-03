#ifndef __TREEFUNC_H
#define __TREEFUNC_H

#include "bintree.h"

template <class T>
T sumTree (typename BinTree<T>::Position);

template <class T>
bool member (const T& x, typename BinTree<T>::Position);

template <class T>
void insertBot (const T& x, typename BinTree<T>::Position);


#endif