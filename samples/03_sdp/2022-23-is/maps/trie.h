#pragma once

#include <string>
#include <vector>
#include <map>

template <typename ValueType>
class Trie
{
    public:

    Trie();
    Trie(const Trie&);
    Trie<ValueType>& operator=(const Trie<ValueType>&);

    ValueType& operator[](const std::string&);
    ValueType operator[](const std::string&) const;

    ~Trie();

    private:
    struct Node
    {
        ValueType *val;

        std::map<char,Node*> children;
    };
    Node *root;

    Node *lookup(const std::string&)
};