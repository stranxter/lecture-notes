#pragma once

#include <string>
#include <vector>

template <typename Value>
class TrieMap
{
    public:

    TrieMap();

    //Value& operator[](const std::string& key);

    Value getValue(const std::string &key) const;
    void setValue(const std::string &key, const Value &value);

    bool hasKey(const std::string&);

    private:
    
    struct TrieNode;

    struct child
    {
        char label;
        TrieNode *ptr;
    };

    struct TrieNode
    {
        //TrieNode* children[27];
        Value* value;
        std::vector<child> children; 

    };

    TrieNode* locateNode(const std::string& key) const;

    TrieNode *root = nullptr;

};