#pragma once

template <class T>
class LList
{
    public:

    using value_type = T;


    LList();

    void push(const T&);
    const T& get(size_t i) const;
    size_t size() const;
    bool insertAt(size_t i, const T&);
    bool pop();
    bool deleteAt(size_t i);
    const T& operator[] (size_t i);

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
        Iterator(box *init);

        bool operator != (const Iterator& other) const;
        Iterator& operator ++();
        T operator *();

        private:
        box* current;     

    };

    Iterator begin();
    Iterator end();


    private:


    box* locate(size_t i) const;

    box *first;
};