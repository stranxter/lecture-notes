#include <iostream>
#include <cstring>
#include <fstream>

#include "dynarrayc.h"

template <typename T>
DynArray<T>::DynArray()
{
    arr = nullptr;
    size = 0;
}

template <typename T>
DynArray<T>::DynArray(const DynArray<T>& original)
{
    copy(original);
}

template <typename T>
DynArray<T>::DynArray (const char *original)
{
    size = strlen(original);
    arr = new T[size];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = original[i];
    }
}

template <typename T>
DynArray<T>::DynArray(T singleton)
{
    arr = new T[1];
    arr[0] = singleton;
    size = 1;
}

template <typename T>
void DynArray<T>::print(/*DynArray *this*/)
{
    for(int i = 0; i < this->size; ++i)
    {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void DynArray<T>::trim(unsigned n)
{   
    if(n >= size)
        return;
    
    T* new_array = new T[n];

    for(int i = 0; i < n; ++i)
    {
        new_array[i] = arr[i];
    }
    delete []arr;
    arr = new_array;
    size = n;
}

template <typename T>
DynArray<T>& DynArray<T>::insert(T x)
{
    T *new_array = new T[this->size+1];
    for (int i = 0; i < this->size; ++i)
    {
        new_array[i] = this->arr[i];
    }
    new_array[this->size] = x;
    ++this->size;
    
    delete []arr;
    arr = new_array;
    return *this;
}

template <typename T>
DynArray<T>& DynArray<T>::input()
{
    T x;
    do
    {
        std::cout << "Моля, въведете елемент:";
        std::cin >> x;
        std::cin.ignore();

        this->insert(x);

        std::cout << "Ще въвеждате ли още елементи?";
    } while (std::cin.get()=='y');

    return *this;
}

template <typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& original)
{
    if(this != &original)
    {
        delete []this->arr;
        copy(original);            
    }
    return *this;
}

template <typename T>
DynArray<T>& DynArray<T>::operator+=(DynArray<T> a2)
{
    *this = (*this + a2);
    return *this;
}

template <typename T>
DynArray<T> DynArray<T>::operator+(DynArray<T> a2)
{
    DynArray<T> result;// = {new T[this->size + a2.size], //result.arr
                    //this->size + a2.size}; //result.size 
    result.arr = new T[this->size + a2.size];
    result.size = this->size + a2.size;

    for(int i = 0; i < this->size; ++i)
    {
        result.arr[i] = this->arr[i];
    }

    for(int i = 0; i < a2.size; ++i)
    {
        result.arr[this->size+i] = a2.arr[i];
    }
        
    return result;  //(a+b)
}

template <typename T>
T& DynArray<T>::operator[](unsigned index)
{
    return arr[index];
}

template <typename T>
unsigned DynArray<T>::lenght() const
{
    return size;
}

template <typename T>
DynArray<T>::~DynArray()
{
    delete []arr;        
}

template <typename T>
T DynArray<T>::reduce(BinOp<T> op, T null_val)
{
    T result = null_val;
    for (int i = 0; i < this->size; ++i)
    {
        result = op(result,this->arr[i]);
    }

    return result;
}

template <typename T>
void DynArray<T>::copy(const DynArray<T>& original)
{
    this->arr = new T[original.size];
    this->size = original.size;

    for (int i = 0; i < size; ++i)
    {
        this->arr[i] = original.arr[i];
    }
}

template <typename T>
void operator<<(std::ostream& out, const DynArray<T>&d)
{
    out << "{";
    for(int i = 0; i < d.size; ++i)
    {
        out << d.arr[i] << " ";
    }
    out << std::endl;
    out << "}";

}


template <typename T>
DynArrayIterator<T>::DynArrayIterator(unsigned init, T* _arr):current(init),arr(_arr){};

template <typename T>
T DynArrayIterator<T>::operator*() const
{
    return arr[current];
}

template <typename T>
DynArrayIterator<T>& DynArrayIterator<T>::operator++()
{
    ++current;
    return *this;
}

template <typename T>
bool DynArrayIterator<T>::operator!=(const DynArrayIterator<T> &other)
{
    return current != other.current || arr != other.arr;
}


template <typename T>
DynArrayIterator<T> DynArray<T>::begin() const
{
    return DynArrayIterator<T>(0,arr);
}

template <typename T>
DynArrayIterator<T> DynArray<T>::end() const
{
    return DynArrayIterator<T>(size,arr);
}
