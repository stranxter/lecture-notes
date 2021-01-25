#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <string>
#include <ostream>

#include "graph.cpp"

TEST_CASE("Basic Test")
{

    Graph<std::string,double> cities;

    CHECK(cities.hasVertex("Sofia")==false);
    cities.addVertex("Sofia");
    CHECK(cities.hasVertex("Sofia")==true);
    CHECK(cities.hasVertex("Rome")==false);
    cities.addVertex("Rome");

    cities.addEdge("Sofia","Rome",350);
    CHECK(cities.hasEdge("Sofia","Rome")==true);
    CHECK(cities.hasEdge("Rome","Sofia")==false);

    cities.addEdge("Rome","Sofia",351);
    CHECK(cities.hasEdge("Rome","Sofia")==true);

    CHECK(cities["Sofia"]["Rome"]==350);
    CHECK(cities["Rome"]["Sofia"]==351);
    CHECK(cities.hasEdge("Sofia","New York")==false);

    cities.addVertex("Milan");

    cities.addEdge("Sofia","Milan",30);
    cities.addEdge("Milan","Sofia",25);
    CHECK(cities["Sofia"]["Rome"]==350);
    CHECK(cities["Sofia"]["Milan"]==30);

    unsigned int count = 0;

    for (std::string city : cities)
    {
        CHECK((city == "Sofia" || city == "Milan" || city == "Rome"));
        ++count;
    }
    CHECK(count==3);


    count = 0;
    for (auto neighb : cities["Sofia"])
    {
        CHECK((neighb.first=="Milan" || neighb.first == "Rome"));
        ++count;
    }
    CHECK(count==2);

    
}

int main()
{

    // пускане на тестовете
    doctest::Context().run();

}