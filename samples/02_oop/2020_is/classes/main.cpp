#include <iostream>
#include "vector.h"
#include "vector.cpp"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

TEST_CASE("Insertion Test")
{
    Vector<int> v;

    v.push_back(0);
    v += 1;

    v.push(11);
    v.push(12); //[12,11,0,1]

    CHECK (v[0]==12);
    CHECK (v[1]==11);
    CHECK (v[2]==0);
    CHECK (v[3]==1);

}

TEST_CASE("Copying test")
{
    Vector<int> v;

    v.push_back(0);
    v.push_back(1);

    v.push(11);
    v.push(12); //[12,11,0,1]

    Vector<int> copied = v;
    
    copied[0] = 100;
    CHECK(copied[0]==100);
    CHECK(v[0]==12);

    v[1] = 100;
    CHECK(v[1]==100);
    CHECK(copied[1]==11);
}

TEST_CASE("Assignemt test")
{
    Vector<int> v;

    v.push_back(0);
    v.push_back(1);

    v.push(11);
    v.push(12); //[12,11,0,1]

    Vector<int> copied;
    
    copied = v;
    
    copied[0] = 100;
    CHECK(copied[0]==100);
    CHECK(v[0]==12);

    v[1] = 100;
    CHECK(v[1]==100);
    CHECK(copied[0]==100);
}

TEST_CASE("Concatenation test")
{
    Vector<int> v;

    v.push_back(0);
    v.push_back(1);

    v.push(11);
    v.push(12); //[12,11,0,1]

    CHECK ((v+v)[4] == 12);
    CHECK ((v+v).length() == 8);
}

TEST_CASE("Test vector of vectors")
{
    Vector<double> dv1, dv2;
    dv1.push (0.5);
    dv1.push (1.5);
    dv2.push (5.5);
    dv2.push (6.5);
    dv2.push (7.5);

    Vector<Vector<double>> vvd;
    vvd.push (dv1);
    vvd.push (dv2);

    CHECK(vvd.length() == 2);
    CHECK(vvd[0][0]==7.5);
    CHECK(vvd[1][0]==1.5);
    CHECK(vvd[0].length()==3);
    CHECK(vvd[1].length()==2);

}

TEST_CASE("Modification test")
{
    Vector<int> v;

    v.push_back(0);
    v.push_back(1);

    v.push(11);
    v.push(12); //[12,11,0,1]

    CHECK(v[0]==12);
    v[0] = 70;
    CHECK(v[0]==70);
    CHECK(v[1]==11);

}


int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}