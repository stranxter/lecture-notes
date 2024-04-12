#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "llist.cpp"

TEST_CASE("Test Push")
{
    LList<int> l;

    l.push(0);
    CHECK(l.size() == 1);
    l.push(1);
    CHECK(l.size() == 2);
    l.push(2);
    CHECK(l.size() == 3);

    CHECK(l[0]==2);
    CHECK(l[1]==1);
    CHECK(l[2]==0);
}

TEST_CASE("Test Insertion")
{
    LList<int> l;

    l.push(0);
    CHECK(l.size() == 1);
    l.push(1);
    CHECK(l.size() == 2); //--->[1]---->[0]

    l.insertAfter(0,7); //--->[1]->[7]--->[0]
    CHECK(l.size()==3);
    CHECK(l[0]==1);
    CHECK(l[1]==7);
    CHECK(l[2]==0);

    l.insertAfter(2,10); //--->[1]->[7]--->[0]--->[10]
    CHECK(l.size() == 4);
    CHECK(l[3]==10);
    CHECK(l[2]==0);

}

TEST_CASE("Test Copying")
{
    LList<int> l;

    l.push(0);
    l.push(1);
    l.push(2);  

    LList<int> copy(l);

    CHECK(copy.size() == l.size());
    for (int i = 0; i < l.size(); ++i)
    {
        CHECK(copy[i]==l[i]);
    }

    copy[0]=100;
    CHECK(l[0]==2);

    LList<int> empty, empty_copy(empty);
    CHECK(empty_copy.size() == 0);
    empty_copy.push(0);
    CHECK(empty_copy[0]==0);
    CHECK(empty_copy.size() == 1);

    LList<int> size1_copy(empty_copy);
    CHECK(size1_copy.size() == 1);
    size1_copy.push(2);
    CHECK(size1_copy[0]==2);
    CHECK(size1_copy.size() == 2);
}

TEST_CASE("Test Assigment")
{
    LList<int> l;

    l.push(0);
    l.push(1);
    l.push(2);  

    LList<int> copy;
    copy = l;

    CHECK(copy.size() == l.size());
    for (int i = 0; i < l.size(); ++i)
    {
        CHECK(copy[i]==l[i]);
    }

    copy[0]=100;
    CHECK(l[0]==2);

    LList<int> empty, empty_copy;
    empty_copy = empty;
    CHECK(empty_copy.size() == 0);
    empty_copy.push(0);
    CHECK(empty_copy[0]==0);
    CHECK(empty_copy.size() == 1);

    LList<int> size1_copy;
    size1_copy = empty_copy;
    CHECK(size1_copy.size() == 1);
    size1_copy.push(2);
    CHECK(size1_copy[0]==2);
    CHECK(size1_copy.size() == 2);
}


int main()
{
   doctest::Context().run();
}

