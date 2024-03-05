#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <vector>

#include "dllist/dllist.cpp"


template <typename Container>
bool compare(const Container& c1, const Container& c2)
{
    typename Container::const_iterator i1 = c1.begin();
    typename Container::const_iterator i2 = c2.begin();

    while(i1 != c1.end() && 
          i2 != c2.end() &&
          *i1 == *i2)
    {
        ++i1;
        ++i2;
    }

    return !(i1 != c1.end()) && !(i2 != c2.end());
}

TEST_CASE("Test Copying")
{
    std::vector<int> elems = {1,2,3,4,5};  
    DLList<int> l;
    for(int x: elems)
    {
        l.push_back(x);
    }

    DLList<int> l2(l),l3;
    CHECK(compare(l,l2));

    *l.begin() = 100;
    CHECK(*l.begin() != *l2.begin());

    l.pop_front();
    CHECK(!compare(l,l2));

    DLList<int> l4(l3);
    CHECK(l4.size() == 0);
    l4.push_front(10);
    CHECK(*l4.begin() == 10);
    CHECK(!(++l4.begin() != l4.end()));


    
}


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
        *current = *current + 1;
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