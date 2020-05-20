#pragma once

#include <cstdlib>

template <class T>
class LList
{
    public:

    using element_type = T;

    LList ();

    void push(const T& x);
    void pop();

    size_t size() const;
    T& operator[](size_t i);
    T operator[](size_t i) const;

    void insertAfter (const T& x, size_t pos);
    void deleteAfter (size_t pos);

    void push_back(const T& x);


  private:

    struct box
    {
        box(const T& _data, box *_next):data(_data),next(_next){}
        T data;
        box *next;
    };

    box* at (size_t pos);

    box *first, *last;  
    //size_t s;

  public:

    using value_type = T;

    class Iterator
    {
        public:
        Iterator (box *element);
        bool operator != (const Iterator& it);
        Iterator& operator ++();
        T& operator *();

        private:
        box *current;
    };

    Iterator begin();
    Iterator end();


};
