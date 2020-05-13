#ifndef __VECTOR_CPP
#define __VECTOR_CPP

#include <iostream>
#include "vector.h"
#include <cassert>
#include <stdexcept>

template<class T>
Vector<T>::Vector ()
{
    data = nullptr;
    size = 0;
}


template<class T>
Vector<T>::Vector (const Vector<T>& other)
{
    this->data = new T [other.size];
    for (size_t i = 0; i < other.size; ++i)
    {
        this->data[i] = other.data[i];
    }
    this->size = other.size; 
}


template <class T>
Vector<T>::Vector (size_t initial_size)
{
    data = new T[initial_size];
    size = initial_size;
}

template<class T>
template<class InitType>
Vector<T>::Vector (size_t initial_size, const InitType& init)
{
    data = nullptr;
    size = 0;
    for (size_t i = 0; i < initial_size; ++i)
    {
        to_end (T(init));
    }
}


template<class T>
void Vector<T>::to_end (const T& x)
{
    
    T *bigger_buffer = new T [size+1];
    for (size_t i = 0; i < size; i++)
    {
        bigger_buffer[i] = data[i];
    }
    bigger_buffer[size] = x;
    ++size;

    delete []data;
    data = bigger_buffer;

}

template<class T>
void Vector<T>::push (const T& x)
{
    T *bigger_buffer = new T [size+1];

    for (size_t i = 0; i < size; i++)
    {
        bigger_buffer[i+1] = data[i];
    }
    bigger_buffer[0] = x;
    ++size;

    delete []data;
    data = bigger_buffer;      
}

template<class T>
Vector<T> Vector<T>::operator + (const Vector<T> other) const
{
    Vector<T> result;
    result.data = new T [size+other.size];
    for (size_t i = 0; i < size; ++i)
    {
        result.data[i] = data[i];
    }
    for (size_t i = 0; i < other.size; ++i)
    {
        result.data[size+i] = other.data[i];
    }
    result.size = size + other.size;
    return result;
}

template<class T>
Vector<T> Vector<T>::operator + (const T& x)  const
{
    Vector<T> result (*this);
    result += x;
    return result;
}

template<class T>
Vector<T>& Vector<T>::operator += (const T& x) 
{
    this->to_end (x);
    return *this;
}

template<class T>
T& Vector<T>::operator [] (size_t i)
{
    //assert(i >= 0 && i <= size);
    if (i > size)
    {
        resize (i+1);
    }
    return data[i];
}

template<class T>
T Vector<T>::operator [] (size_t i) const
{
    if (i >= size)
    {
        throw std::out_of_range("Index too large!");
    }

    return data[i];
}

template<class T>
void Vector<T>::resize (size_t new_size)
{

    assert (new_size > size);

    T* new_buffer = new T[new_size];
    for (size_t i = 0; i < size; ++i)
    {
        new_buffer[i] = data[i];
    }

    delete data;
    size = new_size;
    data = new_buffer;

}

template<class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
    if (this != &other)
    {
        delete []this->data; 

        this->data = new T [other.size];
        for (size_t i = 0; i < other.size; ++i)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size; 
    }
    return *this;
}

template<class T>
Vector<T>::~Vector () 
{
    delete []data;
}

template<class T>
size_t Vector<T>::length () const
{
    return size;
}

template<class T>
bool Vector<T>::operator!= (const Vector<T>& other) const
{
    return !(*this == other);
}

template<class T>
bool Vector<T>::operator== (const Vector<T>& other) const
{        
    if (this->size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }
    return true;
}


template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v)
{
    
    for (size_t i = 0; i < v.length(); i++)
    {
        stream << v[i] << " ";
    }
    return stream;
}


#endif