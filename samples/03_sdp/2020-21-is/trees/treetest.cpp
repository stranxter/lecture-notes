#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <fstream>


#include "bintree.cpp"
#include "treefunctions.cpp"

TEST_CASE("Test Tree Insertion")
{

    BinTree<int> t;

    t.rootPosition().set(1);
    t.rootPosition().right().set(5);
    t.rootPosition().left().set(2);
    t.rootPosition().left().left().set(3);
    t.rootPosition().left().left().right().set(4);
    t.rootPosition().left().left().left().set(6);
    
    CHECK(t.rootPosition().get()==1);
    CHECK(t.rootPosition().left().get()==2);
    CHECK(t.rootPosition().left().left().get()==3);
    CHECK(t.rootPosition().left().left().right().get()==4);

    std::ofstream dotfile ("mytree.dot");
    t.toDotty(dotfile);
}

TEST_CASE("Test Tree Modification")
{
    BinTree<int> t;
    
    t.rootPosition().set(1);
    t.rootPosition().left().set(2);
    t.rootPosition().left().left().set(3);
    t.rootPosition().left().left().right().set(4);
    
    CHECK(t.rootPosition().get()==1);
    CHECK(t.rootPosition().left().get()==2);
    CHECK(t.rootPosition().left().left().get()==3);
    CHECK(t.rootPosition().left().left().right().get()==4);

    t.rootPosition().set(10);
    t.rootPosition().left().set(20);
    t.rootPosition().left().left().set(30);
    t.rootPosition().left().left().right().set(40);

    CHECK(t.rootPosition().get()==10);
    CHECK(t.rootPosition().left().get()==20);
    CHECK(t.rootPosition().left().left().get()==30);
    CHECK(t.rootPosition().left().left().right().get()==40);

}

TEST_CASE("Test Serialization, Deserialization, and Equality")
{
    BinTree<int> t;
    
    t.rootPosition().set(1);
    t.rootPosition().right().set(5);
    t.rootPosition().left().set(2);
    t.rootPosition().left().left().set(3);
    t.rootPosition().left().left().right().set(4);
    t.rootPosition().left().left().left().set(6);  

    std::ofstream out ("mytree.scheme");
    t.toScheme (out);
    out.close();

    std::ifstream in ("mytree.scheme");

    BinTree<int> t2;

    t2.fromScheme (in);

    bool equaltrees = t == t2;
    CHECK (equaltrees == true);

    t2.rootPosition().left().left().left().right().set(7);

    equaltrees = t == t2;
    CHECK (equaltrees == false);

}


TEST_CASE("Test Utilities")
{
    BinTree<int> t;
    
    t.rootPosition().set(1);
    t.rootPosition().right().set(5);
    t.rootPosition().left().set(2);
    t.rootPosition().left().left().set(3);
    t.rootPosition().left().left().right().set(4);
    t.rootPosition().left().left().left().set(6);  

    CHECK(sumTree<int>(t.rootPosition()) == 21);

    CHECK(member(2,t.rootPosition()));
    CHECK(!member(7,t.rootPosition()));



}



TEST_CASE("Test Ordered Insertion")
{
        
    BinTree<int> t;

    insertBot(50,t.rootPosition());
    insertBot(30,t.rootPosition());
    insertBot(90,t.rootPosition());
    insertBot(20,t.rootPosition());
    insertBot(70,t.rootPosition());
    insertBot(45,t.rootPosition());
    insertBot(99,t.rootPosition());

    std::ofstream out ("bot.dot");

    t.toDotty(out);
    
    int sum = 0;
    int lastElement = 0; 
    for (int x : t)
    {
        sum += x;
        CHECK (lastElement < x);
        lastElement = x;
    }
    std::cerr << std::endl;

    CHECK (sum == 404);

}

int main()
{
    // пускане на тестовете
    doctest::Context().run();

}