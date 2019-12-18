#include <iostream>
using namespace std;

struct Test 
{   
    double d;
    int i;
    int i2;
    char c;

};

void increase (int &y)
{
    ++y;
}

void increaseInts (Test *t)
{
    ++t->i;
    ++t->i2;
}

void printTest (Test t)
{
    cout << "[" << t.i << "," << t.i2 << "]\n";
}

int main ()
{
    int x = 0;

    Test t,t2;
    t.i = 0;
    t.i2 = 0;
    t2.i = 5;
    t2.i2 = 5;

    printTest (t);
    printTest (t2);

    increaseInts (&t);
    increaseInts (&t2);

    printTest (t);
    printTest (t2);

    Test *tp = &t;
    
    tp->i = 0;

    tp = &t2;

    tp->i = 0;

    increaseInts (&t);
    increaseInts (&t2);

    increase (x);
    increase (t.i);

    //cout << x << endl;


}