#pragma once


template <class T>
class Stack
{
    public:

    Stack();
    Stack(const Stack&);
    Stack& operator= (const Stack&);
    ~Stack();

    T top();
    void pop();
    void push(const T&);
    bool empty();
    size_t size();

    private:
    struct box
    {
        T data;
        box *next;
    };
    size_t count;
    box *head;

    box* copy(box *);
    void clear();

};