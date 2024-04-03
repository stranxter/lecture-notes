#include <iostream>
#include "list.h"


template <typename T>
List<T>::List():first(nullptr),current_size(0)
{}


template <typename T>
void List<T>::pop()
{
    //         ------------
    //         |           |
    //         |           \/
    //first ---|  [1]---->[2]---->[3] //first ----> [1]---->[2]---->[3]

    box *save = first;
    first = first->next;
    delete save;
    --current_size;
}

template <typename T>
void List<T>::push(const T& x)
{
    //first --|  [1]---->[2]---->[3] //first ----> [1]---->[2]---->[3]
    //        |   ^
    //       \/   |
    //       [x]--|

    //first ----> [x] -----> [1]---->[2]---->[3]

    //box *myNewElement = new box{x,first};
    //first = myNewElement;

    first = new box{x,first};
    ++current_size;

}

template <typename T>
int List<T>::size() const
{
    return current_size;
}

template <typename T>
T& List<T>::operator[](unsigned int i)
{
    typename List<T>::box *crr = first;
    for(int count = 0; count < i; ++count)
    {
        crr = crr->next;
    }

    return crr->data ;
}

template <typename T>
void List<T>::clear()
{
    typename List<T>::box *save = first;
    while (first != nullptr)
    {
        save = first->next;
        delete first;
        first = save;
    }        
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>::List(const List<T>& other)
{
    copy(other);
}

template <typename T>
void List<T>::copy(const List<T>& other)
{
    if(other.first == nullptr)
    {
        first = nullptr;
        return;
    }

    first = new box{other.first->data, nullptr};
    typename List<T>::box *previous = first;
    typename List<T>::box *otherCurent = other.first->next;
    
    while (otherCurent != nullptr)
    {
        previous->next = new box{otherCurent->data,nullptr};
        otherCurent = otherCurent->next;
        previous = previous->next;
    }     
    current_size = other.current_size;
}

template <typename T>
List<T>& List<T>::operator=(const List<T> &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& l)
{
    
    typename List<T>::box *crr = l.first;
    out << "{";
    while (crr != nullptr)
    {
        out << " " <<  crr->data;
        crr = crr->next;
    }
    out << "}";
    return out;
}


template <typename T>
bool List<T>::operator==(const List<T> &other) const
{
    if(size() != other.size()) return false;

    List<T>::box *crr = first, *other_crr = other.first;
    while (crr != nullptr && other_crr != nullptr && crr->data == other_crr->data)
    {
        crr = crr->next;
        other_crr = other_crr->next;
    }

    return crr == nullptr;
}