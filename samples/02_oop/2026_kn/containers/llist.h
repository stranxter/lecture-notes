#include <iostream>

template <typename T>
struct box
{
    T data;
    box* next;
};

template <typename T>
class ListIterator
{
    public:

    ListIterator(box<T> *init);

    T operator*() const;
    ListIterator& operator++();
    bool operator!=(const ListIterator&);

    private:
    box<T> *current;
};

template <typename T>
class LList
{
    public:

    using value_type = T;

    LList():first(nullptr),crrsize(0){}
    LList(const LList& other);

    LList& push(const T& newdata);
    bool insertAfter(const T& newdata, unsigned position);

    T& operator[](unsigned index);
    T operator[](unsigned index) const;
    unsigned length() const;

    ListIterator<T> begin() const;
    ListIterator<T> end() const;

    ~LList();

    private:
    box<T>* first;
    
    unsigned crrsize;

    box<T>* findByIndex(unsigned index) const;

};

template <typename T>
std::ostream& operator<<(std::ostream &out, const LList<T>& l);
