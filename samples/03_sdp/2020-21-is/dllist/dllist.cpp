#ifndef __DLLLIST_CPP
#define __DLLLIST_CPP

#include "dllist.h"

template<class T>
DLList<T>::DLList():first(nullptr),last(nullptr)
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
    first=nullptr; 
    last=nullptr;
}

template<class T>
DLList<T>& DLList<T>::operator=(const DLList<T> &list)
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
    } else 
    {
        last = newFirst;
    }
    
    first = newFirst;

    return *this;
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

template<class T>
bool DLList<T>::empty()
{
    return first == nullptr;
}

template<class T>
void DLList<T>::reverse()
{
    typename DLList<T>::Box *crr = first,
                            *savenext;
    
    while (crr != nullptr)
    {

        savenext = crr->next;
        crr->next = crr->prev;
        crr->prev = savenext;

        crr = savenext;
    }

    savenext = first;
    first = last;
    last = savenext;

}

template<class T>
DLList<T>::Iterator::Iterator(Box *_current,DLList<T> *_list):current(_current),list(_list)
{}

template<class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator++()
{
    
    if (current == nullptr)
    {
        throw std::out_of_range("No more elements in list.");
    }
    current=current->next;
    
    return *this;
}

template<class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator--()
{
    if (current == nullptr)
    {
        if (list->first == nullptr)
        {
            throw std::out_of_range("List is empty");
        } else 
        {
            current = list->last;
        }
    } else
    {
        current=current->prev;    
    }
    
    return *this;
}


template<class T>
T& DLList<T>::Iterator::operator*()
{
    return current->data;
}

template<class T>
bool DLList<T>::Iterator::operator!= (const Iterator& other)
{
    return current != other.current;
}

template<class T>
typename DLList<T>::Iterator DLList<T>::begin()
{
    return typename DLList<T>::Iterator(first,this);
}

template<class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    return typename DLList<T>::Iterator(nullptr,this);
}

template<class T>
bool DLList<T>::deleteAt(const Iterator &it)
{
    typename DLList<T>::Box *crr = it.current,
                            *save;

    if (crr == nullptr)
    {
        return false;
    }

    if (crr->prev == nullptr)
    //изтривамне първи елемент
    {
        save = first;
        first = first->next;
        delete save;

        if (first == nullptr)
        {
            last = nullptr;
        }

    }

    save = crr;
    crr->prev->next = crr->next;
    crr->next->prev = crr->prev;

    delete save;

    return true;
};


#endif