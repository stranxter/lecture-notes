#pragma once

template <typename T>
class DLList
{
    public:
    DLList();
    DLList(DLList&);
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

    template <typename ElRef>
    class iterator_template
    {
        public:

        iterator_template(node *ptr, node* const *);

        ElRef operator*() const;
        iterator_template& operator++();
        iterator_template& operator--();
        bool operator != (const iterator_template&);

        private:
        node* current;
        node* const* ptr_to_last;
    };

    public:
    using iterator = iterator_template<T&>;
    using const_iterator = iterator_template<T>;

    const_iterator begin() const;
    iterator begin();
    const_iterator end() const;
    iterator end();
    
    void remove(const iterator&);

    ~DLList();
    
    private:
    node *first, *last;
    unsigned count;
};