#ifndef __GROUP_H
#define __GROUP_H

#include "shape.h"
#include <vector>

class Group: public Shape
{
    public:
    Group (int _x, int _y, const char *s);
    Group (const Group&);
    void draw();
    Shape *clone();
    void serialize(std::ostream &);

    void addShape (Shape*);

    Group& operator =(const Group &g);


    ~Group ();

    private:
    std::vector<Shape*> children;
};

#endif  