#include <iostream>

template <typename T>
struct box
{
    T data;
    box* next;
};

template <typename T>
class LList
{
    public:

    LList():first(nullptr),crrsize(0){}

    LList& push(const T& newdata)
    {
        first = new box<T>{newdata,first};
        ++crrsize;
        return *this;
        
        /*box<T> *newbox = new box<T>;
        newbox->data = newdata;
        newbox->next = first;

        first = newbox;*/
    }

    LList(const LList& other)
    {
        box<T> *crr = other.first,
               *newElement = nullptr,
               *lastCreated = nullptr;


        first = new box<T>{other.first->data, nullptr};

        crr=crr->next;
        lastCreated = first;

        while(crr != nullptr)
        {
            newElement = new box<T>{crr->data,nullptr};
            crr = crr->next;
            lastCreated->next = newElement;
            lastCreated = newElement;
        }

        crrsize = other.crrsize;

    }

    bool insertAfter(const T& newdata, unsigned position)
    {
        box<T> *newbox = new box<T>{newdata,nullptr};
        ++crrsize;

        //[1|]->[2|null]
        //       ^
        //       |
        //      crr

        box<T> *crr=findByIndex(position);

        if(crr == nullptr)
        {
            return false;
        }

        newbox->next = crr->next;
        crr->next = newbox;

        return true;
    }

    T& operator[](unsigned index) 
    {
        box<T> *crr = findByIndex(index);
        
        if(crr == nullptr)
        {
            throw "Index too large.";
        }

        return crr->data;
    }

    T operator[](unsigned index) const
    {
        box<T> *crr = findByIndex(index);
        
        if(crr == nullptr)
        {
            throw "Index too large.";
        }

        return crr->data;
    }

    unsigned size() const
    {
        return crrsize;
    }

    ~LList()
    {
        box<T> *crr = first,
               *save;
        while(crr != nullptr)
        {
            save = crr->next;
            delete crr;
            crr=save;
        }
    }


    private:
    box<T>* first;
    unsigned crrsize;


    box<T>* findByIndex(unsigned index) const
    {
        if (index >= size())
            return nullptr;

        box<T> *crr = first;
        for(int i=0; i < index && crr != nullptr; ++i)
        {
            crr=crr->next;
        }
        return crr;
    }


};

template <typename T>
std::ostream& operator<<(std::ostream &out, const LList<T>& l)
{
    for(int i = 0; i < l.size(); ++i)
    {
        out << l[i] << " ";
    }

    return out;
}



int main()
{
    LList<int> l;

    l.push(10).push(20).push(30).push(40).push(50).push(60);

    l.insertAfter(100,2);

    l[1] = 1000;

    std::cout << l << std::endl;

    LList<int> l2 (l);

    std::cout << l2 << std::endl;



}