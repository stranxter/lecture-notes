#include <iostream>

template <typename T>
class List
{
    public:

    struct box
    {
        T data;
        box *next;
    };

    box *first;

    List():first(nullptr)
    {}



    void pop()
    {
        //         ------------
        //         |           |
        //         |           \/
        //first ---|  [1]---->[2]---->[3] //first ----> [1]---->[2]---->[3]

        box *save = first;
        first = first->next;
        delete save;
    }

    void push(const T& x)
    {
        //first --|  [1]---->[2]---->[3] //first ----> [1]---->[2]---->[3]
        //        |   ^
        //       \/   |
        //       [x]--|

        //first ----> [x] -----> [1]---->[2]---->[3]

        //box *myNewElement = new box{x,first};
        //first = myNewElement;

        first = new box{x,first};

    }

    int size() const
    {
        int count = 0;
        box *crr = first;
        while (crr != nullptr)
        {
            ++count;
            crr = crr->next;
        }

        return count;

    }

    T& operator[](unsigned int i)
    {
        box *crr = first;
        for(int count = 0; count < i; ++count)
        {
            crr = crr->next;
        }

        return crr->data ;
    }


    void clear()
    {
        box *save = first;
        while (first != nullptr)
        {
            save = first->next;
            delete first;
            first = save;
        }        
    }

    ~List()
    {

        clear();

    }

    List(const List<T>& other)
    {
        copy(other);
    }

    void copy(const List<T>& other)
    {
        if(other.first == nullptr)
        {
            first = nullptr;
            return;
        }

        first = new box{other.first->data, nullptr};
        box *previous = first;
        box *otherCurent = other.first->next;
        
        while (otherCurent != nullptr)
        {
            previous->next = new box{otherCurent->data,nullptr};
            otherCurent = otherCurent->next;
            previous = previous->next;
        }           
    }

    List<T>& operator=(const List<T> &other)
    {
        if(this != &other)
        {
            clear();
            copy(other);
        }
        return *this;
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& l)
{
    
    typename List<T>::box *crr = l.first;
    out << "{";
    while (crr != nullptr)
    {
        out << " " <<  crr->data;
        crr = crr->next;
    }
    out << "}";
    return out;
}

int main()
{

    List<int> l1;

    l1.push(10);
    l1.push(20);
    l1.push(30);

    std::cout << l1.size() << std::endl;
    std::cout << l1 << std::endl;

    l1.pop();

    std::cout << l1 << std::endl;

    for(int i = 0; i < l1.size(); ++i)
    {
        ++l1[i];
    }
    std::cout << l1 << std::endl;

    List<int> l2;

    l2.push(10);
    l2.push(20);

    List<int> l3;

    l3 = l1;
    std::cout << l3 << std::endl;
    l1[0] = 100;
    std::cout << l1 << std::endl;
    std::cout << l3 << std::endl;

    List<int> empty;
    l3 = empty;

    List<int> l5(l1);
/*
    std::cout << l1 + l2 << std::endl;


    l1.deleteAt(3);

    std::cout << l1 << std::endl;

    l1.insertAt(3,450);

    std::cout << l1 << std::endl;
*/
}