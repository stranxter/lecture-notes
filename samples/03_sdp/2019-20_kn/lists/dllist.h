#ifndef __DLLIST_H
#define __DLLIST_H
#include <cstdlib>

template <class T>
class DLList
{
    public:
    DLList ();
    DLList (const DLList&);
    ~DLList ();

    bool insertAt (size_t position, const T& element);
    T& operator [] (size_t index);
    T& fromBack (size_t index);
    bool member (const T&) const;
    size_t size () const;
    DLList<T>& operator= (const DLList<T>&);

    private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node (const T& _d, Node *n, Node *p):data(_d),next(n),prev(p){}
    };

    void copy (const DLList<T>&);
    void deleteall ();
    Node* locate (size_t index);

    Node *first, *last;
};


#endif