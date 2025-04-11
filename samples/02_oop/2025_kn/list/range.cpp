#include "range.h"

template <typename T>
Range<T>::Iterator::Iterator(const T& x):current(x)
{
}

template <typename T>
typename Range<T>::Iterator& Range<T>::Iterator::operator++()
{
    current++;    
    return *this;
}

template <typename T>
T Range<T>::Iterator::operator*()
{
    return current;
}

template <typename T>
bool Range<T>::Iterator::operator!=(const typename Range<T>::Iterator &other) const
{
    return current != other.current;
}

template <typename T>
typename Range<T>::Iterator Range<T>::begin()
{
    return Iterator(a);
}

template <typename T>
typename Range<T>::Iterator Range<T>::end()
{
    return Iterator(b+1);
}
