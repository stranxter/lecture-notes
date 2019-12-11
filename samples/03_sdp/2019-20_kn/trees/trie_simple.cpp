#include <iostream>
#include <vector>
#include <string>

struct TrieNode;

struct TrieNode
{
    bool eow;
    TrieNode *children[26];
    TrieNode ()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }

};

void trieInsert (TrieNode *&root, const char *s)
{

    if (root == nullptr)
    {
        root = new TrieNode;
    }

    if (s[0] == 0)
    {
        root->eow = true;
        return;
    }

    assert (s[0] >= 'a' && s[0] <= 'z');

    trieInsert (root->children[s[0]-'a'],s+1);
}

void dottyPrintHelp (std::ostream& out, TrieNode *root)
{
    if (root==nullptr)    
    {
        return;
    }

    if (root->eow)
    {
        out << (long)root << "[label=\"X\"];\n";
    } else {
        out << (long)root << "[label=\" \"];\n";
    }
    

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != nullptr)
        {
            out << (long)root 
                << "->" 
                << (long)(root->children[i]) 
                << "[label=\""
                << (char)(i+'a')
                << "\"];\n";
        }
        dottyPrintHelp (out,root->children[i]);
    }
}


void dottyPrint (std::ostream& out, TrieNode *root)
{
    out << "digraph G{\n";
    dottyPrintHelp (out, root);
    out << "}";
}



int main ()
{
    TrieNode *root = nullptr;

    trieInsert (root, "toy");
    trieInsert (root, "ten");
    trieInsert (root, "to");
    trieInsert (root, "two");

    dottyPrint (std::cout, root);
    
}