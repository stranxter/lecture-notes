#ifndef __PSTACK_H
#define __PSTACK_H

#include <memory>

template <class T>
class pstack
{

    public:
    pstack();
    pstack<T> push(const T &x) const;
    pstack<T> pop() const;
    T top() const;
    bool empty() const;

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