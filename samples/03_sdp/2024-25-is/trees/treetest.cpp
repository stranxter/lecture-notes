#define DOCTEST_CONFIG_IMPLEMENT
#include <fstream>
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

TEST_CASE("Test Tree Membership")
{
    BinTree<int> t;
    t.insertBOT(50);
    CHECK(t.max() == 50);

    t.insertBOT(30);
    t.insertBOT(90);

    CHECK(t.max() == 90);

    t.insertBOT(20);
    t.insertBOT(45);
    t.insertBOT(70);
    t.insertBOT(99);

    CHECK(t.max() == 99);

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


    std::ofstream out("tree.txt");

    t.printHaskell(out);

    out.close();

    BinTree<int> t2;
    std::ifstream in("tree.txt");
    t2.fromHaskell(in);

    t.print();

    std::cout << std::endl << std::endl << std::endl;

    t2.remove(50);

    t2.print();

    doctest::Context().run();

    return 0;
}