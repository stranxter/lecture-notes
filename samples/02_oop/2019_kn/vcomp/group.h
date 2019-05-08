#ifndef __GROUP_H
#define __GROUP_H

#include "shape.h"
#include <vector>

class Group: public Shape
{
    public:
    Group (int _x, int _y, const char *s);
    Group (const Group&);
    Shape *clone();

    void accept (Visitor*);

    void addShape (Shape*);

    Group& operator =(const Group &g);

    size_t get_nChildren () const;
    Shape* getChild (size_t i) const;

    ~Group ();

    private:
    std::vector<Shape*> children;
};

#endif  