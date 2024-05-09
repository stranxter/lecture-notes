#include "figure.h"
#include <vector>

class Group : public Figure
{
    public:
  //  Group(std::vector<Figure*>);

    Group() = default;
    Group(const Group&);

    double area() const;
    double perimeter() const;
    void draw() const;
    void saveToFile(std::ostream&) const;
    void loadFromFile(std::istream&);

    Group& operator=(const Group&);

    void addFigure(Figure*);

    Figure* copy() const;
    void clear();

    ~Group();

    private:
    std::vector<Figure*> figures;

    void copyContents(const Group &);

};
