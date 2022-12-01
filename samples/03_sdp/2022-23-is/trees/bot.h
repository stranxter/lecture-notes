#pragma once
#include <iostream>


template <typename T>
struct Maybe
{
    T value;
    bool defined;
    Maybe():defined(false){}
    Maybe(const T &v):value(v),defined(true){}
};

template <typename T> //<
class BinOrdTree
{
    public:
    BinOrdTree();
    BinOrdTree(const BinOrdTree<T>&);

    void add(const T&);
    void addRec(const T&);
    void toDotty(std::ostream&);

    bool member(const T& x);
    size_t size();
    bool checkOrder();

    BinOrdTree<T>& operator=(const BinOrdTree<T>&);

    ~BinOrdTree();

    private:
    struct box
    {
        T data;
        box *left;
        box *right;
    };

    box* root;

    void add(box *&,const T&);
    void toDotty(box *, std::ostream &out);
    void printDotStatements(box *, std::ostream &out);

    box* copy(const box*);
    void clear(box* root);

    bool member(box *,const T&);
    size_t count(box *);
    bool checkOrder(box *, const Maybe<T>&, const Maybe<T>&);

};