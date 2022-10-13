#pragma once


template <typename T>
class LList
{
    public:
        LList();

        void push(const T&);
        void print() const;

        T& operator[] (size_t i);
        T operator[] (size_t i) const;

        LList<T>& operator= (const LList<T>&);

        size_t size() const;

        ~LList();

        void clear();

    private:
        struct box
        {
            T data;
            box* next;
        };

        box* first;

        void copy(box*);
        
        box* copy2(box*);

};