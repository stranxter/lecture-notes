#include "btree.h"
#include <iostream>
#include <cassert>

template <class T>
TreeNode<T>::TreeNode (const T& _data,
                       TreeNode<T> *_left,
                       TreeNode<T> *_right):data(_data),
                                            left(_left),
                                            right(_right)
{
  id = maxid;
  maxid++;
}

template <class T>
int TreeNode<T>::getId ()
{
  return id;
}

template <class T>
int TreeNode<T>::maxid = 0;


template <class T>
BTree<T>::BTree():root(nullptr)
{

}

template <class T>
BTree<T>::BTree(const T data, const BTree<T> &lt, const BTree<T> &rt)
{
  root = new TreeNode<T> (data,copyFrom(lt.root),copyFrom(rt.root));

}

template <class T>
void printNodesLISP (std::ostream& out, TreeNode<T> *root)
{
  if (root == nullptr)
  {
    out << "()";
    return;
  }

  out << "( " << root->data << " ";
  printNodesLISP (out, root->left);
  out << " ";
  printNodesLISP (out, root->right);
  out << " )";
}

template <class T>
void printNodesDotty (std::ostream& out, TreeNode<T> *root)
{
  if (root == nullptr)
  {
    return;
  }

  out << root->getId()
      << "[label=\""
      << root->data
      << "\"];"
      << std::endl;

  if (root->left != nullptr)
  {
    out << root->getId()
        << "->"
        << root->left->getId()
        << "[color = \"red\"]"
        << ";"
        << std::endl;
  }

  if (root->right != nullptr)
  {
    out << root->getId()
        << "->"
        << root->right->getId()
        << ";"
        << std::endl;
  }
  printNodesDotty (out, root->left);
  printNodesDotty (out, root->right);
}



std::ostream& operator << (std::ostream &out,const BTree<int> &t)
{
/*  out << "digraph G {" << std::endl;
  printNodesDotty (out, t.root);
  out << "}" << std::endl;*/

  printNodesLISP (out,t.root);

  return out;
}

template <class T>
bool BTree<T>::insertElement (std::string trace, const T& x, TreeNode<T> *&crr)
{
  if (trace == "" && crr == nullptr)
  {
    crr = new TreeNode<T> (x,nullptr,nullptr);
    return true;
  }
  if (trace != "" && crr == nullptr)
  {
    return false;
  }
  //=> trace != "" && current != nullptr
  if (trace[0] == 'L')
  {
    trace.erase (trace.begin());
    return insertElement (trace,x,crr->left);
  }
  if (trace[0] == 'R')
  {
    trace.erase (trace.begin());
    return insertElement (trace,x,crr->right);
  }
  return false;
}


template <class T>
bool BTree<T>::insertElement (std::string trace, const T& x)
{
  return insertElement (trace, x, root);
}

template <class T>
void BTree<T>::insertBOT (const T &x, TreeNode<T> *&crr)
{
  if (crr == nullptr)
  {
    crr = new TreeNode<T> (x,nullptr,nullptr);
    return;
  }

  if (x < crr->data){
    insertBOT (x,crr->left);
    return;
  }

  insertBOT (x,crr->right);


}

template <class T>
void BTree<T>::insertBOT (const T& x)
{
  insertBOT (x, root);
}

template <class T>
bool BTree<T>::member (const T& y) const
{
  return member (y, root);
}


template <class T>
bool BTree<T>::member (const T& y, const TreeNode<T> *crr) const
{
  if (crr == nullptr)
  {
      return false;
  }

  return crr->data == y ||
         member (y,crr->left) ||
         member (y,crr->right);
}


template <class T>
void BTree<T>::read (std::istream &in)
{
  //приемаме, че дървото е празно
  root = readFromStream (in);
}


template <class T>
TreeNode<T>* BTree<T>::readFromStream (std::istream &in)
{ //()..............
  //( 7 ( 30 () ( 12 ( 90 () () ) () ) ) ( 5 ( 50 () () ) () ) )

  char nextChar;
  nextChar = in.get();
  assert (nextChar == '(');

  nextChar = in.get();
  assert (nextChar == ' ' || nextChar == ')');

  if (nextChar == ')')
  {
    return nullptr;
  }
  //уверени сме, че в потока следват следните неща:
  //1. СТОЙНОСТ НА КОРЕНА. ПРИЕМАМЕ, ЧЕ ОПЕРАТОР >>T КОРЕКТНО ЩЕ Я ИЗЧЕТЕ

  T rootValue;
  in >> rootValue;

  //2. интервал

  nextChar = in.get();
  assert (nextChar == ' ');

  //3. ЛЯВО ПОДДЪРВО

  TreeNode<T> *leftSubTree;
  leftSubTree = readFromStream (in);

  //4. интервал

  nextChar = in.get();
  assert (nextChar == ' ');

  //5. ДЯСНО ПОДДЪРВО

  TreeNode<T> *rightSubTree;
  rightSubTree = readFromStream (in);

  //6. интервал

  nextChar = in.get();
  assert (nextChar == ' ');

  //7. затваряща скоба

  nextChar = in.get();
  assert (nextChar == ')');

  return new TreeNode<T> (rootValue,leftSubTree,rightSubTree);

}


template <class T>
void BTree<T>::del (TreeNode<T> *crr)
{
  if (crr == nullptr)
  {
    return;
  }

  del (crr->left);
  del (crr->right);
  delete crr;
}


template <class T>
BTree<T>::~BTree ()
{
  del (root);
}

template <class T>
TreeNode<T>* BTree<T>::copyFrom (const TreeNode<T> *crr)
{
  if (crr == nullptr)
  {
    return nullptr;
  }

  return new TreeNode<T> (crr->data,
                          copyFrom (crr->left),
                          copyFrom (crr->right));
}


template <class T>
BTree<T>::BTree (const BTree<T> &other)
{
  root = copyFrom (other.root);
}

template <class T>
BTree<T>& BTree<T>::operator = (const BTree<T> &other)
{
  if (this != &other)
  {
      del (root);
      root = copyFrom (other.root);
  }
  return *this;
}

template <class T>
bool BTree<T>::operator == (const BTree<T> &other) const
{
  return compare (root, other.root);
}

template <class T>
bool BTree<T>::compare (const TreeNode<T> *t1, const TreeNode<T> *t2) const
{
  if (t1 == nullptr)
    return t2 == nullptr;

  if (t2 == nullptr)
    return t1 == nullptr;

  return t1->data == t2->data &&
         compare (t1->left,t2->left) &&
         compare (t1->right, t2->right);
}

template <class T>
void BTree<T>::deleteBOT (const T &x)
{

  removeFromSubtreeProc (x,root);

}

template <class T>
T& BTree<T>::findmin (TreeNode<T> *crr)
{
  assert (crr != nullptr);

  while (crr->left != nullptr)
  {
    crr = crr->left;
  }

  return crr->data;

}

template <class T>
TreeNode<T>* BTree<T>::removeFromSubtree (const T &x, TreeNode<T> *crr)
{
    //1
    if (crr == nullptr)
      return nullptr;

    //2
    if (crr->data == x && crr->left == nullptr)
    {
      TreeNode <T> *save = crr->right;
      delete crr;
      return save;
    }
    //3
    if (crr->data == x && crr->right == nullptr)
    {
      TreeNode <T> *save = crr->left;
      delete crr;
      return save;
    }
    //4
    if (crr->data == x)
    {
      T rightmin = findmin (crr->right);
      crr->data = rightmin;
      crr->right = removeFromSubtree (rightmin,crr->right);
      crr = removeFromSubtree (x,crr);
      return crr;

    }
    //5, 6
    if (crr->data < x)
    {
      crr->right = removeFromSubtree (x,crr->right);
    } else {
      crr->left = removeFromSubtree (x,crr->left);
    }

    return crr;

}


template <class T>
void BTree<T>::removeFromSubtreeProc (const T &x, TreeNode<T> *&crr)
{
    //1
    if (crr == nullptr)
      return;

    //2
    if (crr->data == x && crr->left == nullptr)
    {
      TreeNode <T> *save = crr->right;
      delete crr;
      crr = save;
      return;
    }
    //3
    if (crr->data == x && crr->right == nullptr)
    {
      TreeNode <T> *save = crr->left;
      delete crr;
      crr = save;
      return;
    }
    //4
    if (crr->data == x)
    {
      T rightmin = findmin (crr->right);
      crr->data = rightmin;
      removeFromSubtreeProc (rightmin,crr->right);
      removeFromSubtreeProc (x,crr);
      return;

    }
    //5, 6
    if (crr->data < x)
    {
      removeFromSubtreeProc (x,crr->right);
    } else {
      removeFromSubtreeProc (x,crr->left);
    }

    return;

}


template <class T>
void BTree<T>::printDotty (std::ostream &out)
{
  out << "digraph G{" << std::endl;
  printNodesDotty (out,root);
  out << "}" << std::endl;
}

template <class T>
void BTree<T>::fillGaps (const T& x, unsigned int h)
{
  fillGaps (x,root,h);
}


template <class T>
void BTree<T>::fillGaps (const T &x, TreeNode<T> *&crr, unsigned int h)
{
  if (h == 0)
  {
    return;
  }

  if (crr == nullptr)
  {
    crr = new TreeNode<T> (x,nullptr,nullptr);
  }

  fillGaps (x,crr->left,h-1);
  fillGaps (x,crr->right,h-1);

}
