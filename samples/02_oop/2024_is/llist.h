#pragma once


template <typename T>
class LList
{

    public:
    LList();
    LList(const LList<T>&);

    void push(const T&);
    unsigned int size() const;
    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;

    void insertAfter(unsigned int, const T&);
    LList<T>& operator=(const LList<T>&);
    void clear();

    ~LList();

    private:
    struct box
    {
        T data;
        box *next;
    };
    box *first;

    box* locate(unsigned int) const;
    void copy(const LList<T>&);
};