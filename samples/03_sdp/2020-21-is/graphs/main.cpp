#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <string>

#include "graph.cpp"


TEST_CASE("Basic Test")
{
    Graph<std::string, double> airports;

    airports.addVertex ("Sofia");
    airports.addVertex ("New York");
    airports.addVertex ("Milan");

    airports.addEdge("Sofia","Milan",20);
    airports.addEdge("Milan","Sofia",25);

    airports.addEdge("Milan","New York",650);
    airports.addEdge("New York","Milan",800);


    CHECK(airports.hasVertex ("Sofia"));
    CHECK(airports.hasVertex ("Milan"));
    CHECK(!airports.hasVertex ("Paris"));

    CHECK(airports.hasEdge("Sofia","Milan"));
    CHECK(!airports.hasEdge("Sofia","New York"));

    CHECK(airports.getCost("Sofia","Milan")==20);
    CHECK(airports.getCost("New York","Milan")==800);

    unsigned int count = 0;
    for (auto neighbor : airports.neighbors("Milan"))
    {
        CHECK((neighbor.first == "Sofia" || neighbor.first == "New York"));
        ++count;
    }
    CHECK(count == 2);
    
    count = 0;
    for (std::string airport : airports)
    {
        CHECK((airport == "Sofia" || airport == "New York" || airport == "Milan"));
        ++count;
    }
    CHECK(count == 3);

}

int main ()
{
    // пускане на тестовете
    doctest::Context().run();

    return 0;
}