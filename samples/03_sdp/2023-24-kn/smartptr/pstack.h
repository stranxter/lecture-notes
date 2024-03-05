#pragma once
#include <memory>


template <typename T>
class pstack
{
    public:

    pstack();
    pstack(const T&, const pstack&);

    pstack push(const T&) const;
    pstack pop() const;
    bool empty() const;

    T top() const;

    struct box
    {
        box(const T& _data, std::shared_ptr<box> _next):data(_data),next(_next)
        {

        }
        T data;
        std::shared_ptr<box> next;
    };

    private:
    std::shared_ptr<box> head;
};