#include <iostream>
#include <cstring>
#include <fstream>

template <typename T>
using BinOp = T(*)(T,T);

template <typename T>
class DynArrayIterator
{
    public:

    DynArrayIterator(unsigned init, T* _arr);
    
    T operator*() const;
    DynArrayIterator& operator++();
    bool operator!=(const DynArrayIterator<T>&);

    private:
    unsigned current;
    T* arr;
};


template <typename T>
class DynArray   //DynArray<int>, DynArray<char>
{
    public:

    using value_type = T;

    DynArray();
    DynArray(const DynArray<T>& original);
    DynArray (const char *original); 
    DynArray(T singleton);

    DynArrayIterator<T> begin() const;
    DynArrayIterator<T> end() const;

    
    void print(/*DynArray *this*/);

    /* намалява броя на елементите на масив до число n*/
    // приемаме, че a.size > n */
    void trim(unsigned n);

    DynArray<T>& insert(T x);

    DynArray<T>& input();

    DynArray<T>& operator=(const DynArray<T>& original);

    DynArray<T>& operator+=(DynArray<T> a2);

    DynArray<T> operator+(DynArray<T> a2);

    T& operator[](unsigned index);

    unsigned lenght() const;

    ~DynArray();

    //агрегиране на елементите на масив чрез двуместна операция
    //(събиране, умножеснир и др.)
    T reduce(BinOp<T> op, T null_val);

    private:

    T *arr;
    unsigned size;

    void copy(const DynArray<T>& original);
};
