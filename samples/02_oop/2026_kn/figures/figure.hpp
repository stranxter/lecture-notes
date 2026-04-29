#pragma once

#include <string>

struct Point {
	double x, y;
};

class Figure {
   public:
	Figure();
	Figure(const Point &center, const char *_label);
	Figure(const char *_label);

    virtual Figure* copy() const = 0;

	virtual double area() const		 = 0;
	virtual double perimeter() const = 0;
	virtual void serialize(std::ostream&) const = 0;
	virtual void deserialize(std::istream&) = 0;

	bool contains(const Point &p) const { return this->containsCentered({p.x - center.x, p.y - center.y}); }

	virtual bool containsCentered(const Point &p) const = 0;

    virtual ~Figure(){};

    protected:
	std::string	 label;
	Point		 center;
};

Figure* figureFactory(const std::string& figure);
