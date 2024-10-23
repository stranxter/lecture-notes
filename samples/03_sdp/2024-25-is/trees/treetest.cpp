#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "bintree.cpp"

TEST_CASE("Test Tree Membership")
{
    BinTree<int> t;
    t.insert("",7);
    t.insert("L",30);
    t.insert("LR",12);
    t.insert("LRL",90);
    t.insert("R",5);
    t.insert("RL",50);

    CHECK(t.member(7));
    CHECK(!t.member(100));
    CHECK(t.member(50));
}



int main()
{

    BinTree<int> t;
    t.insertBOT(50);
    t.insertBOT(30);
    t.insertBOT(90);
    t.insertBOT(20);
    t.insertBOT(45);
    t.insertBOT(70);
    t.insertBOT(99);

    t.print();

    doctest::Context().run();

    return 0;
}