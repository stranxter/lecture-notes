#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

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

    void insertOrdered (const T&);

    T operator[](const char*) const;
    void set (const T &x, const char *trace);

    bool member (const T&) const;

    bool operator == (const BinTree<T>&) const;
    
    T sum () const;

    void toScheme (std::ostream&);
    void fromScheme (std::istream&);

    ~BinTree ();

    private:
    struct node
    {
        T data;
        node *left, *right;
    };

    node *root;

    void printhelp (std::ostream&, node*);
    void printdothelp (std::ostream&, node*);
    void toScheme (std::ostream&, node*);

    node* locate (const char*) const;

    bool memberhelp (const T&, node*) const;

    T sum (node *) const;

    void deleteTree (node*);

    bool equalTrees (node*, node*) const;

    node* readScheme (std::istream&);

    void insertOrdered (const T&, node*&);
};


#endif