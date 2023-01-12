#include "trie.h"

template <typename ValueType>
Trie<ValueType>::Trie():root(nullptr)
{

}
template <typename ValueType>
Trie<ValueType>::Trie(const Trie&):root(nullptr)
{

}
template <typename ValueType>
Trie<ValueType>& Trie<ValueType>::operator=(const Trie<ValueType>&)
{

}
template <typename ValueType>
ValueType& Trie<ValueType>::operator[](const std::string &key)
{
    if (root == nullptr)
    {
        root = new typename Trie<ValueType>::Node {nullptr};
    }

    typename Trie<ValueType>::Node *current = root;

    for (char c:key)
    {
        if(current->children.find(c) != current->children.end())
        {
            current = current->children[c];        
        } else 
        {
            current->children[c] = new typename Trie<ValueType>::Node {nullptr}; 
            current = current->children[c];
        }
    }

    if (current->val == nullptr)
    {
        ValueType dummy;
        current->val = new ValueType {dummy};
    }
    
    return *current->val;
}

template <typename ValueType>
ValueType Trie<ValueType>::operator[](const std::string &key) const
{
    if (root == nullptr)
    {
        throw "Key not found!";
    }

    typename Trie<ValueType>::Node *current = root;

    for (char c:key)
    {
        if(current->children.find(c) == current->children.end())
        {
            throw "Key not found!";
        }
        current = current->children[c];
    }

    if (current->val == nullptr)
    {
        throw "Key not found!";
    }

    return *current->val;
}

template <typename ValueType>
typename Trie<ValueType>::Node* Trie<ValueType>::lookup(const std::string&)
{
    
}

template <typename ValueType>
Trie<ValueType>::~Trie()
{

}

template <typename ValueType>
void Trie<ValueType>::printAllKeys()
{
    printAllKeys(root,"");
}

template <typename ValueType>
void Trie<ValueType>::printAllKeys(typename Trie<ValueType>::Node *current, 
                                   std::string currentPath)
{
    if (current == nullptr)
    {
        return;
    }

    if(current->val != nullptr)
    {
        std::cout << currentPath << std::endl;
    }

    for(std::pair<char,typename Trie<ValueType>::Node*> child : current->children)
    {
        printAllKeys(child.second,currentPath+child.first);
    }

}

template <typename ValueType>
using stack_pair = std::pair<typename Trie<ValueType>::Node*,std::string>;

template <typename ValueType>
using tree_node = typename Trie<ValueType>::Node;


template <typename ValueType>
typename Trie<ValueType>::Iterator Trie<ValueType>::begin()
{
    return Trie<ValueType>::Iterator(root);
}

template <typename ValueType>
typename Trie<ValueType>::Iterator Trie<ValueType>::end()
{   
    return Trie<ValueType>::Iterator(nullptr);
}

template <typename ValueType>
std::string Trie<ValueType>::Iterator::operator*()
{
    return s.top().second;
}

template <typename ValueType>
typename Trie<ValueType>::Iterator& Trie<ValueType>::Iterator::operator++()
{

    stack_pair<ValueType> current = s.top();

    do
    {
        s.pop();
        for(std::pair<char,tree_node<ValueType>*> child : current.first->children)
        {
            s.push(stack_pair<ValueType> {child.second,current.second+child.first});
        }
        if (s.size() > 0)
        {
            current = s.top();    
        }
    }while (current.first->val == nullptr && s.size() > 0);

    return *this;
}

template <typename ValueType>
bool Trie<ValueType>::Iterator::operator!=(const Iterator &other)
{
    return s != other.s;
}

template <typename ValueType>
Trie<ValueType>::Iterator::Iterator(typename Trie<ValueType>::Node *root)
{
    if(root == nullptr)
    {
        return;
    }

    s.push(stack_pair<ValueType>{root,""});

    stack_pair<ValueType> current = s.top();
    
    while(current.first->val == nullptr && s.size() > 0)
    {
        s.pop();
        for(std::pair<char,tree_node<ValueType>*> child : current.first->children)
        {
            s.push(stack_pair<ValueType> {child.second,current.second+child.first});
        }
        current = s.top();
    }
    
}

