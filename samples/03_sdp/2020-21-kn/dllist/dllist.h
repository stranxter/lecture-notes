#ifndef __DLLIST_H
#define __DLLIST_H

#include <iostream>

template <class T>
class DLList
{

    public:
    DLList();
    DLList(const DLList<T>&);
    ~DLList();
    DLList<T>& operator= (const DLList<T>&);

    DLList<T> operator+ (const T&) const;
    DLList<T>& operator+= (const T&);

    private:
    struct box
    {
        T data;
        box *next, *prev;
    };

    box *first;

    template<class E>
    friend std::ostream& operator<< (std::ostream&,const DLList<E>&);

    void copy(const DLList<T>&);
    void clear();

};

template<class T>
std::ostream& operator<< (std::ostream&,const DLList<T>&);

#include "dllist.cpp"

#endif