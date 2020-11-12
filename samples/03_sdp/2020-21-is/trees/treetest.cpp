#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <fstream>


#include "bintree.cpp"

TEST_CASE("Test Tree Insertion")
{

    BinTree<int> t;
    
    t.add(1,"");
    t.add(5,"R");
    t.add(2,"L");
    t.add(3,"LL");
    t.add(4,"LLR");
    t.add(6,"LLL");

    CHECK(t.get("")==1);
    CHECK(t.get("L")==2);
    CHECK(t.get("LL")==3);
    CHECK(t.get("LLR")==4);

    std::ofstream dotfile ("mytree.dot");
    t.toDotty(dotfile);
}

TEST_CASE("Test Tree Modification")
{
    BinTree<int> t;
    
    t.add(1,"");
    t.add(2,"L");
    t.add(3,"LL");
    t.add(4,"LLR");

    CHECK(t[""]==1);
    CHECK(t["L"]==2);
    CHECK(t["LL"]==3);
    CHECK(t["LLR"]==4);

    t[""] = 10;
    t["L"] = 20;
    t["LL"] = 30;
    t["LLR"] = 40;

    CHECK(t[""]==10);
    CHECK(t["L"]==20);
    CHECK(t["LL"]==30);
    CHECK(t["LLR"]==40);

}

TEST_CASE("Test Serialization, Deserialization, and Equality")
{
    BinTree<int> t;
    
    t.add(1,"");
    t.add(5,"R");
    t.add(2,"L");
    t.add(3,"LL");
    t.add(4,"LLR");
    t.add(6,"LLL");    

    std::ofstream out ("mytree.scheme");
    t.toScheme (out);
    out.close();

    std::ifstream in ("mytree.scheme");

    BinTree<int> t2;

    t2.fromScheme (in);

    bool equaltrees = t == t2;
    CHECK (equaltrees == true);

    t2.add(7,"LLLR");

    equaltrees = t == t2;
    CHECK (equaltrees == false);

}

TEST_CASE("Test Ordered Insertion")
{
    BinTree<int> t;

    t.insertOrdered(50);
    t.insertOrdered(30);
    t.insertOrdered(90);
    t.insertOrdered(20);
    t.insertOrdered(70);
    t.insertOrdered(45);
    t.insertOrdered(99);

    std::ofstream out ("bot.dot");

    t.toDotty(out);

}

int main()
{
    // пускане на тестовете
    doctest::Context().run();

}