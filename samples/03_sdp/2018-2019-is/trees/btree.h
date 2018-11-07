#ifndef __BTREE_H_
#define __BTREE_H_

#include <iostream>
#include <limits.h>

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

  BTree<T>& operator = (const BTree<T>&);

  bool operator == (const BTree<T>&);
  bool member (const T&);
  T sum ();
  int countLeaves ();

  void insert (const T&,const char*);
  void insertBOT (const T&);
  void printToDotty (std::ostream&);
  void printToHs (std::ostream&);
  void readFromHs (std::istream&);

  bool isBOT ();

  ~BTree ();

private:
  Node<T> *root;

  void insertHelper (const T&,const char*,Node<T>*&);
  void printHelper (std::ostream&,Node<T>*);

  Node<T>* copy (Node<T>*otherCurrent);
  void deleteSubtree (Node<T> *currentRoot);
  bool compareTrees (Node<T> *root1, Node<T> *root2);
  bool member (Node<T>*,const T&);
  T sum (Node<T>*);
  int countLeaves (Node<T>*);
  void printToHs (Node<T>*, std::ostream&);
  Node<T>* readFromHsHelper (std::istream&);

  bool isBOT (Node<T>*,const T&, const T&);
  void insertBOT (Node<T>*&,const T&);

};


#endif
