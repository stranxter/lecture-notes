#include "pstack.h"

template <typename T>
pstack<T>::pstack(){}


template <typename T>
pstack<T> pstack<T>::push(const T& data) const
{
    return pstack(data,*this);
}

template <typename T>
pstack<T>::pstack(const T& data, const pstack& tail)
{
    head = std::make_shared<typename pstack<T>::box>(data,tail.head);
}

template <typename T>
pstack<T> pstack<T>::pop() const
{
    pstack<T> result;
    result.head = head->next;
    return result;
}

template <typename T>
bool pstack<T>::empty() const
{
    return head == nullptr;
}

template <typename T>
T pstack<T>::top() const
{
    return head->data;
}