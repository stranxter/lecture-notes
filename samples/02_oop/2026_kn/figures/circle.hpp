#pragma once
#include "figure.hpp"


class Circle : public Figure {
   public:
	double r;

	Circle(const Point &point, double _r, const char *_label);

	void serialize(std::ostream& out) const override;
	virtual void deserialize(std::istream&) override;

	double area() const override;
	double perimeter() const override;

	bool containsCentered(const Point &) const override;

    virtual Figure* copy() const override;

};
