#pragma once
#include "llist.h"
#include <iostream>

template <typename T>
LList<T>::LList():first(nullptr)
{
}

template <typename T>
void LList<T>::push(const T& x)
{
    first = new typename LList<T>::box{x,first};
    /*
    box<T>* newBox = new box<T>{x,nullptr};
    newBox->next = first;
    first = newBox;
    */
}

template <typename T>
void LList<T>::print() const
{
    typename LList<T>::box* crr = first;
    while (crr != nullptr)
    {
        std::cout << crr->data << " ";
        crr = crr->next;
    }
    //crr==nullptr в този момент
}

template <typename T>
T& LList<T>::operator[](size_t i)
{
    typename LList<T>::box* crr = locateBox(i);

    if(crr == nullptr)
        throw "Index out of bounds.";

    return crr->data;
}

template <typename T>
T LList<T>::operator[](size_t i) const
{
    typename LList<T>::box* crr = locateBox(i);

    if(crr == nullptr)
        throw "Index out of bounds.";

    return crr->data;
}

template <typename T>
typename LList<T>::box* LList<T>::locateBox(size_t i) const
{
    typename LList<T>::box* crr = first;

    for(int count = 0; count < i && crr != nullptr; ++count)
    {
        crr = crr->next;
    }
    
    return crr;
}

template <typename T>
size_t LList<T>::size() const
{
    size_t count = 0;
    typename LList<T>::box* crr = first;
    while(crr != nullptr)
    {
        crr = crr->next;
        ++count;
    }

    return count;
}

template <typename T>
void LList<T>::insertAt(size_t i, const T& x)
{

    if(i==0)
    {
        push(x);
        return;
    }

    typename LList<T>::box* newBox 
        = new typename LList<T>::box{x,nullptr};
    
    typename LList<T>::box* prev 
        = locateBox(i-1);

    if(prev == nullptr)
        throw "Index out of bounds.";

    newBox->next = prev->next;
    prev->next = newBox;
}

template <typename T>
void LList<T>::pop()
{
    if(first == nullptr)
    {
        throw "Popping from an empty list.";
    }
    typename LList<T>::box* save = first->next;
    delete first;
    first = save;
}

template <typename T>
void LList<T>::deleteAt(size_t i)
{
    if (i==0)
    {
        pop();
        return;
    }

    typename LList<T>::box* prev = locateBox(i-1);
    typename LList<T>::box* save = prev->next;
    prev->next = prev->next->next;
    delete save;
}


template <typename T>
LList<T>::~LList()
{
    while(first != nullptr)
    {
        pop();
    }    
}

template <typename T>
LList<T>::LList(const LList<T> &other)
{
    typename LList<T>::box* other_current = other.first;

    typename LList<T>::box* last_created = nullptr;
    typename LList<T>::box* just_created = nullptr;

    while(other_current != nullptr)
    {
        just_created = new LList<T>::box{other_current->data, nullptr};
        if(last_created != nullptr)
        {
            last_created->next = just_created;    
        } else {
            first = just_created;
        }
        other_current = other_current->next;
        last_created = just_created;
    }
}

template <typename T>
typename LList<T>::box* LList<T>::rec_copy(box* other_first) const
{
    if(other_first == nullptr)
    {
        return nullptr;
    }

    return new typename LList<T>::box{other_first->data,rec_copy(other_first->next)};

}

template <typename T>
typename LList<T>::const_iterator LList<T>::begin() const
{
    typename LList<T>::const_iterator fromFirst(first);
    return fromFirst;
}
template <typename T>
typename LList<T>::const_iterator LList<T>::end() const
{
    typename LList<T>::const_iterator toEnd(nullptr);
    return toEnd;
}


template <typename T>
typename LList<T>::iterator LList<T>::begin()
{
    typename LList<T>::iterator fromFirst(first);
    return fromFirst;
}

template <typename T>
typename LList<T>::iterator LList<T>::end()
{
    typename LList<T>::iterator toEnd(nullptr);
    return toEnd;
}

template <typename T, typename ElemRef>
LListIterator<T,ElemRef>::LListIterator(typename LList<T>::box *start):position(start)
{
}

template <typename T, typename ElemRef>
ElemRef LListIterator<T,ElemRef>::operator*()
{
    return position->data;
}
    
template <typename T, typename ElemRef>
LListIterator<T,ElemRef>& LListIterator<T,ElemRef>::operator++()
{
    if (position == nullptr)
    {
        throw "No more elements!";
    }
    position = position->next;
    return *this;
}
template <typename T, typename ElemRef>
bool LListIterator<T,ElemRef>::operator!= (const LListIterator &other)
{
    return position != other.position;
}
