#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dllist.h"
#include "dllist.cpp"

TEST_CASE("Insertion test")
{
    DLList<int> test;
    CHECK(test.insertAt(10,10)==false);
    test.insertAt(0, 1);
    test.insertAt(0, 2);
    test.insertAt(1, 3);
    test.insertAt(0, 3);
    test.insertAt(1, 4);
}

TEST_CASE("Membership and size test")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(test.member(1));
    CHECK(test.member(2));
    CHECK(test.member(3));
    CHECK(test.member(4));
    CHECK(test.size() == 4);

    CHECK(test.member(-1)==false);
    CHECK(test.member(5)==false);
}

TEST_CASE("Ordering test")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(test[0] == 3);
    CHECK(test[1] == 4);
    CHECK(test[2] == 1);
    CHECK(test[3] == 2);
}

TEST_CASE("Backwards test")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(test.fromBack (3) == 3);
    CHECK(test.fromBack (2) == 4);
    CHECK(test.fromBack (1) == 1);
    CHECK(test.fromBack (0) == 2);
}
