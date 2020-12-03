#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>
#include <stack>

template <class T>
class BinTree
{
    public:

    BinTree();

    //Конструктор за копиране
    //Оператор за присвояване
    //Деструктор
    

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
        Position (node *&);


        Position left() const;
        Position right() const;
        T get() const;
        void set(const T&);
        bool empty() const;

        private:
        node *&current;

    };

    class Iterator
    {
        public:
        Iterator (node*);

        T operator *() const;
        Iterator& operator ++();
        bool operator != (const Iterator&) const;

        private:
        std::stack<node*> s;
        
    };

    Iterator begin();
    Iterator end();

    Position rootPosition();

    //Вмъква ново листо в дървото на дадена позиция. Не позволява 
    //изменяне на съшествуващи елементи
    void add (const T&, const char*);
    T get (const char*) const;
    T& operator [](const char*);
    void toDotty(std::ostream& out);

    bool operator == (const BinTree<T>&);
    
    void toScheme (std::ostream&);
    void fromScheme (std::istream&);

    private:


    void toDottyHelp (std::ostream& out, node*);
    node* locate (const char*) const;
    void toScheme (std::ostream&, node*);
    node* readSchemeRec (std::istream&);

    bool equaltrees (node*, node*);
        void clear(node*);

    node *root;
};

#endif