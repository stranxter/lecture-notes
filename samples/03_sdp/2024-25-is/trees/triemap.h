#pragma once

#include <string>
#include <vector>

template <typename Value>
class TrieMap
{
    public:

    TrieMap();

    Value& operator[](const std::string& key);
    Value operator[](const std::string& key) const;

    Value getValue(const std::string &key) const;
    void setValue(const std::string &key, const Value &value);

    bool hasKey(const std::string&);

    void toDotty(std::ostream& out) const;

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

    void toDotty(TrieNode* node, std::ostream& out) const;

    TrieNode* locateNode(const std::string& key) const;
    TrieNode* createNode(const std::string& key, const Value& value);

    TrieNode *root = nullptr;

    void free(TrieNode *node);

};