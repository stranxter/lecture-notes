#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include <iostream>
#include <vector>

#include "pstack.cpp"


TEST_CASE("Basic Stack Test")
{
    std::vector<int> elems = {1,2,3};

    pstack<int> stack;

    for(int i = 0; i < elems.size(); ++i)
    {
        stack = stack.push(elems[i]);
    }

    CHECK(!stack.empty());

    for(int i = elems.size()-1; i >=0; --i)
    {
        CHECK(stack.top() == elems[i]);
        stack = stack.pop();   
    }

    CHECK(stack.empty());
}

int main()
{
 
    doctest::Context().run();

}