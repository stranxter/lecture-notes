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


#endif