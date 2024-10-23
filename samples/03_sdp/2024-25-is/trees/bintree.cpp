#include "bintree.h"
#include <cstring>
#include <cassert>
#include <iostream>
#include <iomanip>


template<typename T>
BinTree<T>::BinTree():root(nullptr){}

template<typename T>
void BinTree<T>::insert(const char *trace, const T& x)
{
    if(strlen(trace)==0)
    {
        //искаме да променим стойността на корена
        //или да създадем нов корен, ако няма такъв

        if(root == nullptr)
        {
            root = new BinTree<T>::Node{x,nullptr,nullptr};
        } else 
        {
            root->value = x;
        }
    } else 
    {
        BinTree<T>::Node *current = root;
        for(int i = 0; i < strlen(trace); ++i)
        {
            if(trace[i]=='L')
            {
                if(current->left == nullptr)
                {
                    assert(i == strlen(trace)-1);
                    current->left = new BinTree<T>::Node{x,nullptr,nullptr};
                }
                current = current->left;
            } else if (trace[i] == 'R')
            {
                if(current->right == nullptr)
                {
                    assert(i == strlen(trace)-1);
                    current->right = new BinTree<T>::Node{x,nullptr,nullptr};
                }
                current = current->right;
            } else 
            {
                throw "Incorrent trace instruction.";
            }          
        }
        current->value=x;
    }
}

template<typename T>
void BinTree<T>::print() const
{
    printHelper(root,0);
}

template<typename T>
void BinTree<T>::printHelper(typename BinTree<T>::Node *current,int depth) const
{
    if(current==nullptr)
    {
        return;
    }

    printHelper(current->right,depth+1);
    std::cout << std::setw(depth*3) << current->value << std::endl;
    printHelper(current->left,depth+1);

}

template<typename T>
bool BinTree<T>::member(const T& x) const
{
    return memberHelper(root,x);
}

template<typename T>
bool BinTree<T>::memberHelper(typename BinTree<T>::Node *current, const T& x) const
{
    if(current == nullptr)
    {
        return false;
    }

    return current->value == x ||
           memberHelper(current->left,x) ||
           memberHelper(current->right,x);  
}

template<typename T>
T BinTree<T>::sum() const
{
    return sumHelper(root);
}

template<typename T>
T BinTree<T>::sumHelper(BinTree<T>::Node *current) const
{
    if(current == nullptr)
    {
        return 0;
    }

    return current->value +
           sumHelper(current->left) +
           sumHelper(current->right);
}


template<typename T>
void BinTree<T>::insertBOT(const T& x)
{
    if(root == nullptr)
    {
        root = new BinTree<T>::Node {x,nullptr,nullptr};
    } else 
    {
        BinTree<T>::Node *current = root;
        while (!((x <= current->value) && (current->left == nullptr) ||
                 (x > current->value) && (current->right == nullptr)))
        {
            if(x <= current->value)
            {
                current = current->left;
            } else
            {
                current = current->right;
            }
        }

            if(x <= current->value)
            {
                current->left = new BinTree<T>::Node {x,nullptr,nullptr};
            } else
            {
                current->right = new BinTree<T>::Node {x,nullptr,nullptr};
            }
    }
}