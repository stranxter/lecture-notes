#include "bot.h"


template <typename T>
BinOrdTree<T>::BinOrdTree():root(nullptr)
{}

template <typename T>
BinOrdTree<T>::BinOrdTree(const BinOrdTree<T> &other)
{
    root=copy(other.root);
}

template <typename T>
typename BinOrdTree<T>::box* copy(const typename BinOrdTree<T>::box *otherRoot)
{
    if(otherRoot == nullptr)
    {
        return nullptr;
    }

    return new typename BinOrdTree<T>::box {otherRoot->data,
                                            copy(otherRoot->left),
                                            copy(otherRoot->right)};
}

template <typename T>
void  BinOrdTree<T>::clear(typename BinOrdTree<T>::box *current)
{
    if(current==nullptr)
    {
        return;
    }

    clear(current->left);
    clear(current->right);
    delete current;
}


template <typename T>
BinOrdTree<T>& BinOrdTree<T>::operator=(const BinOrdTree<T> &other)
{
    if(this != &other)
    {
        clear(root);
        root=copy(other->root);
    }
    return *this;
}

template <typename T>
BinOrdTree<T>::~BinOrdTree()
{
    clear(root);
}

template <typename T>
void BinOrdTree<T>::add(const T& x)
{
    if(root == nullptr)
    {
        root=new BinOrdTree<T>::box {x,nullptr,nullptr};
        return;
    }
    BinOrdTree<T>::box *parent = root;
    while(!((parent->left==nullptr && x < parent->data) ||
            (parent->right==nullptr && x >= parent->data)))
    {
        if(x<parent->data)
        {
            parent=parent->left;
        } else 
        {
            parent=parent->right;
        }
    }    
    if(x<parent->data)
    {
        parent->left=new BinOrdTree<T>::box {x,nullptr,nullptr};
    } else
    {
        parent->right=new BinOrdTree<T>::box {x,nullptr,nullptr};
    }
}

template <typename T>
void BinOrdTree<T>::toDotty(typename BinOrdTree<T>::box *current, std::ostream &out)
{
    out << "Digraph G{\n";
    printDotStatements(current,out);
    out << "}";
}

template <typename T>
void BinOrdTree<T>::printDotStatements(typename BinOrdTree<T>::box *root, std::ostream &out)
{
    if(root==nullptr)
    {
        return;
    }

    printDotStatements(root->left,out);
    printDotStatements(root->right,out);

    out << (long)root << "[label=\"" << root->data << "\"];\n";

    if(root->right != nullptr)
    {
        out << (long)root << "->" << (long)(root->right) << "[color=\"blue\",label=\"R\"];" << std::endl;
    }
    if(root->left != nullptr)
    {
        out << (long)root << "->" << (long)(root->left) << "[color=\"red\",label=\"L\"];" << std::endl;
    }
}



template <typename T>
void BinOrdTree<T>::toDotty(std::ostream &out)
{
    toDotty(root,out);
}

template <typename T>
void BinOrdTree<T>::addRec(const T &x)
{
    add(root,x);
}

template <typename T>
void BinOrdTree<T>::add(typename BinOrdTree<T>::box *&current,const T &x)
{
    if(current==nullptr)
    {
        current=new typename BinOrdTree<T>::box {x,nullptr,nullptr};
        return;
    }
    if(x<current->data)
    {
        add(current->left,x);
    } else 
    {
        add(current->right,x);
    }
}


template <typename T>
bool BinOrdTree<T>::member(const T& x)
{

}
template <typename T>
size_t BinOrdTree<T>::size()
{

}

template <typename T>
bool BinOrdTree<T>::member(box *root,const T &x)
{
    return root != nullptr &&
           (root->data == x ||
            member(root->left,x) ||
            member(root->right,x));
}

template <typename T>
size_t BinOrdTree<T>::count(box *current)
{
    if(current == nullptr)
    {
        return 0;
    }

    return count(current->left) +
           count(current->right) + 1;
}

template <typename T>
bool BinOrdTree<T>::checkOrder()
{
    return checkOrder(root,Maybe<T>(),Maybe<T>());
}

template <typename T>
bool BinOrdTree<T>::checkOrder(box *current, 
                               const Maybe<T>& min,
                               const Maybe<T>& max)
{
    if(current == nullptr)
    {
        return true;
    }
    
    //грешката по време на лекции: тук вместо "current", 
    //бахме написали "root"...
    if(min.defined && current->data <= min.value ||
       max.defined && current->data > max.value)
    {
        return false;
    }

    return checkOrder(current->left,min,Maybe<T>(current->data)) &&
           checkOrder(current->right,Maybe<T>(current->data),max);


}
