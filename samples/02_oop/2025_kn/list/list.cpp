#include "list.h"

template <typename T>
List<T>::List()
{
}
template <typename T>
bool List<T>::empty() const
{
    return first == nullptr;
}

template <typename T>
unsigned List<T>::count() const
{
    unsigned c = 0;
    box<T> *current = first;
    while(current != nullptr)
    {
        ++c;
        current=current->next;
    }
    return c;
}

template <typename T>
void List<T>::clear()
{
    box<T> *save;
    while(first != nullptr)
    {
        save = first->next;
        delete first;
        first = save;
    }
    first = nullptr;
}


template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>::List(const List<T>& other)
{
    copyfrom(other.first);
}
template <typename T>
void List<T>::copyfrom(box<T> *other)
{
    box<T> *current = other;
    box<T> *prevCreated = nullptr;
    box<T> *newCreated = nullptr;

    while(current != nullptr)
    {
        newCreated = new box<T>{current->data,nullptr};
        if(prevCreated == nullptr)
        { 
            first = newCreated;
        } else 
        {
            prevCreated->next = newCreated;
        }
        prevCreated = newCreated;

        //prevCreated = prevCreated->next = nex box<T>{current->data,nullptr};

        current=current->next;
    }

}

template <typename T>
void List<T>::operator=(const List& other) //&other == this
{
    if(&other != this)
    {
        clear();
        copyfrom(other.first);    
    }
}


template <typename T>
T& List<T>::operator[](unsigned i)
{
    box<T> *current = pointerTo(i);
    if(current == nullptr)
    {
        throw "Index our of bounds.";
    }
    return current->data;
}

template <typename T>
T List<T>::operator[](unsigned i) const
{
    box<T> *current = pointerTo(i);
    if(current == nullptr)
    {
        throw "Index our of bounds.";
    }
    return current->data;
}

template <typename T>
box<T>* List<T>::pointerTo(unsigned i) const
{
    unsigned c = 0;
    box<T> *current = first;
    while(current != nullptr && c < i)
    {
        ++c;
        current=current->next;
    }
    return current;
}

template <typename T>
void List<T>::insertAfter(T x, unsigned i)
{
    box<T> *current = pointerTo(i);
    if(current == nullptr)
    {
        throw "Index out of bounds.";
    }
    current->next = new box<T>{x,current->next};    

}

template <typename T>
void List<T>::push(T x)
{
    /* first = new box<T>{x,first}; */
    box<T> *newBox = new box<T>{x,nullptr};
    newBox->next = first;
    first = newBox;
}

template <typename T>
ListIterator<T> List<T>::begin()
{
    return ListIterator<T>(first);
}

template <typename T>
ListIterator<T> List<T>::end()
{
    return ListIterator<T>(nullptr);
}

template <typename T>
ListIterator<T>::ListIterator(box<T> *first):current(first)
{
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    current = current->next;
    return *this;
} 

template <typename T>
T& ListIterator<T>::operator*()
{
    return current->data;
}

template <typename T>
bool  ListIterator<T>::operator!=(const ListIterator<T> &other)
{
    return this->current != other.current;
}
