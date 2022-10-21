#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <cstdlib>
#include "llist/llist.cpp"

TEST_CASE("Push test")
{

    LList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);

    CHECK(l.size() == 3);
    CHECK(l[0]==2);
    CHECK(l[1]==1);
    CHECK(l[2]==0);
}

TEST_CASE("Test Clear")
{
    LList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);

    l.clear();
    CHECK(l.size()==0);
    l.clear();
    l.push(0);
    CHECK(l.size()==1);
}

TEST_CASE("Test Copy")
{
    LList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);

    LList<int> l2(l);

    CHECK(l2.size() == 3);
    CHECK(l2[0]==2);
    CHECK(l2[1]==1);
    CHECK(l2[2]==0);
 
    l[1]=70;
    CHECK(l2[1]==1);
    
    l.clear();

    CHECK(l2.size() == 3);
    CHECK(l2[0]==2);
    CHECK(l2[1]==1);
    CHECK(l2[2]==0);


}

TEST_CASE("Test Assignment")
{
    LList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);

    LList<int> l2;

    l2 = l;

    CHECK(l2.size() == 3);
    CHECK(l2[0]==2);
    CHECK(l2[1]==1);
    CHECK(l2[2]==0);

    
    l[1]=70;
    CHECK(l2[1]==1);
    
    l.clear();

    CHECK(l2.size() == 3);
    CHECK(l2[0]==2);
    CHECK(l2[1]==1);
    CHECK(l2[2]==0);

}

TEST_CASE("Test Sum")
{

    LList<int> l;

    CHECK(sum(l) == 0);

    l.push(0);
    l.push(1);
    l.push(2);

    CHECK(sum(l) == 3);

    LList<double> l2;
    l2.push(1.1);
    l2.push(2.2);
    CHECK(sum(l2) <= 3.3 + 0.00005);
    CHECK(sum(l2) >= 3.3 - 0.00005);

}


int main()
{
    LList<int> l;

    l.push(0);
    l.push(1);
    l.push(2);
    l.push(3);

    std::cout << sum(l) << std::endl;

    l.print();

    std::cout << l.size() << std::endl;


    for (size_t i = 0; i < l.size(); ++i)
    {
        ++l[i];
    }

    for (size_t i = 0; i < l.size(); ++i)
    {
        std::cout << i << ":" << l[i] << std::endl;
    }

    LList<int> save;

    save = l;

    l.clear();



    doctest::Context().run();

    return 0;
}

