#ifndef __BOTREE_HPP
#define __BOTREE_HPP

#include "bintree.hpp"
#include "botree.h"

template <class T>    
BOTree<T>::BOTree ():BinTree<T> (){}

template <class T>    
BOTree<T>::BOTree (const BOTree &t):BinTree<T>(t){}
    
template <class T>   
BOTree<T>::BOTree (BOTree &&t):BinTree<T>(t){}

template <class T>
void BOTree<T>::dottyPrint (std::ostream &out)
{
    BinTree<T>::dottyPrint (out);
}


template <class T>   
BOTree<T>& BOTree<T>::insert (const T &x)
{
    insertHelper (x,this->root);
    return *this;
}

template <class T>   
BOTree<T>& BOTree<T>::remove (const T &x)
{
    removeHelper (x,this->root);
    return *this;
}


template <class T>
void BOTree<T>::insertHelper (const T &x, BinTreeNode<T> *&current)
{
    if (current == nullptr)
    {
        current = new BinTreeNode<T> (x,nullptr,nullptr);
        return;
    }

    if (x <= current->data)
    {
        insertHelper (x,current->left);
    } else {
        insertHelper (x,current->right);
    }
}

template <class T>
BinTreeNode<T>*& BOTree<T>::minNode (BinTreeNode<T> *&current)
{
    if (current->left == nullptr)
    {
        return current;
    } else {
        return minNode (current->left);
    }
}


template <class T>
void BOTree<T>::removeHelper (const T &x, BinTreeNode<T>*&current)
{
    if (current == nullptr)
    {
        return;
    }
    if (x < current->data)
    {
        removeHelper (x, current->left);
    } else if (current->data < x)
    {
        removeHelper (x, current->right);
    } else if (current->right == nullptr) /*x == current->data*/
    {        
        BinTreeNode<T> *save = current;
        current = current->left;
        delete save;
    } else /*x == current->data && current->right != nullptr*/
    {
        BinTreeNode<T> *&minn = minNode (current->right);
        BinTreeNode<T> *saveMinNodeAddr = minn;
        minn = minn->right;

        saveMinNodeAddr->left = current->left;
        saveMinNodeAddr->right = current->right;
        BinTreeNode<T> *saveCurrentAddr = current;
        current = saveMinNodeAddr;
        delete saveCurrentAddr;
    }

}
template <class T>
void BOTree<T>::printTree (std::ostream&out)
{
    BinTree<T>::printTree (out);
}

template <class T>
typename BOTree<T>::Iterator BOTree<T>::begin ()
{
    return BOTree<T>::Iterator (this->root);
}
template <class T>
typename BOTree<T>::Iterator BOTree<T>::end ()
{
    return BOTree<T>::Iterator (nullptr);
}

template <class T>
BOTree<T>::Iterator::Iterator (BinTreeNode<T> *node)
{
    if (node != nullptr)
    {
        s.push ({TYPE_TRAVERSE,node});
        windstack();
    }
}


template <class T>
void BOTree<T>::Iterator::windstack ()
{
    while (!s.empty() && s.top().type != TYPE_PRINT)
    {
        typename BOTree<T>::Iterator::WaitingOperation 
                                  operation = s.top(); s.pop();

        //operation.type == TYPE_TRAVERSE
        if (operation.node->right != nullptr)
        {
            s.push ({TYPE_TRAVERSE,operation.node->right});
        }   
        s.push ({TYPE_PRINT,operation.node});
        if (operation.node->left != nullptr)
        {
            s.push ({TYPE_TRAVERSE,operation.node->left});
        }   
    }
}

template <class T>
T& BOTree<T>::Iterator::operator * ()
{
    assert (!s.empty() && s.top().type == TYPE_PRINT);
    return s.top().node->data;
}
template <class T>
typename BOTree<T>::Iterator& BOTree<T>::Iterator::operator ++()
{
    assert (!s.empty());
    s.pop();
    windstack();
    return *this;
}
template <class T>
bool BOTree<T>::Iterator::operator != (const typename BOTree<T>::Iterator &it) const
{
    return !(*this == it);
}

template <class T>
bool BOTree<T>::Iterator::operator == (const typename BOTree<T>::Iterator &it) const
{
    return (s.empty() && it.s.empty()) ||
           (!s.empty() && !it.s.empty() && s.top() == it.s.top());
}

template <class T>
bool BOTree<T>::Iterator::WaitingOperation::operator == (const typename BOTree<T>::Iterator::WaitingOperation &op) const 
{
    return node == op.node && type == op.type;
}


#endif