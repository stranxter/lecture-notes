#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

#include "llist.cpp"

TEST_CASE("Test Push")
{
    LList<int> l;

    CHECK(l.size() == 0);

    l.push(1);
    l.push(2);
    l.push(3);

    CHECK(l.size() == 3);
    CHECK(l[0]==3);
    CHECK(l[1]==2);
    CHECK(l[2]==1);
}

TEST_CASE("Test Indexing")
{
    LList<int> l;
    l.push(1);
    l[0] = 2;

    CHECK(l[0]==2);
    CHECK(l.size()==1);

}

TEST_CASE("Test Insert")
{
    LList<int> l;

    CHECK(l.size() == 0);

    l.push(1);
    l.push(2);
    l.push(3);//3,2,1

    l.insertAfter(11,1);//3,2,11,1
    l.insertAfter(12,3);//3,2,11,1,12


    CHECK(l.size() == 5);
    CHECK(l[0]==3);
    CHECK(l[1]==2);
    CHECK(l[2]==11);
    CHECK(l[3]==1);
    CHECK(l[4]==12);
}

TEST_CASE("Test Pop")
{
    LList<int> l;

    CHECK(l.size() == 0);

    l.push(1);
    l.push(2);
    l.push(3);//3,2,1

    CHECK(l.size() == 3);

    l.pop();
    l.pop();

    CHECK(l.size() == 1);
    CHECK(l[0]==1);

    l.pop();
    CHECK(l.size() == 0);
}


TEST_CASE("Test Delete After")
{
    LList<int> l;

    CHECK(l.size() == 0);

    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);

    CHECK(l.size() == 4);

    l.deleteAfter(3);
    CHECK(l.size() == 4);

    l.deleteAfter(0);//4,3,2,1 -> 4,2,1
    CHECK(l.size() == 3);
    CHECK(l[0]==4);
    CHECK(l[2]==1);

    l.deleteAfter(1);//4,2,1 -> 4,2
    CHECK(l.size() == 2);
    CHECK(l[0]==4);
    CHECK(l[1]==2);

}

TEST_CASE("Test Push Back")
{
    LList<int> l;

    CHECK(l.size() == 0);

    l.push(1);
    l.push(2);
    l.push(3);
    l.push_back(10);
    l.push_back(20);
    l.push_back(30); //3,2,1,10,20,30

    CHECK(l.size() == 6);

    CHECK(l[3]==10);
    CHECK(l[5]==30);

}


int main ()
{
    // пускане на тестовете
    doctest::Context().run();    

}