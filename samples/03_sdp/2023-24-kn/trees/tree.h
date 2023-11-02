#pragma once


class Tree
{
    public:


    Tree();
    Tree(const Tree&);
    Tree(const Tree&&);

    Tree& operator = (const Tree&);


    void insert(int x, const char *trace);
    void print();
    void printDot();

    ~Tree();


    private:

    struct box
    {
        box *left, *right;
        int data;

    };


    void insertHelp(int x, const char *trace, box *&current);
    void print(box *&current, int depth);
    void printDot(box *&current);

    box *root;
};