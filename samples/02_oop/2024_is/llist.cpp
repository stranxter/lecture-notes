#include <iostream>
#include "llist.h"

template <typename T>
LList<T>::LList():first(nullptr)
{
}

template <typename T>
void LList<T>::push(const T& x)
{
    /*
    LList<T>::box *newBox = new LList<T>::box {x,nullptr};
    newBox->next = first;
    first = newBox;
    */
    first = new LList<T>::box{x,first};
}

template <typename T>
unsigned int LList<T>::size() const
{
    unsigned count = 0;
    LList<T>::box *crr = first;
    while(crr != nullptr)
    {
        crr = crr->next;
        ++count;
    }

    return count;   
}

template <typename T>
T& LList<T>::operator[](unsigned int i) 
{
    return locate(i)->data;
}

template <typename T>
const T& LList<T>::operator[](unsigned int i) const
{
    return locate(i)->data;
}

template <typename T>
typename LList<T>::box* LList<T>::locate(unsigned int i) const
{
    LList<T>::box *crr = first;
    for(int count = 0; count < i; ++count)
    {
        crr=crr->next;
    }
    return crr;
}

template <typename T>
void LList<T>::insertAfter(unsigned int i, const T& x)
{
    LList<T>::box* pred = locate(i);
    pred->next = new LList<T>::box{x,pred->next};
}

template <typename T>
void  LList<T>::copy(const LList<T>& other) 
{
    LList<T>::box *other_crr = other.first;
     
    if(other_crr == nullptr)
    {
        first = nullptr;
        return;
    }

    first = new LList<T>::box {other_crr->data,nullptr};

    LList<T>::box *pred = first;
    other_crr = other_crr->next;

    while(other_crr != nullptr)
    {/*
        Приемаме, че pred сочи адреса на последния
        създаден елемент (от предишната итерация на цикъла)
      */
        pred->next = new LList<T>::box{other_crr->data,nullptr};
        other_crr = other_crr->next;
        pred = pred->next;
    }
}

template <typename T>
LList<T>& LList<T>::operator=(const LList<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <typename T>
LList<T>::LList(const LList<T> &other)
{
    copy(other);
}

template <typename T>
void LList<T>::clear()
{
    LList<T>::box *save;
    while (first != nullptr)
    {
        save = first->next;
        delete first;
        first = save;
    }   
}
template <typename T>
LList<T>::~LList()
{
    clear();
}
