#pragma once

#include <iostream>

template <typename T>
class Vector
{
    //...
    public:

    Vector();
    Vector(const Vector<T>& other);

    void add(const T& data);

    Vector<T>& operator=(const Vector<T>& other);


    private:
    T *contents;
    size_t size;


};

template <typename T>
std::ostream& operator<<(std::ostream&,Vector<T>);

