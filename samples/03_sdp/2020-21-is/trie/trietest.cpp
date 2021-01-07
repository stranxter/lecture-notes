#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "triemap.cpp"
#include <fstream>

TEST_CASE("Basic Test")
{
    TrieMap<int> map;

    CHECK(map.hasKey("ted") == false);

    map["ted"] = 4;
    CHECK(map.hasKey("ted") == true);
    CHECK(map.hasKey("t") == false);
    CHECK(map.hasKey("te") == false);
    CHECK(map.hasKey("ten") == false);
    CHECK(map["ted"] == 4);


    map["te"] = 14;
    CHECK(map.hasKey("ted") == true);
    CHECK(map.hasKey("t") == false);
    CHECK(map.hasKey("te") == true);
    CHECK(map.hasKey("ten") == false);
    CHECK(map["te"] == 14);

    map["tedology"] = 24;
    CHECK(map["tedology"] == 24);

}

TEST_CASE("Pretty Tree")
{
    
    TrieMap<int> map;

  	map["to"] = 7;
  	map["tea"] = 3;
  	map["ted"] = 4;
  	map["ten"] = 12;
  	map["A"] = 15;
  	map["i"] = 11;
  	map["in"] = 5;
  	map["inn"] = 9;

    std::ofstream dot ("trie.dot");

    map.exportToDot(dot);


}

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}