#include "figure.h"

class Rect : public Figure
{

    public:
    Rect(Point2D _a, double, double);

    double surface();

    double perimeter();

    void writeToStream(std::ostream& out);
    void loadFromStream(std::istream &in);

    void draw();

    void translate(double x, double y);
   
    Figure* clone();

    Point2D getVertex() const;
    double getW() const;
    double getH() const;

    void accept(Visitor*);

    private:
    Point2D a;
    double w;
    double h;
};

