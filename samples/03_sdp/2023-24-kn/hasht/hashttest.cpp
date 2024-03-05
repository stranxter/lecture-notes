#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include <string>
#include <vector>

#include "hasht.cpp"

size_t hash(const std::string& key)
{
    size_t sum = 0;
    for (char c : key)
    {
        sum += c;
    }

    return sum;
}

TEST_CASE("Basic Hash Table Test")
{
    HashTable<std::string,int> phonebook(5,hash);

    CHECK(!phonebook.exists("John Smith"));
    phonebook["John Smith"] = 10;
    CHECK(phonebook.exists("John Smith"));
    CHECK(!phonebook.exists("Jane Smith"));
    CHECK(phonebook["John Smith"] == 10);
    CHECK(phonebook.get("John Smith") == 10);

    CHECK_THROWS(phonebook.get("Jane Smith"));
        
}

TEST_CASE("Test With Collisions")
{
    HashTable<std::string,int> table(5,hash);

    std::vector<std::pair<std::string,int>> tests = {{"abc",0},
                                                     {"cba",1},
                                                     {"test1",2},
                                                     {"test2",3},
                                                     {"etst3",4},
                                                     {"ascsac",5},
                                                     {"zmnxxzkjn",6}};

    for(auto kvp : tests)
    {
        CHECK(!table.exists(kvp.first));
        table[kvp.first] = kvp.second;
        CHECK(table.exists(kvp.first));
    }

    for(auto kvp : tests)
    {
        CHECK(table.get(kvp.first) == kvp.second);
    }

}


TEST_CASE("Test Key Iteration")
{
   HashTable<std::string,int> table(5,hash);

    std::vector<std::pair<std::string,int>> tests = {{"abc",0},
                                                     {"cba",1},
                                                     {"test1",2},
                                                     {"test2",3},
                                                     {"etst3",4},
                                                     {"ascsac",5},
                                                     {"zmnxxzkjn",6}
                                                     };

    for(auto kvp : tests)
    {
        table[kvp.first] = kvp.second;
    }

    for(std::pair<std::string,int> &kvp : tests)
    {
        kvp.second = 0;
    }

    for(std::string key : table)
    {
        for(std::pair<std::string,int> &kvp : tests)
        {
            if(kvp.first == key)
            {
                ++kvp.second;
            }
        }
    }

    for(std::pair<std::string,int> &kvp : tests)
    {
        CHECK(kvp.second == 1);
    }

}

int main()
{
    doctest::Context().run();
}


