#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>
#include <stack>

template<class T>
class BinTree
{

    public:
    BinTree();

    /*
        Добавя елемент в дървото на позиция,
        пососчена от следата trace. На тази позиция не се 
        допуска да има елемент в дървото преди вмъкването.

    */
    void add (const T &x, const char *trace);
    void printall (std::ostream&);
    void printdot (std::ostream&);

    T operator[](const char*) const;
    void set (const T &x, const char *trace);

    bool operator == (const BinTree<T>&) const;

    void toScheme (std::ostream&);
    void fromScheme (std::istream&);

    ~BinTree ();

    private:
    struct node
    {
        T data;
        node *left, *right;
    };

    public:

    class Position
    {
        public:
        Position (node*&);
        Position left() const;
        Position right() const;
        bool empty() const;
        void set(const T&);
        T get() const;
    
        private:
        node *&current;

    };

    Position rootPosition();


    class Iterator
    {
        public:
        Iterator(Position, bool);
        T operator *();
        Iterator& operator ++();
        bool operator != (const Iterator&);
        private:
        std::stack<Position> s;
    };

    Iterator begin();
    Iterator end();


    private:

    node *root;

    void printhelp (std::ostream&, node*);
    void printdothelp (std::ostream&, node*);
    void toScheme (std::ostream&, node*);

    node* locate (const char*) const;

    void deleteTree (node*);

    bool equalTrees (node*, node*) const;

    node* readScheme (std::istream&);

};


#endif