#pragma once
#include "figure.hpp"


class HalfPlane : public Figure {
	double a, b, c;

   public:
	HalfPlane(double a, double b, double c);
	HalfPlane(const Point &a, const Point &b);

	void serialize(std::ostream& out) const override;
	virtual void deserialize(std::istream&) override;

	double area() const override;
	double perimeter() const override;
	bool   containsCentered(const Point &) const override;

	Figure* copy() const override;
};
