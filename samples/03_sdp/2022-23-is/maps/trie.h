#pragma once

#include <string>
#include <vector>
#include <map>
#include <stack>

template <typename ValueType>
class Trie
{
    public:

    Trie();
    Trie(const Trie&);
    Trie<ValueType>& operator=(const Trie<ValueType>&);

    ValueType& operator[](const std::string&);
    ValueType operator[](const std::string&) const;

    void printAllKeys();

    ~Trie();

    private:
    struct Node
    {
        ValueType *val;

        std::map<char,Node*> children;
    };
    Node *root;

    Node *lookup(const std::string&);

    void printAllKeys(Node *root,std::string currentPath);


    public:


    class Iterator
    {
        public:

        Iterator(typename Trie<ValueType>::Node* root);

        std::string operator*();
        Iterator& operator++();
        bool operator!=(const Iterator&);

        private:

        std::stack<std::pair<typename Trie<ValueType>::Node*,std::string>> s;


    };

    Iterator begin();
    Iterator end();

};