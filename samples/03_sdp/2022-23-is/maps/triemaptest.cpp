#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"


#include "trie.cpp"
#include <string>
#include <iostream>
#include <vector>


TEST_CASE("Basic Test")
{
    Trie<int> phonebook;

    phonebook["Kalin Georgiev"] = 9999;
    CHECK(phonebook["Kalin Georgiev"] == 9999);

    phonebook["Ivanka Petrova"] = 19999;
    CHECK(phonebook["Ivanka Petrova"] == 19999);
    CHECK(phonebook["Kalin Georgiev"] == 9999);

    phonebook["Kalin Georgiev"] = 29999;
    CHECK(phonebook["Kalin Georgiev"] == 29999);

}

int main()
{

    Trie<int> trie;
    trie["to"] = 7;
    trie["tea"] = 3;
    trie["ted"] = 4;
    trie["ten"] = 12;
    trie["A"] = 15;
    trie["i"] = 11;
    trie["in"] = 5;
    trie["inn"] = 9;

    trie.printAllKeys();

    for(std::string key : trie)
    {
        std::cout << key << ":" << trie[key] << std::endl;
    }

    doctest::Context().run();
}