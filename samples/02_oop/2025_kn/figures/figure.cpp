#include "figure.h"
#include "draw/sdlwrapper.h"

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "group.h"

std::ostream& operator << (std::ostream &out,const Point &p)
{
    out << p.x << " " << p.y;
    return out;
}

std::istream& operator >> (std::istream &in,Point &p)
{
    in >> p.x >> p.y;
    return in;
}

void Figure::setColor(Color color)
{
    this->color = color;
}

Figure::Figure():color(white){};

Figure::Figure(Color c):color(c){};

void Figure::predraw()
{
    sdlw::setColor(color.r,color.g,color.b);
}


std::ostream& operator<<(std::ostream& out,const std::vector<Figure*> v)
{
    out << v.size() << std::endl;
    for (Figure* fig : v)
    {
        fig->serialize(out);
        out << std::endl;
    }
    return out;
}

Figure* factory(std::string type)
{
    if (type == "circle")
    {
        return new Circle();
    } else if (type == "rect")
    {
        return new Rect();
    } else if (type == "tri")
    {
        return new Triangle();
    } else if (type == "group")
    {
        return new Group();
    }

    throw "Unknow object type!";
    return nullptr;
}

std::istream& operator>>(std::istream &in, std::vector<Figure*>& v)
{   
    v.clear();
    int n;
    in >> n;
    for(int i = 0; i < n; ++i)
    {

        std::string type;
        in >> type;

        Figure *f = factory(type);

        f->deserialize(in);
        v.push_back(f);
    }
    return in;
}
