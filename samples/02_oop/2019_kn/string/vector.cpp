#include <iostream>
#include <cassert>

#include "vector.h"

//#define debug 

template <typename T>
Vector<T>:: Vector()
{
#ifdef debug
    std::cout << "Create: " << (long)this << std::endl;
#endif
    elements = new T [0];
    nCapacity = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &original)
{
#ifdef debug
    std::cout << "Copy: " << (long)&original << "->" << (long)this << std::endl;
#endif
    nCapacity = original.nCapacity;
    elements = new T[nCapacity];
    for (size_t i = 0; i < nCapacity; i++)
    {
    elements[i] = original.elements[i];
    }
}
// v2 = v1; //v2operator=(v1)
// v = v

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &original)
{
    if (this != &original)
    {
#ifdef debug
        std::cout << "Assign: " << (long)&original << "->" << (long)this << std::endl;
#endif            

        delete []elements;
        nCapacity = original.nCapacity;
        elements = new T[nCapacity];
        for (size_t i = 0; i < nCapacity; i++)
        {
            elements[i] = original.elements[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other)
{
    Vector<T> result (*this);
    //!!!много неефективно
    for (size_t i = 0; i < other.nCapacity; i++)
    {
        result.push (other.elements[i]);
    }
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T> &other)
{
    for (size_t i = 0; i < other.nCapacity; i++)
    {
        push(other.elements[i]);
    }
    return *this;
}

template <typename T>
void Vector<T>::push(T x)
{
    //приемаме че масивът сочен от 
    //elemennts е инициализиран и има вместимост точно
    //nCapacity елемента (int elements[nCapacity]);

    T* newElements = new T [nCapacity +1];
    for (size_t i = 0; i < nCapacity; i++)
    {
        newElements[i] = elements[i];
    }
    newElements[nCapacity] = x;

    delete []elements;
    elements = newElements;
    nCapacity++;
}

template <typename T>
void Vector<T>::print()
{
    std::cout << "[";
    
    for (size_t i = 0; i < nCapacity; i++)
    {
        std::cout<< elements[i];
        if (i < nCapacity-1)
        {
            std::cout << "";
        }
    }
    std::cout << "]\n";
}

template <typename T>
void Vector<T>::change(size_t index, T newValue)
{
    assert (index >= 0 && index < nCapacity);
    elements[index] = newValue;
}

template <typename T>
Vector<T>::~Vector()
{
#ifdef debug
    std::cout << "Destroy: " << (long)this << std::endl;
#endif
    delete elements;
}

template <typename T>
T& Vector<T>::operator[](size_t i)
{
    assert (i < nCapacity);
    return elements[i];
}

template <typename T>
T Vector<T>::operator[](size_t i) const
{
    assert(i < nCapacity);
    return elements[i];
}

template <typename T>
size_t Vector<T>::size() const
{
    return nCapacity;
}


template <typename T>
Vector<T> map(const Vector<T> &original, T (*f)(T))
{
    Vector<T> result;
    for (size_t i = 0; i < original.size(); i++)
    {
        resultpush(f (original[i]));
    }
    return result;
}

template <typename T>
Vector<T> filter(const Vector<T> &original, pred<T> p)
{
    Vector<T> result;
    for (size_t i = 0; i < original.size(); i++)
    {
        if (p(original[i]))
        {
            resultpush (original[i]);
        }
    }
    return result;   
}

