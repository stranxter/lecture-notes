#include "vector.h"


template <typename T>
Vector<T>::Vector()
{
    contents = nullptr;
    size = 0;
}

template <typename T>
void Vector<T>::add(const T& data)
{
    //contents: буфер в паметта, съдържащ size на брой числа,
    //вмъкнати до момента чрез add
    //size: броя на числа в буфера
    
    T *newContents = new T [size+1];

    for (size_t i = 0; i < size; ++i)
    {
        newContents[i] = contents[i];
    }

    newContents[size] = data;
    ++size;

    //не е нужно
    if (contents != nullptr)
    {
        delete []contents;
    }
    contents = newContents;
    
} 

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    contents = new T[other.size];
    size = other.size;

    for (size_t i = 0; i < size; ++i)
    {
        contents[i] = other.contents[i];
    }        
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{

    if (this != &other)
    {
        delete []contents;
        contents = new T[other.size];
        size = other.size;

        for (size_t i = 0; i < size; ++i)
        {
            contents[i] = other.contents[i];
        }        
    }
    return *this;
}


template <typename T>
std::ostream& operator<<(std::ostream &out, Vector<T> v)
{
    out << "{";
    for (size_t i = 0; i < v.size; ++i)
    {
        out << v.contents[i] << " ";
    }
    out << "}";
    return out;
}