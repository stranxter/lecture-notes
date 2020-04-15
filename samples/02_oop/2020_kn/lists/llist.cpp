#pragma once

#include "llist.h"
#include <cassert>

template<class T>
LList<T>::LList ()
{
    first = nullptr;
    last = nullptr;
}

template<class T>
void LList<T>::push (const T& x)
{
    /*box<T> *newElement = new box<T> (x,nullptr);
    newElement->next = first;
    first = newElement;*/
    first = new box(x,first);
    if (last == nullptr)
    {
        last = first;
    }
}

template<class T>
size_t LList<T>::size() const
{
    size_t count = 0;
    box *crr = first;
    while (crr != nullptr)
    {
        crr = crr->next;
        ++count;
    }
    return count;
}
template<class T>
T& LList<T>::operator[] (size_t i)
{
    return at(i)->data;
}
template<class T>
T LList<T>::operator[] (size_t i) const
{
    return at(i)->data;
}

template<class T>
void LList<T>::insertAfter (const T& x, size_t pos)
{
    box *pred = at(pos);
    
    /*box *newElement = new box (x,nullptr);
    newElement->next = pred->next;
    pred->next = newElement;*/

    pred->next = new box(x,pred->next);
    if (pred == last)
    {
        last = last->next;
    }
}

template<class T>
typename LList<T>::box* LList<T>::at (size_t pos)
{
    assert (first != nullptr);
    box *crr = first;
    while (pos > 0 && crr != nullptr)
    {
        crr = crr->next;
        --pos;
    }
    assert (crr != nullptr);    
    return crr;
}

template<class T>
void LList<T>::pop()
{
    if (first != nullptr)
    {   
        box *tmp = first;
        first = first->next;
        delete tmp;
        if (first==nullptr)
        {
            last = nullptr;
        }
    }
}

template<class T>
void LList<T>::deleteAfter (size_t pos)
{
    box *pred = at(pos);
    box *save = pred->next;
    if (pred->next == nullptr)
    {
        return;
    }
    pred->next = pred->next->next;
    
    if (save == last)
    {
        last = pred;   
    } 
    delete save;

}

template<class T>
void LList<T>::push_back(const T& x)
{
    if (first == nullptr)
    {
        push(x);
        return;
    }
    last = last->next = new box (x,nullptr);
}
