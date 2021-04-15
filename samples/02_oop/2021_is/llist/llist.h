#pragma once

template <class T>
class LList
{
    public:

    LList();

    void push(const T&);
    const T& get(size_t i) const;
    size_t size() const;
    bool insertAt(size_t i, const T&);
    bool pop();
    bool deleteAt(size_t i);

    private:

    struct box 
    {
        T data;
        box *next;
    };

    box* locate(size_t i) const;

    box *first;
};