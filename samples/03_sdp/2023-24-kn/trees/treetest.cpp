#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include <iostream>
#include <sstream>

#include "tree.h"


TEST_CASE("Test Membership")
{

    Tree t;

    CHECK(!t.member(1));

    t.insert(7,"");
    t.insert(30,"L");
    t.insert(5,"R");
    t.insert(50,"RL");
    t.insert(7,"LR");
    t.insert(90,"LRL");

    CHECK(t.member(50));
    CHECK(!t.member(51));
    CHECK(t.member(90));

}


TEST_CASE("Test Sum")
{

    Tree t;

    CHECK(!t.member(1));

    t.insert(7,"");
    t.insert(30,"L");
    t.insert(5,"R");
    t.insert(50,"RL");
    t.insert(7,"LR");
    t.insert(90,"LRL");

    CHECK(t.sum() == 189);

}

TEST_CASE("Test Iteration")
{

    Tree t;

    t.insert(7,"");
    t.insert(30,"L");
    t.insert(5,"R");
    t.insert(50,"RL");
    t.insert(7,"LR");
    t.insert(90,"LRL");

    int sum = 0;
    for (int x : t)
    {
        //std::cerr << "(" << x << ")";
        
        sum += x;
    }    

    CHECK(sum==189);

}

TEST_CASE("Test Serialization")
{
    Tree t;

    t.insert(7,"");
    t.insert(30,"L");
    t.insert(5,"R");
    t.insert(50,"RL");
    t.insert(7,"LR");
    t.insert(90,"LRL");

    std::stringstream s,s2;

    s << t;

    //std::cout << s.str();

    Tree t2;

    s >> t2;

    s2 << t2;

    CHECK(s.str() == s2.str());

}

int main()
{
    Tree t;

    t.insert(7,"");
    t.insert(30,"L");
    t.insert(5,"R");
    t.insert(50,"RL");
    t.insert(7,"LR");
    t.insert(90,"LRL");

    t.printDot();

    doctest::Context().run();

}