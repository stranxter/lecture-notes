#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

class Figure
{
    public:
    virtual double surface() = 0;
    virtual double perim() = 0;
    virtual void save(std::ostream &out) = 0;

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
        out << "circ " << x << " " << y << " " << r << " ";
    }

    private:
    double x,y;
    double r;
};

class Square : public Figure
{
    public:
    Square (double _a):a(_a){}

    double perim()
    {
        return 4*a;
    }

    double surface()
    {
        return a*a;
    }

    int nsides()
    {
        return 4;
    }

    void save(std::ostream &out)
    {
        out << "sq " << a << " ";
    }

    private:
    double a;
};

double sumSurface(std::vector<Figure*> figures)
{
    double sum = 0;
    for (size_t i = 0; i < figures.size(); i++)
    {
        sum += figures[i]->surface();
    }

    return sum;
}

std::ostream& operator << (std::ostream &out, std::vector<Figure*> figures)
{
    
    out << figures.size() << " ";

    for (Figure *f : figures)
    {
        f->save(out);
    }
    return out;
}


int main()
{

    std::vector<Figure*> f = {new Circle(0,0,1), new Square(1), new Circle(3,0,2), new Square(2)};

    std::cout << sumSurface(f) << std::endl;

    std::ofstream out ("figures.fig");
    out << f;

    //in >> f;

    std::ifstream in ("figures.fug");
    //in >> f;

    return 0;

}
