#include <iostream>


class Base
{
    public:
    Base(){std::cout << "Base()\n";}
    Base(int y){std::cout << "Base(int)\n"; this->g();}

    Base(const Base& other){std::cout << "Base(const Base&)\n";}


    void operator=(const Base& other)
    {std::cout << "Base::operator=(const Base&)\n";}

    void f()
    {
        std::cout << "Base::f()\n";

        //Base* this
        this->g();
    }

    virtual void g()
    {
        std::cout << "Base::g()\n";
    }

    virtual ~Base(){std::cout << "~Base()\n";g();}
    int a,b;
};


class Derived: public Base
{
    public:
    Derived():b2(0){std::cout << "Derived()\n";}
    Derived(int x):Base(x),b1(1){std::cout << "Derived(int)\n";}

    Derived(const Derived& other):Base(other),b1(1){std::cout << "Derived(const Derived&)\n";}

    void operator=(const Derived& other)
    {
        std::cout << "Derived::operator=(const Derived&)\n";
        Base::operator=(other);
        b1 = other.b1;
        b2 = other.b2;

    }


    void g()
    {
        std::cout << "Derived::g()\n";
    }

    ~Derived(){std::cout << "~Derived()\n";}

    Base b1, b2;

    int c,d;
};



int main()
{

    Derived d1,d2;

    d1 = d2;

}