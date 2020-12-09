#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "bintree.cpp"
#include "treefunctions.cpp"

#include <fstream>
#include <iostream>

TEST_CASE("Test Insertion")
{

    BinTree<int> t;
    
    t.rootPosition().set(10);
    t.rootPosition().left().set(20);
    t.rootPosition().right().set(30);
    t.rootPosition().left().left().set(40);
    t.rootPosition().left().left().left().set(50);
    t.rootPosition().left().left().right().set(60);

    CHECK(t.rootPosition().get()==10);
    CHECK(t.rootPosition().left().get()==20);
    CHECK(t.rootPosition().right().get()==30);
    CHECK(t.rootPosition().left().left().get()==40);
    CHECK(t.rootPosition().left().left().left().get()==50);
    CHECK(t.rootPosition().left().left().right().get()==60);


}

TEST_CASE("Test Modification")
{

    BinTree<int> t;

    t.rootPosition().set(10);
    t.rootPosition().left().set(20);
    t.rootPosition().right().set(30);

    CHECK(t.rootPosition().get() == 10);
    CHECK(t.rootPosition().left().get() == 20);
    CHECK(t.rootPosition().right().get() == 30);


    t.rootPosition().set(100);
    CHECK(t.rootPosition().get() == 100);
    CHECK(t.rootPosition().left().get() == 20);
    CHECK(t.rootPosition().right().get() == 30);


    t.rootPosition().left().set(200);
    CHECK(t.rootPosition().get() == 100);
    CHECK(t.rootPosition().left().get() == 200);
    CHECK(t.rootPosition().right().get() == 30);

    t.rootPosition().right().set(300);
    CHECK(t.rootPosition().get() == 100);
    CHECK(t.rootPosition().left().get() == 200);
    CHECK(t.rootPosition().right().get() == 300);

    
}

TEST_CASE("Test Member")
{    
    BinTree<int> t;
    
    t.rootPosition().set(10);
    t.rootPosition().left().set(20);
    t.rootPosition().right().set(30);
    t.rootPosition().left().left().set(40);
    t.rootPosition().left().left().left().set(50);
    t.rootPosition().left().left().right().set(60);

    CHECK (member(10,t.rootPosition()));
    CHECK (member(30,t.rootPosition()));
    CHECK (member(50,t.rootPosition()));
    CHECK (member(60,t.rootPosition()));

    CHECK (!member(11,t.rootPosition()));
    CHECK (!member(21,t.rootPosition()));

    t.rootPosition().right().set (31);
    CHECK (!member(30,t.rootPosition()));
    CHECK (member(31,t.rootPosition()));

}

TEST_CASE("Test Sum")
{    
    BinTree<int> t;
    
    t.rootPosition().set(10);
    t.rootPosition().left().set(20);
    t.rootPosition().right().set(30);

    CHECK (sum<int>(t.rootPosition()) == 60);

}

TEST_CASE("Test Serialization/Deserialization")
{
   /* BinTree<int> t;

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
*/

}

TEST_CASE("Test Ordered Insertion")
{
 
    BinTree<int> to;

    insertOrdered (50,to.rootPosition());
    insertOrdered (30,to.rootPosition());
    insertOrdered (90,to.rootPosition());
    insertOrdered (45,to.rootPosition());
    insertOrdered (20,to.rootPosition());
    insertOrdered (70,to.rootPosition());
    insertOrdered (99,to.rootPosition());

    std::ofstream bot ("bot.dot");

    to.printdot (bot);
 
    int lastElement = 0,
        sum = 0;
        
    for (int x : to)
    {
        CHECK (lastElement <= x);
        lastElement = x;
        sum += x;
    }

    CHECK (sum == 404);

}

int main()
{

 
    // пускане на тестовете
    doctest::Context().run();

}