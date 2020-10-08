#ifndef __DLLLIST_H
#define __DLLLIST_H

#include <iostream>
#include <exception>

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

    void reverse();

    bool empty();

    private:

    struct Box
    {
        T data;
        Box *next;
        Box *prev;
    };

    public:

    class Iterator
    {
        public:
        Iterator(Box*,DLList*);
        Iterator& operator++();
        Iterator& operator--();
        T& operator*();
        bool operator != (const Iterator& other);

        friend class DLList;

        private:
        Box *current;
        DLList *list;
    };

    private:

    void copy(const DLList<T>&);
    void clear();

    Box *first, *last;

    //временно
    template<class E> 
    friend std::ostream& operator << (std::ostream&, const DLList<E>&);

    public:

    Iterator begin();
    Iterator end();
    
    bool deleteAt(const Iterator&);


};

template<class T>
std::ostream& operator << (std::ostream&,const DLList<T>&);

#include "dllist.cpp"

#endif