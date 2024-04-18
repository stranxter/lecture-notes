#include <iostream>



class Base
{
    public:
    Base(){std::cout << "Base()\n";}
    Base(int) 
    {   
        this->f();
        std::cout << "Base(int)\n";
    }

    Base(const Base&){}; 

    void g()
    {
        std::cout << "Base::g()\n";
        //Base* this;
        this->f();
    }

    void operator=(const Base&)
    {
        std::cout << "Base=\n";  

    }


    virtual void f(){std::cout << "Base::f()\n";}

    int a,b;

    ~Base()
    {
        std::cout << "~Base\n";
        this->f();
    }
    

};


class Derived : public Base
{
    public:
    Derived()
    {
        std::cout << "Derived()\n";
        c = a+b;
    }

    Derived(const Derived &other):Base(other){}; 

    void operator=(const Derived& other)
    {
        Base::operator=(other);
        std::cout << "Derived=\n";  
    }


    Derived(int x):Base(x)
    {
        std::cout << "Derived(int)\n";
        c = a+b;
    }

    void f(){std::cout << "Derived::f()\n";}

    int c,d;
    //Base b1,b2;

    ~Derived(){std::cout << "~Derived\n";}
};

class Derived2 : public Base
{
    public:

    void f(){std::cout << "Derived2::f()\n";}

};


int main()
{

    Derived d(5),d1;

   
   d1 = d;
   d.g();
   // d.g();

    //Derived2 d2;

    //d2.g();


}