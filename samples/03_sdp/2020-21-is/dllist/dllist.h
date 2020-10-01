#ifndef __DLLLIST_H
#define __DLLLIST_H

#include <iostream>

template <class T>
class DLList
{
    public:

    DLList();
    DLList(const DLList<T>&);
    ~DLList();
    DLList<T>& operator = (const DLList<T>&);


    DLList<T> operator + (const T&) const;
    DLList<T>& operator += (const T&);

    void print();

    private:

    struct Box
    {
        T data;
        Box *next;
        Box *prev;
    };

    void copy(const DLList<T>&);
    void clear();

    Box *first;

    //временно
    template<class E> //Липсата на този ред създаваше проблема при свързването
                      //по време на лекции
    friend std::ostream& operator << (std::ostream&, const DLList<E>&);

};

template<class T>
std::ostream& operator << (std::ostream&,const DLList<T>&);

#include "dllist.cpp"

#endif