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
    std::cout << std::setw(depth*5) << current->value << std::endl;
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
    /*
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
    */

   insertBOThelper(root,x);
}


template<typename T>
void BinTree<T>::insertBOThelper(Node *&current, int x)
{
    if(current == nullptr)
    {
        current=new BinTree<T>::Node{x,nullptr,nullptr};
        return;
    }

    if(current->value > x)
    {
        insertBOThelper(current->left,x);
    } else 
    {
        insertBOThelper(current->right,x);
    }

}

template<typename T>
void BinTree<T>::printHaskell(std::ostream &out) const
{
    printHaskellHelper(root,out);
}

template<typename T>
void BinTree<T>::printHaskellHelper(BinTree<T>::Node *current, std::ostream& out) const
{
    if(current == nullptr)
    {
        out << "Empty ";
        return;
    }

    out << "Node " << current->value << " ";
    printHaskellHelper(current->left,out);
    printHaskellHelper(current->right,out);

}

template<typename T>
void BinTree<T>::fromHaskell(std::istream &in)
{
    root = createTreeFromHaskell(in);
}

template<typename T>
typename BinTree<T>::Node* BinTree<T>::createTreeFromHaskell(std::istream &in)
{
    std::string constr;
    in >> constr;

    if(constr == "Empty")
    {
        return nullptr;
    }

    if(constr == "Node")
    {
        T val;
        in >> val;  

        BinTree<T>::Node* left = createTreeFromHaskell(in);
        BinTree<T>::Node* right = createTreeFromHaskell(in);

        return new BinTree<T>::Node{val,left,right};     
    }

    throw "Incorrect tree constructor.";
}


template<typename T>
T BinTree<T>::max() const
{
    return max(root);
}

template<typename T>
T BinTree<T>::max(Node *current) const
{
    while(current->right != nullptr)
    {
        current = current->right;
    }

    return current->value;
}



template<typename T>
T BinTree<T>::min() const
{
    return min(root);
}

template<typename T>
T BinTree<T>::min(Node *current) const
{
    while(current->left != nullptr)
    {
        current = current->left;
    }

    return current->value;
}

template<typename T>
bool BinTree<T>::remove(const T&x)
{
 
 return removeHelper(root,x);

}

template<typename T>
bool BinTree<T>::removeHelper(Node *&current, const T&x)
{
    if(current == nullptr)
    {
        return false;
    }

    if(current->value > x)
    {
        return removeHelper(current->left,x); 
    } else if (current->value < x)
    {
        return removeHelper(current->right,x); 
    }

    //current->value == x

    if(current->right == nullptr)
    {
        BinTree<T>::Node *save = current;
        current = current->left;
        delete save;
        return true;
    }

    T minel = min(current->right); 
    current->value = minel;
    removeHelper(current->right,minel);
    return true;

}


template <typename T>
void BinTree<T>::iterator::windstack()
{
    while(s.top()->left != nullptr)
    {
        s.push(s.top()->left);
    }
}


template <typename T>
BinTree<T>::iterator::iterator(Node *root)
{
    if(root != nullptr)
    {
        s.push(root);
        windstack();
    }
}

template <typename T>
typename BinTree<T>::iterator& BinTree<T>::iterator::operator++()
{
    Node* crr = s.top(); s.pop();
    if(crr->right != nullptr)
    {
        s.push(crr->right);
        windstack();
    }
    return *this;
}

template <typename T>
T BinTree<T>::iterator::operator*() const
{
    if(s.empty())
    {
        throw "No more elements to iterate";
    }
    return s.top()->value;
}

template <typename T>
bool BinTree<T>::iterator::operator !=(const BinTree<T>::iterator &other) const
{
    return s != other.s;
}

template <typename T>
typename BinTree<T>::iterator BinTree<T>::begin() const
{
    return iterator(root);
}

template <typename T>
typename BinTree<T>::iterator BinTree<T>::end() const
{
    return iterator(nullptr);
}
