#ifndef __VECTOR_H
#define __VECTOR_H

template <typename T>
class Vector
{
  public:
    Vector();

    Vector(const Vector<T> &original);
    Vector<T> &operator=(const Vector<T> &original);
    Vector<T> operator+(const Vector<T> &other);
    Vector<T> &operator+=(const Vector<T> &other);
    void push(T x);
    void print();
    void change(size_t index, T newValue);
    ~Vector();
    T &operator[](size_t i);
    T operator[](size_t i) const;
    size_t size() const;

  private:
    T *elements;
    size_t nCapacity;
};

template <typename T>
Vector<T> map(const Vector<T> &original, T (*f)(T));

template <typename T>
using pred = bool (*)(T);

template <typename T>
Vector<T> filter(const Vector<T> &original, pred<T> p);

#endif