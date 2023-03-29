#pragma once

#include <cstdlib>
#include <functional>

template <typename T, typename U>
using Fn = std::function<U(const T&)>;   //fn: T -> U

template <typename T>
class Vector
{
    private:
        T *elements;
        size_t s;

    void copy(const T* arr, size_t s);

    public:

    Vector();
    Vector(const Vector<T> &other);
    Vector(const T arr[], size_t size);

    Vector<T>& operator=(const Vector<T> &other);
    bool operator==(const Vector<T> &other) const;
    bool operator!=(const Vector<T> &other) const;    

    Vector<T>& operator+=(const T&);
    Vector<T> operator+(const T&);

    Vector<T>& operator+=(const Vector<T>&);
    Vector<T> operator+(const Vector<T>&);

    size_t size() const;
    T& operator[](size_t index);

    template <typename U>
    Vector<U> map(Fn<T,U> f) const;

    template <typename U>
    U reduce(U null_val, std::function<U(U,T)>) const;

    ~Vector();
};

