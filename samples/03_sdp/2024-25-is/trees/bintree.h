#pragma once


template <typename T>

class BinTree
{

    public:
    BinTree();
    void insert(const char *trace, const T& x);
    void insertBOT(const T& x);
    void print() const;
    bool member(const T&) const;
    T sum() const;


    private:
    struct Node
    {
        T value;
        Node *left, *right;
    };

    void printHelper(Node *current, int depth) const;
    bool memberHelper(Node *current, const T& x) const;
    T sumHelper(Node *current) const;
    Node *root;

};

