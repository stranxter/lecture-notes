#include <cmath>
#include <iostream>
#include <string>

struct Point
{
    double x,y;
};

class Figure
{
    public:

    Figure();
    Figure(const char *_label);

    virtual double area()=0;
    virtual double perimeter()=0;

    protected:
    std::string label;


};

Figure::Figure()
{
    std::cout << "Figure::Figure()\n";
    label = "No label";
}
Figure::Figure(const char *_label):label(_label)
{
    std::cout << "Figure::Figure(const char*)\n";
}

class Square : public Figure
{
    public:
    Point a,b;

    Square(Point _a, Point _b, const char*_label);

    double area();
    double perimeter();
    double side();

};

Square::Square(Point _a, Point _b, const char *_label):a(_a),b(_b),Figure(_label)
{
    std::cout << "Square::Square()\n";
    //label = _label;
}   


double Square::side()
{
    return sqrt(((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))/2);
}

double Square::area()
{
    std::cout << "Square::area()\n";
    return side()*side();
}

double Square::perimeter()
{
    return 4*side();
}

class Circle : public Figure
{
    public:
    Point c;
    double r;

    Circle(Point _c, double _r, const char *_label);

    double area();
    double perimeter();

};

Circle::Circle(Point _c, double _r, const char *_label):c(_c),r(_r)
{
    label = _label;
}

double Circle::area()
{
    std::cout << "Circle::area()\n";
    return 3.14*r*r;
}

double Circle::perimeter()
{
    return 2*3.14*r;
}

double sumArea(Figure *figs[], unsigned size)
{
    double result = 0;
    for (int i = 0; i<size; ++i)
    {
        result += figs[i]->area();
    }

    return result;
}

int main()
{

    Figure *c[] = {new Circle{{0,0},1,"Circle 1"},
                   new Circle{{1,1},2,"Circle 2"},
                   new Square{{-1,-1},{1,1},"Square 1"},
                   new Square {{1,0},{3,2},"Square 2"}};
    
    std::cout << sumArea(c,4) << std::endl;

}