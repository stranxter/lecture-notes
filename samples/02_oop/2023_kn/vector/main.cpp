#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "vector.cpp"
#include <string>


int inc(const int &x)
{
    return x+1;
}

int one(const int &x)
{
    return 1;
}

int id(const int &x)
{
    return x;
}

int sq(const int &x)
{
    return x*x;
}

int cube(const int &x)
{
    return x*x*x;
}

int quadr(const int &x)
{
    return x*x*x*x;
}

struct PowerCalculator
{
    int n;
    int operator()(int x)
    {
        int result = 1;
        for (int i = 0; i < n; ++i)
        {
            result *= x;
        }
        return result;
    }
};

Fn<int,int> squareFn (Fn<int,int> f)
{

    return [f](double x)->double{return f(x)*f(x);};

}

PowerCalculator powerF(const int n)
{
 
  return PowerCalculator{n};

}



TEST_CASE("Test Assignment")
{
    int arr[]={0,1,2};
    Vector<int> v(arr,3),u;
    
    CHECK(u.size()==0);
    u = v;
    CHECK(u.size()==3);

    u[0]=1;
    CHECK(u[0]==1);
    CHECK(v[0]==0);
}

TEST_CASE("Test Copying")
{
    int arr[]={0,1,2};
    Vector<int> v(arr,3);
    
    Vector<int> u(v);
    
    CHECK(u.size()==3);
    u[0]=1;
    CHECK(u[0]==1);
    CHECK(v[0]==0);
}

TEST_CASE("Test Indexing")
{
    Vector<int> v;

    v[10] = 10;
    CHECK(v.size() == 11);
    CHECK(v[10]==10);

    v += 5; 
    CHECK(v.size()==12);
    CHECK(v[11]==5);
    CHECK(v[10]==10);
}

TEST_CASE("Test Concatenation")
{
    int arr[]={0,1,2};
    Vector<int> v(arr,3);
    
    int arr2[]={3,4,5,6};
    Vector<int> u(arr2,4);
    
    v += u;
    CHECK(u.size() == 4);
    CHECK(v.size() == 7);

    for (int i = 0; i < 7; ++i)
    {
        CHECK(v[i]==i);
    }

    u = v + v;
    CHECK(v.size()==7);
    CHECK(u.size() == 14);

    for (int i = 0; i < 14; ++i)
    {
        CHECK(u[i]==i%7);
    }
}

TEST_CASE("Test Comparison")
{
    int arr[]={0,1,2};
    Vector<int> v(arr,3);

    CHECK(v==v);

    Vector<int> u;
    u[0]=0;
    u[1]=1;
    u[2]=2;

    CHECK(v==u);
    CHECK(u==v);

    CHECK(!(v!=u));
    CHECK(!(u!=v));

    u[2]=3;
    CHECK(!(v==u));
    CHECK(!(u==v));

    CHECK(v!=u);
    CHECK(u!=v);

    u[2]=2;
    CHECK(v==u);

    u[4]=4;
    CHECK(!(v==u));
    CHECK(!(u==v));

    CHECK(v!=u);
    CHECK(u!=v);    
}

TEST_CASE("Power Calculation")
{
    CHECK(powerF(4)(2) == 16);

    PowerCalculator p26 = PowerCalculator{26};

    p26(2);
}

TEST_CASE("squareFn test")
{

    std::function<double(double)> f1, f2, f3;

    f1 = [](double x)->double{return x+1;};

    f2 = squareFn(f1);
    f3 = squareFn(f2);

    CHECK(f1(2.0)==3);
    CHECK(f2(2.0)==9);
    CHECK(f3(2.0)==81);
}

TEST_CASE("Test Map")
{
    int arr[]={0,1,2};
    Vector<int> v(arr,3);

    Vector<int> v1 = v.map<int>([](const int &x)->int{return x+1;}).map<int>([](const int &x)->int{return x*x;});
    Vector<int> v2 = v.map<int>([](const int &x)->int{return (x+1)*(x+1);});
    Vector<int> v3 = v.map<int>([](const int &x)->int{if (x%2==0) return x+1; return x;});
    
    CHECK(v1.size() == 3);
    for(int i = 0; i < v1.size(); ++i)
    {
        CHECK((v[i]+1)*(v[i]+1) == v1[i]);
    }

}

TEST_CASE("Test Reduce")
{
    int arr[]={0,1,2};
    Vector<int> v(arr,3);

    CHECK(v.reduce<int>(0,[](int sum, int el)->int{return sum+el;})==3);
 
}

struct S
{
    int a;
    int b;
    int c;

};

TEST_CASE("Test Complex Reduce")
{
    S arr[] = {{1,2,3},{4,5,6},{7,8,9}};
    Vector<S> v(arr,3);

    int res = v.map<int>([](const S &s)->int{return s.b;})
               .reduce<int>(0,[](int x, int y)->int{return x+y;}); 

    CHECK(res == 15);

    res = v.reduce<int>(0,[](int partialSum, S currentEl)
                               ->int{return partialSum+currentEl.b;});

    CHECK(res == 15);
}

TEST_CASE("Test Reduce with Strings")
{
    std::string arr[] = {"Hello ", "world ", "have a", "nice ", "day!"};
    Vector<std::string> v(arr,5);

    // {"Hello ", "world ", "have a", "nice ", "day!"} -> {1,0,1,1,0}


    int count =     
        v.map<int>([](const std::string &s)
                        ->int{return std::count(s.begin(),s.end(),'e');})
        .reduce<int>(0,[](int sum, int countEs)->int{return sum + countEs;});

    CHECK(count == 3);


    //да се напише функция, която по символ намира функция, която брои срещанията
    //на този символ в даден символен низ
    std::function<std::function<int(std::string)>(char)> functionMaker =
        [](char c)->std::function<int(std::string)>
           {return [c](std::string s)->int{return std::count(s.begin(),s.end(),c);};};

    
    std::function<int(std::string)> countEs = functionMaker('e'),
                                    countHs = functionMaker('H');

    count = v.reduce<int>(0,[functionMaker](int sum,std::string s)
                            ->int{return sum+functionMaker('H')(s);});

    CHECK(count == 1);

}

int main()
{

    doctest::Context().run();
}