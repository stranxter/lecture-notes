#pragma once

#include <iostream>

template <typename T>
class DynArray
{
    public:

    T *arr;
    size_t crr_size;
    using value_type = T;

    T operator[](int i)
    {
        return arr[i];
    }

    int size()
    {
        return this->crr_size;
    }

    DynArray() //конструктор
    {
        arr = new T[0];
        crr_size = 0;

        //std::cout << "I AM BORN!n";
    }

    DynArray(T x) //конструктор
    {
        arr = new T[1];
        crr_size = 1;
        arr[0] = x;
    }

    void copy(const DynArray& other)
    {
        this->crr_size = other.crr_size;

        this->arr = new T[this->crr_size];

        for(int i = 0; i < this->crr_size; ++i)
        {
            this->arr[i] = other.arr[i];
        }
    }

    
    DynArray(const DynArray& other)
    {
        //std::cout << "COPY CONSTRUCTOR\n";          
        copy(other);
    }
    
    DynArray<T>& operator=(const DynArray& other)
    {
        //a=b | &a->this, b->other

        if(this != &other)
        {
            delete arr;
            copy(other);
        }

        //c = (a = b)
        return *this;
    }

    DynArray& operator+=(const T& x)
    {
        //arr[size] = x;
        //arr------>[1] [3] [1] [5] +[x]

        T *newArr = new T[crr_size+1];
        //newArr --------> [?] [?] [?] [?] [?]

        for(int i = 0; i < crr_size; ++i)
        {
            newArr[i] = arr[i];
        }
        //newArr --------> [1] [3] [1] [5] [?]

        newArr[crr_size] = x;
        //newArr --------> [1] [3] [1] [5] [x]

        //arr---------> [1] [3] [1] [5]
        //newArr -----> [1] [3] [1] [5] [x]

        delete arr;
        //arr---------> ~~~~~~~~~~~~~~~~~~~~~~~~
        //newArr -----> [1] [3] [1] [5] [x]
        
        arr = newArr;
        //arr------\    ~~~~~~~~~~~~~~~~~~~~~~~~~~
        //newArr -----> [1] [3] [1] [5] [x]

        ++crr_size;

        return *this;
    }

    DynArray operator+(const DynArray& other) const
    {
        DynArray result;
        result.init();

        for(int i = 0; i < this->crr_size; ++i)
        {
            result += this->arr[i];
        }

        for(int i = 0; i < other.crr_size; ++i)
        {
            result += other.arr[i];
        }

        return result;

    }

    bool operator==(const DynArray& other)
    {
        if (this->crr_size != other.crr_size)
            return false;

        for(int i = 0; i < this->crr_size; ++i)
        {
            if(this->arr[i] != other.arr[i])
            {
                return false;
            } 
        }

        return true;
    }

    ~DynArray()
    {
        //std::cout << "DESTRUCTOR!\n";
        delete arr;
    }

};

template<typename T>
std::ostream& operator<<(std::ostream& out, const DynArray<T>& da)
{
    out << "{";
    for (int i = 0; i < da.crr_size; ++i)
    {
        std::cout << da.arr[i] << " ";
    }
    out << "}";

    return out;
}

void printSize(DynArray<int> arr)
{
    std::cout << "size = " << arr.crr_size;
    arr += 30;
    std::cout << arr;
}


DynArray<int> createSuperArray()
{
    DynArray<int> superArray;
    superArray += 0; superArray += 0; superArray += 0;

    return superArray;
}

