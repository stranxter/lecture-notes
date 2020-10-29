#ifndef __PSTACK_H
#define __PSTACK_H

#include <memory>

template <class T>
class pstack
{
    public:

    pstack();

    T top() const;

    pstack<T> push(const T&) const;
    pstack<T> pop() const;

    bool empty();

    private:
    struct node
    {
        node (const T&, std::shared_ptr<node>);
        T head;
        std::shared_ptr<node> tail;
        ~node();
    };


    pstack(std::shared_ptr<node>);

    std::shared_ptr<node> first;

};


#endif