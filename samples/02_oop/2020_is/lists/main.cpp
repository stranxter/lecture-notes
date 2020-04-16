#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


#include "llist.cpp"

TEST_CASE("Test Push")
{
    LList<int> l;
    
    l.push(0);
    l.push(1);
    l.push(2);//2,1,0

    CHECK(l.size()==3);
    CHECK(l[0]==2);
    CHECK(l[1]==1);
    CHECK(l[2]==0);
}

TEST_CASE("Test Element Assignment")
{
    LList<int> l;
    
    l.push(0);
    l.push(1);
    l.push(2);//2,1,0

    CHECK(l.size()==3);
    
    l[0]=10;
    l[2]=20;

    CHECK(l.size()==3);
    CHECK(l[0]==10);
    CHECK(l[2]==20);
    CHECK(l[1]==1);
}

TEST_CASE("Test Pop")
{
    LList<int> l;
    
    l.push(0);
    l.push(1);
    l.push(2);//2,1,0

    CHECK(l.size()==3);

    l.pop();    //1,0
    CHECK(l.size()==2);
    CHECK(l[0]==1);
    CHECK(l[1]==0);

}


TEST_CASE("Test Insert After")
{
    LList<int> l;
    
    l.push(0);
    l.push(1);
    l.push(2);//2,1,0

    l.insertAfter(0,10);//2,10,1,0
    l.insertAfter(3,20);//2,10,1,0,20
    l.insertAfter(1,30);//2,10,30,1,0,20

    CHECK(l.size()==6);
    CHECK(l[1]==10);
    CHECK(l[2]==30);
    CHECK(l[5]==20);

}

TEST_CASE("Test Delete After")
{
    LList<int> l;

    l.push(0);
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5); //5,4,3,2,1,0

    l.deleteAfter(5);
    CHECK(l.size()==6);

    l.deleteAfter(4); //5,4,3,2,1
    CHECK(l.size()==5);
    CHECK(l[4]==1);

    l.deleteAfter(0); //5,3,2,1
    CHECK(l.size()==4);
    CHECK(l[1]==3);

    l.deleteAfter(1); //5,3,1
    CHECK(l.size()==3);
    CHECK(l[2]==1);
}

TEST_CASE("Test Insert After")
{
    LList<int> l;
    
    l.push(0);
    l.push(1);
    l.push(2);//2,1,0

    l.push_back(3);
    l.push_back(4); //2,1,0,3,4

    CHECK(l.size()==5);
    CHECK(l == std::vector<int>({2,1,0,3,4}));

}



int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}