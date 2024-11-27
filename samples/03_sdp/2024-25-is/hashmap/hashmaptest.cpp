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


int main()

{
    doctest::Context().run();
    return 0;

}