#pragma once

template <typename T>

class BinTree
{

    public:
    BinTree();
    void insert(const char *trace, const T& x);
    void insertBOT(const T& x);
    void print() const;
    void printHaskell(std::ostream&) const;
    bool member(const T&) const;
    T sum() const;
    void fromHaskell(std::istream&);
    T max() const;
    T min() const;

    bool remove(const T&x);


    private:
    struct Node
    {
        T value;
        Node *left, *right;
    };

    void insertBOThelper(Node *&current, int x);
    void printHelper(Node *current, int depth) const;
    bool memberHelper(Node *current, const T& x) const;
    T sumHelper(Node *current) const;
    void printHaskellHelper(Node *current,std::ostream&) const;
    T max(Node *current) const;
    T min(Node *current) const;
    
    Node *createTreeFromHaskell(std::istream&);

    bool removeHelper(Node *&current, const T&x);
    
    
    Node *root;

};

