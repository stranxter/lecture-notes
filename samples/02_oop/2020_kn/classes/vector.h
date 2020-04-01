#ifndef __VECTOR_H
#define __VECTOR_H

#include <iostream>

template <class T>
class Vector
{
    
    private:
    T *data;
    size_t size;

    public:
    Vector ();
    Vector (const Vector<T>& other);
    template<class InitType>
    Vector (size_t initial_size, const InitType& init);
    Vector (size_t initial_size);
    void to_end (const T& x);
    void push (const T& x);
    Vector<T> operator + (const Vector<T> other) const;
    Vector<T> operator + (const T& x)  const;
    Vector<T>& operator += (const T& x);
    T& operator[] (size_t i);
    T operator[] (size_t i) const;
    Vector<T>& operator= (const Vector<T>& other);
    ~Vector ();
    size_t length () const;
    bool operator!= (const Vector<T>& other) const;
    bool operator== (const Vector<T>& other) const;

    private:
    void resize (size_t new_size);
};

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v);


#endif