#include "list.h"

template <typename T>
List<T>::List()
{
}
template <typename T>
bool List<T>::empty()
{
    return first == nullptr;
}

template <typename T>
unsigned List<T>::count()
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
box<T>* List<T>::pointerTo(unsigned i)
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
