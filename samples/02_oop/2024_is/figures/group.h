#include "figure.h"
#include <vector>

class Group : public Figure
{

    public:

    Group(const Group&);
    Group() = default;

    double area() const;
    double perimeter() const;
    void draw(Point origin) const;
    void save(std::ostream& out) const;
    void load(std::istream& in);

    Group& operator=(const Group&);

    Figure* copy() const;

    void add(Figure*);
    void clear();
    
    ~Group();

    private:
    std::vector<Figure*> figures;

    void copyContents(const Group&);


};