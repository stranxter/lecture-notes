#include "vector.h"


template <typename T>
void Vector<T>::copy(const T* arr, size_t size)
{
    s = size;
    elements = new T[s];
    for(int i = 0; i < s; ++i)
    {
        elements[i] = arr[i];
    }
}

template <typename T>
Vector<T>::Vector():s(0),elements(nullptr)
{
}
template <typename T>
Vector<T>::Vector(const Vector<T> &other)
{
    copy(other.elements,other.s);
}
template <typename T>
Vector<T>::Vector(const T arr[], size_t size)
{
    copy(arr,size);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other)
{
    if(this != &other)
    {
        if (elements != nullptr)
        {
            delete []elements;
        }
        copy(other.elements,other.s);
    }
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &other) const
{
    if(s != other.s)
    {
        return false;
    }

    for (int i = 0; i < s; ++i)
    {
        if(elements[i] != other.elements[i])
        {
            return false;
        }
    }

    return true;
}
template <typename T>
bool Vector<T>::operator!=(const Vector<T> &other) const  
{
    return !(*this == other);
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const T &x)
{
    //elements -> {.....} @ x

    T* newElements = new T[s+1];

    for (int i = 0; i < s; ++i)
    {
        newElements[i]=elements[i];
    }
    newElements[s] = x;
    ++s;

    delete []elements;
    elements = newElements;

    return *this;
}
template <typename T>
Vector<T> Vector<T>::operator+(const T &x)
{
    Vector<T> result(*this);
    result += x;
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T> &other)
{
    T *newElements = new T[this->size() + other.size()];
    for (int i = 0; i < size(); ++i)
    {
        newElements[i] = this->elements[i];
    }
    for (int i = 0; i < other.size(); ++i)
    {
        newElements[size()+i] = other.elements[i];
    }

    delete []elements;
    elements = newElements;
    s=this->size()+other.size();
    return *this;
}
template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other)
{
    Vector<int> result(*this);
    result += other;

    return result;
}
template <typename T>
size_t Vector<T>::size() const
{
    return s;
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    //  (u[2]) = 2;
    if (index >= size())
    {
        T *newElements = new T[index+1];
        for (int i = 0; i < size(); ++i)
        {
            newElements[i] = elements[i];
        }
        delete []elements;
        elements = newElements;
        s = index+1;
    }

    return elements[index];
}

template <typename T>
Vector<T>::~Vector()
{
    delete []elements;
}

template <typename T>
template <typename U>
Vector<U> Vector<T>::map(Fn<T,U> f) const
{
    Vector<U> result;
    for (int i = 0; i < size(); ++i)
    {
        result += f(elements[i]);
    }
    return result;
}

template <typename T>
template <typename U>
U Vector<T>::reduce(U null_val, std::function<U(U,T)> op) const
{
    U result = null_val;
    for (int i = 0; i < size(); ++i)
    {
        result = op(result,elements[i]);
    }
    return result;
}
