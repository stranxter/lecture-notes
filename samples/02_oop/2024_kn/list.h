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

