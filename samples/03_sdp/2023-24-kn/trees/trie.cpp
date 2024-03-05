#include "trie.h"


template <typename T>
Trie<T>::box::box(T* _val):value(_val)
{
    for(int i = 0; i < 26; ++i)
    {
        children[i] = nullptr;
    }
}

template <typename T>
bool Trie<T>::box::hasChildren()
{
    for(int i = 0; i < 26; ++i)
    {
        if (children[i] != nullptr)
        {
            return true;
        }
    }   
    return false;
}


template <typename T>
Trie<T>::Trie()
{
    root = new typename Trie::box(nullptr);
}

template <typename T>
bool Trie<T>::contains(const char* key) const
{

    typename Trie<T>::box* current = root;

    while(current != nullptr && key[0] != 0)
    {
        current = current->children[key[0]-'a'];
        ++key;
    }

    return current != nullptr && 
           current->value != nullptr;
}

template <typename T>
T& Trie<T>::operator[](const char* key)
{
    typename Trie<T>::box* current = root;        

    while(key[0] != 0)
    {

        if(current->children[key[0]-'a'] == nullptr)
        {
            current->children[key[0]-'a'] = new typename Trie<T>::box(nullptr);
        }
        current = current->children[key[0]-'a'];
        ++key;
    }

    if(current->value == nullptr)
    {
        current->value = new T();
    }

    return *(current->value);
}

template <typename T>
bool Trie<T>::remove(const char* key)
{
    return removeHelp(key,root);
}

template <typename T>
bool Trie<T>::removeHelp(const char* key, typename Trie<T>::box *&current)
{
    if(current == nullptr)
    {
        return key[0] == 0;
    }

    if(key[0]==0)
    {
        if(current->value == nullptr)
        {
            return false;
        }

        delete current->value;
        if(!current->hasChildren() && current != root)
        {
            delete current;
            current = nullptr;
        }

        return true;
    }

    if(current->children[key[0]-'a'] == nullptr)
    {
        return false;
    }

    if (!removeHelp(key+1,current->children[key[0]-'a']))
    {
        return false;
    }

    if(!current->hasChildren() && 
        current->value != nullptr && 
        current != root)
    {
        delete current;
        current = nullptr;
    }

    return true;
}
