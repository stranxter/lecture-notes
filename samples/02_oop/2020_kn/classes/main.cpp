#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include "vector.cpp"


TEST_CASE("Insertion Test")
{
    Vector<int> v;
    v.to_end (1);
    v.to_end (2);
    CHECK (v.length()==2);
    v.to_end (3);
    v.push (4);
    CHECK (v.length()==4);

    CHECK(v[0]==4);
    CHECK(v[1]==1);
    CHECK(v[2]==2);
    CHECK(v[3]==3);
}   

TEST_CASE("Modification test")
{
    Vector<int> v;
    v.to_end (1);
    v.to_end (2);
    v.to_end (3);

    v[1] = 7;
    CHECK (v[1] == 7);
    CHECK (v[0] == 1);
    CHECK (v[2] == 3);

}   

TEST_CASE("Copying test")
{
    Vector<int> v;
    v.to_end (1);
    v.to_end (2);
    v.to_end (3);

    {
        Vector<int> copy(v);

        copy[0] = 7;
        CHECK(v[0]==1);

        v[0] = 17;
        CHECK(copy[0]==7);
    }//~copy

    Vector<int> v1,v2,v3;
    v1.push(8);v2.push(8);v3.push(8);

    CHECK(v[0]==17);
    CHECK(v[1]==2);
    CHECK(v[2]==3);
}


TEST_CASE("Assignment test")
{
    Vector<int> v;
    v.to_end (1);
    v.to_end (2);
    v.to_end (3);

    {
        Vector<int> other;

        other = v;

        other[0] = 7;
        CHECK(v[0]==1);

        v[0] = 17;
        CHECK(other[0]==7);
    }//~other

    Vector<int> v1,v2,v3;
    v1.push(8);v2.push(8);v3.push(8);

    CHECK(v[0]==17);
    CHECK(v[1]==2);
    CHECK(v[2]==3);   
}

TEST_CASE("Comparison test")
{
    Vector<int> v1;
    v1.to_end (1);
    v1.to_end (2);
    v1.to_end (3);

    Vector<int> v2 (v1);

    CHECK ((v1 == v2) == true);
    CHECK ((v1 != v2) == false);
    v2[0]=0;
    CHECK ((v1 == v2) == false);
    CHECK ((v1 != v2) == true);
}

TEST_CASE("Adition test")
{
    Vector<int> v1;
    v1.to_end (1);
    v1.to_end (2);
    v1.to_end (3);

    Vector<int> v2(v1);
    v2.to_end(4);

    CHECK (v1+4 == v2);

    v1 += 4;
    CHECK (v1 == v2);

    Vector<int> v3;
    v3.to_end (1);
    v3.to_end (2);
    v3.to_end (1);
    v2 = v3;

    CHECK(v2+v3 == v3+v2);
    CHECK((v2+v3).length() == 6);
    CHECK((v2+v1)[6]==4);

}

int main ()
{

    // пускане на тестовете
    doctest::Context().run();    

}