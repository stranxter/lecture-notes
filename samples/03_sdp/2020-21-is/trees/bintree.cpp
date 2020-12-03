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

template<class T>
bool BinTree<T>::operator == (const BinTree<T> &other)
{
    return equaltrees (root, other.root);
}


template<class T>
bool BinTree<T>::equaltrees (node *root1, node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return root2 == nullptr && root1 == nullptr;
    }

    return root1->data == root2->data &&
           equaltrees (root1->left, root2->left) &&
           equaltrees (root1->right, root2->right);

}


template<class T>
void BinTree<T>::toScheme(std::ostream &out)
{
    toScheme (out, root);
}

template<class T>
void BinTree<T>::toScheme (std::ostream &out, BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        out << "()";
        return;
    }

    out << '('
        << current->data
        << " ";

    toScheme (out, current->left);

    out << " ";

    toScheme (out, current->right);

    out << ")";
}


template<class T>
void BinTree<T>::fromScheme(std::istream &in)
{
    clear (root);

    root = readSchemeRec (in);

}

template<class T>
typename BinTree<T>::node* BinTree<T>::readSchemeRec (std::istream &in)
{
  
    char c;
    in >> c; 
    assert (c == '(');

    if (in.peek() == ')')
    {//празно дърво
        in.get();
        return nullptr;
    }

    T value;
    in >> value;

    //(<value>  <Tree> <Tree>)
    //        /|\.
    //         |

    BinTree<T>::node *left=readSchemeRec (in);

    //(<value>  <Tree> <Tree>)
    //               /|\.
    //                |


    BinTree<T>::node *right=readSchemeRec (in);

    //(<value>  <Tree> <Tree> )
    //                      /|\.
    //                       |

    in >> c;
    assert (c == ')');

    return new node {value,left,right};
}

template<class T>
void BinTree<T>::clear(BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }   

   clear (current->left);
   clear (current->right);
   delete current; 

}


template <class T>
typename BinTree<T>::Position BinTree<T>::rootPosition()
{
    return Position(root);
}

template <class T>
BinTree<T>::Position::Position (BinTree<T>::node *&_current):current(_current)
{

}

template <class T>
typename BinTree<T>::Position BinTree<T>::Position::left() const
{
    assert (current != nullptr);
    return Position(current->left);
}

template <class T>
typename BinTree<T>::Position BinTree<T>::Position::right() const
{
    assert (current != nullptr);
    return Position(current->right);
}

template <class T>
T BinTree<T>::Position::get() const
{
    assert (current != nullptr);
    return current->data;

}

template <class T>
void BinTree<T>::Position::set(const T &x)
{
    if (current == nullptr)
    {
        current = new node {x, nullptr, nullptr};
    } else 
    {
        current->data = x;
    }
}

template <class T>
bool BinTree<T>::Position::empty() const
{
    return current == nullptr;
}

template <class T>
BinTree<T>::Iterator::Iterator (BinTree<T>::node *start)
{
    if (start == nullptr)
    {
        return;
    } 
    
    while (start != nullptr)
    {
        s.push(start);
        start = start->left;
    }

}

template <class T>
T BinTree<T>::Iterator::operator *() const
{
    assert (!s.empty());

    return s.top()->data;
}

template <class T>
typename BinTree<T>::Iterator& BinTree<T>::Iterator::operator ++()
{

    BinTree<T>::node *current = s.top();s.pop();
    if (current->right != nullptr)
    {
        current = current->right;
        while (current)
        {
            s.push(current);
            current = current->left;
        }
    } 
    
    return *this;
}

template <class T>
bool BinTree<T>::Iterator::operator != (const typename BinTree<T>::Iterator &other) const
{
    return s != other.s;
}


template <class T>
typename BinTree<T>::Iterator BinTree<T>::begin()
{
    return Iterator(root);
}

template <class T>
typename BinTree<T>::Iterator BinTree<T>::end()
{
    return Iterator(nullptr);
}

#endif