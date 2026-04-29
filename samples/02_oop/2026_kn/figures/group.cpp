#include "group.hpp"
#include <iostream>


double Group::area() const
{
    double sum = 0;
    for (Figure *f : contents)
    {
        sum += f->area();
    }
    return sum;
}

double Group::perimeter() const
{
    double sum = 0;
    for (Figure *f : contents)
    {
        sum += f->perimeter();
    }
    return sum;
}

void Group::serialize(std::ostream& out) const
{
	out << "[Grp]\n";
    out << contents.size() << "\n";
	for (const Figure *fig : contents)
	{
		fig->serialize(out);
		out << "\n";
	}
}


void Group::deserialize(std::istream& in)
{
	std::string type;
	int count;
	in >> count;

	for(int i = 0; i < count; ++i)
	{
		in >> type;
		Figure *fig = figureFactory(type);
		fig->deserialize(in);
		contents.push_back(fig);
	}
}

//bool contains(const Point &p) const { return this->containsCentered({p.x - center.x, p.y - center.y}); }

bool Group::containsCentered(const Point &p) const
{
    for (Figure *f : contents)
    {
        if(f->containsCentered(p))
            return true;
    }
    return false;   
}

void Group::addFigure(Figure *f)
{
    contents.push_back(f->copy());
}




void Group::drawToPPM(std::ostream &out) {
	const unsigned int size	  = 500;	 // [0...size-1]
	const double	   bounds = 5;		 // [-bounds, +bounds]

	out << "P3\n" << size << " " << size << "\n" << 255 << "\n";

	for (unsigned int j = 0; j < size; ++j) {
		for (unsigned int i = 0; i < size; ++i) {
			Point currentPoint = {-bounds + i * bounds * 2 / size, -bounds + (size - j - 1) * bounds * 2 / size};
			bool  isInside	   = false;
			for (Figure *f : contents) {
				if (f->contains(currentPoint)) { isInside = true; }
			}
			if (isInside) out << "255 255 255 ";
			else out << "0 0 0 ";
			out << "\n";
		}
	}
}


Group::~Group()
{
    for(Figure *f : contents)
    {
        delete f;
    }
}

Group::Group(const Group& original)
{
    for(Figure *f: original.contents)
    {
        this->contents.push_back(f->copy());
    }
}

Figure* Group::copy() const
{
    return new Group(*this);
}

Group::Group()
{

}