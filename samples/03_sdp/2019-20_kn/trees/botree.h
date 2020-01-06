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

    struct TreeTraverseStack
    {
        struct WaitingOperation
        {
            int type;
            BinTreeNode<T> *node;    
            bool operator == (const WaitingOperation&) const;
        };
        
        BinTreeNode<T> *getTop () const;
        void next ();
        void init (BinTreeNode<T> *);
        bool operator == (const TreeTraverseStack&) const;
        
        std::stack<WaitingOperation> s;   
        void windstack ();          
    };

    class Iterator
    {
        public:
        Iterator (BinTreeNode<T>*);
        T& operator * ();
        Iterator& operator ++();
        bool operator != (const Iterator&) const;
        bool operator == (const Iterator&) const;

        private:
            TreeTraverseStack stack;
    };

    class ConstIterator
    {
        public:
        ConstIterator (BinTreeNode<T>*);
        T operator * () const;
        ConstIterator& operator ++();
        bool operator != (const ConstIterator&) const;
        bool operator == (const ConstIterator&) const;

        private:
            TreeTraverseStack stack;
    };


    BOTree ();
    BOTree (const BOTree&);
    BOTree (BOTree&&);

    BOTree& insert (const T&);
    BOTree& remove (const T&);

    bool member (const T&) const;
    T& findormake (const T&);

    void dottyPrint (std::ostream&);
    void printTree (std::ostream&);

    BOTree<T>::Iterator begin ();
    BOTree<T>::Iterator end ();
    BOTree<T>::ConstIterator begin () const;
    BOTree<T>::ConstIterator end () const;

    private:
    void insertHelper (const T&, BinTreeNode<T>*&);
    void removeHelper (const T&, BinTreeNode<T>*&);
    bool memberHelper (const T&, BinTreeNode<T>*) const;
    T& findormakeHelper (const T&, BinTreeNode<T>*&);

    BinTreeNode<T>*& minNode (BinTreeNode<T>*&);

};

#endif