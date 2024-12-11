#include <cassert>
#include "triemap.h"

template <typename Value>
TrieMap<Value>::TrieMap()
{
}


template <typename Value>
typename TrieMap<Value>::TrieNode* TrieMap<Value>::createNode(const std::string& key, const Value& val)
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
    return current;
}

template <typename Value>
void TrieMap<Value>::setValue(const std::string& key, const Value &val)
{
    createNode(key,val);
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

template<typename Value>
Value& TrieMap<Value>::operator[](const std::string& key)
{

    TrieMap<Value>::TrieNode* node = locateNode(key);
    if(node != nullptr)
    {
        if(node->value == nullptr)
        {
            node->value = new Value();
        }
        return *(node->value);
    } else 
    {
        return *(createNode(key,Value())->value);
    }
}

template<typename Value>
Value TrieMap<Value>::operator[](const std::string& key) const
{
    return getValue(key);
}

template<typename Value>
void TrieMap<Value>::toDotty(std::ostream& out) const
{
    out << "digraph G{\n";
    toDotty(root,out);
    out << "}";
}

template<typename Value>
void TrieMap<Value>::toDotty(typename TrieMap<Value>::TrieNode* node, std::ostream& out) const
{
    if(node == nullptr)
    {
        return;
    }

    if (node->value != nullptr)
    {
        out << (long)node << "[label=\"" << *(node->value) << "\"]\n";    
    } else 
    {
        out << (long)node << "[label=\"_\"]\n";
    }
    

    for(auto c: node->children)
    {
        out << (long)node << "->" << (long)(c.ptr) << "[label = \"" << c.label << "\"]\n";
        toDotty(c.ptr,out);
    }
}


template<typename Value>
void TrieMap<Value>::free(typename TrieMap<Value>::TrieNode *node)
{
    if(node == nullptr)
        return;

    for(auto c: node->children)
    {
        free(c.ptr);
    }
    if (node->value != nullptr) delete node->value;
    delete node;
}



template<typename Value>
TrieMap<Value>::iterator::iterator(TrieNode *root)
{
    if(root == nullptr)
        return;
    s.push({root,""});
    skip_non_values();
}

template<typename Value>
void TrieMap<Value>::iterator::skip_non_values()
{
    while(!s.empty() && s.top().first->value == nullptr)
    {
        next();
    }
}

template<typename Value>
void TrieMap<Value>::iterator::next()
{
    std::pair<TrieNode*,std::string> t = s.top(); s.pop();
    for(child c : t.first->children)
    {
        s.push({c.ptr,t.second+c.label});
    }
}

template<typename Value>
std::string TrieMap<Value>::iterator::operator*() const
{
    return s.top().second;
}

template<typename Value>
typename TrieMap<Value>::iterator& TrieMap<Value>::iterator::operator++()
{
    next(); skip_non_values();
    return *this;
}

template<typename Value>
bool TrieMap<Value>::iterator::operator!=(const iterator &other) const
{
    return s != other.s;
}

template<typename Value>
typename TrieMap<Value>::iterator TrieMap<Value>::begin() const
{
    return iterator(root);
}

template<typename Value>
typename TrieMap<Value>::iterator TrieMap<Value>::end() const
{
    return iterator(nullptr);
}
