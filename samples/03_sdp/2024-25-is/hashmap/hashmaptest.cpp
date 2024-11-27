#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "hashmap.cpp"

unsigned strhash(const std::string &s)
{
    unsigned sum = 0;
    for (char c: s)
    {
        sum += c;    
    }

    return sum;
}


TEST_CASE("Empty Map Test")
{
    HashMap<std::string,std::string> map(strhash,5);

    CHECK(!map.hasKey(""));
    CHECK(!map.hasKey("test"));
}

TEST_CASE("Test Addition and HasKey")
{
    HashMap<std::string,std::string> map(strhash,5);

    map.add("one","");
    CHECK(map.hasKey("one"));
    CHECK(!map.hasKey("two"));

    map.add("eno","");
    CHECK(map.hasKey("one"));
    CHECK(map.hasKey("eno"));
    CHECK(!map.hasKey("neo"));

    map.add("two","");
    map.add("three","");
    map.add("four","");
    map.add("five","");
    map.add("six","");

    CHECK(map.hasKey("five"));
    CHECK(map.hasKey("six"));

}


int main()

{
    doctest::Context().run();
    return 0;

}