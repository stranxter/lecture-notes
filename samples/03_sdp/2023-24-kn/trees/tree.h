#pragma once

#include <stack>
#include <iostream>


class TreeVisitor;

class Tree
{
    public:

    Tree();
    //Tree(const Tree&);
    //Tree(Tree&&);
    Tree(int root, Tree&&, Tree&&);

    //Tree& operator = (const Tree&);

    void insert(int x, const char *trace);
    void print();
    void printDot();

    ~Tree();

    bool member(int x);
    int sum();

    private:

    struct box
    {
        box *left, *right;
        int data;

    };

    public:

    class Iterator
    {
        public:
        Iterator(box*);
        Iterator& operator++();
        int operator *();
        bool operator != (const Iterator&);
        private:
        void windstack();
        std::stack<box*> s;
    };

    class TreeVisitor
    {
        public:
            TreeVisitor(box *);
            bool empty() const;
            int root() const;
            TreeVisitor left() const;
            TreeVisitor right() const;
        private:
            box *current;

    };

    Iterator begin() const;
    Iterator end() const;

    TreeVisitor visit();    

    private:

    void insertHelp(int x, const char *trace, box *&current);
    void print(box *&current, int depth);
    void printDot(box *&current);

    bool member(int x, box *current);
    int sum(box *current);

    box *root;
};

std::ostream& operator << (std::ostream&,Tree&);
std::istream& operator >> (std::istream&,Tree&);

