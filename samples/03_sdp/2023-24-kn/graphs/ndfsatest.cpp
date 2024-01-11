#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include <iostream>
#include "ndfsa.h"
#include <fstream>

TEST_CASE("Test Accept")
{
    std::ifstream a1File ("example1.ndfsa");
    NDFSA a1;
    a1File >> a1;

    std::ofstream out ("example.dot");

    printDotty(out, a1);


    CHECK(a1.accept("aaa"));
    CHECK(!a1.accept("aa"));
    CHECK(a1.accept("baa"));
    CHECK(!a1.accept("ba"));

}


int main()
{

    doctest::Context().run();

}