#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "dynarray.cpp"

TEST_CASE("Test Resizing")
{
    DynArray<int> a;
       
    int test[] = {10,20,30,40,50};
    const int size = 5;

    for(int i = 0; i < size; ++i)
    {
        a.push_back(test[i]);
    }

    a.setSize(10);
    CHECK(a.getSize() == 10);

    for(int i = 0; i < size; ++i)
    {
        CHECK(a[i] == test[i]);
    }

    a.setSize(2);
    CHECK(a.getSize() == 2);

    for(int i = 0; i < 2; ++i)
    {
        CHECK(a[i] == test[i]);
    }

}

TEST_CASE("Test Insertion")
{
    DynArray<int> a;
       
    int test[] = {10,20,30,40,50};
    const int size = 5;

    for(int i = 0; i < size; ++i)
    {
        a.push_back(test[i]);
    }

    CHECK(a.getSize() == size);

    for(int i = 0; i < size; ++i)
    {
        CHECK(a[i] == test[i]);
    }
}

TEST_CASE("Test Copying")
{
    DynArray<int> a;
       
    int test[] = {10,20,30,40,50};
    const int size = 5;

    for(int i = 0; i < size; ++i)
    {
        a.push_back(test[i]);
    }

    DynArray<int> b(a);
    
    CHECK(b.getSize() == a.getSize());

    for(int i = 0; i < size; ++i)
    {
        CHECK(b[i] == a[i]);
    }

    b[0] = 100;
    CHECK(a[0] == 10);

    DynArray<int> empty;
    DynArray<int> empty2(empty);

    CHECK(empty2.getSize() == 0);
    empty2.push_back(1);
    CHECK(empty.getSize() == 0);
    CHECK(empty2.getSize() == 1);
    CHECK(empty2[0] == 1);

}


TEST_CASE("Test Assignment")
{
    DynArray<int> a;
       
    int test[] = {10,20,30,40,50};
    const int size = 5;

    for(int i = 0; i < size; ++i)
    {
        a.push_back(test[i]);
    }

    DynArray<int> b;

    b=a;
    
    CHECK(b.getSize() == a.getSize());

    for(int i = 0; i < size; ++i)
    {
        CHECK(b[i] == a[i]);
    }

    b[0] = 100;
    CHECK(a[0] == 10);

    DynArray<int> empty;
    DynArray<int> empty2;

    empty2 = empty;

    CHECK(empty2.getSize() == 0);
    empty2.push_back(1);
    CHECK(empty.getSize() == 0);
    CHECK(empty2.getSize() == 1);
    CHECK(empty2[0] == 1);

    empty = empty;
    empty.push_back(1);
    CHECK(empty.getSize() == 1);
    CHECK(empty[0] == 1);

    empty = a = b = empty2;

    CHECK(empty.getSize() == a.getSize());
    CHECK(a.getSize() == b.getSize());
    CHECK(b.getSize() == empty2.getSize());

}

TEST_CASE("Check Appending")
{
    DynArray<int> a,b;
       
    int test[] = {10,20,30};
    const int size = 3;

    for(int i = 0; i < size; ++i)
    {
        a.push_back(test[i]);
        b.push_back(test[i]+1);
    }

    DynArray<int> empty;

    a += b;
    a += empty;

    CHECK(a.getSize() == 6);

    for(int i = 0; i < size*2; ++i)
    {
        CHECK(a[i] == test[i%3]+(i/3));
    }   

    empty += a;

    for(int i = 0; i < size*2; ++i)
    {
        CHECK(empty[i] == test[i%3]+(i/3));
    }
}

TEST_CASE("Check Concatenation")
{

    int test[] = {10,20,30};
    int test2[] = {11,21,31};
    const int size = 3;

    const DynArray<int> a(test,3),b(test2,3);
       
    CHECK((a+b).getSize() == size*2);

    for(int i = 0; i < size*2; ++i)
    {
        CHECK((a+b)[i] == test[i%3]+(i/3));
    }   

    for(int i = 0; i < size; ++i)
    {
        CHECK(a[i] ==  test[i]);
        CHECK(b[i] == test2[i]);
    }   


    //CHECK(a.getSize()==3) -- НЯМА НУЖДА!

}

int main()
{

    doctest::Context().run();
}