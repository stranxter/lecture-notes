#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include <iomanip>

class Figure
{
    public:
    virtual double surface() = 0;
    virtual double perim() = 0;
    virtual void save(std::ostream&) = 0;
    //virtual void load(std::istream&) = 0;

    protected:
    char label[15];
};

class Circle : public Figure
{
    public:
    Circle (double _x, double _y, double _r):x(_x),y(_y),r(_r){}

    double perim()
    {
        return 2*3.14*r;        
    }

    double surface()
    {
        return 3.14*r*r;
    }

    void save(std::ostream &out)
    {
        out << "circle: "<< x << " " << y << " " << r << " "; 
    }

    private:
    double x,y;
    double r;
};

class Rectangle : public Figure
{
    public:
    Rectangle (double _a, double _b):a(_a),b(_b){}

    double perim()
    {
        return 2*a+2*b;
    }

    double surface()
    {
        return a*b;
    }

    int nsides()
    {
        return 4;
    }

    void save(std::ostream &out)
    {
        out << "rect: " << a << " " << b << " "; 
    }

    private:
    double a,b;
};

double sumSurfaces(std::vector<Figure*> figures)
{
    double sum = 0;
    for (Figure* f : figures)
    {
        sum += f->surface();
    }
    return sum;
}

std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures)
{
    size_t nFigures;
    in >> nFigures;
    std::string type;
    for (size_t i = 0; i < nFigures; ++i)
    {
        in >> type;
        /*
        if (type == "circle:")
            figures[i] = new Circle(0,0,0);
        else if (type == "square:")
            figures[i] = new Rectangle(0,0);
        
        figures[i]->load(in);
        */
    }
    return in;
}


std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures)
{
    out << figures.size () << " ";
    for (Figure *f : figures)
    {
        f->save(out);
    }
    return out;
}

int main()
{

    std::vector<Figure*> figures = {new Circle(0,0,1), 
                                    new Circle(3,0,2), 
                                    new Rectangle(1,2), 
                                    new Rectangle(2,4)};

    std::cout << sumSurfaces(figures) << std::endl;

    std::ofstream out ("figures.fig");

    out << figures;

    /*

    std::ifstream in ("figures.fig");

    std::vector<Figure*> input;

    in >> input;

    */


}