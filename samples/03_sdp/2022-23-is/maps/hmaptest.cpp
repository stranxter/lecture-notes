#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"


#include "hmap.cpp"
#include <string>
#include <iostream>
#include <vector>


int h1 (const std::string &key)
{
    return key.length();
}

TEST_CASE("Basic Test")
{
    HMap<std::string,int> phonebook(10, h1);

    phonebook["Kalin Georgiev"] = 9999;
    CHECK(phonebook["Kalin Georgiev"] == 9999);

    phonebook["Ivanka Petrova"] = 19999;
    CHECK(phonebook["Ivanka Petrova"] == 19999);
    CHECK(phonebook["Kalin Georgiev"] == 9999);

    phonebook["Kalin Georgiev"] = 29999;
    CHECK(phonebook["Kalin Georgiev"] == 29999);

}

TEST_CASE("Test Collisions")
{
    HMap<std::string,int> map(3, h1);

    std::vector<std::pair<std::string,int>> expected =
        {{"aaa",1},
         {"bbbb", 2},
         {"bbbc", 3},
         {"c",4},
         {"dd",5}};

    for(std::pair<std::string,int> p:expected)
    {
        map[p.first] = p.second;
    }   

    for(std::pair<std::string,int> p:expected)
    {
        CHECK(map[p.first] == p.second);
    }

}

int main()
{
    
    doctest::Context().run();
}