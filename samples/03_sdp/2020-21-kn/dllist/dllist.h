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

    bool empty();

    private:
    
    struct box
    {
        T data;
        box *next, *prev;
    };

    public:

    class Iterator 
    {
        public:

        Iterator(box *_current, box *_first);

        T& operator *();
        Iterator& operator ++();
        Iterator& operator --();
        bool operator!= (const Iterator&);
        
        private:
        box *current;
        box *first;
    };   

    Iterator begin();
    Iterator last();
    Iterator end();

    private:

    box first;

    template<class E>
    friend std::ostream& operator<< (std::ostream&,const DLList<E>&);

    void copy(const DLList<T>&);
    void clear();

};

template<class T>
std::ostream& operator<< (std::ostream&,const DLList<T>&);

#include "dllist.cpp"

#endif