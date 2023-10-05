#pragma once

template <typename T>
class DLList
{
    public:
    DLList();
    DLList(const DLList&);
    DLList(const DLList&&);

    void push_front(const T&);
    void push_back(const T&);
    unsigned int size() const;

    bool pop_back();
    bool pop_front();

    private:
    struct node
    {
        T data;
        node *next, *prev;
    };

    public:
    class iterator
    {
        public:

        iterator(node *ptr, node* const *);

        T operator*() const;
        iterator& operator++();
        iterator& operator--();
        bool operator != (const iterator&);

        private:
        node* current;
        node* const* ptr_to_last;
    };

    iterator begin();
    iterator end();
    
    void remove(const iterator&);

    ~DLList();
    
    private:
    node *first, *last;
    unsigned count;
};