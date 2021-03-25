#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include "vector.cpp"
#include <iostream>


TEST_CASE("Insertion in an empty vector")
{
    Vector<int> v;

    CHECK(v.length()==0);
    v.push_back(1); 
    CHECK(v.length()==1);
    CHECK(v[0]==1);

}

TEST_CASE("Insertion of multiple elements")
{

    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    CHECK(v.length() == 6);
    CHECK(v[0]==1);
    CHECK(v[2]==3);
    CHECK(v[5]==6);

}

TEST_CASE("Test copying")
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    Vector<int> v2(v);

    CHECK(v2.length() == 3);
    CHECK(v2[1]==2);

    v[1] = 5;
    CHECK(v[1]==5);
    CHECK(v2[1]==2);
}

TEST_CASE("Test assignment")
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    Vector<int> v2;

    v2 = v;

    CHECK(v2.length() == 3);
    CHECK(v2[1]==2);

    v[1] = 5;
    CHECK(v[1]==5);
    CHECK(v2[1]==2);
}


Vector<int> createVector()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    return v;
}

int sum (const Vector<int>& v)
{

    int sum = 0;
    for (size_t i = 0; i < v.length(); ++i)
    {
        sum += v[i];
    }

    return sum;
}

TEST_CASE("Test sum")
{
    CHECK(sum(createVector())==6);
}

TEST_CASE("Test element modification")
{
    
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v[1]=7;
    CHECK(v[0]==1);
    CHECK(v[1]==7);
    CHECK(v[2]==3);
    CHECK(v.length() == 3);

}


int main()
{
    doctest::Context().run();
}