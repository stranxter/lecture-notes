#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include <iostream>

#include "llist.cpp"

TEST_CASE("Test Pushing")
{
    LList<int> test;

    CHECK(test.size() == 0);
    
    test.push(0);
    test.push(1);
    test.push(2);
        
    CHECK(test.size() == 3);
    CHECK(test.get(0) == 2);
    CHECK(test.get(1) == 1);
    CHECK(test.get(2) == 0);

}

TEST_CASE("Test Insertion")
{
    LList<int> test;

    CHECK(test.size() == 0);
    
    test.push(0); //7
    test.push(1); //6
    test.push(2); //5
    test.push(3); //4
    test.push(4); //3
    test.push(5); //2
    test.push(6); //1
    test.push(7); //0
        //[7,6,5,4,3,2,1,0]

    test.insertAt(0,10); //[10,7,6,5,4,3,2,1,0]
    CHECK(test.size() == 9);
    CHECK(test.get(0) == 10);
    CHECK(test.get(1) == 7);

    test.insertAt(9,12); //[10,7,6,5,4,3,2,1,0,12]
    CHECK(test.size() == 10);
    CHECK(test.get(9) == 12);
    CHECK(test.get(8) == 0);

    test.insertAt(1,14); //[10,14,7,6,5,4,3,2,1,0]
    CHECK(test.size() == 11);
    CHECK(test.get(1) == 14);
    CHECK(test.get(0) == 10);
    CHECK(test.get(2) == 7);


    test.insertAt(4,100); //[10,14,7,6,100,5,4,3,2,1,0]
    CHECK(test.size() == 12);
    CHECK(test.get(4) == 100);
    CHECK(test.get(3) == 6);
    CHECK(test.get(5) == 5);
}


TEST_CASE("Test Deletion")
{
    LList<int> test;

    CHECK(test.size() == 0);
    
    test.push(0); //7
    test.push(1); //6
    test.push(2); //5
    test.push(3); //4
    test.push(4); //3
    test.push(5); //2
    test.push(6); //1
    test.push(7); //0

    //[7,6,5,4,3,2,1,0]

    test.deleteAt(0); //[6,5,4,3,2,1,0]
    CHECK(test.size() == 7);
    CHECK(test.get(0) == 6);

    test.deleteAt(6); //[6,5,4,3,2,1]
    CHECK(test.size() == 6);
    CHECK(test.get(5) == 1);

    test.deleteAt(1); //[6,4,3,2,1]
    CHECK(test.size() == 5);
    CHECK(test.get(0) == 6);
    CHECK(test.get(1) == 4);

    test.deleteAt(3); //[6,4,3,1]
    CHECK(test.size() == 4);
    CHECK(test.get(2) == 3);
    CHECK(test.get(3) == 1);

}


TEST_CASE("Test Pop")
{
    LList<int> test;

    CHECK(test.size() == 0);
    
    test.push(0); 
    test.push(1); 
    test.push(2); //[2,1,0]

    test.pop();
    CHECK(test.size() == 2);
    CHECK(test.get(0) == 1);

    test.pop();
    test.pop();
    CHECK(test.size() == 0);

}
    


int main()
{
    doctest::Context().run();
}