#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <cstring>

#include "list.cpp"

TEST_CASE("Test Size")
{
    List<int> l1;

    CHECK(l1.size() == 0);

    l1.push(10);
    l1.push(20);

    l1.push(30);


    CHECK(l1.size() == 3);

    l1.pop();
    CHECK(l1.size() == 2);
    
    l1.pop();
    l1.pop();
    CHECK(l1.size() == 0);

}

TEST_CASE("Test Push")
{
    List<int> l1;
    l1.push(10);
    l1.push(20);
    l1.push(30);

    CHECK(l1[0]==30);
    CHECK(l1[1]==20);
    CHECK(l1[2]==10);

    const char* texts[] = {"Hello", "World", "And so on"};

    List<const char*> l2,l3;
    l2.push(texts[0]);
    l2.push(texts[1]);
    l2.push(texts[2]);

    CHECK(strcmp(l2[0],texts[2])==0);
    CHECK(strcmp(l2[1],texts[1])==0);
    CHECK(strcmp(l2[2],texts[0])==0);

    List<List<const char*>> m;

    m.push(l3);
    m.push(l2);

    CHECK(m[0][0] == texts[2]);
    CHECK(m[1].size() == 0);

}

TEST_CASE("Test Pop")
{
    List<int> l1;
    l1.push(10);
    l1.push(20);
    l1.push(30);

    l1.pop();

    CHECK(l1.size() == 2);
    CHECK(l1[0]==20);
    CHECK(l1[1]==10);

    l1.pop();
    l1.pop();

    CHECK(l1.size() == 0);

    l1.push(1);
    CHECK(l1.size() == 1);
    CHECK(l1[0] == 1);

}

TEST_CASE("Test Copying")
{
    List<int> l1;
    l1.push(10);
    l1.push(20);
    l1.push(30);

    List<int> l2(l1); 

    CHECK(l1 == l2);
    l1[0] = 0;
    CHECK(l2[0]==30);

    l1.pop();
    CHECK(l2.size() == 3);
}


TEST_CASE("Test Assignment")
{
    List<int> l1;
    l1.push(10);
    l1.push(20);
    l1.push(30);

    List<int> l2;
    l2 = l1;

    CHECK(l1 == l2);
    l1[0] = 0;
    CHECK(l2[0]==30);

    l1.pop();
    CHECK(l2.size() == 3);

    l1 = l1;
    CHECK(l1[0]==20);
}


int main()
{

    doctest::Context().run();
}