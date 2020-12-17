#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "hashmap.cpp"
#include <sstream>


TEST_CASE("Basic Test")
{

    HashMap<int,int> map(10,[](const int &x)->int{return x/2;});

    CHECK(!map.hasKey(0));
    map[0] = 1;
    CHECK(map.hasKey(0));
    CHECK(map[0]==1);

    CHECK(!map.hasKey(4));
    map[4] = 3;
    CHECK(map.hasKey(4));
    CHECK(map[4]==3);

    CHECK(!map.hasKey(1));
    map[1] = 7;
    CHECK(map.hasKey(1));
    CHECK(map[1]==7);
    CHECK(map.hasKey(0));
    CHECK(map[0]==1);

    CHECK(!map.hasKey(21));
    map[21] = 9;
    CHECK(map.hasKey(21));
    CHECK(map[21]==9);
    CHECK(map.hasKey(1));
    CHECK(map[1]==7);
    CHECK(map.hasKey(0));
    CHECK(map[0]==1);

}

TEST_CASE("Test Iteration")
{

    std::stringstream input ("lorem ipsum dolor ipsum ipsum lorem");

    std::function<size_t(const std::string&)> h = [](const std::string &s)->size_t
    {
        size_t sum = 0;
        for (char c: s)
        {
            sum += c;
        }
        return sum;
    };


    HashMap<std::string,int> map (10,h);

    std::string current;
    while (input >> current)
    {
        if (map.hasKey(current))
        {
            map[current]++;
        } else
        {
            map[current] = 1;
        }
    }

    HashMap<std::string,int> check (10,h);

    for (std::string key : map)
    {
        if (check.hasKey(key))
        {
            check[key]++;
        } else
        {
            check[key] = 1;
        }        
    }

    CHECK(check["lorem"]==1);
    CHECK(check["ipsum"]==1);
    CHECK(check["dolor"]==1);
}


int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}