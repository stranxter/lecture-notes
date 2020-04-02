#include <iostream>
#include "vector.h"
#include "vector.cpp"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <string>

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

TEST_CASE("Test matrices")
{

    Vector<double> v(10);

    v[9] = 9;
    CHECK(v[9]==9);

    Vector<Vector<double>> m(20,10);

    m[19][9] = 100;
    CHECK(m[19][9] == 100);
    CHECK(m.length() == 20);
    CHECK(m[5].length() == 10);

    Vector<std::string> strings (10,"Hello world!");
    CHECK(strings[5]=="Hello world!");

    Vector<Vector<Vector<double>>> cube (20,Vector<Vector<double>>(10,5));
    cube[12][7][4] = 100;
    CHECK(cube[12][7][4] == 100);

    //Vector<int> v20;
    //v20[99] = 99;

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