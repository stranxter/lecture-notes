#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "list.cpp"

TEST_CASE("Test Empty Lists")
{
    List<int> l;

    CHECK(l.empty() == true);
    CHECK(l.count() == 0);
}

TEST_CASE("Test Pushing")
{
    List<int> l;

    l.push(7);
    CHECK(l.empty() == false);
    CHECK(l.count() == 1);
    CHECK(l[0]==7);

    l.push(1);
    l.push(2);
    CHECK(l.count() == 3);
    CHECK(l[0]==2);
    CHECK(l[1]==1);
    CHECK(l[2]==7);
}

TEST_CASE("Test Insertion")
{
    List<int> l;
    l.push(3);
    l.push(2);
    l.push(1);
    l.push(0);

    l.insertAfter(10,0);
    //0 10 1 2 3
    CHECK(l.count() == 5);
    CHECK(l[1] == 10);
    CHECK(l[0] == 0);
    CHECK(l[2] == 1);

    l.insertAfter(20,4);
    //0 10 1 2 3 20
    CHECK(l.count() == 6);
    CHECK(l[5] == 20);
    CHECK(l[4] == 3);

}

TEST_CASE("Test Assignement")
{
    List<int> l;
    l.push(3);
    l.push(2);
    l.push(1);
    l.push(0);

    CHECK(l[0] == 0);
    l[0] = 100;
    CHECK(l[0] == 100);
}

template<typename T>
void print(const List<T>& l)
{
    std::cout << "{";
    for(int i = 0; i < l.count(); ++i)
    {
        std::cout << l[i] << " ";
    }
    std::cout << "}\n";
}


int main()
{
   doctest::Context().run();
   return 0;
}
