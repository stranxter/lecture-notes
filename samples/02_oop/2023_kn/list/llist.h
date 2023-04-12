#pragma once

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

    ~LList();

    private:
    struct box
    {
        T data;
        box *next;
    };

    box* locateBox(size_t i) const;

    box* rec_copy(box* other_first) const;

    box* first;
};