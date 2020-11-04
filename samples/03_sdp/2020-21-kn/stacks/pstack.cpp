#ifndef __PSTACK_CPP
#define __PSTACK_CPP

#include <cassert>
#include "pstack.h"
#include <iostream>

template<class T>
pstack<T>::pstack():first(nullptr)
{

}

template<class T>
pstack<T>::pstack(std::shared_ptr<pstack<T>::node> _first):first(_first)
{

}


template<class T>
pstack<T> pstack<T>::push(const T &x) const
{
    return pstack<T>(std::make_shared<node>(x,first));

}

template<class T>
pstack<T> pstack<T>::pop() const
{
    assert(!empty());
    return pstack<T>{first->tail};
}

template<class T>
T pstack<T>::top() const
{
    assert(!empty());
    return first->head;
}

template<class T>
pstack<T>::node::node (const T& _head, std::shared_ptr<pstack<T>::node> _tail):head(_head),tail(_tail)
{
    std::cout << "+[" << head << "]";
}

template<class T>
pstack<T>::node::~node()
{
    std::cout << "-[" << head << "]";
}

template<class T>
bool pstack<T>::empty() const
{
    return ((bool)first == false);
}

#endif