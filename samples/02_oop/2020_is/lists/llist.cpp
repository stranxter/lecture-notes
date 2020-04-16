#pragma once

#include "llist.h"
#include <cassert>

template <class T>
LList<T>::LList():first(nullptr),last(nullptr)
{
}

template <class T>
void LList<T>::push(const T& x)
{
    /*box *newel = new box {x,nullptr};
    newel = first;
    first = newel;*/

    first = new box {x,first};
    if (last == nullptr)
    {
        last = first;
    }
}

template <class T>
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
template <class T>
T& LList<T>::operator[](size_t i)
{
    return at(i)->data;
}
template <class T>
T LList<T>::operator[](size_t i) const
{
    return at(i)->data;
}

template <class T>
typename LList<T>::box* LList<T>::at (size_t pos) const
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

template <class T>
void LList<T>::insertAfter(size_t i, const T& x)
{
    box* pred = at(i);

    /*box *newel = new box {x,nullptr};
    newel = pred->next;
    pred->next = newel;*/
    
    pred->next = new box{x,pred->next};
    if (last == pred)
    {
        last = last->next;
    }
    
}

template <class T>
void LList<T>::pop()
{
    assert(first != nullptr);

    box* save = first;  

    first = first->next;
    delete save;

    if (first == nullptr)
    {
        last = nullptr;
    }
}

template <class T>
void LList<T>::deleteAfter(size_t i)
{
    box *pred = at(i);
    if (pred->next == nullptr)
    {
        return;
    }
    if (last == pred->next)
    {
        last = pred;
    }
    box *save = pred->next;
    pred->next = pred->next->next;

    delete save;

}

template <class T>
void LList<T>::push_back(const T& x)
{
    if (first == nullptr)
    {
        last = first = new box{x,nullptr};
        return;
    }
    last = last->next = new box{x,nullptr};
}

template <class T>
bool LList<T>::operator==(const std::vector<T> &v) const
{
    size_t vi = 0;
    box *crr = first;
    while (crr != nullptr && 
           vi < v.size() &&
           crr->data == v[vi])
    {
        ++vi;
        crr=crr->next;
    }

    return (crr==nullptr && vi == v.size());
}

