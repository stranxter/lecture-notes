#include <iostream>


class A
{
    public:

    A(int _x) {x=_x; std::cout << "A()::A("<< x << ")\n";}

    A(const A &o) {x = o.x*10; std::cout << "A()::A(const A&), x =" << x << "\n";}

    A& operator=(const A& o)
    {
        x=o.x+1;
        std::cout << "A()::=, x =" << x << "\n";
        return *this;
    }

    ~A(){std::cout << "A()::~A(" << x << ")\n";}

    void print() const {std::cout << "x=" << x << std::endl;} 

    private:
    int x;
};

void f()
/*
  Локални промениливи и 
  променливи в динамичната памет
*/
{
    A *pa = new A(0);

    A a(1),b(2);

    delete pa;
}

void g(A z)
/*
    Параметри по копие
    (инициализират се от к.к. или друг конструктор,
    в засимимост от типа на аргумента)
*/
{

}
//A(7)->
/*
 стек на h:
 <temp result>
 <return address>
 result
*/

A h()
/*
    Връщане на стойност от клас
*/
{
    A local1(8);
    A local2(9);
    A result(7);

    return result;
}

void test(const A& a)
/*
    Изпълнение на функция 
    над резултат от друга функция
*/
{
    a.print();
}

int main()
{
    //f();
    //A a(1); //-> A(int)
    //g(a); //-> A(A&)
    //g(5);

    //A a(0);

    //a = h();

    //test(h());
    
    //!!!
    //h() = a;

/*
    A operator=(const A& o)
    {
        x=o.x+1;
        std::cout << "A()::=, x =" << x << "\n";
        return o;
    }
*/

    A a(0),b(1),c(2);

    c = (b = a);


}