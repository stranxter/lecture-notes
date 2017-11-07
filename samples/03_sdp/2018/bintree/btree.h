#ifndef __BTREE_H
#define __BTREE_H

#include <iostream>
#include <string>

template <class T>
struct TreeNode
{
  TreeNode (const T& data, TreeNode<T> *_left, TreeNode<T> *_right);
  TreeNode<T> *left, *right;
  T data;

  int getId ();

private:
  static int maxid;
  int id;
};


template <class T>
class BTree
{
public:
  BTree();
  BTree(const T, const BTree<T>&, const BTree<T>&);
  BTree (const BTree<T>&);

  BTree<T>& operator = (const BTree<T>&);

  bool operator == (const BTree<T>&) const;

  friend std::ostream& operator << (std::ostream&,const BTree<T>&);

  bool insertElement (std::string, const T&);
  void insertBOT (const T&);
  void deleteBOT (const T&);

  void fillGaps (const T&, unsigned int);

  TreeNode<T>* removeFromSubtree (const T&, TreeNode<T> *);
  void removeFromSubtreeProc (const T&, TreeNode<T> *&);


  bool member (const T& x) const;

  void read (std::istream&);
  void printDotty (std::ostream&);

  ~BTree ();

private:
  TreeNode<T> *root;

  void fillGaps (const T&, TreeNode<T> *&, unsigned int);

  bool insertElement (std::string, const T&, TreeNode<T>*&);
  void insertBOT (const T&, TreeNode<T>*&);
  void del (TreeNode<T>*);
  T& findmin (TreeNode<T> *);

  bool member (const T& x, const TreeNode<T> *) const;
  TreeNode<T>* readFromStream (std::istream &);

  TreeNode<T>* copyFrom (const TreeNode<T> *);

  bool compare (const TreeNode<T> *t1, const TreeNode<T> *t2) const;

};
template <class T>
std::ostream& operator << (std::ostream&,const BTree<T>&);

#endif
