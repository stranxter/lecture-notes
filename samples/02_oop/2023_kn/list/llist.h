#pragma once

template <typename T, typename ElemRef>
class LListIterator;

template <typename T>
class LList
{

    public:
    LList();
    LList(const LList<T> &other);

    void push(const T& x);
    void pop();
    void insertAt(size_t i, const T& x);
    void deleteAt(size_t i);

    //д.р. operator =

    void print() const;

    size_t size() const;

    T& operator[](size_t i);
    T operator[](size_t i) const;

    using iterator = LListIterator<T,T&>;
    using const_iterator = LListIterator<T,const T&>;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    ~LList();

    using elem_type = T;

    private:
    struct box
    {
        T data;
        box *next;
    };

    box* locateBox(size_t i) const;

    box* rec_copy(box* other_first) const;

    box* first;

    friend iterator;
    friend const_iterator;
};

template <typename T, typename ElemRef>
class LListIterator
{
    public:
    LListIterator(typename LList<T>::box*);

    ElemRef operator*();

    LListIterator<T,ElemRef>& operator++();
    bool operator!= (const LListIterator &other);

    private:
    typename LList<T>::box *position;
};

