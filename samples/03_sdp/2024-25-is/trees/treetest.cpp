#define DOCTEST_CONFIG_IMPLEMENT
#include <fstream>
#include "../doctest.h"

#include "bintree.cpp"
#include "triemap.cpp"

//dot -Tpdf tree.dot -o tree.pdf

TEST_CASE("Basic Map Test")
{
    TrieMap<int> t;

    CHECK(t.hasKey("to") == false);

    t.setValue("to",7);

    CHECK(t.getValue("to")==7);
    
}

TEST_CASE("Map Test")
{
    TrieMap<int> t;

    t["to"] = 7;
    t["tea"] = 3;
    t["ted"] = 4;
    t["ten"] = 12;
    t["A"] = 15;
    t["i"] = 11;    
    t["in"] = 5;
    t["inn"] = 9;

    CHECK(t["to"] == 7);
    CHECK(t["in"] == 5);
    CHECK(!t.hasKey("te"));
    CHECK(!t.hasKey("innn"));

    std::ofstream treef ("mytree.dot");
    t.toDotty(treef);
 
}



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

TEST_CASE("Test Tree Iterator")
{
    BinTree<int> t;
    t.insertBOT(50);
    t.insertBOT(30);
    t.insertBOT(90);
    t.insertBOT(20);
    t.insertBOT(45);
    t.insertBOT(70);
    t.insertBOT(99);

    int count = 0, last_element = -1;

    /*
    for(BinTree<int>::iterator it = t.begin(); it != t.end(); ++it)
    {
        x = *it;
    }
    */
    for(int x : t)
    {
        ++count;
        if(count > 0)
        {
            CHECK(x > last_element);
        }
        last_element = x;
    }

    CHECK(count == 7);

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