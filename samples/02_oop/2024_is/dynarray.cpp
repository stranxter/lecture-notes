#include <iostream>
#include <fstream>
#include <cmath>

#include "dynarray.h"


template <typename T>
DynArray<T>::Iterator::Iterator(unsigned int start, T* _arr):i(start),arr(_arr){}

template <typename T>
T& DynArray<T>::Iterator::operator*() const
{
    return arr[i];
}

template <typename T>
typename DynArray<T>::Iterator& DynArray<T>::Iterator::operator++()
{
    ++i;  
    return *this;
}

template <typename T>
bool DynArray<T>::Iterator::operator!=(const typename DynArray<T>::Iterator &other) const
{
    return i != other.i;
}


template <typename T>
typename DynArray<T>::Iterator DynArray<T>::begin()
{
    return DynArray<T>::Iterator(0,arr);
}
template <typename T>
typename DynArray<T>::Iterator DynArray<T>::end()
{
    return DynArray<T>::Iterator(size,arr); 
}

template <typename T>
int DynArray<T>::getSize() const
{
    return size;
}
template <typename T>
void DynArray<T>::setSize(unsigned int newSize)
{
    T* newArr = new T[newSize];    

    for(int i = 0; i < std::min(size,newSize); ++i)
    {
        newArr[i] = arr[i];
    }
    
    delete []arr;
    arr = newArr;
    size = newSize;
}

template <typename T>
DynArray<T>::DynArray()
{
    init();
}
template <typename T>
DynArray<T>::DynArray(int i)
{
    this->size = i;
    this->arr = new T[i];
}
template <typename T>
DynArray<T>::DynArray(int ia[], int size)
{
    this->size = size;
    this->arr = new T[size];
    for(int count=0; count <  size; ++count)
    {
        this->arr[count] = ia[count];
    }
}
template <typename T>
DynArray<T>::DynArray(const DynArray<T>& other)
{

    copy(other);
}

template <typename T>
void DynArray<T>::copy(const DynArray<T>& other)
{
    this->size = other.size;
    this->arr = new T[this->size];
    for(int count=0; count <  this->size; ++count)
    {
        this->arr[count] = other.arr[count];
    }    
}
template <typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <typename T>
void DynArray<T>::init()
{
    this->size = 0;
    this->arr = nullptr;    
}

template <typename T>
void DynArray<T>::push_back(const T& x)
{
    /*
        a:{
            arr -------------> [1] [2] [3]
            size: 3
        }
    */
T* tmp = new T[this->size+1];
    /*
        a:{
            arr -------------> [1] [2] [3]
            size: 3
        }
        tmp ----------------> [13134] [756] [12313] [464745]
    */
for(int i = 0; i < this->size; ++i)
{
    tmp[i] = this->arr[i];
}
    /*
        a:{
            arr -------------> [1] [2] [3]
            size: 3
        }
        tmp ----------------> [1] [2] [3] [464745]
    */
tmp[this->size] = x;
this->size++;
    /*
        a:{
            arr -------------> [1] [2] [3]
            size: 4
        }
        tmp ----------------> [1] [2] [3] [x]
    */
    delete []this->arr;
    this->arr = tmp;
    /*
        a:{
            arr --------\ ~~~~~~~~~~~~~~~~~~~
            size: 4      \
        }              |
        tmp ----------------> [1] [2] [3] [x]
    */
}

template <typename T>
DynArray<T> DynArray<T>::operator+(const DynArray<T>& b) const
{
    DynArray<T> result;
    result.init();
    (result += *this) += b;

    return result;
}
template <typename T>
DynArray<T>& DynArray<T>::operator+=(const T& x)
{
    push_back(x);
    return *this;
}

template <typename T>
DynArray<T>& DynArray<T>::operator+=(const DynArray<T>& b)
{
    /*
        a:{
            arr -------------> [1] [2] [3] [4] [5] [+1] [+2] [+3]
            size: 5
        }
        b:{
            arr -------------> [1] [2] [3]
            size: 3
        }
    */

    T* tmp = new T[this->size+b.size];
    for(int i = 0; i < this->size; ++i)
    {
        tmp[i] = this->arr[i];
    }
    for(int i = this->size; i < this->size+b.size; ++i)
    {
        tmp[i] = b.arr[i-this->size];
    }

    this->size = this->size + b.size;
    delete []this->arr;
    this->arr = tmp;

    return *this;
}

template <typename T>
bool DynArray<T>::operator!=(const DynArray<T>& b) const
{
    return !(*this == b);
}
template <typename T>
bool DynArray<T>::operator==(const DynArray<T>& b) const
{
    if(this->size != b.size)
    {
        return false;
    }
    for(int i = 0; i < this->size; ++i)
    {
        if(this->arr[i] != b.arr[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
T DynArray<T>::operator[](unsigned int i) const
{

    return this->arr[i];
}
template <typename T>
T& DynArray<T>::operator[](unsigned int i)
{
    return this->arr[i];
}

template <typename T>
void DynArray<T>::clear()
{
    delete arr;
}
template <typename T>
DynArray<T>::~DynArray()
{
    clear();
}

template<typename T>
std::ostream& operator<<(std::ostream& out,const DynArray<T>& arr)
{   //DynArray<T>* this;
    out << "{";
    for(int i = 0; i < arr.getSize(); ++i)
    {
        out << arr[i] << " ";
    }
    out << "}";

    return out;
}

/*

void set0(DynArray<int>& dai)
{
    for(int i = 0; i < dai.getSize(); ++i)
    {
        dai[i]= 0;
    }
}

DynArray<int> makeZeros(unsigned int n)
{
    DynArray<int> result(n);
    for(int i = 0; i < n; ++i)
    {
        result[i] = 0;
    }
    return result;
}

*/