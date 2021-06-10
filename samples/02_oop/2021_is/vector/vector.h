#pragma once

#include <iostream>

template <typename T>
class Vector
{
    public:
    Vector();
    Vector(const Vector<T>& other);

    void push_back(const T& data);
    
    T getElement(size_t i) const;
    void setElement(size_t i, const T& x);

    T& operator[](size_t i); 
    T operator[](size_t i) const; 

    operator int();

    Vector<T>& operator=(const Vector<T>& other);

    template <typename E>
    friend std::ostream& operator<<(std::ostream&,Vector<E>);

    size_t length() const;

    ~Vector();

    private:
    T *contents;
    size_t size;


};

template <typename T>
std::ostream& operator<<(std::ostream&,Vector<T>);

