#include <iostream>

class Rat
{  
    
private:
    int nom;
    unsigned int denom;

  public:

    Rat ()
    {
        nom = 1;
        denom = 1;
    }

    void init (int nom, unsigned int denom)
    {
        this->nom = nom;
        this->denom = denom;
    }

    //Rat sum(Rat sumThisWith)
    Rat operator+ (Rat sumThisWith)
    {
        Rat result;
        result.nom = nom*sumThisWith.denom + denom*sumThisWith.nom;
        result.denom = denom*sumThisWith.denom;
        return result;
    }
    //r3 += r1;
    Rat operator+=(Rat other)
    {
        *this = *this + other;
        return *this;
    }

    bool operator > (Rat compareWith)
    {
        return nom*compareWith.denom > compareWith.nom*denom;
    }

    void print ()
    {
        std::cout << nom << "/" << denom << std::endl;
    }

    Rat operator* (Rat r2)
    {
        Rat result;
        result.nom = nom * r2.nom;
        result.denom = denom * r2.denom;

        return result;
    }

    Rat operator* (int coef)
    {
        Rat result;
        result.init (nom*coef,denom);

        return result;
    }

/*    
    //++x;
    Rat operator++()
    {

    }
    
    //x++
    Rat operator++ (int)
    {

    }
*/
};

Rat operator* (int coef, Rat rat)
{
    return rat*coef;
}

int main ()
{


    Rat r1, r2;

    r1.init (1,2);
    r2.init (1,3);

    r1.operator+ (r2).print();
    (r1 + r2).print();
    (r1 * r2).print();

    if (r1 > r2)
    {
        std::cout << "YES!\n";
    }

    //r1.operator* (2);
    (r1*2).print();
   
    //2.operator* (r1)
    (2 * r1).print();

    Rat r3;

    r3 = r1;

    r3 = r3 + r1;

    r3.print();
    (r3 += r1).print();
    r3.print();

    //std::cout << r3 += r1;

    int x = 3, y;

    x = 3;
    //x.operator++
    //y = x++;


    int ints[100];

    Rat rats[100];   

}