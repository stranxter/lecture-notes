#ifndef __BTREE_H_
#define __BTREE_H_

#include <iostream>

template <class T>
struct Node
{
  T data;
  Node<T> *left, *right;
  Node (const T&, Node<T>*, Node<T>*);
};

template <class T>
class BTree
{
public:
  BTree ();
  BTree (const BTree<T>&);

  void insert (const T&,const char*);
  void printToDotty (std::ostream&);

private:
  Node<T> *root;

  void insertHelper (const T&,const char*,Node<T>*&);
  void printHelper (std::ostream&,Node<T>*);

  Node<T>* copy (Node<T>*otherCurrent);

};


#endif
