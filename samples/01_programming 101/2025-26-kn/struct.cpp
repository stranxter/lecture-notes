#include <iostream>

struct Point
{
    double x;
    int y;
};

struct Rational
{
    long nom;
    long denom;
};


Rational readRat()
{
    Rational result;
    std::cout << "Моля, въведете числител =";
    std::cin >> result.nom;
    std::cout << "Моля, въведете знаменател =";
    std::cin >> result.denom;

    return result;
}

void printRat(Rational rat)
{
    std::cout << rat.nom << "/" << rat.denom;
}


Rational sum(Rational a, Rational b)
{
    return {a.nom*b.denom + b.nom*a.denom,a.denom*b.denom};
}
Rational operator+(Rational a, Rational b)
{
    return {a.nom*b.nom,a.denom*b.denom};
}

Rational prod(Rational a, Rational b)
{
    return {a.nom*b.nom,a.denom*b.denom};
}
Rational operator*(Rational a, Rational b)
{
    return {a.nom*b.nom,a.denom*b.denom};
}

void f(int x)
{
    std::cout << "I'm the int function\n";
}

void f(char *s)
{
    std::cout << "I'm the string function\n";
}

void f(Rational r)
{
    std::cout << "I'm the rational function\n";
}

bool operator==(Rational r1, Rational r2)
{
    return r1.nom == r2.nom && r1.denom == r2.denom;
}

std::ostream& operator<<(std::ostream &out,Rational rat)
{
    out << rat.nom << "/" << rat.denom;
    return out;
}

int main()
{

    f(0);
    f("Hello");

    Rational a = readRat(),
             b = readRat(),
             c = readRat();
    

    std::cout << (a==b);

    std::cout << 15;
    std::cout << 15.0;
    std::cout << "15jhjkhk";
    std::cout << a*b+c;

    Rational *pr = &a;

    int i = 8, j = 10;
    int *pi = &j;

    std::cout << *pi;
    std::cout << (*pr).nom;
    std::cout << pr->nom;

}