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
