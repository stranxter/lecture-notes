#include <iostream>
#include <cassert>

template <typename T>
struct box
{
    box(const T &d, box<T> *n):data(d), next(n){}
    box(){}
    T data;
    box<T>* next;
};


template <typename T>
class LList
{
public:

    LList ()
    {
        first = nullptr;
    }

    LList (const LList<T>& other)
    {
        copy (other);
    }


    LList<T>& operator = (const LList<T>& other)
    {
        if (this != &other)
        {
            clear();
            copy (other);

        }
        return *this;
    }

    void push (const T& newElementValue)
    {
        //1. Създаваме нова двойна кутия
        box<T> *newNode = new box<T>;
        newNode->data = newElementValue;
        //2. Свързваме новата двйна кутия със стария списък
        newNode->next = first;
        //3. Правим newNode да е новият първи елемент на списъка
        first = newNode;
        
        //first = new box<T> (newElementValue,first);
    }

    void insertAt (size_t index, const T& newElementValue)
    //ако inxex >= броя на елементите, вмъкваме в края
    {
        if (first == nullptr || index == 0)
        {
            push (newElementValue);
            return;
        }
        
        box<T> *previous = locate (index-1);
        assert (previous != nullptr);

        box<T> *newBox = new box<T>;
        newBox->data = newElementValue;
        newBox->next = previous->next;
        previous->next = newBox;
        //current->next = new box<T> (newElementValue,current->next);
    }

    void deleteAt (size_t index)
    {
        if (index == 0)
        {
            pop();
            return;
        }

        box<T> *previous = locate (index-1);
        assert (previous != nullptr);
        assert (previous->next != nullptr);

        box<T> *save = previous->next;
        previous->next = previous->next->next;
        delete save;
    }

    void print () const
    {
        box<T> *current = first;
        while (current != nullptr)
        {
            std::cout << current->data;
            current = current->next;
            if (current != nullptr)
            {
                std::cout << "--->";
            }  
        }
        std::cout << std::endl;
    }

    void pop ()
    {
        assert (first != nullptr);
        box<T> *save = first->next;
        delete first;
        first = save;
    }



    ~LList ()
    {
        clear();
    }

private:
    box<T> *first;


    void copy (const LList<T>& other)
    {
        //фунцкиоята приема, че списъкът е
        //празен или неинициализиран

        box<T> *toCopy = other.first;
        box<T> *previouslyCopied = nullptr;

        //копиране на празен списък
        if (other.first == nullptr)
        {
            first = nullptr;
            return;
        }
        //отделно оравим копие на първия елемент, за да можем да
        //го "завържем" за чл. данната first
        first = new box<T> (other.first->data,nullptr);
        //previouslyCopied адреса на последно създадения елемент 
        //(на предишна стъпка от цикъла по-долу)
        previouslyCopied = first;
        toCopy = toCopy->next;

        while (toCopy != nullptr)
        {
            previouslyCopied->next 
                    = new box<T> (toCopy->data,nullptr);
            previouslyCopied = previouslyCopied->next;
            toCopy = toCopy->next;
        }

    }

    void clear ()
    {
        while (first != nullptr)
        {
            pop();
        }
    }

    box<T>* locate (size_t index)
    {
        box<T> *crr = first;
        while (index > 0 && crr != nullptr)
        {
            crr = crr->next;
            --index;
        }
        return crr;
    }
};

int main ()
{
    LList<int> l;


    l.push(5);
    l.push(4);
    l.push(3);
    l.push(2);
    l.push(1);

    l.print ();

    l.insertAt (3,7);
    l.print();

    l.deleteAt (3);
    l.print();

    std::cout << "===============\n";   
    LList<int> l2 (l);

    l2.print();
    l2.pop ();
    l2.print();
    l.print();

    std::cout << "===============\n";   
    LList<int> l3;

    l3 = l;
    l3.print();
    l3.pop ();
    l3.print();
    l.print();



}