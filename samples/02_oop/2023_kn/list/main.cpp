#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "llist.cpp"
#include <iostream>

TEST_CASE("Text Exception")
{

    LList<int> l;
    CHECK_THROWS(l.insertAt(100,100));

}

template <typename T>
void printList(const LList<T>& l)
{
    for(int i = 0; i < l.size(); ++i)
    {
        std::cout << l[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{

    LList<int> l;
    
    l.push(10);
    l.push(9);
    l.push(8);
    l.push(7);
    l.push(6);

    l.print();
    std::cout << std::endl;

    l[2] = 10;


    l.insertAt(1,100);
    printList(l);

    l.insertAt(3,300);
    printList(l);

    l.insertAt(5,500);
    printList(l);

    l.deleteAt(5);
    printList(l);

    l.deleteAt(3);
    printList(l);

    l.deleteAt(1);
    printList(l);

    LList<int> l2(l);

    printList(l2);
    l.pop();
    printList(l2);

    doctest::Context().run();
}
