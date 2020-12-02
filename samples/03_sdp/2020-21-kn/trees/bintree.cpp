#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "bintree.h"
#include <cassert>

template <class T>
BinTree<T>::BinTree():root(nullptr)
{

}

template <class T> 
void BinTree<T>::add (const T &x, const char *trace)
{
    if (root == nullptr || trace[0] == 0)
    {
        assert (root == nullptr && trace[0] == 0);
        root = new BinTree<T>::node {x, nullptr, nullptr};
        return;
    }

    BinTree<T>::node *current = root;
    while (current != nullptr && trace[1] != 0)
    {
        assert (trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }    
        ++trace; 
    }

   assert (current != nullptr); 
   assert (trace[0] == 'L' || trace[0] == 'R');

   if (trace[0] == 'L')
   {
       assert (current->left == nullptr);
       current->left = new node{x,nullptr,nullptr};
   } else 
   {
       assert (current->right == nullptr);
       current->right = new node{x,nullptr,nullptr};
   }

}


template <class T>
void BinTree<T>::printall (std::ostream &out)
{
    printhelp (out,root);
    out << std::endl;
}
template <class T>
void BinTree<T>::printhelp (std::ostream &out, BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }

    printhelp (out, current->left);
    out << current->data << " ";
    printhelp (out, current->right);

}


template <class T>
void BinTree<T>::printdot (std::ostream &out)
{
    out << "digraph G{\n";
    printdothelp (out,root);
    out << "}\n";
}
template <class T>
void BinTree<T>::printdothelp (std::ostream &out, BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }

    printdothelp (out, current->left);
    
    out << (long)current << "[label=\"" << current->data << "\"]\n";

    if (current->left != nullptr)
    {
        out << (long)current << "->" << (long)(current->left) << "[color=red]" << std::endl;
    } 
    if (current->right != nullptr)
    {
        out << (long)current << "->" << (long)(current->right) << std::endl;
    } 
    
    printdothelp (out, current->right);

}


template <class T>
T BinTree<T>::operator[](const char *trace) const
{
    return locate(trace)->data;
}

template <class T>
void BinTree<T>::set (const T &x, const char *trace)
{
    locate(trace)->data = x;
}

template <class T>
typename BinTree<T>::node* BinTree<T>::locate (const char *trace) const
{
    assert (root != nullptr);

    if (trace[0] == 0)
    {
        return root;    
    }

    BinTree<T>::node *current = root;
    while (current != nullptr && trace[0] != 0)
    {
        assert (trace[0] == 'L' || trace[0] == 'R');
        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }
        ++trace;
    }

    assert (current != nullptr);

    return current;
}

template <class T>
bool BinTree<T>::member (const T &x) const
{
    return memberhelp (x, root);
}

template <class T>
bool BinTree<T>::memberhelp (const T &x, node *current) const
{

    return current != nullptr &&
           (x == current->data ||
            memberhelp (x, current->left) ||
            memberhelp (x, current->right));

    /*
    if (current == nullptr)
    {
        return false;
    }

    if (current->data == x)
    {
        return true;
    }

    if (memberhelp (x, current->left))
    {
        return true;
    }

    if (memberhelp (x, current->right))
    {
        return true;
    }

    return false;
    */
}

template <class T>
T BinTree<T>::sum () const
{
    return sum(root);
}

template <class T>
T BinTree<T>::sum (BinTree<T>::node *current) const
{
    if (current == nullptr)
    {
        return 0;
    }

    return current->data +
           sum(current->left) +
           sum(current->right);
}


template <class T>
void BinTree<T>::toScheme (std::ostream &out)
{
    this->toScheme (out, root);
}

template <class T>
void BinTree<T>::toScheme (std::ostream &out, 
                             BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        out << "()";
        return;
    }    

    out << "("
        << current->data;

    toScheme (out, current->left);
    toScheme (out, current->right);

    out << ")";

}

template <class T>
void BinTree<T>::deleteTree (node *current)
{
    if (current == nullptr)
    {
        return;
    }

    //--------------------------------


    deleteTree (current->left);
    deleteTree (current->right);

    delete current;

}

template <class T>
BinTree<T>::~BinTree ()
{
    deleteTree (root);
}

template <class T>
bool BinTree<T>::operator == (const BinTree<T> &other) const
{
    return equalTrees (root, other.root);
}

template <class T>
bool BinTree<T>::equalTrees (BinTree<T>::node* root1, BinTree<T>::node* root2) const
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return root1 == nullptr && root2 == nullptr;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    //-------------------

    return equalTrees (root1->left, root2->left) &&
           equalTrees (root1->right, root2->right);
}

template <class T>
void BinTree<T>::fromScheme (std::istream &in)
{
  
    deleteTree(root);
    root = readScheme (in);            

}

template <class T>
typename BinTree<T>::node* BinTree<T>::readScheme (std::istream &in)
{
/*
<tree> ::= <empty> | <non-empty>
<empty> ::= ()
<non-empty> ::= (<node> <tree> <tree>)
*/
    assert(in.get() == '(');
    
    if (in.peek() == ')')
    //')' - празно дърво
    {
        in.get();
        return nullptr;
    } 

    //-----------------------------
    //( <node> <tree> <tree>)
    // /|\

    T data;
    in >> data;

    //( <node> <tree> <tree>)
    //       /|\

    BinTree<T>::node *left = readScheme(in);

    //( <node> <tree> <tree>)
    //              /|\

    BinTree<T>::node *right = readScheme(in);

    //( <node> <tree> <tree>)
    //                     /|\

    assert (in.get() == ')');

    return new BinTree<int>::node {data, left, right};
}

template <class T>
void BinTree<T>::insertOrdered (const T &x)
{
    insertOrdered (x,root);
}

template <class T>
void BinTree<T>::insertOrdered (const T &x, node *&current)
{
    if (current == nullptr)
    {
        current = new node {x, nullptr, nullptr};
        return;
    }

    //-------------------------

    if (x <= current->data)
    {
      insertOrdered (x, current->left);        
    } else 
    {
      insertOrdered (x, current->right);
    }

}


#endif