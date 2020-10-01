#ifndef __DLLLIST_CPP
#define __DLLLIST_CPP

#include "dllist.h"

template<class T>
DLList<T>::DLList():first(nullptr)
{

}
template<class T>
DLList<T>::DLList(const DLList<T> &l)
{
    copy(l);
}
template<class T>
DLList<T>::~DLList()
{
    clear();
}


template<class T>
void DLList<T>::clear()
{
    DLList<T>::Box *crr = first, *save;
    while (crr != nullptr)
    {
        save = crr->next;
        delete crr;
        crr = save;
    }
}

template<class T>
DLList<T>& DLList<T>::operator = (const DLList<T> &list)
{
    if (this != &list)
    {
        clear();
        copy(list);
    }
    return *this;
}

template<class T>
DLList<T> DLList<T>::operator + (const T &x) const
{
    //ВНИМАНИЕ: трябва да има работещ конструктор за копиране
    DLList<T> result (*this);
    result += x;
    return result;
}

template<class T>
DLList<T>& DLList<T>::operator += (const T&x)
{
    DLList<T>::Box *newFirst = new DLList<T>::Box {x,first,nullptr};

    if (first != nullptr)
    {
        first->prev = newFirst;
    }
    
    first = newFirst;

    return *this;
}

template<class T>
void DLList<T>::print ()
{
    DLList<T>::Box *crr = first;
    while (crr != nullptr)
    {
        std::cout << crr->data << " ";
        crr = crr->next;
    }
}

template<class T>
std::ostream& operator << (std::ostream &out,const DLList<T> &list)
{
    typename DLList<T>::Box *crr = list.first;
    while (crr != nullptr)
    {
        out << crr->data << " ";
        crr = crr->next;
    }
    return out;
}

template<class T>
void DLList<T>::copy(const DLList<T>&)
{
    //HOMEWORK!!!!!
    first = nullptr;
}


#endif