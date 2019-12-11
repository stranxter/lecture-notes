#ifndef __BOTREE_H
#define __BOTREE_H

#include "bintree.h"
#include <stack>

const int TYPE_PRINT = 0;
const int TYPE_TRAVERSE = 1;


template <class T>
class BOTree : protected BinTree<T>
{

    public:

    class Iterator
    {
        struct WaitingOperation
        {
            int type;
            BinTreeNode<T> *node;    
            bool operator == (const typename BOTree<T>::Iterator::WaitingOperation&) const;
        };    
        public:
        Iterator (BinTreeNode<T>*);
        T& operator * ();
        Iterator& operator ++();
        bool operator != (const Iterator&) const;
        bool operator == (const Iterator&) const;

        private:
            std::stack<WaitingOperation> s;   
            void windstack ();         
    };


    BOTree ();
    BOTree (const BOTree&);
    BOTree (BOTree&&);

    BOTree& insert (const T&);
    BOTree& remove (const T&);

    void dottyPrint (std::ostream&);
    void printTree (std::ostream&);

    BOTree<T>::Iterator begin ();
    BOTree<T>::Iterator end ();

    private:
    void insertHelper (const T&, BinTreeNode<T>*&);
    void removeHelper (const T&, BinTreeNode<T>*&);

    BinTreeNode<T>*& minNode (BinTreeNode<T>*&);

};

#endif