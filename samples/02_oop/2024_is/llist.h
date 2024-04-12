#pragma once


template <typename T>
class LList
{

    private:
    struct box
    {
        T data;
        box *next;
    };

    public:
    class Iterator
    {
        public:

        Iterator(box*);

        T& operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator&) const;

        private:
        box *current;
    };

    Iterator begin();
    Iterator end();

    LList();
    LList(const LList<T>&);

    void push(const T&);
    unsigned int getSize() const;
    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;

    void insertAfter(unsigned int, const T&);
    LList<T>& operator=(const LList<T>&);
    void clear();

    ~LList();

    using value_type = T;

    private:
    box *first;

    box* locate(unsigned int) const;
    void copy(const LList<T>&);
};