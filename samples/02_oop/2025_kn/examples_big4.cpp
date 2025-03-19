#include <iostream>

class A {
public:
    A() {
        std::cout << "Constr of A" << std::endl;
    }

    A(int x)
    {
        std::cout << "Constr of A(" << x << ")" << std::endl;
    }

    A(const A& other) {
        std::cout << "Copy constr of A" << std::endl;
    }
    A& operator=(int x) 
    {
        std::cout << "Op= of A" << std::endl;
        return *this;
    }

    A& operator=(const A& other) {
        std::cout << "Op= of A" << std::endl;
        return *this;
    }
    ~A() {
        std::cout << "Destr of A" << std::endl;
    }

};

class B {
public:
    B() {
        std::cout << "Constr of B" << std::endl;
    }
    B(const B& other) {
        std::cout << "Copy constr of B" << std::endl;
    }
    B& operator=(const B& other) {
        std::cout << "Op= of B" << std::endl;
        return *this;
    }
    ~B() {
        std::cout << "Destr of B" << std::endl;
    }
};

class C {
    A a;
    B b;
    
public:
    C(): b(), a() {
        std::cout << "Constr of C" << std::endl;
    }
    C(const C& other): a(other.a), b(other.b) {
        std::cout << "Copy constr of C" << std::endl;
    }
    C& operator=(const C& other) {
        std::cout << "Op= of C" << std::endl;
        a = other.a;
        b = other.b;
        return *this;
    }
    ~C() {
        std::cout << "Destr of C" << std::endl;
    }
    
};
void f(A a) {}
void g(A& a) {}
void h(A* a) {}

class D
{
    private:
    int i;
    A a;
    public:
    D():a(5)
    //D()
    {
       // a = 5;
        std::cout << "Constr of D" << std::endl;
    }
    ~D()
    {
        std::cout << "Destr of D" << std::endl;
    }
};

int main()
{


    D d;

/*     {
        C arr[2];
        A* ptr;
        {
            ptr = new A();
            A a;
        }

        delete ptr;
    }
    std::cout << std::endl;

    {

        A a(450);
        A a1(a);
        A a2 = a;
        a1 = a2;
        f(a);
        g(a);
        h(&a);
    }
    std::cout << std::endl;

    {
        C c;
        C c1(c);
        c = c1;
    }
 */}