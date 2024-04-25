#include "figure.h"

#include "utils.h"

class Triangle : public Figure
{

    public:

    Triangle(const Point& _p1, const Point& _p2, const Point& _p3);


    double area() const;
    double perimeter() const;
    void draw() const;
    void save(std::ostream& out) const;
    void load(std::istream& in);

    double sidea() const;
    double sideb() const;
    double sidec() const;

    private:
    Point p1;
    Point p2;
    Point p3;
};