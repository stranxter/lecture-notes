#pragma once

#include <iostream>
#include <fstream>

struct DynaArrayOutOfMemoeryExceptioin
{
    unsigned int elementsBeforeDeath;
};

template <typename T>
class DynArray
{
    public:

    class Iterator
    {
        public:

        Iterator(unsigned int, T*);

        T& operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator&) const;

        private:
        unsigned int i;
        T *arr;
    };

    Iterator begin();
    Iterator end();


    int getSize() const;
    void setSize(unsigned int newSize);
    DynArray();
    DynArray(int i);
    DynArray(int ia[], int size);
    DynArray(const DynArray<T>& other);

    DynArray<T>& operator=(const DynArray<T>& other);
    void push_back(const T& x);
    DynArray<T> operator+(const DynArray<T>& b) const;  
    DynArray<T>& operator+=(const T& x);
    DynArray<T>& operator+=(const DynArray<T>& b);
    bool operator!=(const DynArray<T>& b) const;
    bool operator==(const DynArray<T>& b) const;
    T operator[](unsigned int i) const;
    T& operator[](unsigned int i);

    ~DynArray();

    using value_type = T;

    private:
    T *arr;
    unsigned int size;

    void copy(const DynArray<T>& other);
    void init();
    void clear();


};

template<typename T>
std::ostream& operator<<(std::ostream& out,const DynArray<T>& arr);
