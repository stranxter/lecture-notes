#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include "bot.cpp"


TEST_CASE("Test Member")
{    
    BinOrdTree<int> t;

    t.add(50);
    t.add(30);
    t.add(20);
    t.add(45);
    t.add(90);
    t.add(99);
    t.add(70);   

    CHECK(t.member(50));
    CHECK(t.member(30));
    CHECK(t.member(70));
    CHECK(!t.member(51));
}


TEST_CASE("Test Copy")
{
    BinOrdTree<int> t;

    t.add(50);
    t.add(30);
    t.add(20);
    t.add(45);
    t.add(90);
    t.add(99);
    t.add(70);

    BinOrdTree<int> t2(t);

    CHECK(t2.size()==t.size());
    CHECK(t2.checkOrder());
    CHECK(t2.member(70));
    CHECK(!t2.member(71)); 

    t2.add(100);
    CHECK(t2.member(100));
    CHECK(!t.member(100));


}


TEST_CASE("Test Assignment")
{
    BinOrdTree<int> t;

    t.add(50);
    t.add(30);
    t.add(20);
    t.add(45);
    t.add(90);
    t.add(99);
    t.add(70);

    BinOrdTree<int> t2;
    t2=t;

    CHECK(t2.size()==t.size());
    CHECK(t2.checkOrder());
    CHECK(t2.member(70));
    CHECK(!t2.member(71)); 

    t2.add(100);
    CHECK(t2.member(100));
    CHECK(!t.member(100));
}


int main()
{
    BinOrdTree<int> t;

    t.add(50);
    t.add(30);
    t.add(20);
    t.add(45);
    t.add(90);
    t.add(99);
    t.add(70);

    for(int x:t.leaves())
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    for(int x:t.level(1))
    {
        std::cout << x << " ";
    }

    std::cout << "Levels:\n";
    t.printLevels();

    doctest::Context().run();
}