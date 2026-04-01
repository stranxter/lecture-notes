#include <iostream>

#include "llist.h"

template <typename T>
box<T>* LList<T>::findByIndex(unsigned index) const
{
    if (index >= length())
        return nullptr;

    box<T> *crr = first;
    for(int i=0; i < index && crr != nullptr; ++i)
    {
        crr=crr->next;
    }
    return crr;
}

template <typename T>
LList<T>::~LList()
{
    box<T> *crr = first,
            *save;
    while(crr != nullptr)
    {
        save = crr->next;
        delete crr;
        crr=save;
    }
}



template <typename T>
unsigned LList<T>::length() const
{
    return crrsize;
}


template <typename T>
T LList<T>::operator[](unsigned index) const
{
    box<T> *crr = findByIndex(index);
    
    if(crr == nullptr)
    {
        throw "Index too large.";
    }

    return crr->data;
}


template <typename T>
T& LList<T>::operator[](unsigned index) 
{
    box<T> *crr = findByIndex(index);
    
    if(crr == nullptr)
    {
        throw "Index too large.";
    }

    return crr->data;
}


template <typename T>
bool LList<T>::insertAfter(const T& newdata, unsigned position)
{
    box<T> *newbox = new box<T>{newdata,nullptr};
    ++crrsize;

    //[1|]->[2|null]
    //       ^
    //       |
    //      crr

    box<T> *crr=findByIndex(position);

    if(crr == nullptr)
    {
        return false;
    }

    newbox->next = crr->next;
    crr->next = newbox;

    return true;
}


template <typename T>
LList<T>& LList<T>::push(const T& newdata)
{
    first = new box<T>{newdata,first};
    ++crrsize;
    return *this;
    
    /*box<T> *newbox = new box<T>;
    newbox->data = newdata;
    newbox->next = first;

    first = newbox;*/
}

template <typename T>
LList<T>::LList(const LList<T>& other)
{
    box<T> *crr = other.first,
            *newElement = nullptr,
            *lastCreated = nullptr;

    crrsize = other.crrsize;

    if(crr == nullptr)
    {
        first = nullptr;
        return;
    }

    first = new box<T>{other.first->data, nullptr};

    crr=crr->next;
    lastCreated = first;

    while(crr != nullptr)
    {
        newElement = new box<T>{crr->data,nullptr};
        crr = crr->next;
        lastCreated->next = newElement;
        lastCreated = newElement;
    }

}


template <typename T>
std::ostream& operator<<(std::ostream &out, const LList<T>& l)
{
    for(int i = 0; i < l.length(); ++i)
    {
        out << l[i] << " ";
    }

    return out;
}

template <typename T>
ListIterator<T> LList<T>::begin() const
{
    return ListIterator<T>(first);
}

template <typename T>
ListIterator<T> LList<T>::end() const
{
    return ListIterator<T>(nullptr);
}


template <typename T>
ListIterator<T>::ListIterator(box<T> *init):current(init){}

template <typename T>
T ListIterator<T>::operator*() const
{
    return current->data;
}


template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator &other)
{
    return current != other.current;
}
