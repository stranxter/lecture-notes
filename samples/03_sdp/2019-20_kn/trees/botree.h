#ifndef __BOTREE_H
#define __BOTREE_H

#include "bintree.h"

template <class T>
class BOTree : protected BinTree<T>
{
    public:
    BOTree ();
    BOTree (const BOTree&);
    BOTree (BOTree&&);

    BOTree& insert (const T&);
    BOTree& remove (const T&);

    void dottyPrint (std::ostream&);

    private:
    void insertHelper (const T&, BinTreeNode<T>*&);
    void removeHelper (const T&, BinTreeNode<T>*&);

    BinTreeNode<T>*& minNode (BinTreeNode<T>*&);

};

#endif