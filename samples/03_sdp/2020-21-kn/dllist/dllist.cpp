
#ifndef __DLLIST_CPP
#define __DLLIST_CPP

#include "dllist.h"
#include <iostream>
#include <exception>

template<class T>
DLList<T>::DLList()
{
    first.next = &first;
    first.prev = &first;
}
template<class T>
DLList<T>::DLList(const DLList<T> &other)
{
    copy(other);
}
template<class T>
DLList<T>::~DLList()
{
    clear();
}

template<class T>
void DLList<T>::clear()
{
    DLList<T>::box *crr = first.next,
                   *save = nullptr;
    while (crr != &first)
    {
        save = crr;
        crr = crr->next;
        delete save;
    }

    first.next = &first;    
    first.prev = &first;    
}

template<class T>
DLList<T>& DLList<T>::operator= (const DLList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template<class T>
DLList<T> DLList<T>::operator+ (const T &x) const
{
    DLList<T> result(*this);
    result += x;
    return result;
}
template<class T>
DLList<T>& DLList<T>::operator+= (const T &x)
{
    first.next = new DLList<T>::box {x,first.next,&first};

    if (first.prev == &first)
    {
        first.prev = first.next;
    } else 
    {
        first.next->next->prev = first.next;
    }

    return *this;
}

template<class T>
void DLList<T>::copy(const DLList<T> &other)
{
  //ЗА ДОМАШНО!!!  
}

template<class T>
bool DLList<T>::empty()
{
  return first.next == &first;
}

template<class T>
std::ostream& operator<< (std::ostream &out,const DLList<T> &list)
{
    typename DLList<T>::box *crr = list.first.next;

    while (crr != &list.first)
    {
        out << crr->data << " ";
        crr=crr->next;
    }

    return out;
}

template <class T>
T& DLList<T>::Iterator::operator *()
{
    if (current == first)
    {
        throw std::out_of_range ("Nil iterator");
    }
    return current->data;
}

template <class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator ++()
{
    if (current == first)
    {
        throw std::out_of_range ("Nil iterator");
    }
    current = current->next;
    return *this;
}

template <class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator --()
{
    if (current == first)
    {
        throw std::out_of_range ("Nil iterator");
    }
    current = current->prev;
    return *this;
}

template <class T>
bool DLList<T>::Iterator::operator!= (const Iterator &it)
{
    return current != it.current;
}

template <class T>
DLList<T>::Iterator::Iterator(box *_current, box *_first):current(_current),first(_first){}

template <class T>
typename DLList<T>::Iterator DLList<T>::begin()
{
    return DLList<T>::Iterator(first.next, &first);
}

template <class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    return DLList<T>::Iterator(&first, &first);
}

template <class T>
typename DLList<T>::Iterator DLList<T>::last()
{
    return DLList<T>::Iterator(first.prev, &first);
}


#endif