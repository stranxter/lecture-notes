#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Figure
{
    public:
    Figure(const std::string& _name):name(_name){}

    virtual double perimeter() = 0;
    virtual double surface() = 0;

    virtual void writeToStream(std::ostream&) = 0;
    virtual void loadFromStream(std::istream&) = 0;

    std::string getName() {return name;}

    private:
    std::string name;

};

struct Point2D
{
    double x,y;
};

class Circle : public Figure
{

    public:
    Circle(Point2D _center, double _r):Figure("circle"),center(_center), r(_r){}

    double surface()
    {
        return 3.14*r*r;
    }

    double perimeter()
    {
        return 2*3.14*r;
    }

    void writeToStream(std::ostream& out)
    {
        out << "Circle " << r << " " << center.x << " " << center.y;
    }

    void loadFromStream(std::istream &in)
    {
        in >> r >> center.x >> center.y;
    }

    private:
    Point2D center;
    double r;
};

double distance(Point2D a, Point2D b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

class Square : public Figure
{

    public:
    Square(Point2D _a1, Point2D _a3):Figure("Square"),a1(_a1),a3(_a3){}

    double surface()
    {
        double diag = distance(a1,a3);
        return diag*diag/2;
    }

    double perimeter()
    {
        double side = distance(a1,a3)/sqrt(2);
        return side*4;
    }

     void writeToStream(std::ostream& out)
    {
        out << "Square " << a1.x << " " << a1.y << " " << a3.x << " " << a3.y;
    }

    void loadFromStream(std::istream &in)
    {
        in >> a1.x >> a1.y >> a3.x >> a3.y;
    }

   
    private:
    Point2D a1,a3;
};

double sumPerim(std::vector<Figure*> figures)
{
    double sum = 0;
    for (Figure* figure : figures)
    {
        sum += figure->perimeter();
    }

    return sum;
}

std::ostream& operator << (std::ostream &out, const std::vector<Figure*>& figures)
{
    out << figures.size() << std::endl;
    for (Figure *f : figures)
    {
        f->writeToStream(out);
        out << std::endl;
    }
    return out;
}

Figure* factory(const std::string &type)
{
    
    if (type == "Circle")
    {
        return new Circle({0,0},0);
    } else if (type == "Square")
    {
        return new Square({0,0},{0,0});
    }

    return nullptr;
}

std::istream& operator >> (std::istream &in, std::vector<Figure*>& figures)
{
    size_t nFugures;
    in >> nFugures;
    for (size_t i = 0; i < nFugures; ++i)
    {
        std::string figureType;
        in >> figureType;

        Figure *f = factory(figureType);

        f->loadFromStream(in);
        figures.push_back(f);

    }
    return in;
}

int main()
{


    std::vector<Figure*> figures = {new Circle({0,0},1), 
                                    new Square({0,0},{1,1}),
                                    new Circle({1,1},2),
                                    new Square({0,1},{1,2})};


    std::cout << sumPerim(figures) << std::endl;

    std::ofstream fout ("figures.txt");

    fout << figures;

    fout.close();

    std::ifstream fin ("figures.txt");

    std::vector<Figure*> loaded;

    fin >> loaded;

    std::cout << loaded;

    

}