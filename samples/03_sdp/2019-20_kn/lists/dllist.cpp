#include "dllist.h"
#include <cassert>

template <class T>
DLList<T>::DLList():first(nullptr), last(nullptr){

}
template <class T>
DLList<T>::DLList(const DLList &l){
    copy (l);
}
template <class T>
DLList<T>::~DLList()
{
    deleteall ();
}

template <class T>
typename DLList<T>::Node* DLList<T>::locate(size_t index)
{
    DLList<T>::Node *current = first;
    while (index != 0 && current != nullptr)
    {
        --index;
        current = current->next;
    }
    return current;
}

template <class T>
bool DLList<T>::insertAt(size_t position, const T &element)
{
    if (position == 0)
    {
        first = new Node(element,first,nullptr);
        assert (first != nullptr);
        if (first->next != nullptr)
        {
            first->next->prev = first;
        }
        if (last == nullptr)
        {
            last = first;
        }
        return true;
    }

    DLList<T>::Node *current = locate (position-1);

    if (current == nullptr)
    {
        return false;
    }

    DLList<T>::Node *saveNext = current->next;
    DLList<T>::Node *newElement = new DLList<T>::Node(element, current->next, current);
    assert (newElement != nullptr);
    current->next = newElement;
    if (saveNext != nullptr)
    {
        saveNext->prev = newElement;
    } else {
        last = newElement;
    }
    
    return true;
}
template <class T>
T& DLList<T>::operator[](size_t index)
{
    DLList<T>::Node *element = locate(index);
    assert (element != nullptr);
    return element->data;
}
template <class T>
bool DLList<T>::member(const T& x) const
{
    DLList<T>::Node *current = first;
    while (current != nullptr && current->data != x)
    {
        current = current->next;
    }

    return current != nullptr;
}
template <class T>
size_t DLList<T>::size() const
{
    DLList<T>::Node *current = first;
    size_t count = 0;
    while (current != nullptr)
    {
        current = current->next;
        ++count;
    }

    return count;
}

template <class T>
DLList<T> &DLList<T>::operator=(const DLList<T> &l)
{
    if (this != &l)
    {
        deleteall ();
        copy (l);
    }
    return *this;
}

template <class T>
void DLList<T>::copy(const DLList<T> &l)
{
    //copy assumes list is empty or uninitialized

    DLList<T>::Node *other = l.first,
                    *lastCreated = nullptr,
                    *newElement = nullptr;

    if (other == nullptr)
    {
        first = nullptr;
        last = nullptr;
        return;
    }

    first = new DLList<T>::Node(other->data, nullptr, nullptr);
    assert(first != nullptr);
    lastCreated = first;
    other = other->next;

    while (other != nullptr)
    {
        newElement = new DLList<T>::Node(other->data, nullptr, lastCreated);
        assert (newElement != nullptr);
        lastCreated->next = newElement;

        other = other->next;
        lastCreated = newElement;  
    }

    last = lastCreated;
}
template <class T>
void DLList<T>::deleteall()
{
    DLList<T>::Node *save;
    while (first != nullptr)
    {
        save = first->next;
        delete first;
        first = save;
    }
    last = nullptr;   
}

template <class T>
T& DLList<T>::fromBack(size_t index)
{
    DLList<T>::Node *current = last;
    while (index != 0 && current != nullptr)
    {
        --index;
        current = current->prev;
    }
    assert (current != nullptr);
    return current->data;
}

template <class T>
DListIterator<T> DLList<T>::begin()
{
    return DListIterator<T> (first);
}

template <class T>
DListIterator<T> DLList<T>::end()
{
    return DListIterator<T>(nullptr);
}

template <class T>
bool DListIterator<T>::operator==(const DListIterator &it) const
{
    return current == it.current;
}

template <class T>
bool DListIterator<T>::operator!=(const DListIterator &it) const
{
    return current != it.current;
}

template <class T>
DListIterator<T>& DListIterator<T>::operator++()
{
    assert (current != nullptr);
    current = current->next;
    return *this;
}

template <class T>
T& DListIterator<T>::operator*()
{
    return current->data;
}

template <class T>
DListIterator<T>::DListIterator(typename DLList<T>::Node *start)
{
    current = start;
}
