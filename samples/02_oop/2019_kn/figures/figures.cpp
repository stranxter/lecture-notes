#include <iostream>
#include <vector>
#include <cstring>

class Figure 
{
public:


    virtual Figure* clone () = 0;

    Figure (const char *s)
    {
        std::cout << "Figure(const char*)\n";
        strcpy (label,s);
    }

    void operator = (Figure*);

    void whoami ()
    {
        std::cout << "I am a " << label << std::endl;
    }

    virtual double surface () = 0;

    char label [15]; 

    virtual ~Figure()
    {
        std::cout << "~Figure\n";
    }
};

class Rectangle : public Figure
{
public:

    Figure* clone ()
    {
        return new Rectangle (*this);
    }

    Rectangle(double _a, double _b) : Figure("rectangle"),a(_a), b(_b) 
    {
        std::cout << "Rectangle(double _a, double _b)\n";
    }

    double a, b;

    double surface()
    {
      return a * b; 
    }

    double perimeter ()
    {
        return 2*(a+b);
    }
    ~Rectangle()
    {
        std::cout << "~Rectangle\n";
    }
};

class Square : public Figure
{
  public:
    Figure *clone()
    {
        return new Square(*this);
    }

    Square(double _a) : Figure ("square"), a(_a) 
    {
        std::cout << "Square(double _a)\n";
    }

    double a;

    double surface()
    {
        return a * a;
    }

    double perimeter()
    {
        return 4 * a;
    }
    ~Square()
    {
        std::cout << "~Sqaure\n";
    }
};

class Circle : public Figure
{
  public:
    Figure *clone()
    {
        return new Circle(*this);
    }

    Circle(double _r) : Figure("Circle"), r(_r)
    {
        std::cout << "Circle(double _r)\n";
    }

    double r;

    double surface()
    {
        return 3.14 * r * r;
    }

    double perimeter()
    {
        return 2 * 3.14 * r;
    }
    ~Circle()
    {
        std::cout << "~Circle\n";
    }
};

double sumSurfaces (Figure *figures[], size_t n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += figures[i]->surface();
    }
    return sum;
}

int Test1 ()
{
    Rectangle r (2,4);
    Square s (4);
    
    std::cout << "r.surface=" << r.surface() << std::endl;

    Figure *f;

    f = &r;

    std::cout << "f.surface = " <<  f->surface() << std::endl;

    f = &s;

    std::cout << "f.surface = " << f->surface() << std::endl;

    Figure *figures[2] = {&r,&s};

    std::cout <<"sum=" << sumSurfaces (figures,2) << std::endl;


    //std::cout << "f.surface = " << f->perimeter() << std::endl;

    return 0;
}

int main ()
{
    char c = -1;
    std::vector<Figure*> figures;
    while (c != 'e')
    {
        std::cout << "Please enter figure type or 'e' for exit:";
        std::cin >> c;
        switch (c)
        {
           case 'r': figures.push_back (new Rectangle (2,4));break;
           case 's': figures.push_back (new Square (5));break;
           case 'c': figures.push_back (new Circle (5));break;
        }
        std::cout << "We just created:";
        figures[figures.size()-1]->whoami();
    }

    double sum = 0;
    for (Figure *f : figures)
    {
        sum += f->surface();
    }

    std::cout << "Sum = " << sum << std::endl;

    for (Figure *f : figures)
    {
        delete f;
    }

}

