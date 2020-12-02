#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "bintree.cpp"

#include <fstream>
#include <iostream>

TEST_CASE("Test Insertion")
{

    BinTree<int> t;

    t.add(10,"");
    t.add(20,"L");
    t.add(30,"R");
    t.add(40,"LL");
    t.add(50,"LLL");
    t.add(60,"LLR");

    CHECK(t[""] == 10);    
    CHECK(t["L"] == 20);    
    CHECK(t["R"] == 30);    
    CHECK(t["LL"] == 40);    
    CHECK(t["LLL"] == 50);    
    CHECK(t["LLR"] == 60);   

}

TEST_CASE("Test Modification")
{

    BinTree<int> t;

    t.add(10,"");
    t.add(20,"L");
    t.add(30,"R");

    CHECK(t[""] == 10);    
    CHECK(t["L"] == 20);    
    CHECK(t["R"] == 30);    

    t.set(100,"");     
    CHECK(t[""] == 100);    
    CHECK(t["L"] == 20);    
    CHECK(t["R"] == 30);    

    t.set(200,"L");     
    CHECK(t[""] == 100);    
    CHECK(t["L"] == 200);    
    CHECK(t["R"] == 30);    

    t.set(300,"R");     
    CHECK(t[""] == 100);    
    CHECK(t["L"] == 200);    
    CHECK(t["R"] == 300);    

}

TEST_CASE("Test Member")
{
    BinTree<int> t;

    t.add(10,"");
    t.add(20,"L");
    t.add(30,"R");
    t.add(40,"LL");
    t.add(50,"LLL");
    t.add(60,"LLR");

    CHECK (t.member(10));
    CHECK (t.member(30));
    CHECK (t.member(50));
    CHECK (t.member(60));

    CHECK (!t.member(11));
    CHECK (!t.member(21));

    t.set (31, "R");
    CHECK (!t.member(30));
    CHECK (t.member(31));

}

TEST_CASE("Test Serialization/Deserialization")
{
    BinTree<int> t;

    t.add(10,"");
    t.add(20,"L");
    t.add(30,"R");
    t.add(40,"LL");
    t.add(50,"LLL");
    t.add(60,"LLR");

    std::ofstream out ("tree.scheme");

    t.toScheme (out);
    out.close();

   std::ifstream in ("tree.scheme");

    BinTree<int> t2;

    t2.fromScheme (in);

    bool equal = t == t2;
    CHECK (equal);

    t2.set(61,"LLR");

    equal = t == t2;
    CHECK (!equal);


}

int main()
{

    BinTree<int> t;

    t.add(10,"");
    t.add(20,"L");
    t.add(30,"R");
    t.add(40,"LL");
    t.add(50,"LLL");
    t.add(60,"LLR");

    t.printall(std::cout);

    std::ofstream dot ("mytree.dot");
    t.printdot (dot);


    BinTree<int> to;

    to.insertOrdered (50);
    to.insertOrdered (30);
    to.insertOrdered (90);
    to.insertOrdered (45);
    to.insertOrdered (20);
    to.insertOrdered (70);
    to.insertOrdered (99);

    std::ofstream bot ("bot.dot");

    to.printdot (bot);
    
    // пускане на тестовете
    doctest::Context().run();

}