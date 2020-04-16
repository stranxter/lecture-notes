#pragma once

#include <cstdlib>
#include <vector>

template <class T>
class LList
{
    public:

    LList ();
    void push(const T& x); 
    void pop();
    void push_back(const T& x);

    size_t size() const; 
    T& operator[](size_t i);
    T operator[](size_t i) const;

    void insertAfter(size_t i, const T& x);
    void deleteAfter(size_t i);

    bool operator==(const std::vector<T> &v) const;

    private:
        struct box
        {
            T data;
            box *next;
        };
        box *first, *last;
        box* at (size_t pos) const;
};