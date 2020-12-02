#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


#include <iostream>
#include <vector>
#include "dllist.h"

TEST_CASE("Test Iterator")
{

    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4;
    list += 5; //5,4,3,2,1

    int counter = 0;
    for (int x : list)
    {
        CHECK(x==5-counter);
        std::cout << x << std::endl;
        ++counter;
    }
}

TEST_CASE("Test Reverse Iteratoration")
{

    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4;
    list += 5; //5,4,3,2,1

    DLList<int>::Iterator it = list.begin();

    if (!list.empty())
    {
        DLList<int>::Iterator it = list.last();
        int count = 1;
        
        std::cout << *it << std::endl;
        do
        {
            --it;
            ++count;
            std::cout << *it << std::endl;
            CHECK(*it==count);            
            
        }
        while (it != list.begin());
    }

}


TEST_CASE("Test Iterator Exception")
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4;
    list += 5; //5,4,3,2,1

    DLList<int>::Iterator it = list.end();

    try
    {
        ++it; 
        CHECK(false);   
    }
    catch(const std::out_of_range& e)
    {
        CHECK(true);
    }
    catch (...)
    {
        CHECK(false);
    }

}

int main()
{

    // пускане на тестовете
    doctest::Context().run();

}