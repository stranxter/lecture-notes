#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <vector>

#include "dllist/dllist.cpp"

TEST_CASE("Test Head Removal")
{
    std::vector<int> elems = {1,2,3,4,5};

    //create list
    DLList<int> l;
    for(int x: elems)
    {
        l.push_back(x);
    }

    for(int i = 0; i < elems.size();++i)
    {
        CHECK(l.size() == elems.size() - i);
        CHECK(*l.begin() == elems[i]);
        l.pop_front();
        l.push_front(100);
        CHECK(l.size() == elems.size() - i);
        CHECK(*l.begin() == 100);
        l.pop_front();
    }   
}

int main()
{

    DLList<int> l;

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);

    DLList<int>::iterator current = l.begin();
    while (current != l.end())
    {
        std::cout << *current << " ";
        ++current;
    }
    std::cout << std::endl;

    current = l.end();

    if (current != l.begin())
    {
        do
        {
            --current;
            std::cout << *current << " ";
        }while(current != l.begin());
    }

    doctest::Context().run();
}