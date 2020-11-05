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
    if (root == nullptr)
    {
        assert (trace[0] == 0);
        root = new node {x,nullptr,nullptr};
        return;
    }

    assert (trace[0] != 0);

    BinTree<T>::node *current = root;

    while (trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        
        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        assert (current != nullptr);    
        ++trace;
    }

    if (trace[0] == 'L')
    {
        assert(current->left == nullptr);
        current->left = new node {x,nullptr,nullptr};
    } else if (trace[0] == 'R')
    {
        assert(current->right == nullptr);
        current->right = new node {x,nullptr,nullptr};
    } else 
    {
        assert (false);
    }



}

template <class T>
T BinTree<T>::get (const char *trace) const
{

    BinTree<T>::node *element = locate(trace);
    assert (element != nullptr);
    return element->data;

}

template <class T>
typename BinTree<T>::node* BinTree<T>::locate (const char *trace) const
{
    BinTree<T>::node *current = root;
    while (trace[0] != 0)
    {
        assert (current != nullptr);
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
T& BinTree<T>::operator [](const char *trace)
{
    BinTree<T>::node *element = locate(trace);
    assert (element != nullptr);
    return element->data; 
}

template <class T>
void BinTree<T>::toDotty(std::ostream& out)
{
    out << "digraph G{\n";
    toDottyHelp(out, root);
    out << "}";
}

template <class T>
void BinTree<T>::toDottyHelp (std::ostream& out, node *current)
{
    if (current == nullptr)
    {
        return;
    }
    out << (long)current << "[label=\"" << current->data << "\"];\n";

    if (current->left != nullptr)
    {
        out << (long)current << "->" << (long)(current->left) << "[color=red];\n";
    } 
    if (current->right != nullptr)
    {
        out << (long)current << "->" << (long)(current->right) << "\n";
    }

    toDottyHelp (out, current->left);
    toDottyHelp (out, current->right);
}


template <class T>
bool BinTree<T>::member (const T& x)
{
    return memberHelp(x,root);
}

template <class T>
bool BinTree<T>::memberHelp (const T& x, node* current)
{
    if (current == nullptr)
    {
        return false;
    }

    return current->data == x ||
           memberHelp (x, current->left) ||
           memberHelp (x, current->right);

/*
    return current != nullptr &&   
                (current->data == x ||
                memberHelp (x, current->left) ||
                memberHelp (x, current->right));
*/
}

template <class T>
T BinTree<T>::sum ()
{
    return sumHelper(root);
}


template <class T>
T BinTree<T>::sumHelper (node* current)
{
    if (current == nullptr)
    {
        return 0;
    }

    return current->data +
           sum(current->left) +
           sum(current->right);
}


#endif