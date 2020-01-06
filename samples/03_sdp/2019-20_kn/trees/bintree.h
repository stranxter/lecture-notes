#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
struct BinTreeNode
{
    T data;
    BinTreeNode *left, *right;

    BinTreeNode (const T&, BinTreeNode*, BinTreeNode*);
    BinTreeNode ();
};

template <class T>
class Position 
{

public:
   Position (BinTreeNode<T> *_root);

   Position<T> left () const;
   Position<T> right () const;
   T operator * () const;
   bool empty () const;

private:
    BinTreeNode<T> *root;
};

template <class T>
class BinTree
{

    public:
        BinTree ();
        BinTree (const T&);
        BinTree (const BinTree<T> &);
        BinTree (BinTree<T> &&);
        BinTree (const T&, const BinTree<T>&, const BinTree<T>&);
        BinTree (const T&, BinTree<T>&&, BinTree<T>&&);

        BinTree<T>& operator = (const BinTree<T>&);
        BinTree<T>& operator = (BinTree<T>&&);

        Position<T> rootPos () const;

        void addElement (const char*, const T&);

        void printTree (std::ostream&);
        void prettyPrint (std::ostream&);
        void dottyPrint (std::ostream&);

        bool member (const T& x) const;
        T reduce (T (*op)(const T&, const T&), const T& null_val);

        ~BinTree();

    protected:
        BinTreeNode<T> *root;

        void printTreeHelp (std::ostream&, BinTreeNode<T> *current);
        void prettyPrintHelp (std::ostream&, BinTreeNode<T> *current, int level);
        void dottyPrintHelp (std::ostream&, BinTreeNode<T> *current);

        bool memberHelp (const T& x, BinTreeNode<T> *current) const;
        T sumHelp (BinTreeNode<T> *current);
    
        T reduceHelp (T (*op)(const T&, const T&), const T& null_val, BinTreeNode<T> *current);

        BinTreeNode<T>* copyHelper (BinTreeNode<T> *current);

        void deleteHelper (BinTreeNode<T> *current);

};


#endif