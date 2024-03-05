#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include <iostream>
#include <sstream>

#include "tree.h"
#include "trie.cpp"


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

TEST_CASE("Test Removal")
{
    Tree t;

    t.insertBot(50);
    t.insertBot(30);
    t.insertBot(90);
    t.insertBot(20);
    t.insertBot(45);
    t.insertBot(70);
    t.insertBot(99);

    std::vector<int> toRemove = {99, 30, 50};

    for(int x:toRemove)
    {
        CHECK(t.member(x));
        t.remove(x);
        CHECK(!t.member(x));
    }
}

TEST_CASE("Test Contains")
{
    Trie<int> t;

    std::vector<std::pair<const char*,int>> keys = {{"",0},
                                                    {"to",7}, 
                                                    {"tea",3},
                                                    {"ted",4},
                                                    {"ten",12},
                                                    {"A",15},
                                                    {"i",11},
                                                    {"in",5},
                                                    {"inn",9}};
    for(auto kv: keys)
    {
        CHECK(!t.contains(kv.first));
        t[kv.first] = kv.second;
        CHECK(t.contains(kv.first));
    }

    for(auto kv: keys)
    {
        CHECK(t.contains(kv.first));
    }
    
}

TEST_CASE("Test Remove")
{
    Trie<int> t;

    std::vector<std::pair<const char*,int>> keys = {{"",0},
                                                    {"to",7}, 
                                                    {"tea",3},
                                                    {"ted",4},
                                                    {"ten",12},
                                                    {"A",15},
                                                    {"i",11},
                                                    {"in",5},
                                                    {"inn",9}};
    for(auto kv: keys)
    {
        t[kv.first] = kv.second;
    }

    t.remove("in");
    CHECK(!t.contains("in"));
    CHECK(t.contains("inn"));

    t.remove("inn");
    CHECK(!t.contains("inn"));
    CHECK(t.contains("i"));

}



TEST_CASE("Test Access")
{
    Trie<int> t;

    std::vector<std::pair<const char*,int>> keys = {{"to",7}, 
                                                    {"tea",3},
                                                    {"ted",4},
                                                    {"ten",12},
                                                    {"A",15},
                                                    {"i",11},
                                                    {"in",5},
                                                    {"inn",9}};
    for(auto kv: keys)
    {
        t[kv.first] = kv.second;
    }

    for(auto kv: keys)
    {
        CHECK(t[kv.first] == kv.second);
    }
    
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