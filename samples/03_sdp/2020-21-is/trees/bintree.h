#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
class BinTree
{
    public:

    BinTree();

    //Вмъква ново листо в дървото на дадена позиция. Не позволява 
    //изменяне на съшествуващи елементи
    void add (const T&, const char*);
    T get (const char*) const;
    T& operator [](const char*);
    void toDotty(std::ostream& out);

    bool operator == (const BinTree<T>&);
    
    void toScheme (std::ostream&);
    void fromScheme (std::istream&);

    bool member (const T& x);
    T sum ();

    void insertOrdered (const T&);

    private:
    struct node
    {
        T data;
        node *left, *right;
    };

    void toDottyHelp (std::ostream& out, node*);
    node* locate (const char*) const;
    bool memberHelp (const T&, node*);
    T sumHelper (node*);
    void toScheme (std::ostream&, node*);
    node* readSchemeRec (std::istream&);

    bool equaltrees (node*, node*);

    void insertOrdered (const T&, node*&);

    void clear(node*);

    node *root;
};

#endif