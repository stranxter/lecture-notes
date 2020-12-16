#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <string>
#include <sstream>

#include "hashmap.cpp"


TEST_CASE("Simple Mapping")
{
    HashMap<int, int> m(10,[](const int& key)->size_t{return key/2;});

    CHECK (!m.hasKey(0));
    m[0] = 0;
    CHECK (m.hasKey(0));
    CHECK (m[0] == 0);

    CHECK (!m.hasKey(4));
    m[4] = 3;
    CHECK (m.hasKey(4));
    CHECK (m[4] == 3);
}

TEST_CASE("Test Colllisions")
{
    HashMap<int, int> m(10,[](const int& key)->size_t{return key/2;});

    CHECK (!m.hasKey(0));
    m[0] = 0;
    CHECK (m.hasKey(0));
    CHECK (m[0] == 0);

    CHECK (!m.hasKey(1));
    m[1] = 1;
    CHECK (m.hasKey(1));
    CHECK (m[1] == 1);
    CHECK (m.hasKey(0));
    CHECK (m[0] == 0);
    CHECK (!m.hasKey(20));

    m[20] = 2;
    CHECK (m.hasKey(1));
    CHECK (m[1] == 1);
    CHECK (m.hasKey(0));
    CHECK (m[0] == 0);
    CHECK (m.hasKey(20));
    CHECK (m[20] == 2);

}

TEST_CASE("Test Iteration")
{

    std::function<size_t(const std::string&)> h = [](const std::string &key)->size_t
      {
        size_t sum = 0;
        for (char c: key)
        {
            sum += c;
        }     
        return sum;
      };

    HashMap<std::string, int> dict(10,h);

      std::stringstream input ("lorem ipsum dolie ipsum lorem ipsum ipsum");

      std::string word;
      while (input >> word)
      {
          if (dict.hasKey(word))
          {
              dict[word]++;
          } else
          {     
            dict[word] = 1;
          }
      }

      HashMap<std::string, int> check(10,h);
      
      for (std::string key : dict)
      {
          if (!check.hasKey(key))
          {
              check[key] = 1;
          } else 
          {
              check[key]++;
          }
      }

      CHECK(dict["lorem"] == 2);
      CHECK(dict["dolie"] == 1);
      CHECK(dict["ipsum"] == 4);

      CHECK(check["lorem"] == 1);
      CHECK(check["dolie"] == 1);
      CHECK(check["ipsum"] == 1);

}

int main()
{

    // пускане на тестовете
    doctest::Context().run();
    return 0;
}    
