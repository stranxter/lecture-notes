#include <cassert>
#include "triemap.h"

template <typename Value>
TrieMap<Value>::TrieMap()
{
}

template <typename Value>
void TrieMap<Value>::setValue(const std::string& key, const Value &val)
{
    if(root == nullptr)
    {
        root = new TrieMap<Value>::TrieNode;
        root->value = nullptr;
    }

    TrieMap<Value>::TrieNode* current = root;

    for(char c: key)
    //много важно условие: приемаме, че на всяка итерация на цикъла
    //current НЕ Е nullpt
    {        
        //std::vector<TrieMap<Value>::child>::iterator it = current->children.begin();
        int i = 0;
        while(i < current->children.size() && 
              current->children[i].label != c)
        {
            ++i;
        }
        if(i == current->children.size())
        {
            TrieMap<Value>::TrieNode *newNode = new TrieMap<Value>::TrieNode;
            newNode->value = nullptr;

            current->children.push_back({c,newNode});      
            current = newNode;

        } else 
        {
            current = current->children[i].ptr;
        }
    }
    assert(current != nullptr);
    if(current->value == nullptr)
    {
        current->value = new Value(val);
    } else
    {
        *(current->value) = val;
    }

}


template <typename Value>
bool TrieMap<Value>::hasKey(const std::string& s)
{
    TrieMap<Value>::TrieNode* node = locateNode(s);
    return node != nullptr && node->value != nullptr;
}


template <typename Value>
Value TrieMap<Value>::getValue(const std::string& key) const
{
    TrieMap<Value>::TrieNode* node = locateNode(key);   
    if(node == nullptr || node->value == nullptr)
        throw "Key not found!";
    return *(node->value);
}

template <typename Value>
typename TrieMap<Value>::TrieNode* TrieMap<Value>::locateNode(const std::string& key) const
{
    TrieMap<Value>::TrieNode* current = root;

    for(char c: key)
    {
        if(current == nullptr)
        {
            return nullptr;
        }
        
        //std::vector<TrieMap<Value>::child>::iterator it = current->children.begin();
        int i = 0;
        while(i < current->children.size() && 
              current->children[i].label != c)
        {
            ++i;
        }
        if(i == current->children.size())
        {
            return nullptr;
        }
        current = current->children[i].ptr;
    }
    assert(current != nullptr);

    return current;


}

