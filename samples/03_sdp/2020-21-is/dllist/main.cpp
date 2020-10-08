#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>

#include "dllist.h"

TEST_CASE("Test Forward Iteration")
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4;

    /*
    DLList<int>::Iterator it = list.begin();
    int count = 0;
    while (it != list.end())
    {
        CHECK(*it==4-count);
        ++count;
        ++it;
    }*/

    int count = 0;
    for (int x:list)
    {
         CHECK(x==4-count);
         ++count;
    }

}

TEST_CASE("Test Empty")
{
    DLList<int> list;

    CHECK(list.empty()==true);

    list += 1;
    CHECK(list.empty()==false);

    list += 2;
    CHECK(list.empty()==false);

}

TEST_CASE("Test Backwards Iteration")
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4; 

    if (list.empty())
    {
        DLList<int>::Iterator it = list.end();
        int count = 4;
        do 
        {
            CHECK(*it==count);
            --count;
            --it;
        } while (it != list.begin());
    }

}

TEST_CASE("Test Exceptions")
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4; 

    DLList<int>::Iterator it = list.end();
    try
    {
        ++it;
        
        CHECK(false);

    }
    catch(const std::out_of_range& e)
    {
        //CHECK(true);
    }
    catch (...)
    {
        CHECK(false);
    }

    std::cout << "Still alive...";

}

TEST_CASE("Test Reverse")
{
    DLList<int> list;
    list.reverse();

    CHECK(list.empty() == true);

    list += 1;

    list.reverse();
    CHECK(*list.begin()==1);

    list += 2;
    list += 3;
    list += 4; //4 3 2 1 

    list.reverse();
                //1 2 3 4 

    int count = 1;
    for (int x:list)
    {
         CHECK(x==count);
         ++count;
    }

}

TEST_CASE("Test Delete")
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4; //4 3 [2] 1

    DLList<int>::Iterator it = list.begin();
    ++(++it);
    list.deleteAt(it);

    it = list.begin();
    ++it;
    CHECK (*it==3);
    ++it;
    CHECK (*it==1);

    it = list.begin();
    list.deleteAt(it); //[4] 3 [2] 1

    it = list.begin();
    CHECK(*it == 3);

    ++it;
    list.deleteAt(it); //[4] 3 [2] [1]

    it = list.begin();
    CHECK(*it == 3);
}


int main()
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list += 4;


    std::cout << list << std::endl;

    DLList<int>::Iterator it = list.begin();
    (++(++it));
    list.deleteAt(it);

    std::cout << list << std::endl;
 
 
    // пускане на тестовете
    doctest::Context().run();

}