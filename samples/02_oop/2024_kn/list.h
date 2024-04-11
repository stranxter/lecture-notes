#pragma once

#include <iostream>

template <typename T>
class List
{
    public:
    using value_type = T;
    struct box
    {
        T data;
        box *next;
    };
    
    class Iterator
    {
        public:

        Iterator(box *_current);

        Iterator& operator++();
        T& operator*();
        bool operator!=(const Iterator&);

        private:
        box *current;
    };

    Iterator begin();
    Iterator end();

    List();
    List(const List<T>& other);

    void push(const T& x);
    void pop();
    int size() const;
    T& operator[](unsigned int i);

    List<T>& operator=(const List<T> &other);
    bool operator==(const List<T> &other) const;

    void clear();

    ~List();

    private:
    box *first;
    int current_size;
    void copy(const List<T>& other);
    

};

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& l);

