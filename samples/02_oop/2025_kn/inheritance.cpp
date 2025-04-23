#include <iostream>


class A
{
    public:

    A():y(0){std::cout<<"A::A() ";};
    A(int x):y(x){std::cout<<"A::A(int) ";};

    virtual void f() {std::cout << "A::f()\n";};
    void g() {std::cout << "A::g() "; this->f();}

    virtual ~A(){std::cout << "~A()\n";};

    private:
    int y;
};
class B : public A
{
    public:
    B(int x):z(x),A(x+2){std::cout<<"B::B(int)\n";};
    void f() {std::cout << "B::f()\n";};
    void g() {std::cout << "B::g() "; this->f();}

    ~B(){std::cout << "~B()\n";};

    private:
    int z;
};
class C : public B
{
    public:
    void f() {std::cout << "C::f()\n";};
};
int main()
{
    A *pa = new B(0);
    
    delete pa;

}