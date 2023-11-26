#pragma once
#include <vector>

template <typename T>
//ключове само {a..z}*
class Trie
{
    struct box
    {
        box(T*);
        T* value;
        //std::vector<std::pair<char,box*>> children;

        // a   b   c d e 
        // |   |   ...
        // \/  \/
        
        box* children[26];
        bool hasChildren();
    };

    public:
    Trie();
    
    T& operator[](const char*);   // table[key] --> value
    bool contains(const char*) const;
    bool remove(const char*);

    private:
    box *root;    

    bool removeHelp(const char*, box *&current);

};