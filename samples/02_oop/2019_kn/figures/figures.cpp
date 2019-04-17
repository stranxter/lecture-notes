#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

class Figure 
{
public:

    Figure (const char *s)
    {
#ifdef debug
        std::cout << "Figure(const char*)\n";
#endif        
        strcpy (label,s);
    }

    virtual void saveToStream (std::ostream&) = 0;
    virtual void loadFromStream(std::istream &) = 0;

    void whoami ()
    {
        std::cout << "I am a " << label << std::endl;
    }

    virtual double surface () = 0;

    char label [15]; 

    virtual ~Figure()
    {
#ifdef debug
        std::cout << "~Figure\n";
#endif
    }

    static Figure* figureFactory (const std::string &figureType);
};

class Rectangle : public Figure
{
public:

    Rectangle(double _a, double _b) : Figure("rectangle"),a(_a), b(_b) 
    {
#ifdef debug
        std::cout << "Rectangle(double _a, double _b)\n";
#endif
    }

    void saveToStream (std::ostream &out)
    {
        out << "rect " << a << " " << b << " ";
    }

    void loadFromStream(std::istream &in)
    {
        in >> a >> b;
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
#ifdef debug
        std::cout << "~Rectangle\n";
#endif
    }
};

class Square : public Figure
{
  public:

    Square(double _a) : Figure ("square"), a(_a) 
    {
#ifdef debug
        std::cout << "Square(double _a)\n";
#endif
    }

    void saveToStream (std::ostream &out)
    {
        out << "sq " << a << " ";
    }

    void loadFromStream(std::istream &in)
    {
        in >> a;
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
#ifdef debug
        std::cout << "~Sqaure\n";
#endif
    }
};

class Circle : public Figure
{
  public:


    void saveToStream (std::ostream &out)
    {
        out << "cir " << r << " ";
    }
    void loadFromStream(std::istream &in)
    {
        in >> r;
    }

    Circle(double _r) : Figure("Circle"), r(_r)
    {
#ifdef debug
        std::cout << "Circle(double _r)\n";
#endif
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
#ifdef debug        
        std::cout << "~Circle\n";
#endif        
    }
};

Figure* Figure::figureFactory(const std::string &figureType)
{
    if (figureType == "cir")
    {
        return new Circle(0);
    }
    if (figureType == "sq")
    {
        return new Square(0);
    }
    if (figureType == "rect")
    {
        return new Rectangle(0, 0);
    };

    return nullptr;
}

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

void testInteractiveCreation ()
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

std::ostream &operator<<(std::ostream &out, const std::vector<Figure *> &v)
{
    out << v.size() << " ";
    for (Figure *v : v)
    {
        v->saveToStream(out);
    }
    return out;
}

std::istream& operator >> (std::istream &in, std::vector<Figure*>& v)
{
    v.clear();

    size_t n;
    in >> n;

    for (size_t i = 0; i < n; ++i)
    {
        std::string figureType;
        in >> figureType;

        Figure *newFigure = Figure::figureFactory (figureType);        
        assert (newFigure != nullptr);

        newFigure->loadFromStream (in);
        v.push_back (newFigure);
    }
   

    return in;
}

void testCreateFile()
{
    std::vector<Figure *> v;
    v.push_back(new Circle(3));
    v.push_back(new Rectangle(3, 4));
    v.push_back(new Circle(4));
    v.push_back(new Square(4));

    std::ofstream outdata("figures.dat");

    outdata << v;
}

void testLoadFile ()
{
    std::vector<Figure *> v;
    
    std::ifstream indata ("figures.dat");

    std::cerr << "Reading data from file...\n";
    indata >> v;
    std::cerr << "Sucess!!! Array values:\n";
    std::cout << v;
}

int main ()
{
    testCreateFile();
    testLoadFile ();

    return 0;
}