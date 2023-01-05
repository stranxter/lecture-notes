#include "trie.h"

template <typename ValueType>
Trie<ValueType>::Trie()
{

}
template <typename ValueType>
Trie<ValueType>::Trie(const Trie&)
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

    typename Trie<ValueType> current = root;

    for (char c:key)
    {
        if(current->children.find(c) == children.end())
        {
            children[c] = new typename Trie<ValueType>::Node {nullptr}; 
        }
        current = current->children[c];
    }

    if (current->value)
    {
        ValueType dummy;
        current->value = new ValueType {dummy};
    }
    return current->value;

}
template <typename ValueType>
ValueType Trie<ValueType>::operator[](const std::string &key) const
{

    if (root != nullptr)
    {
        throw "Key not found!";
    }

    typename Trie<ValueType> current = root;

    for (char c:key)
    {
        if(current->children.find(c) == children.end())
        {
            throw "Key not found!";
        }
        current = current->children[c];
    }

    return current->value;
}

template <typename ValueType>
typename Trie<ValueType>::Node* Trie<ValueType>::lookup(const std::string&)
{
    
}

template <typename ValueType>
Trie<ValueType>::~Trie()
{

}
