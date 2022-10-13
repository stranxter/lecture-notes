#include "llist.h"
#include <iostream>
#include <exception>

template <typename T>
LList<T>::LList()
{
    first = nullptr;
}

template <typename T>
void LList<T>::push(const T& x)
{
    first = new LList<T>::box {x,first};

/*
    LList<T>::box* newBox = new LList<T>::box;
    newBox->data = x;
    newBox->next = first;
    first = newBox;
*/    
}

template <typename T>
void LList<T>::print() const
{ 
/*    LList<T>::box *crr = first;
    while (crr != nullptr)
    {
        std::cout << crr->data << std::endl;
        crr = crr->next;
    }
*/
    for ( LList<T>::box *crr = first; 
          crr != nullptr; 
          crr=crr->next)
    {
        std::cout << crr->data << std::endl;
    }
}

template <typename T>
size_t LList<T>::size() const
{
    LList<T>::box* crr = first;
    size_t count = 0;
    while (crr != nullptr)
    {
        ++count;
        crr = crr->next;
    }

    return count;
}

template <typename T>
T& LList<T>::operator[] (size_t i)
{
    //!
    LList<T>::box* crr = first;
    for (size_t count = 0; count < i; ++count)
    {  
        if (crr == nullptr)
        {
            throw std::out_of_range("Index out of bounds");
        }
        crr=crr->next;
    }
    return crr->data;
}

template <typename T>
T LList<T>::operator[] (size_t i) const
{
    //!
    LList<T>::box* crr = first;
    for (size_t count = 0; count < i; ++count)
    {  
        if (crr == nullptr)
        {
            throw std::out_of_range("Index out of bounds");
        }
        crr=crr->next;
    }
    return crr->data;
}

template <typename T>
void LList<T>::clear()
{
    LList<T>::box* save = first;
    while (first != nullptr)
    {
        save=first->next;
        delete first;
        first=save;
    }
}

template <typename T>
LList<T>::~LList()
{

}

template <typename T>
LList<T>& LList<T>::operator= (const LList<T> &other)
{
    if (this != &other)
    {
        clear();
        first=copy2(other.first);
    }

    return *this;
}

template <typename T>
void LList<T>::copy(LList<T>::box* other_first)
{
    //приемаме, че нашият списък е празен вече
    if (other_first == nullptr)
        return;


    LList<T>::box* lastCreated = nullptr;
    while (other_first != nullptr)
    {
        //other_first на този етап сочи към някой от елементите на
        //другия списък
        LList<T>::box* newBox = new LList<T>::box {other_first->data,nullptr};
        if (lastCreated != nullptr)
        {
            lastCreated->next = newBox;
        } else {
            first = newBox;
        }
        
        lastCreated = newBox;
        other_first = other_first->next;
    }
}

template <typename T>
typename LList<T>::box* LList<T>::copy2(LList<T>::box* other)
{
    if (other == nullptr)
        return nullptr;

    return new LList<T>::box {other->data,copy2(other->next)};
}