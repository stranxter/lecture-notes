#include "dllist.h"

template <typename T>
DLList<T>::DLList():first(nullptr),last(nullptr),count(0)
{
}
template <typename T>
DLList<T>::DLList(DLList &other):first(nullptr),last(nullptr),count(0)
{
    for(T x:other)
    {
        push_back(x);
    }
}
template <typename T>
DLList<T>::DLList(const DLList&&)
{
    //!!!!!
}

template <typename T>
void DLList<T>::push_front(const T& x)
{
    typename DLList<T>::node *newNode = new typename DLList<T>::node {x,first,nullptr};

    if(first != nullptr)
    {
        first->prev = newNode;    
    } else {
        last = newNode;
    }
    first = newNode;
    ++count;
}
template <typename T>
void DLList<T>::push_back(const T& x)
{
    typename DLList<T>::node *newNode = new typename DLList<T>::node {x,nullptr,last};
    
    if(last != nullptr)
    {
        last->next = newNode;
    } else {//last == nullptr
        first = newNode;
    }

    last = newNode;
    ++count;
}
template <typename T>
unsigned int DLList<T>::size() const
{
    return count;
}

template <typename T>
bool DLList<T>::pop_back()
{
    return false;
}
template <typename T>
bool DLList<T>::pop_front()
{

    if(first == nullptr)
    {
        return false;
    }

    typename DLList<T>::node* save = first;
    if(first->next != nullptr)
    {
        first->next->prev=nullptr;
    }
    first=first->next;

    delete save;
    
    --count;
    return true;
}

template<typename T>
typename DLList<T>::const_iterator DLList<T>::begin() const
{
    typename DLList<T>::const_iterator it(first,&last);
    return it;
}
template<typename T>
typename DLList<T>::const_iterator DLList<T>::end() const
{
    typename DLList<T>::const_iterator it(nullptr,&last);
    return it;
}

template<typename T>
typename DLList<T>::iterator DLList<T>::begin()
{
    typename DLList<T>::iterator it(first,&last);
    return it;
}
template<typename T>
typename DLList<T>::iterator DLList<T>::end()
{
    typename DLList<T>::iterator it(nullptr,&last);
    return it;
}


template<typename T>
template<typename ElRef>
DLList<T>::iterator_template<ElRef>::iterator_template(typename DLList<T>::node *crr, 
                                                       typename DLList<T>::node * const *plast)
{
    current = crr;
    ptr_to_last = plast;
}


template<typename T>
template<typename ElRef>
ElRef DLList<T>::iterator_template<ElRef>::operator*() const
{
    return current->data;
}
template<typename T>
template<typename ElRef>
typename DLList<T>::template iterator_template<ElRef>& DLList<T>::iterator_template<ElRef>::operator++()
{
    current = current->next;
    return *this;    
}
template<typename T>
template<typename ElRef>
typename DLList<T>::template iterator_template<ElRef>& DLList<T>::iterator_template<ElRef>::operator--()
{
    if (current == nullptr)
    {
        current = *ptr_to_last;
    } else {
        current = current->prev;
    }
    return *this;
}
template<typename T>
template<typename ElRef>
bool DLList<T>::template iterator_template<ElRef>::operator != (const typename DLList<T>::iterator_template<ElRef>& other)
{
    return current != other.current;
}

template<typename T>
void DLList<T>::remove(const typename DLList<T>::iterator&)
{

}

template<typename T>
DLList<T>::~DLList()
{

}

