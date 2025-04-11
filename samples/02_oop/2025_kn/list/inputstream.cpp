#include "inputstream.h"

template <typename T>
InputStream<T>::Iterator::Iterator(unsigned n):remaining(n)
{
}

template <typename T>
T InputStream<T>::Iterator::operator*()
{
    if(hasbuffered)
    {
        return buffered;
    }
    else
    {
        std::cin >> buffered;
        hasbuffered = true;
        return buffered;
    }
}

template <typename T>
typename InputStream<T>::Iterator& InputStream<T>::Iterator::operator++()
{
    remaining--;
    hasbuffered = false;
    return *this;
}

template <typename T>
bool InputStream<T>::Iterator::operator!=(const typename InputStream<T>::Iterator &other)
{
    return remaining != other.remaining;
}


template <typename T>
typename InputStream<T>::Iterator InputStream<T>::begin()
{
    return InputStream<T>::Iterator(count);
}

template <typename T>
typename InputStream<T>::Iterator InputStream<T>::end()
{
    return InputStream<T>::Iterator(0);
}

template <typename T>
InputStream<T>::InputStream(unsigned c):count(c){};
