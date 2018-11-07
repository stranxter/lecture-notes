#include "btree.h"
#include <cassert>

template <class T>
Node<T>::Node (const T &_data, Node<T> *_left, Node<T>*_right)
    :data(_data),left(_left),right(_right)
{}

template <class T>
BTree<T>::BTree ():root(nullptr)
{}

template <class T>
BTree<T>::BTree (const BTree<T> &other)
{
  root = copy (other.root);
}

template <class T>
Node<T>* BTree<T>::copy (Node<T>*otherCurrent)
{
  if (otherCurrent == nullptr)
  {
    return nullptr;
  }
  return new Node<T> (otherCurrent->data,
                      copy (otherCurrent->left),
                      copy (otherCurrent->right));
}

template <class T>
void BTree<T>::insertHelper (const T &x, const char *trace, Node<T> *&current)
{
  if (current == nullptr)
  {
    assert (trace[0]==0);
    current = new Node<T> (x,nullptr,nullptr);
    return;
  }
  assert (trace[0] == 'L' || trace[0] == 'R');
  if (trace[0]=='L')
  {
    insertHelper (x,trace+1,current->left);
  } else {
    insertHelper (x,trace+1,current->right);
  }
}

template <class T>
void BTree<T>::insert (const T &x, const char *trace)
{
  insertHelper (x,trace,root);
  /*
  Node<T> **current = &root;
  while (trace[0] != 0)
  {
    assert (trace[0] == 'L' || trace[0] == 'R');
    assert (*current != nullptr);

    if (trace[0] == 'L')
    {
      current = &((*current)->left);
    }else{
      current = &((*current)->right);
    }
    trace++;
  }
  //в този момент какво имаме?
  //Какво е current: Указател към указателя към пддървото
  //Какво е trace: Кое поддърво на current ще почупим

  assert (*current == nullptr);
  *current=new Node<T>(x,nullptr,nullptr);
  */
}

template <class T>
void BTree<T>::printToDotty (std::ostream &out)
{
    out << "digraph {";

    printHelper (out, root);

    out << "}";
}

template <class T>
void BTree<T>::printHelper (std::ostream &out,Node<T> *current)
{
  if (current == nullptr)
  {
    return;
  }

  out << (long)current
      << "[label=\""
      << current->data
      << "\"];\n";

  if (current->left != nullptr)
  {
      out << (long)current
          << "->"
          << (long)current->left
          << "[color=\"red\"];" << std::endl;
  }
  if (current->right != nullptr)
  {
      out << (long)current
          << "->"
          << (long)current->right
          << "[color=\"green\"];" << std::endl;
  }

  printHelper (out, current->left);
  printHelper (out, current->right);
}

template <class T>
void BTree<T>::deleteSubtree (Node<T> *currentRoot)
{
  if (currentRoot == nullptr)
  {
    return;
  }

  deleteSubtree (currentRoot->left);
  deleteSubtree (currentRoot->right);
  delete currentRoot;

}

template <class T>
BTree<T>::~BTree ()
{
  deleteSubtree (root);
}

template <class T>
BTree<T>& BTree<T>::operator = (const BTree<T> &other)
{
  if (&other != this)
  {
    deleteSubtree (root);
    root = copy (other.root);
  }
  return *this;
}

template <class T>
bool BTree<T>::operator == (const BTree<T> &other)
{
  return compareTrees (root,other.root);
}

template <class T>
bool BTree<T>::compareTrees (Node<T> *root1, Node<T> *root2)
{
  if (root1 == nullptr || root2 == nullptr)
  {
    return root1 == root2;
  }

  return root1->data == root2->data &&
         compareTrees (root1->left, root2->left) &&
         compareTrees (root1->right, root2->right);

}

template <class T>
bool BTree<T>::member (Node<T> *root, const T&x)
{
  if (root == nullptr)
  {
    return false;
  }

  return
      x == root->data ||
      member (root->left,x) ||
      member (root->right,x);
}

template <class T>
bool BTree<T>::member (const T&x)
{
  return member (root,x);
}


template <class T>
T BTree<T>::sum (Node<T> *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  return
      root->data +
      sum (root->left) +
      sum (root->right);
}

template <class T>
T BTree<T>::sum ()
{
  return sum (root);
}

template <class T>
int BTree<T>::countLeaves (Node<T> *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  if (root->left == nullptr && root->right == nullptr)
  {
    return 1;
  }

  return
      countLeaves (root->left) +
      countLeaves (root->right);
}

template <class T>
int BTree<T>::countLeaves ()
{
  return countLeaves (root);
}

template <class T>
void BTree<T>::printToHs (Node<T> *root, std::ostream &out)
{
  if (root == nullptr)
  {
    out << "Empty ";
    return;
  }
  out << "Node " << root->data << " ";
  printToHs (root->left, out);
  printToHs (root->right, out);

}

template <class T>
void BTree<T>::printToHs (std::ostream &out)
{
  printToHs (root, out);
}

template <class T>
Node<T>* BTree<T>::readFromHsHelper (std::istream &in)
{
  std::string nodeType;
  in >> nodeType;

  if (nodeType == "Empty")
  {
    return nullptr;
  }

  assert (nodeType == "Node");

  T rootData;
  in >> rootData;

  return new Node<T> (rootData,
                      readFromHsHelper (in),
                      readFromHsHelper (in));
}

template <class T>
void BTree<T>::readFromHs (std::istream &in)
{
  deleteSubtree (root);
  root = readFromHsHelper (in);
}

template <class T>
bool BTree<T>::isBOT (Node<T> *root, const T &min, const T &max)
{
  if (root == nullptr)
  {
    return true;
  }

  return root->data >= min &&
         root->data < max &&
         isBOT (root->left,min,root->data) &&
         isBOT (root->right,root->data, max);

}

template <class T>
bool BTree<T>::isBOT ()
{
  return isBOT (root,INT_MIN,INT_MAX);
}

template <class T>
void BTree<T>::insertBOT (Node<T> *&root,const T &x)
{
  if (root == nullptr)
  {
    root = new Node<T> (x,nullptr,nullptr);
    return;
  }

  if (x < root->data)
  {
    insertBOT (root->left,x);
  } else {
    insertBOT (root->right,x);
  }
}

template <class T>
void BTree<T>::insertBOT (const T &x)
{
  insertBOT (root,x);
}
