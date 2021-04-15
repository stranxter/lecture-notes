#pragma once

#include <cassert>

#include "llist.h"

template <typename T>
LList<T>::LList():first(nullptr)
{

}

template <typename T>
void LList<T>::push(const T& x)
{
    first = new box{x,first};
}
template <typename T>
const T& LList<T>::get(size_t i) const
{
    box* crr = locate(i);
    
    assert (crr != nullptr);
    return crr->data;

}
template <typename T>
size_t LList<T>::size() const
{
    box* crr = first;
    size_t counter = 0;

    while (crr != nullptr)
    {
        ++counter;
        crr = crr->next;
    }  
    
    return counter; 
}

template <typename T>
bool LList<T>::insertAt(size_t i, const T& x)
{
    if (i == 0)
    {
        push (x);
        return true;
    }
    --i; //трябва ми указател към предходния елемент
    box *pred = locate(i);
    
    if (pred == nullptr)
    {
        return false;
    }

    box *newBox = new box {x,pred->next};
    pred->next = newBox;

    return true;
}

template <typename T>
bool LList<T>::pop()
{
    if(first == nullptr)
    {
        return false;
    }

    box *save = first;
    first = first->next;

    delete save;
    
    return true;
}

template <typename T>
bool LList<T>::deleteAt(size_t i)
{
    if (i == 0)
    {
        return pop();
    }

    --i;
    box *pred = locate(i);
    if (pred == nullptr || pred->next == nullptr)
    {
        return false;
    }

    box *toBeDeleted = pred->next;

    pred->next = pred->next->next;
    
    delete toBeDeleted;

    return true;

}

template <typename T>
typename LList<T>::box* LList<T>::locate(size_t i) const
{
    box *crr = first;
    while (crr!= nullptr && i > 0)
    {
        --i;
        crr = crr->next;
    }
    return crr;
}