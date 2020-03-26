#pragma once

template <class T>
class Vector
{
    private:
    T *data;
    size_t size;

    public:
    Vector ();
    Vector (const Vector<T>& v);
    void push_back (const T& x);
    void push (const T& x);
    Vector<T>& operator+= (const T& x);
    Vector<T> operator+ (const T& x) const;
    Vector<T>& operator+= (const Vector<T>& other);
    Vector<T> operator+ (const Vector<T>& other) const;
    T& operator[] (size_t i);
    T operator[] (size_t i) const;
    Vector<T>& operator= (const Vector<T>& v);
    size_t length () const;
    //operator ==
    //operator !=
    ~Vector();
};

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v);

