#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"

#include "hashmap.h"
#include "hashmap.hpp"
#include "hm_tests.hpp"
#include "tm_tests.hpp"


#include "treemap.hpp"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();    

    TreeMap<int,int> tm;

    tm[1] = 1;
}