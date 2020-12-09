#ifndef __TREEFUNC_H
#define __TREEFUNC_H

#include "bintree.h"

template <class T>
bool member (const T&, typename BinTree<T>::Position);


template <class T>
T sum (typename BinTree<T>::Position);


template <class T>
void insertOrdered (const T&, typename BinTree<T>::Position);

#endif