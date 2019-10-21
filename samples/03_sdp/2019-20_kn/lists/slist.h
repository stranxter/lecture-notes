#ifndef __SLIST_H
#define __SLIST_H

#include <cstdlib>

template <class T>
using comparator = bool (*) (const T&, const T&);

template <class T>
class SList
{
    public:
        SList(comparator<T> _comp);
        SList(const SList &);
        ~SList();

        void insertSorted(const T &element);
        T &operator[](size_t index);
        bool member(const T &) const;
        size_t size() const;
        SList<T> &operator=(const SList<T> &);

        void speedup();

    private:

        struct Node
        {
            T data;
            Node *next, *skip;
            Node (const T& _d, Node *n, Node *s);
        };

        Node *first;
        size_t count;
        comparator<T> comp;

        Node* locate(const T&) const;

        void deleteall ();
        void copy (const SList<T>&);

};


#endif