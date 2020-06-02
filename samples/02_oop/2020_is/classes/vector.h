#pragma once

template <class T>
class Vector
{
    private:
    T *data;
    size_t size;

    public:

    using value_type = T;

    Vector ();
    Vector (const Vector<T>& v);
    Vector (size_t initial_size);
    template <class InitType>
    Vector (size_t initial_size, const InitType& initValue);
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

    class Iterator
    {
        public:

        using value_type = T;

        Iterator(size_t pos, Vector &_vector);
        bool operator!=(const Iterator&it);
        Iterator& operator++();
        T& operator *();

        private:
        size_t index;
        Vector &vector;

    };

    Iterator begin();
    Iterator end();
};

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v);

