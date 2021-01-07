#ifndef __TRIEMAP_CPP
#define __TRIEMAP_CPP    

#include "triemap.h"
#include <cassert>
    
template<class Values>
TrieMap<Values>::TrieMap()
{
    root = new TrieMap<Values>::Node {nullptr};
}

template<class Values>
Values TrieMap<Values>::operator[](const std::string& key) const
{
    assert (root != nullptr);
    typename TrieMap<Values>::Node* node = locate(key);
    assert(node != nullptr);
    assert(node->value != nullptr);

    return *(node->value);

}

template<class Values>
typename TrieMap<Values>::Node* TrieMap<Values>::locate(const std::string key) const
{
    assert (root != nullptr);
    if (root == nullptr)
    {
        return nullptr;
    }
    
    typename TrieMap<Values>::Node* current = root;
    
    for (char c : key)
    {
        if (current->children.count(c) > 0)
        {
            current = current->children[c];
        } else 
        {
            return nullptr;
        }
    }

    return current;
}

template<class Values>
Values& TrieMap<Values>::operator[](const std::string& key) 
{
    assert (root != nullptr);
    typename TrieMap<Values>::Node* node = locate(key);

    if (node != nullptr)
    {
        if (node->value == nullptr)
        {
            node->value = new Values();
        }
        return *(node->value);
    } else
    {
        typename TrieMap<Values>::Node* current = root; 
        size_t iletter = 0;

        while (current->children.count(key[iletter]) > 0)
        {
            assert(iletter < key.length());
            current = current->children[key[iletter]];
            ++iletter;
        }

        for (;iletter < key.length(); ++iletter)
        {
            current->children[key[iletter]] = new Node{nullptr};
            current = current->children[key[iletter]];
        }

        current->value = new Values();
        return *(current->value);

    }

}

template<class Values>
bool TrieMap<Values>::hasKey(const std::string &key) const
{
    typename TrieMap<Values>::Node* node = locate(key);
    return node != nullptr && node->value != nullptr;   
}


template<class Values>
TrieMap<Values>::~TrieMap()
{
    //За домашно!!!
}



template<class Values>
void TrieMap<Values>::exportToDot(std::ostream &out) const
{
    out << "digraph G{\n";
    exportToDot(out,root);
    out << "}";
}

template<class Values>
void TrieMap<Values>::exportToDot(std::ostream &out, typename TrieMap<Values>::Node* root) const
{

    out << (long)root << "[label=\"";
    if (root->value != nullptr)
    {
        out << *(root->value);
    } else
    {
        out << "_";
    }
    out << "\"];\n";

    for (auto child : root->children)
    {
        //аз -> дете [label="<буква>"]
        out << (long)root 
            << "->" 
            << (long)(child.second) 
            << "[label=\""
            << child.first
            << "\"];\n";

        exportToDot(out, child.second);        
    }
    

}

#endif